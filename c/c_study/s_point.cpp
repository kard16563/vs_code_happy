#include <stdio.h>
 
void tt(int *);//对传入的地址进行寻址
void point_1(const int *p);/* *p 的 值不能动 但可以改动 P的值*/
void point_2(int * const p);/* p的值不能动 *p的可移动  */

int main()
{
    //int i="666";
    /* 我的第一个 C 程序 */
    int a=0 ;
    tt(&a);
    tt(&a);
    int i ,*p;
    p=&i;

    point_1(p);//传入地址
    point_2(p);

    printf("Hello, World! p_> point to  %p --- > %d  \n",p,p);
    getchar();
 
    return 0;
}

void tt(int *a){
    *a=*a+1;
    static int  i=0;
    i=i+1;
    printf("value of i -> %d \n",i,"--->> %d",*a);
}


void point_1(const int *p){
    int i ;
    p=&i;
}

void point_2(int * const p){
    int i;
    // wrong ---》  *p=0;
    *p=0;

}