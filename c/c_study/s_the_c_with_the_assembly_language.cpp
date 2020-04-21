#include<stdio.h>
//处理c与汇编的关系

//gcc ha.cpp -o bman 将改文件编译为 bman.exe
//gcc -Wall ha.cpp 让gcc 警告所有信息 不管是严重的还是不严重的
int bar(int c,int d){
    int e=c+d;
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
//objdump -dS s_c_and_as.exe -t > assembly-objdump.txt保存在本地
//找<main>:11 大概在1602行 从1560为全部程序的入口
//gcc -S s_the_c_with_the_assembly_language.cpp



// warning: Source file is more recent than executable.
// 16          foo(2,3);
// (gdb) s
// foo (a=2, b=3) at s_the_c_with_the_assembly_language.cpp:12
// 12          return bar(a,b);
// (gdb) s
// bar (c=2, d=3) at s_the_c_with_the_assembly_language.cpp:7
// 7           int e=c=d;
// (gdb) disassemble----->进行反汇编当前的函数
// Dump of assembler code for function bar(int, int):
//    0x0000000000401560 <+0>:     push   %rbp 把rbp的值压入栈
//    0x0000000000401561 <+1>:     mov    %rsp,%rbp
//    0x0000000000401564 <+4>:     sub    $0x10,%rsp
//    0x0000000000401568 <+8>:     mov    %ecx,0x10(%rbp)
//    0x000000000040156b <+11>:    mov    %edx,0x18(%rbp)
// => 0x000000000040156e <+14>:    mov    0x18(%rbp),%eax
//    0x0000000000401571 <+17>:    mov    %eax,0x10(%rbp)
//    0x0000000000401574 <+20>:    mov    0x10(%rbp),%eax
//    0x0000000000401577 <+23>:    mov    %eax,-0x4(%rbp)
//    0x000000000040157a <+26>:    mov    -0x4(%rbp),%eax
//    0x000000000040157d <+29>:    add    $0x10,%rsp
//    0x0000000000401581 <+33>:    pop    %rbp
//    0x0000000000401582 <+34>:    retq
// End of assembler dump.
// (gdb) si  编译上进行下一步
// 0x0000000000401571      7          int e=c+d;
// (gdb) s   下一步处理
// 8           return e;
// (gdb) info registers 显示寄存器的值
// rax            0x5      5
// rbx            0x8      8
// rcx            0x2      2
// rdx            0x2      2
// rsi            0x2d     45
// rdi            0x6d14d0 7148752
// rbp            0x61fdf0 0x61fdf0
// rsp            0x61fdf0 0x61fdf0
// r8             0x6d1fb0 7151536
// r9             0x6d1490 7148688.....
// (gdb) p $esp 看寄存器的值
// $1 = 6422000

// (gdb) x/12x $esp 从内存地址的 0x61fdf0:  开始的12个32位的数
// 0x61fdf0:       0x0061fe20      0x00000000      0x0040159d      0x00000000
// 0x61fe00:       0x00000002      0x00000000      0x00000003      0x00000000
// 0x61fe10:       0x00000000      0x00000000      0x00000000      0x00000000