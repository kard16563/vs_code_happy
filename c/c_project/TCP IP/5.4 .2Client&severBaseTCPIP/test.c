#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 100
#define OPSZ 4
// 数字 放入字符串数组中 并 从字符串数组去除参与计算

// 一个int 字符占内存的 4个字符 
// 4 Enter -> new obj
// 2 Enter -> obj-> new function
// 1 Enter -> print dubug

int op (int msg1[] ,char msg[] ,int i);
void check_cha(char ch[], int index);
void check_num(int num[], int index);

int main (){

    char msg[BUF_SIZE];
    char ch;
    int  *tmp;
    int i;
    tmp = (int *)msg; // 将原本数组地址的首地址的  指针类型 强行变为int型
            printf("1 tmp -> %p \n",&tmp);
    
    for (i=0 ;i<5 ;i++){
        tmp[i] = i+1;//强行放入数组 只能用 %d 读出来 %c 读不出来
            printf("i-> %d  msg-> %p tmp-> %p value -> %d \n",i+1, &msg[i], &tmp[i],tmp[i]);//转为数字的化默认 占4个字节的位置
    }
    
            printf("2 tmp -> %p \n\n",&tmp);

    msg[i*OPSZ+1] = '+';// 占 一个字节 的位置
            printf("+: %p \n",&msg[i*OPSZ+1]);
    //scanf("%c", &opmsg[opnd_cnt*OPSZ+1]);


    int *tmp2;
    tmp2 = (int*)msg;
    check_num(tmp2,i);// -》 指针函数检查 对于指针 建议用 函数检查 数据正常
            printf("3 tmp -> %p \n\n",&tmp2);
    

    int get =0;
        for(int t = 0 ;get < 6 ;t++ ){// 指针 本地检查 发现会出错  主要是地址 出现 错位现象
                printf("%d get- %d---> ",t,get);
                //printf(" data-> %d char->%c  %p \n",msg[t*OPSZ],msg[t*OPSZ],&msg[t*OPSZ]);
                printf(" msg: data-> %d char->%c  %p  tmp2: %d  %p\n",msg[t*OPSZ+1],msg[t*OPSZ+1],&msg[t*OPSZ+1],tmp2[i],&tmp2[i]);
                //printf(" msg: data-> %d char->%c  %p  tmp2: %d  %p\n",msg[t*OPSZ+1],msg[t*OPSZ+1],&msg[t*OPSZ+1],tmp2[i*OPSZ+1],&tmp2[i*OPSZ+1]);
            get++;
            }
            printf("total : %d  last : 1 %c  2 %c \n",i,msg[i*OPSZ+1],msg[i]);
    
    
    int *opnd =(int *)msg;
    get =0;
    for(int t = 0 ;get < 6 ;t++ ){
        opnd ++;
                printf("%d get- %d---> ",t,get);
                printf(" data-> %d char->%c  %p \n",opnd[t],opnd[t],(&opnd[t]));
                printf("\n da-> %c ", opnd);
        //printf(" data-> %d char->%c  %p \n",opnd[t*OPSZ+1],opnd[t*OPSZ+1],&opnd[t*OPSZ+1]);
        get++;
        }


    op((int *)msg,msg ,i);// 计算操作





    char msg2[12];
    msg2[0] = (char) 100;// -127 -- 128 一个字节的表示范围 不要超过 --《 用一个字节存储数据
    msg2[1] ='c';// 字符串 转为阿斯克码 然后以二进制 的形式储存在内存中 以数字映射上来可能会出现等值的数字类型 ‘99’ 以下的是可以正确映射并参与计算
    int test;
    test = msg2[0];
    test+=1;
    printf("字符串的数字的阿斯克码 转为数字基本差不多 可以参与计算res-> %d  value:%d  %p %p \n",test,msg[0] , &msg2[0], &msg2[1]);




//---》 用char 定义初始位置 默认分配的 空间为1 给字节 用int 定义初始位置 每个位置为 4个字节 
// char* -> msg[0]   -> var a 
//          msg[0+k] -> var b  虽然间隔了4个但是还是 相邻的
//char型指针  在数组的首地址设定  a与b 在msg上是相邻的 他俩之间的距离为 k 当k=4 时将 char 数组中放入 int型的 数字

    return 0;
}

int op (int msg1[] ,char msg[],int i ){
    int res =0;
if(msg[i*OPSZ+1] == '+'){

        printf("\nadd !!!");
        for (int ttm =0 ; ttm < i; ttm++){
            printf(" %d  %p  ", msg1[ttm], &msg1[ttm]);
            res = res +  msg1[ttm];
        }
    }
    printf("\n res-> %d \n",res);

}

void check_num(int num[], int index){
    int i = 0;
    printf("num check -> total : %d \n",index);
    for(i=0; i<index; i++){
        printf("id-> %d addr-> %p Decimal-> %d char-> %c \n",i, &num[i], num[i], num[i]);
    }

}


