#include<stdio.h>
#include "../stack/stack.h"
//#include"./a22/a2.h"//这里可以使用相对路径

int main(void){
  //  test_aa2();
  const  char *a ="a";
  const  char *b ="b";
  const  char *c ="c";


    push(*a);
    push(*b);
    push(*c);

    // while (!is_empty())
    // {
    //     putchar(pop());
    //     getchar();
    // }

    printf(" \n  end --- ");
    getchar();
    return 0;

}


//生成相对路径

//E:\the_c_of_vs_code\c\c_study\s_Large-scale program\stack\a3\share_lib
//gcc -c -g -fPIC ../stack/stack.cpp ../stack/push.cpp ../stack/pop.cpp ../stack/is_empty.cpp
//pic -> position indepence code 位置无关代码
//objdump -dS push.o -t > push汇编.txt

// gcc -shared -o libstack.so stack.o push.o is_empty.o 生成 libstack.so
//ar rs libstack_1.a stack.o pop.o is_empty.o push.o
//objdump -dS libstack.so -t > libstack汇编.txt
// \share_lib> gcc main.cpp -g -L. -lstack_1 -Istack -o main -->生成新的exe
//ldd main 可以看用了哪些库在乌班图上
