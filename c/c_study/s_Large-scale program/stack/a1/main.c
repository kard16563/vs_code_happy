#include<stdio.h>

//E:\the_c_of_vs_code\c\c_study\s_Large-scale program\stack\a1

int a,b=1;
int main(void){

    push('a');
    push('b');
    push('c');

    while (!is_empty())
    {   
        putchar(pop());
        getchar();
        
    }
    
    return 0;
    //gcc main.c stack.c -o link_1
    //gcc main.c stack.c -g -o   link_1

    //调试的端点设置哦
    //l main 选定函数
    //b 19   对行打定点
    //l stack
    //b push  对函数打定点
}