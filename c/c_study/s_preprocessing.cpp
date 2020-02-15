#include<stdio.h> //文件包含

#define a 10//宏定义
#define begin (
#define end )
#define loop for(;;)//自制循环语句
#define in  int

#define max(x,y) ((x)>(y)?(x):(y))//带参数 不能 用指针指
#define is_s(n) ( (n)%2==0 )
#define pp(x) printf(#x " = %d \n ",x)//#将后面的宏字符串化
#define mk_id(n) i##n //粘连 int mk_id(1)===》 int i1这个变量  ##就是 粘连使之成为一个 记号
// #define generic_max(type ,x) \
//         void type##_max(  type x )\
//         {\
//             printf( "---> %d \n ",x);}

#define wr printf("\n  --->  %d  %s  %s --",__LINE__,__DATE__,__FILE__)

#define DEBUG  1 //控制条件编译 -- 》 在调试模式下进行编译



void type(int x,int y) 
        {   
            printf( "---> %d  %d",x,y ); 
        }

int main(){

    printf("  ---->  %d -------  \n ",a);
    printf begin "   99999    \n" end ;
    printf( " \n max-----> %d  ",max(5,6));
    pp(55);
    printf("\n  --->  %d  %d  %s ",__LINE__,__DATE__,__FILE__);
    // generic_max(int,1);
    type(1,2);
    wr;

#if DEBUG
printf(" \n 55555 DEBUG is open");
#endif

    getchar();
    getchar();
    return 0;
}