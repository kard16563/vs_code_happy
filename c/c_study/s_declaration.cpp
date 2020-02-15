#include<stdio.h>//.h基本上是函数名 并没有函数的定义只讲接口暴露给了用户
                  // 这样对函数进行了抽象
                  //增强了函数的复用性 可维护性

#define public //公有地 默认情况 其他程序可以访问的 变量或函数
#define private static// 私有的 其他程序或者函数是无法访问的 用于信息的隐藏
                      // 安全别人改不了 灵活 重新这个重写时不用动接口 可以复用


typedef struct 
{
  int i;
} haha;//进行数据类型的伪抽象--》
  //及时把他放到了.h中也不是真正的 在调用的时候 .h会暴露它的具体实现方式就像现在一样无法远了点
  //但C没有考虑这种封装性 c++有



void aa(){
  static int i ;//编译器默认为零
  i=i+1;
  printf("\n  static -> %d   \n",i);
}

int main(){
  extern int ii;//几个源文件的共享变量
    static  float     x, y,   z=10;
//储存类型 类型说明符 声明符 初始化
  extern    const  float a[];
  const int i9=5;//初始化之后 const声明为只读 无法改写
  int a2[i9]={0};
//       类型限定符

  haha uu;//只管用就行了无需在意 具体怎么实现的
  aa();
  aa();
    getchar();
    getchar();
    return 0;
}