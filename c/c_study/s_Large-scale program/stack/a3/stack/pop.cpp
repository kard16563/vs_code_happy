#include<stdio.h>

extern char stack[512];
extern int top ;

char pop(void){
    
    char c=stack[top];
    printf("\n pop --> %c ,top-> %d \n",c,top);
    top=top-1;
    return c;
}