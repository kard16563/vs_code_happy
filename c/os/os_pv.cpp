# include <stdio.h>
# include <stdlib.h>
# include<windows.h>

int buff[10]={0};
int full=0;


void v(int *full){
    *full=*full-1;
}
void p(int *full){
    *full=*full+1;
}

void producer(int *full,int i ){
    if (*full == 0){        
        int a = rand();
        printf("\n 写操作： 该操作次数： %d  写入值%d  并执行 p 操作",i,a);
        buff[i]=a;
        p(full);
    }
}

void  consumer(int *full,int i){
    if (*full == 1){
        //printf("\n read \n");        
        printf ("\n 读操作 读取 %d 并执行v操作\n",buff[i]);
        v(full);
    }
}

void go(){
    int times;
    printf("执行次数-->  ");
    scanf("%d",&times);

    for(int i=0;i<times;i=i+1){
        int j=i;
        j=j%10;
        printf("\n 执行第 %d 次 ",j);
        producer(&full,j);
        consumer(&full,j);
    }

}


int main (){
    go();
    printf("\n__ end __\n");
    getchar();
    getchar();
    return 1;

}