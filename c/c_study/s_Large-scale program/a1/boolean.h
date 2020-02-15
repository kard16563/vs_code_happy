#ifndef bool_1 //防止重复引用  boool定义了 就会闭合-->bo1.h

#define bool_1 int
#define true_1  1
#define false_0 0

typedef int Bool;

void make_empty(void);
int is_empty(void);
int is_full(void);
void push(int i);
int pop(void);
int i ;//这里定义了变量i 共享变量放在了头文件

#endif