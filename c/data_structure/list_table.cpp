#include <stdio.h>
#include<stdlib.h>


#define true1 1
#define false1 0
#define ok   1
#define error 0
#define infeasible -1
#define overflow -2


#define list_init_size 100//分配
#define listincrement 10//增加

typedef int status;//新定义

typedef struct {
int *elem;//数组地址
int length;//长度
int listsize;//大小
}sqlist;


status inilist_sq(sqlist &l){
//初始化
l.elem=(int*)malloc(list_init_size*sizeof(int));//开辟空间
if (!l.elem) exit(overflow);
l.length=10;
l.listsize=list_init_size;//赋值

printf("initialize-----\n\n");
return 1;

}




status listinsert_sq(sqlist &l,int i,int e){
//插入
printf("\n\n 插入\n");
printf("insert---- value : %d, set:%d \n\n\n",e,i);
int *newbase;
if (i<1||i>l.length+1)return error;//位置非法

if (l.length>=l.listsize){//空间已满
printf(" application,for the room is busy");
// p.elem=(int*)malloc(list_init_size*sizeof(int));
newbase=(int*)realloc(l.elem,(l.listsize+listincrement)*sizeof(int));//重申空间

if(!newbase)exit(overflow);//申请失败
l.elem=newbase;//地址迁移
l.listsize=l.listsize+listincrement;//改参数

}
printf("ok  the room is leisure----\n");

  
int *q=&(l.elem[i-1]);
for (int *p=&(l.elem[l.length-1]);p>=q;--p)*(p+1)=*p;//后移

*q=e;
++l.length;//长度修改
return 1;

}


int listdelet_sq(sqlist &l,int i,int e){
//删除
printf("删除\n\n\n");
printf(" set: %d ,value: %d \n",i,e);

if ((i<1)||(i>l.length)) return error;// 位置非法
int *p=&(l.elem[i-1]);
e=*p;
int *q=l.elem+l.length-1;// 尾表元素位置
for(++p;p<=q;++p) *(p-1)=*p;// 前移
--l.length;//参数修改

return 1;
}




int check(sqlist &l){

int i=0;
 for (i=0;i<l.length;i=i+1){
 
printf("%d ---i== %d\n ",l.elem[i],i);
}


printf("======check is over =====\n\n");


return 1;


}


int main (){

sqlist pp;
inilist_sq(pp);
check(pp);
listinsert_sq(pp,2,2);
check(pp);
listdelet_sq(pp,3,3);
check(pp);

getchar();
getchar();



return 1;

}
