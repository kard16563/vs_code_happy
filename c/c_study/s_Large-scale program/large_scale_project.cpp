#include<stdio.h>
#include"./a1/bo1.h"
#include"./a1/boolean.h"

int main(){
    extern  int a[];//忽略数组的长度
    
    extern int i;//这里提示编译器 这里的int 是其他地方定义的 因此不用为i分配空间
      make_empty();

    return true_1;
}/*cmake 将相关文件进行编译 为.o文件 然后用cmake进行连接 之后就可以运行了*/