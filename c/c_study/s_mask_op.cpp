#include<stdio.h>

int main (){
    //16进制中的一个数相当于 二进制中的 4位数 比如1个f 为1111
    //下面的一共是 8位16进制的 4*8=32位 二进制数
    //0x0000ff00--》后两个0表示为8个0 ff表示为 第9到第16位
    //取出9-16位
    unsigned int a,b,mask=0x0000ff00;
    a=0x12345678;//10010001101000 1010110 01111000
    b=(a&mask)>>8;//变为2进制进行左移操作 
    //0x00000056 -- 1010110
    printf(" %x---\n %x\n %x  ",a,mask,b);
    
    unsigned int a2,b2,mask2=0x0000ff00;
    a2=0x12345678;
    b2=a2&~mask;
    printf(" \n 消除 第9到第16位  %x",b2);


    getchar();
    return 0;
}