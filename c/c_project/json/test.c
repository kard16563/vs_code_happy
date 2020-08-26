//unit testing

#ifdef _WINDOWS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json.h"

static int main_ret =0;
static int test_count=0;
static int test_pass=0;

#define  expect_eq_base(equality , expect , actual , format)\
            \
            do{\
                test_count++;\
                    if (equality)\
                    {\
                        test_pass++;\
                    }else\
                    {\
                        fprintf(stderr, "\n                         *********>>>>++++++++++++++++++++++++++++++++=====---------->%s:%d: expect: " format " actual: " format "---------------------->>>>>\n", __FILE__, __LINE__, expect, actual);\
                        fprintf(stderr,"\n                          *********>>>+++++++++++++++++++++++++++++++++======---------->%s:%d:expect : " format " actual: " format "--------------------->>>>>\n",__FILE__,__LINE__,expect,actual );\
                        main_ret = 1;\
                    }\
                } while (0);

/////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

#define expect_eq_int(expect,actual) expect_eq_base((expect) == (actual),expect,actual,"%d")//测试宏
#define expect_eq_double(expect, actual) expect_eq_base( ((expect) - (actual) == 0.000000), expect, actual, "%.17g") ;

static void test_parse_null(){
                t_value v;
                v.type=T_TURE;
                expect_eq_int(T_PARSE_OK,t_parse(&v,"null"));
                expect_eq_int(T_NULL,t_get_type(&v));

}

static void test_parse_true(){

    t_value v;
    v.type=T_FALSE;
    //printf("\n\nT_FALSE %d",T_FALSE);
    expect_eq_int(T_PARSE_OK,t_parse(&v, "true"));
    expect_eq_int(T_TURE,t_get_type(&v));//------>
}

static void test_parse_false(){

    t_value v;
    v.type=T_TURE;
    expect_eq_int(T_PARSE_OK,t_parse(&v, "false"));//对判断过程中是否出错
    expect_eq_int(T_FALSE,t_get_type(&v));//---> 判断结果是否出错
}


static void test_parse_expect_value() {
    t_value v;

    v.type = T_FALSE;
    expect_eq_int(T_PARSE_EXPECT_VALUE, t_parse(&v, ""));
    expect_eq_int(T_NULL, t_get_type(&v));

    v.type = T_FALSE;
    expect_eq_int(T_PARSE_EXPECT_VALUE, t_parse(&v, " "));
    expect_eq_int(T_NULL, t_get_type(&v));
}

// static void test_parse_invalid_value() {
//     t_value v;
//     v.type = T_FALSE;
//     expect_eq_int(T_PARSE_INVALID_VALUE, t_parse(&v, "nul"));
//     expect_eq_int(T_NULL, t_get_type(&v));

//     v.type = T_FALSE;
//     expect_eq_int(T_PARSE_INVALID_VALUE, t_parse(&v, "?"));
//     expect_eq_int(T_NULL, t_get_type(&v));
// }

// static void test_parse_root_not_singular() {
//     t_value v;
//     v.type = T_FALSE;
//     expect_eq_int(T_PARSE_ROOT_NOT_SINGULAR, t_parse(&v, "null x"));
//     expect_eq_int(T_NULL, t_get_type(&v));
// }

#define test_number(expect, json)\
    do {\
        t_value v;\
        expect_eq_int(T_PARSE_OK, t_parse(&v, json));\
        expect_eq_int(T_NUMBER, t_get_type(&v));\
        expect_eq_double(expect, t_get_number(&v));\
    } while(0)

static void test_parse_number() {
    char *c;
    test_number(1.1, "1.1");
    //printf("   tt-> %lf ",strtod("0",&c));
    test_number(0, "0");
    test_number(0.0, "-0.0");
    test_number(1.0, "1");
    test_number(-1.0, "-1");
    test_number(1.5, "1.5");
    test_number(1E+10, "1E+10");
    test_number(1e10, "1e10");

}
//
#define test_error(error, json)\
    do {\
        t_value v;\
        v.type = T_FALSE;\
        \
        expect_eq_int(error, t_parse(&v, json));\
        expect_eq_int(T_NULL, t_get_type(&v));\
    } while(0)

