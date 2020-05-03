//unit testing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json.h"

static int main_ret =0;
static int test_count=0;
static int test_pass=0;

#define  expect_eq_base(equality , expect , actual , format)\
            do{\
                test_count++;\
                    if (equality)\
                    {\
                        test_pass++;\
                    }else\
                    {\
                        fprintf(stderr, "---------->%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
                        fprintf(stderr,"----------->%s:%d:expect : " format " actual: " format "\n",__FILE__,__LINE__,expect,actual );\
                        main_ret = 1;\
                    }\
                } while (0);



#define expect_eq_int(expect,actual) expect_eq_base((expect) == (actual),expect,actual,"%d")//测试宏
#define expect_eq_double(expect, actual) expect_eq_base( ((expect) - (actual) == 0.000000), expect, actual, "%.17g") printf(" \n answer -> %d ",((expect) - (actual)) );

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
    test_number(0.0, "0");
    //printf("   tt-> %lf ",strtod("0",&c));
    test_number(0, "0");
    test_number(0.0, "-0.0");
    test_number(1.0, "1");
    test_number(-1.0, "-1");
    test_number(1.5, "1.5");
}

#define test_error(error, json)\
    do {\
        t_value v;\
        v.type = T_FALSE;\
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



static void test_parse(){
    printf("\n  ------>> 1");
    test_parse_null();
    printf("\n  ------>> 1");
    test_parse_true();
    printf("\n  ------>> 2");
    test_parse_false();
    printf("\n  ------>> 2");
    test_parse_number();
    printf("\n  ------>> 3");
    test_parse_expect_value();
    printf("\n  ------>> 4");
    test_parse_invalid_value();
    printf("\n  ------>> 5");
    test_parse_root_not_singular();
    test_parse_number_too_big();




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