//unit testing
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
                        fprintf(stderr, " \n  >>>>=====---------->%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
                        fprintf(stderr,"\n    >>>======---------->%s:%d:expect : " format " actual: " format "\n",__FILE__,__LINE__,expect,actual );\
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

#define test_error(error, json)\
    do {\
        t_value v;\
        v.type = T_FALSE;\
        printf("\n\n  tt----->1 \n");\
        expect_eq_int(error, t_parse(&v, json));\
        printf("\n\n  tt-----> 8888 \n");\
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


///////////////////////////////////////////////
//printf("\n\n   sizeof(expect) - 1 %d alenth %d memcmp(expect,actual,alenth) %d  actual %d  \n\n",sizeof(expect) - 1, alenth, memcmp(expect,actual,alenth), actual);
#define expect_eq_string(expect, actual, alenth)  \
printf("\n\n  define expect_eq_string -b  expect-< %d actual-< %d  alenth-< %d  \n", expect,actual,alenth );\
                    expect_eq_base(sizeof(expect) - 1== alenth && memcmp(expect,actual,alenth) == 0, expect, actual, "%s")\
printf("\n\n  define expect_eq_string -n \n");

#define expect_true(actural) expect_eq_base((actual) != 0, "true", "false", "actural","%s")
#define expect_false(actural) expect_eq_base((actural) != 0, "false", "true", "%s")


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
    test_string("HELLO", "\"Hello\"");
#if 0
    test_string("Hello\nWorld", "\"Hello\\nWorld\"");
    test_string("\" \\ / \b \f \n \r \t", "\"\\\" \\\\ \\/ \\b \\f \\n \\r \\t\"");
#endif

}

static void test_parse_missing_quotation_mark() {
printf("\n\n ------------------ \n");
test_error(T_PARSE_MISS_QUOTATION_MARK, "\"");
printf("\n\n ================== \n");
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
    /* Use EXPECT_TRUE() and EXPECT_FALSE() */
}

static void test_access_number() {
    /* \TODO */
}

static void test_access_string() {
    t_value v;
    t_init(&v);
    t_set_string(&v, "", 0);

    printf("\n\n 0 test_access_string ---> sizeof %d t_get_string(&v) %d   t_get_string_length(&v) %d \n",sizeof(""),t_get_string(&v), t_get_string_length(&v));
    expect_eq_string("", t_get_string(&v), t_get_string_length(&v));
    t_set_string(&v, "Helloa", 6);
    
    printf("\n\n 1 test_access_string ---> sizeof %d t_get_string(&v) %d   t_get_string_length(&v) %d \n",sizeof("Hello"),t_get_string(&v), t_get_string_length(&v));
    expect_eq_string("Helloa", t_get_string(&v), t_get_string_length(&v));//ww
    printf("\n\n 2 test_access_string ---> \n");

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
    printf("\n\n test_parse_missing_quotation_mark---->0 \n");

    test_parse_missing_quotation_mark();
    printf("\n\n test_parse_missing_quotation_mark----> 1\n");
    test_parse_invalid_string_escape();
    test_parse_invalid_string_char();

    test_access_null();
    test_access_boolean();
    test_access_number();
    test_access_string();




    // test_parse_null();

    // test_parse_true();
    // test_parse_false();
    // test_parse_expect_value();
    // test_parse_invalid_value();
    // test_parse_root_not_singular();

}



int main(){

    test_parse();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    getchar();
    return main_ret;
    //E:\the_c_of_vs_code\c\c_project\json
    //E:\the_c_of_vs_code\c\c_project\json>gcc -c json.c
    //gcc -g  test.c json.c -o main
    //gcc -g  test.c json.o -o main
}