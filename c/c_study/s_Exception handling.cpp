//错误处理
#include<stdio.h>
#include <assert.h>//断言 判断大小
#include <errno.h>//数学运算在中的错误 是不是0之类的
#include <signal.h>//异常信号
#include <unistd.h>//获取进程的ID
#include <setjmp.h>//非局部跳转 直接从一个函数调到另一个函数不用返回

static jmp_buf env;//特殊变量 jmp_buf将当前 环境 保存到变量中 返回0 供后续跳回 

void pp(){
    pid_t Pid = getpid(); /* Process gets its id.*/
    printf("pid=%d\n", getpid());
}

void handing (int sig){
    printf("error ,%d ",sig);
    pp();
}

void f2 (){
    printf("\n >> >> 进入f2函数 开始跳转 \n");
    longjmp(env,1);//这是呢里的值变为1 不是默认的0
    printf("\n >> f2函数 over");
}

void f1 (){
    printf("\n >> 进入f1函数 进入f2");
    f2();
    printf("\n >> f1函数 over");
}

int main(){
    // int i;
    // assert(i>10);//只能判断大小 括号内为正常情况下里面的值应当为真
    printf("pid=%d\n", getpid());

    int ret ;
    ret=setjmp(env);//标记完成
    printf(" 标记 结果为 --》 %d",ret);

    switch (ret)
    {
    case 0:
        printf("\n 初始为0 开始进入函数 ————》\n");
        f1();
        break;
    case 1:
        printf("\n 为1  跳转到头再回来成功\n");
        
        break;
    }



    signal(SIGINT,handing);
    while (1) 
    { 
        printf("hello world  中断输入 Ctrl+c 即可断开并被捕获\n"); 
        sleep(1); 
    } 

    getchar();
    return 0;
}