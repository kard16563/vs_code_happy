# include <stdio.h>
# include <stdlib.h>
# include<windows.h>

typedef struct que {
int data[11][2];
int front;
int last;
int len;


} qu , *que_prt;


void init_que( que_prt que ){
//printf("1 -------> %d --- %d ------ %d\n\n",que->front,que->last,&que->data[0]);
que->last=0;
que->front=0;
que->len=0;
//printf("2  -------> %d --- %d ------ %d\n",que->front,que->last,&que->data[0]);

//int value =55;
//*(que.front)=value;
 
//que.data[0]=11;
//que.data[1]=22;
//printf(" ---> %d\n", *(que.front));// the first
//printf(" ---> %d\n", *(que.front+1));// the second
//return que;

}


void input (que_prt que,int times){

//printf(" %d  times\n",times);
//printf("3  -------> %d --- %d -\n",que->front,que->last);
que->len=times;

int value=0;
int tim=1;
for (int i = 0 ; i< times ; i=i+1){
printf("\n 输入 第%d个进程名 > ",i);
scanf("%d",&value);
//printf("\n进程名 ---> _%d_ \n",value);
//printf("....%d \n",que->last);

printf("\n 输入该进程(%d)的执行时间单位为秒--> ",value);
scanf("%d",&tim);


//if(que.front == que.last){
//    *que.front=value;
//    que.last=que.last+1;
 
//    }
//else{
que->data[que->last][0] = value;
que->data[que->last][1] =tim;
//printf("  \n  _%d _---> _%d_ \n",que->last,que->last);

que->last=que->last+1;
//printf(" ....%d \n",que->last);
 
//    }
 
}
que->last=que->last-1; // point to  the end
//return que;
}

void cheack(qu que,int tt ){
printf("__check____>>>\n\n\n");
tt=que.len;
for (int i=0;i<tt; i=i+1){
    int tim=que.data[i][1];
    tim=tim * 1000;
    Sleep(tim);
printf("进程代号 %d 该进程耗时 %d 秒-- 第%d个-- 系统地址-- %p\n",\
que.data[i][0],que.data[i][1],i,&que.data[i]);
}

//printf("\n 3  pr_position -------> %d --- %d -\n",que.front,que.last);

}


void delque(que_prt que,int num){
printf("\n\n ======  delque ===== %d \n\n   ",que->len);


if (que->len < num){
printf(" sorry the num is wrong .max -- %d  capture --  %d",que->len,num);
exit(0); 
}else{ 
printf(" check is over !!\n"); 
}
int tt = que->len;
for (int i=0;i<tt-1; i=i+1){
printf(" value %d -- position %d-- address-- %d\n",que->data[que->front][0],i,&que->data[i]);
que->front = que->front+1;
printf("\n que-> front %d",que->front);

}
que->front=que->front - 1;//point to the first
printf("\n ==== que->front %d  late %d",que->front,que->last);


}






int main (){
qu que;
init_que(&que);
int times;
printf(" 请输入 要执行的进程数（先来先服务）-->  ");
scanf("%d",&times);

input(&que,times);
cheack(que,times );

//delque(&que,2);
//cheack(que,4 );

printf("\n\n\n end ");
getchar();
getchar();


return 1;
}