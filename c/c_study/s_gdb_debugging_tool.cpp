#include<stdio.h>
/* 用gdbc 调试程序  s_gdb_debugging_tool.cpp   */

int  add_range(int low,int high){
    int i=0,sum=0;
    for (i=low;i<=high;i++)
        sum=sum +i;
        return sum;
}


int main(void){
    int result[1000];
    result[0]=add_range(1,10);
    result[1]=add_range(1,100);
    printf(" result[0]=%d \n result[1]=%d \n",result[0],result[1]);
    return 0;

}