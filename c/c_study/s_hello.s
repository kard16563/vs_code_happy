.section .data#分段数据

.section .text#分段 文本保存可读
.globl _start#共链接使用
_start:#入口
movl $1,%eax#把 long 型1放入 寄存器 eax中
movl $4,%ebx
int $0x80#int 进入内核 软中断 0x80 是系统调用
#汇编语言 E:\the_c_of_vs_code\c\c_study\s_hello.s 
#这位是在乌班图下的语法 win下的不是