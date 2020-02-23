#include<stdio.h>

int main(){
    unsigned int i,j,k;
    
    i=1;
    j=i<<2;//move 2 bit  to the left 
    j=i>>2;
    j=3;

    i=21;
    k=~i;

    /*把掩码中的 0 看作不透明，1 看作透明。表达式 flags & MASK 相当于用掩码覆盖在
flags 的位组合上，只有 MASK 为 1 的位才可见*/

    unsigned mask, flag;
    mask=00011;
    flag=10010;

    flag=flag&mask;// 进制转换检查 https://tool.lu/hexconvert/





    getchar();
    getchar();
    return 0;
}