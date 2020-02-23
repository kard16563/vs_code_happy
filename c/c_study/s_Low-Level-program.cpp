#include<stdio.h>

    typedef unsigned char byte1;
    typedef unsigned int word1;


    union 
    {
        struct 
        {
            word1 ax,bx,cx,dx;
        }word;

        struct 
        {
            byte1 al,ah,bl,bh,cl,ch,dl,dh;
        }byte;

    }regs;
    

int main(){
    unsigned int i,j,k;
    
    i=1;
    j=i<<2;//move 2 bit  to the left 
    j=i>>2;
    j=3;

    i=21;
    k=~i;

    /*把掩码中的 0 看作不透明，1 看作透明。
    表达式 flags & MASK 相当于用掩码覆盖在
    flags 的位组合上，只有 MASK 为 1 的位才可见*/

    unsigned mask, flag;
    mask=00011;//掩码
    flag=10010;

    flag=flag&mask;// 00010进制转换检查 https://tool.lu/hexconvert/

    i  = 0x0010;
    i &= ~0x0010;


    regs.byte.ah=0x12;//16位
    regs.byte.al=0x34;//16位
    printf("\n  寄存器模仿 %x  ",regs.word.ax);//16位
    //因为联合的位置是公用父ax的位置里面有ah与al 的位置所以可以输出
    
    //指针地址分析
    int *t,*t1,**tt;
    t= new int;
    *t=1;
    printf(" t --> 0x%x ",*t);
    t1=t;//t1直接指向t所指的地方 值为1

    tt=&t;//tt指向了指针t的地址 他保存了t所指的东西 呢个1的地址


    int  *p;
    p = (int*)0x8048c0;//直接指向了这个地址
    printf(" \n  --- %p ,地址-->0x%x",p,p);

    volatile byte1 *uu;//告诉寄存器这个所指的东西常常变化 所以在编译的时候进行优化




    getchar();
    getchar();
    return 0;
}