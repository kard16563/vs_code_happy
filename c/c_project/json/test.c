//unit testing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json.h"

static int main_ret =0;
static int test_count=0;
static int test_pass=0;

#define  expect_eq_base(equality , expect , actual , format)\
            do\
                {\
                test_count++;\
                printf("\n  test_count-> %d \n",test_count);\
                    if (equality)\
                    {\
                        test_pass++;\
                    }else\
                    {\
                        fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
                        fprintf(stderr,"%s:%d:expect : " format " actual: " format "\n",__FILE__,__LINE__,expect,actual );\
                        main_ret = 1;\
                    }\
                } while (0);



#define expect_eq_int(expect,actual)expect_eq_base((expect) == (actual),expect,actual,"%d")//测试宏

static void test_parse_null(){
    t_value v;
    v.type=T_TURE;
                expect_eq_int(T_PARSE_OK,t_parse(&v,"null"));
                expect_eq_int(T_NULL,t_get_type(&v));

}

static void test_parse(){
    test_parse_null();
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