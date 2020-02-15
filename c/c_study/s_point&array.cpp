#include <stdio.h>
int main(){
    int a[10],*p,*q,i;
    
    p=&a[0];
    *p=5;//a[0]赋值为5

    p=&a[2];
    q=p+3;//q指向了a[5]

    p=&a[8];
    q=p-3;//q指向了a[5]

    p=&a[5];
    q=&a[1];
    i=p-q;//5-4
    printf(" =====>>>  %d   位置上的比较 %d \n " ,i,(p<=q) );
    for( p=&a[0] ; p<&a[10] ;p=p+1 ){
        *p=1;//取值应用
    }

    printf(" ---> %d **  %d",a[1],a[5]);

    for( p=a ; p<a+10 ;p=p+1 ){//取值应用  数组名就是首地址
        *p=2;
    }

    printf("\n  ---> %d **  %d",a[1],a[5]);

    *a=7;//数组名为a a[0]=7
    printf("\n -*a--> %d ",a[0]);

    *(a+1)=77;//数组名为a a[0+1]=7
    printf("\n -*(a+1)--> %d ",a[1]);

    int aaaa [10][10];
    int** aaa;//指向 整形指针 的 指针 aaaa也是
    int* aa;//整形指针
    aaa=&aa;



    
    getchar();
    getchar();

}