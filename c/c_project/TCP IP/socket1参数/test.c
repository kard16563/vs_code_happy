#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//测试目的 将结构体进行转换 其中 aa 有两个double bb有一个double数组 可以对应转换  按照原来的 类型对应即可


typedef struct aa {
    int aa1;
    double aa2;
    double aa3;
} aa ;
typedef struct bb{
    int bb1;
    double bb2[2];
}bb;
// (struct bb*) &aa
int main(){
    aa a1;
    a1.aa1=10;
    a1.aa2= 9.99;
    a1.aa3=0.99;

    bb *b1=(struct bb*) &a1;
    printf(" %d  %lf %lf ",b1->bb1, b1->bb2[0], b1->bb2[1]);

    getchar();
    return 0;
}