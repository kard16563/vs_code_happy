.section .data  #to find the max value in data_items
data_items:   #数组名并将其作为首地址  不用global他在内部使用
.long 3,67,222,75,74 #.long 声明数组 每个数组占32位 .byte 也是数组8位

#edi-数组当前寄存器的位置  ebx 目前找到的最大值存放的寄存器 
#eax-当前要比较的数

.section .text
.globl _start
_start:
    .ascii " hellio \0",
    movl $0 ,%edi   #将edi寄存器指向数组的第0个元素--数组下标
        #立即数寻址 ..

    movl data_items(,%edi,4) %eax,
    
        #变地寻址
        #data_items是数组的首地址 传入位置下标 4表示每个元素占4个字节4*8=32
        #某个元素的地址是 data_items+edi*4  放入寄存器eax
        #直接寻址 movl address ，%eax
        #间接寻址 movl （%eax），%ebx eax的值就是地址

    movl %eax,%ebx

start_loop: #开始循环
    cmpl %0,%eax #比较做差 结果为0 相等 zf为1
    je loop_exit #检查zf为1 就执行
    incl %edi
    movl data_items(%edi,4),
    cmpl %ebx,%eax #把当前的元素与目前的最大值进行比较
    jle start_loop

loop_exit:
    movl %1,%eax
    int %0x80

#as s_find_max.s -o max.o 汇编
#ld max.o -o max 链接
#可以解析一下 elf 文件 来查看汇编与连接 的结果 还有反汇编的结果 