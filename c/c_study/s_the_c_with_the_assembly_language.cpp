#include<stdio.h>
//处理c与汇编的关系

//gcc ha.cpp -o bman 将改文件编译为 bman.exe
//gcc -Wall ha.cpp 让gcc 警告所有信息 不管是严重的还是不严重的
int bar(int c,int d){
    int e=c=d;
    return e;
}

int foo(int a, int b){
    return bar(a,b);
}

int main(void){
    foo(2,3);
    return 0;
}
//gcc s_the_c_with_the_assembly_language.cpp -o s_c_and_as---->错误的
//gcc -g s_the_c_with_the_assembly_language.cpp -o s_c_and_as
//gdb s_c_and_as 调试
//c_study\s_the_c_with_the_assembly_language.cpp
//objdump -ds s_c_and_as.exe  进行反汇编处理
//gcc -S s_the_c_with_the_assembly_language.cpp