static void test_parse_invalid_value() {
test_error(T_PARSE_INVALID_VALUE, "nul");
test_error(T_PARSE_INVALID_VALUE, "?");

#if 0
    /* invalid number */
test_error(T_PARSE_INVALID_VALUE, "+0");
test_error(T_PARSE_INVALID_VALUE, "+1");
test_error(T_PARSE_INVALID_VALUE, ".123"); /* at least one digit before '.' */
test_error(T_PARSE_INVALID_VALUE, "1.");   /* at least one digit after '.' */
test_error(T_PARSE_INVALID_VALUE, "INF");
test_error(T_PARSE_INVALID_VALUE, "inf");
test_error(T_PARSE_INVALID_VALUE, "NAN");
test_error(T_PARSE_INVALID_VALUE, "nan");
#endif
}


static void test_parse_root_not_singular() {
test_error(T_PARSE_ROOT_NOT_SINGULAR, "null x");

#if 0
    /* invalid number */
test_error(T_PARSE_ROOT_NOT_SINGULAR, "0123"); /* after zero should be '.' , 'E' , 'e' or nothing */
test_error(T_PARSE_ROOT_NOT_SINGULAR, "0x0");
test_error(T_PARSE_ROOT_NOT_SINGULAR, "0x123");
#endif
}

static void test_parse_number_too_big() {
#if 0
test_error(T_PARSE_NUMBER_TOO_BIG, "1e309");
test_error(T_PARSE_NUMBER_TOO_BIG, "-1e309");
#endif
}


///////////////////////////////////////////////test_string("Hello", "\"Hello\"");
//printf("\n\n   sizeof(expect) - 1 %d alenth %d memcmp(expect,actual,alenth) %d  actual %d  \n\n",sizeof(expect) - 1, alenth, memcmp(expect,actual,alenth), actual);
#define expect_eq_string(expect, actual, alenth)  \
                    printf("\n\n 168 expect, actual---> %s, %s",expect, actual);\
                    expect_eq_base(sizeof(expect) - 1== alenth && memcmp(expect,actual,alenth) == 0, expect, actual, "%s")
//printf("\n\n  define expect_eq_string -n \n");

#define expect_true(actural) expect_eq_base((actual) != 0, "true", "false", "actural","%s")
#define expect_false(actural) expect_eq_base((actural) != 0, "false", "true", "%s")


#define EXPECT_TRUE(actual) expect_eq_base((actual) != 0, "true", "false", "%s")
#define EXPECT_FALSE(actual) expect_eq_base((actual) == 0, "false", "true", "%s")
//json---> "\"Hello\\nWorld\""
#define test_string(expect,json)\
    do {\
        t_value v;\
        t_init (&v);\
        expect_eq_int(T_PARSE_OK,t_parse(&v,json));\
        expect_eq_int(T_STRING,t_get_type(&v));\
        expect_eq_string(expect, t_get_string(&v), t_get_string_length(&v));\
        t_free(&v);\
    }while(0)

static void test_parse_string(){
    test_string("", "\"\"");
    test_string("Hello", "\"Hello\"");
// #if 0
//     test_string("Hello\nWorld", "\"Hello\\nWorld\"");
//     test_string("\" \\ / \b \f \n \r \t", "\"\\\" \\\\ \\/ \\b \\f \\n \\r \\t\"");
// #endif

    test_string("Hello\nWorld", "\"Hello\\nWorld\"");
    test_string("\" \\ / \b \f \n \r \t", "\"\\\" \\\\ \\/ \\b \\f \\n \\r \\t\"");
    test_string("Hello\0World", "\"Hello\\u0000World\"");
    test_string("\x24", "\"\\u0024\"");         /* Dollar sign U+0024 */
    test_string("\xC2\xA2", "\"\\u00A2\"");     /* Cents sign U+00A2 */
    test_string("\xE2\x82\xAC", "\"\\u20AC\""); /* Euro sign U+20AC */
    test_string("\xF0\x9D\x84\x9E", "\"\\uD834\\uDD1E\"");  /* G clef sign U+1D11E */
    test_string("\xF0\x9D\x84\x9E", "\"\\ud834\\udd1e\"");  /* G clef sign U+1D11E */
    printf("*****************************\n");
}


static void test_parse_invalid_unicode_hex() {
    test_error(T_PARSE_INVALID_UNICODE_HEX, "\"\\u\"");
    test_error(T_PARSE_INVALID_UNICODE_HEX, "\"\\u0\"");
    test_error(T_PARSE_INVALID_UNICODE_HEX, "\"\\u01\"");
    test_error(T_PARSE_INVALID_UNICODE_HEX, "\"\\u012\"");
    test_error(T_PARSE_INVALID_UNICODE_HEX, "\"\\u/000\"");
    test_error(T_PARSE_INVALID_UNICODE_HEX, "\"\\uG000\"");
    test_error(T_PARSE_INVALID_UNICODE_HEX, "\"\\u0/00\"");
    test_error(T_PARSE_INVALID_UNICODE_HEX, "\"\\u0G00\"");
    }

