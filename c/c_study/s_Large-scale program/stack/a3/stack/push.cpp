#include<stdio.h>

extern char stack[512];
extern int top ;

void push(char c){
    printf(" 1 top-> , %d ",top);
    stack[++top]=c;
    printf(" 2 top-> , %d  ,%c \n \n",top,stack[top]);
}