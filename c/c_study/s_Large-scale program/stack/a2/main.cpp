#include<stdio.h>
#include "stack.h"
#include"./a22/a2.h"//这里可以使用相对路径

int main(void){
    test_aa2();
  const  char *a ="a";
  const  char *b ="b";
  const  char *c ="c";


    push(*a);
    push(*b);
    push(*c);

    while (!is_empty())
    {
        putchar(pop());
        getchar();
    }

    printf(" \n  end --- ");
    getchar();
    return 0;
}
    //E:\the_c_of_vs_code\c\c_study\s_Large-scale program\stack\a2
    //gcc main.c stack.h stack.c -g -o link_1
    //gcc main.cpp stack.h stack.cpp -g -o link_1
//cc main.cpp stack.h stack.cpp ./a22/test_aa2.cpp ./a22/a2.h  -g -o link_1
//gcc main.cpp stack.cpp ./a22/test_aa2.cpp   -g -o link_1
//仅仅处理 实体的文件就可以头文件 不用