static void test_parse_invalid_unicode_surrogate() {
    test_error(T_PARSE_INVALID_UNICODE_SURROGATE, "\"\\uD800\"");
    test_error(T_PARSE_INVALID_UNICODE_SURROGATE, "\"\\uDBFF\"");
    test_error(T_PARSE_INVALID_UNICODE_SURROGATE, "\"\\uD800\\\\\"");
    test_error(T_PARSE_INVALID_UNICODE_SURROGATE, "\"\\uD800\\uDBFF\"");
    test_error(T_PARSE_INVALID_UNICODE_SURROGATE, "\"\\uD800\\uE000\"");
}

static void test_parse_missing_quotation_mark() {
//printf("\n\n ------------------ \n");
test_error(T_PARSE_MISS_QUOTATION_MARK, "\"");
//printf("\n\n ================== \n");
test_error(T_PARSE_MISS_QUOTATION_MARK, "\"Cbc");
}

static void test_parse_invalid_string_escape() {
#if 0
test_error(T_PARSE_INVALID_STRING_ESCAPE, "\"\\v\"");
test_error(T_PARSE_INVALID_STRING_ESCAPE, "\"\\'\"");
test_error(T_PARSE_INVALID_STRING_ESCAPE, "\"\\0\"");
test_error(T_PARSE_INVALID_STRING_ESCAPE, "\"\\x12\"");
#endif
}

static void test_parse_invalid_string_char() {
#if 0
test_error(T_PARSE_INVALID_STRING_CHAR, "\"\x01\"");
test_error(T_PARSE_INVALID_STRING_CHAR, "\"\x1F\"");
#endif
}

static void test_access_null() {
    t_value v;
    t_init(&v);
    t_set_string(&v, "a", 1);
    t_set_null(&v);
    expect_eq_int(T_NULL, t_get_type(&v));
    t_free(&v);
}

static void test_access_boolean() {
    /* \TODO */
    t_value v;
    t_init(&v);
    t_set_string(&v, "a", 1);
    t_set_boolean(&v, 1);
    EXPECT_TRUE(t_get_boolean(&v));
    t_set_boolean(&v, 0);
    EXPECT_FALSE(t_get_boolean(&v));
    t_free(&v);//防止内存泄漏
    
}

static void test_access_number() {
    /* \TODO */
    t_value v;
    t_init(&v);//仅仅是将类型 定位null 进行初始化
    t_set_string(&v, "a", 1);
    t_set_number(&v, 1234.5);
    expect_eq_double(1234.5, t_get_number(&v));
    t_free(&v);//防止内存泄漏
    //忘记了释放内存，造成内存泄露
//含有这种错误的函数每被调用一次就丢失一块内存。
//刚开始时系统的内存充足，你看不到错误。
//终有一次程序突然死掉，系统出现提示：内存耗尽。
}

static void test_access_string() {
    t_value v;
    t_init(&v);
    t_set_string(&v, "", 0);

    //printf("\n\n 0 test_access_string ---> sizeof %d t_get_string(&v) %d   t_get_string_length(&v) %d \n",sizeof(""),t_get_string(&v), t_get_string_length(&v));
    expect_eq_string("", t_get_string(&v), t_get_string_length(&v));
    t_set_string(&v, "Helloa", 6);
    
    //printf("\n\n 1 test_access_string ---> sizeof %d t_get_string(&v) %d   t_get_string_length(&v) %d \n",sizeof("Hello"),t_get_string(&v), t_get_string_length(&v));
    expect_eq_string("Helloa", t_get_string(&v), t_get_string_length(&v));//ww
    //printf("\n\n 2 test_access_string ---> \n");

    t_free(&v);
}


/////////////////////////////////////////////////////////////////
// 数组


