#include<stdio.h>
#include "./stack/stack.h"
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

//E:\the_c_of_vs_code\c\c_study\s_Large-scale program\stack\a3
//gcc -c stack/stack.cpp stack/push.cpp stack/pop.cpp stack/is_empty.cpp
//编译为目标文件
//ar rs libstack_1.a stack.o pop.o is_empty.o 
//打包为静态连接库 把一组代码写成一个库 libc  
//用哪个函数就连接那个 没有的就不连 这个就用 push  
//E:\the_c_of_vs_code\c\c_study\s_Large-scale program\stack\a3>ar rs libstack.a stack.o pop.o is_empty.o push.o
//gcc main.cpp -L. -lstack -Istack -o main 
// -L. 在当前目录下 寻找库文件 
//-lstack 连接 stack 
//-I 寻找头文件 -》stack

//位置探究的命令
//stack\a3>gcc -g main.cpp stack.o push.o pop.o -Istack -o main_绝对重定位