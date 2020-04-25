#include<stdio.h>

char stack[512];
int top =-1;

void push(char c){
    printf(" 1 top-> , %d ",top);
    stack[++top]=c;
    printf(" 2 top-> , %d  ,%c \n \n",top,stack[top]);
}

char pop(void){
    
    char c=stack[top];
    printf("\n pop --> %c ,top-> %d \n",c,top);
    top=top-1;
    return c;
}

int is_empty(void){
    printf(" emp _top-> %d ",top);
    return top ==-1;
}