//麻烦之处在于，ANSI C（C89）并没有的 size_t 打印方法，在 C99 则加入了 "%zu"，但 VS2015 中才有，之前的 VC 版本使用非标准的 "%Iu"
#define EXPECT_EQ_SIZE_T(expect, actual) expect_eq_base ((expect) == (actual), (int)expect, (int)actual, "%d" )
//((expect) == (actual), (size_t)expect, (size_t)actual, "%zu")
static void test_parse_array(){//问题所在 2020 8 25 
    t_value v;

    t_init (&v);
    expect_eq_int(T_PARSE_OK, t_parse(&v, "[ ]"));
    expect_eq_int(T_ARRAY, t_get_type(&v));
    EXPECT_EQ_SIZE_T(0, t_get_array_size(&v));
    t_free(&v);



    t_init(&v);
    // printf("\n testing!! position-> test.c 320 \n");
    // getchar();
    expect_eq_int(T_PARSE_OK,t_parse(&v, "[ null , false , true , 123 , \"abc\" ]"));
    // printf("\n testing!! position-> test.c 329  \n");
    // getchar();

    expect_eq_int(T_ARRAY, t_get_type(&v));
    EXPECT_EQ_SIZE_T(5, t_get_array_size(&v));
    
    //expect_eq_int(T_NULL,t_get_array_element(&v, 0, 0));//add
    expect_eq_int(T_FALSE, t_get_array_element_type(&v, 1));
    expect_eq_int(T_TURE, t_get_array_element_type(&v, 2));
    expect_eq_int(T_NUMBER, t_get_array_element_type(&v, 3 ));
    expect_eq_int(T_STRING, t_get_type(t_get_array_element(&v, 4,1)));////不同之处

    // printf("\n testing!! position-> test.c 338  \n");
    // getchar();

    expect_eq_double(123.0, t_get_number( t_get_array_element(&v, 3, 1) ));
    expect_eq_string("abc", t_get_string(t_get_array_element(&v, 4, 1)), t_get_string_length(t_get_array_element(&v, 4, 1)));
    t_free(&v);
    

    t_init(&v);
    expect_eq_int(T_PARSE_OK, t_parse(&v, "[ [ ] , [ 0 ] , [ 0 , 1 ] , [ 0 , 1 , 2 ] ]"));
    expect_eq_int(T_ARRAY, t_get_type(&v));
    EXPECT_EQ_SIZE_T(4, t_get_array_size(&v));
    // printf("\n testing!! position-> test.c 353 \n");
    // getchar();

    for(int i=0; i<4 ; i++){
        t_value *a = t_get_array_element(&v,i,1);
        expect_eq_int(T_ARRAY, t_get_type(a));
        EXPECT_EQ_SIZE_T(i, t_get_array_size(a));
        // printf("\n testing!! position-> test.c 349 \n");
        // getchar();

        for(int j=0 ; j<i ; j++){
            t_value *e =  t_get_array_element(a, j, 1);
            expect_eq_int(T_NUMBER, t_get_type(e));
            //printf("\ntesting!! position-> test.c 361 num ->%lf i->%d j ->%lf  \n",t_get_number( e ),i,(double)j);
            //printf("\n -- %lf -- \n",  t_get_number( t_get_array_element(t_get_array_element(&v,3,1),3, 1) ) );
            //getchar();
            expect_eq_double((double) j, t_get_number( e ));
        }

    }
    //printf("\n  end 2\n ");
    t_free(&v);
    //printf("\n  end 1\n ");


}





static void test_parse_miss_comma_or_square_bracket() {
#if 0
    test_error(T_PARSE_MISS_COMMA_OR_SQUARE_BRACKET, "[1");
    test_error(T_PARSE_MISS_COMMA_OR_SQUARE_BRACKET, "[1}");
    test_error(T_PARSE_MISS_COMMA_OR_SQUARE_BRACKET, "[1 2");
    test_error(T_PARSE_MISS_COMMA_OR_SQUARE_BRACKET, "[[]");
#endif
}



//////////////////////////////////////////// 处理obj

