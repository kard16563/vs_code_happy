.section .data

.section .text
.globl _start
_start:
movl $1,%eax
movl $4,%ebx
int $0x80
#汇编语言 E:\the_c_of_vs_code\c\c_study\s_hello.s 