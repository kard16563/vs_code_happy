//其他函数库
#include<stdio.h>
#include<stdarg.h> // 可变长度实参

int max_int(int n ,...){//... 表示后面可以跟其他可变数量的参数
    va_list ap;//这样可以强制函数访问到 n 后面的实参们
    int i,current,largest;

    va_start(ap,n);
    largest = va_arg(ap,int);

    for (i=i;i<n;i++){
        current = va_arg(ap,int);
        if (current>largest){
            largest=current;

        }

        va_end(ap);
        return largest;
    }


}

int main(){




    getchar();
    getchar();
    return 0
}