static void test_parse_obj(){
    t_value v;
    int i;

    t_init(&v);
    expect_eq_int(T_PARSE_OK, t_parse(&v, "{}"));
    expect_eq_int(T_OBJ, t_get_type(&v));
    EXPECT_EQ_SIZE_T(0, t_get_object_size(&v));
    t_free(&v);

    t_init(&v);
    expect_eq_int(T_PARSE_OK, t_parse(&v,
        " { "
        "\"n\" : null , "
        "\"f\" : false , "
        "\"t\" : true , "
        "\"i\" : 123 , "
        "\"s\" : \"abc\", "
        "\"a\" : [ 1, 2, 3 ],"
        "\"o\" : { \"1\" : 1, \"2\" : 2, \"3\" : 3 }"
        " } "
    ));


//expect_eq_int  expect_eq_string
    expect_eq_int(T_OBJ, t_get_type(&v));
    EXPECT_EQ_SIZE_T(7, t_get_object_size(&v));
    expect_eq_string("n", t_get_object_key(&v, 0), t_get_object_key_length(&v, 0));
    expect_eq_int(T_NULL,   t_get_type(t_get_object_value(&v, 0)));
    expect_eq_string("f", t_get_object_key(&v, 1), t_get_object_key_length(&v, 1));
    expect_eq_int(T_FALSE,  t_get_type(t_get_object_value(&v, 1)));
    expect_eq_string("t", t_get_object_key(&v, 2), t_get_object_key_length(&v, 2));
    expect_eq_int(T_TURE,   t_get_type(t_get_object_value(&v, 2)));
    expect_eq_string("i", t_get_object_key(&v, 3), t_get_object_key_length(&v, 3));
    expect_eq_int(T_NUMBER, t_get_type(t_get_object_value(&v, 3)));
    expect_eq_double(123.0, t_get_number(t_get_object_value(&v, 3)));
    expect_eq_string("s", t_get_object_key(&v, 4), t_get_object_key_length(&v, 4));
    expect_eq_int(T_STRING, t_get_type(t_get_object_value(&v, 4)));
    expect_eq_string("abc", t_get_string(t_get_object_value(&v, 4)), t_get_string_length(t_get_object_value(&v, 4)));
    expect_eq_string("a", t_get_object_key(&v, 5), t_get_object_key_length(&v, 5));
    expect_eq_int(T_ARRAY, t_get_type(t_get_object_value(&v, 5)));
    EXPECT_EQ_SIZE_T(3, t_get_array_size(t_get_object_value(&v, 5)));

    for(i=0; i<3; i++){
        t_value* e = t_get_array_element(t_get_object_value(&v,5),i, 0);
        expect_eq_int(T_NUMBER,t_get_type(e));
        expect_eq_double(i*1.0,t_get_number(e));
    }

    expect_eq_string("o", t_get_object_key(&v, 6), t_get_object_key_length(&v, 6));


    {
        t_value* o = t_get_object_value(&v, 6);
        expect_eq_int(T_OBJ, t_get_type(o));
        for (i = 0; i < 3; i++) {
            t_value* ov = t_get_object_value(o, i);
            EXPECT_TRUE('1' + i == t_get_object_key(o, i)[0]);
            EXPECT_EQ_SIZE_T(1, t_get_object_key_length(o, i));
            expect_eq_int(T_NUMBER, t_get_type(ov));
            expect_eq_double(i + 1.0, t_get_number(ov));
            //expect_eq_double
        }
    }
    t_free(&v);
}




//////////////////////////////////////////////////////////
static void test_parse(){
   // printf("\n  ------>> 1");
    test_parse_null();
    //printf("\n  ------>> 1");
    test_parse_true();
    //printf("\n  ------>> 2");
    test_parse_false();
    //printf("\n  ------>> 2");
    test_parse_number();
   // printf("\n  ------>> 3");
    test_parse_expect_value();
   // printf("\n  ------>> 4");
    test_parse_invalid_value();
   // printf("\n  ------>> 5");
    test_parse_root_not_singular();
    test_parse_number_too_big();
    //printf("\n\n test_parse_missing_quotation_mark---->0 \n");

    test_parse_missing_quotation_mark();
    //printf("\n\n test_parse_missing_quotation_mark----> 1\n");
    test_parse_invalid_string_escape();
    test_parse_invalid_string_char();

    test_access_null();
    test_access_boolean();
    test_access_number();
    test_access_string();

    test_parse_invalid_unicode_hex();
    test_parse_invalid_unicode_surrogate();
    test_parse_string();

    test_parse_miss_comma_or_square_bracket();
    
    test_parse_array();//问题函数所在位置
    test_parse_obj();





    // test_parse_null();

    // test_parse_true();
    // test_parse_false();
    // test_parse_expect_value();
    // test_parse_invalid_value();
    // test_parse_root_not_singular();

}



int main(){
    printf("|test !!!!!! \n\n");

    #ifdef _WINDOWS//内存泄漏检测
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    #endif

    test_parse();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    getchar();
    return main_ret;
    //跳转指定行数: Ctrl + G
    //跳转到函数 F12 
    //E:\the_c_of_vs_code\ c\c_project\json
    //E:\the_c_of_vs_code\c\c_project\json>gcc -c json.c
    //gcc -g  test.c json.c -o main

    // wsl--> /mnt/e/DevelopRoom/Code/the_c_of_vs_code/c/c_project/json
}