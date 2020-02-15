#include <stdio.h>
int main(){
long int a=1, *p=&a;
printf(" %p  %p ",&a,p);
long int_p = (long)p;//十进制 转16
long int *c;
c=(long int *)int_p;//16 转地址
printf("\n\n  %x  %p \n\n", int_p,c);

long int d=0xffffcba8 ;
long int *f;
f=(long int*)d; //访问地址为d的值

printf("\n\n\n  position -->    value--> %d  \n\n\n",*f);
// while(1){
//     printf("id %d  value->  %d   position --->  %d \n",a ,*(p),p);
//     a=a+1;
//     p=p-1;
//     // if(p<-140 ){
//     //     printf("\n\n ok \n\n");
//     // }else{
//     //     printf(" error \n\n");
//     //     break;
//     // }
//     }
printf("end");
getchar();
getchar();
return 0;
}