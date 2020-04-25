#include<stdio.h>
extern int top;

int is_empty(void){
    printf(" emp _top-> %d ",top);
    return top ==-1;
}