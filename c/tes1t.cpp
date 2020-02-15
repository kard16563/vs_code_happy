// #include <stdio.h>
// #include <stdlib.h>


// typedef struct Link{
//     int  elem;
//     struct Link *next;
// }link;

// link * initLink();
// //链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
// link * insertElem(link * p,int elem,int add);
// //删除结点的函数，p代表操作链表，add代表删除节点的位置
// link * delElem(link * p,int add);
// //查找结点的函数，elem为目标结点的数据域的值
// int selectElem(link * p,int elem);
// //更新结点的函数，newElem为新的数据域的值
// link *amendElem(link * p,int add,int newElem);
// void display(link *p);

// int main() {
//     //初始化链表（1，2，3，4）
//     printf("初始化链表为：\n");
//     link *p=initLink();
//     display(p);
   
//     printf("在第4的位置插入元素5：\n");
//     p=insertElem(p, 5, 4);
//     display(p);
   
//     printf("删除元素3:\n");
//     p=delElem(p, 3);
//     display(p);
   
//     printf("查找元素2的位置为：\n");
//     int address=selectElem(p, 2);
//     if (address==-1) {
//         printf("没有该元素");
//     }else{
//         printf("元素2的位置为：%d\n",address);
//     }
//     printf("更改第3的位置的数据为7:\n");
//     p=amendElem(p, 3, 7);
//     display(p);
   
//     return 0;
// }

// link * initLink(){
//     link * p=(link*)malloc(sizeof(link));//创建一个头结点
//     link * temp=p;//声明一个指针指向头结点，用于遍历链表
//     //生成链表
//     for (int i=1; i<5; i++) {
//         link *a=(link*)malloc(sizeof(link));
//         a->elem=i;
//         a->next=NULL;
//         temp->next=a;
//         temp=temp->next;
//     }
//     return p;
// }


// link * insertElem(link * p,int elem,int add){
//     link * temp=p;//创建临时结点temp
//     //首先找到要插入位置的上一个结点
//     for (int i=1; i<add; i++) {
//         if (temp==NULL) {
//             printf("插入位置无效\n");
//             return p;
//         }
//         temp=temp->next;
//     }
//     //创建插入结点c
//     link * c=(link*)malloc(sizeof(link));
//     c->elem=elem;
//     //向链表中插入结点
//     c->next=temp->next;
//     temp->next=c;
//     return  p;
// }

// link * delElem(link * p,int add){
//     link * temp=p;
//     //遍历到被删除结点的上一个结点
//     for (int i=1; i<add; i++) {
//         temp=temp->next;
//     }
//     link * del=temp->next;//单独设置一个指针指向被删除结点，以防丢失
//     temp->next=temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
//     free(del);//手动释放该结点，防止内存泄漏
//     return p;
// }
// int selectElem(link * p,int elem){
//     link * t=p;
//     int i=1;
//     while (t->next) {
//         t=t->next;
//         if (t->elem==elem) {
//             return i;
//         }
//         i++;
//     }
//     return -1;
// }
// link *amendElem(link * p,int add,int newElem){
//     link * temp=p;
//     temp=temp->next;//tamp指向首元结点
//     //temp指向被删除结点
//     for (int i=1; i<add; i++) {
//         temp=temp->next;
//     }
//     temp->elem=newElem;
//     return p;
// }
// void display(link *p){
//     link* temp=p;//将temp指针重新指向头结点
//     //只要temp指针指向的结点的next不是Null，就执行输出语句。
//     while (temp->next) {
//         temp=temp->next;
//         printf("%d",temp->elem);
//     }
//     printf("\n");
// }

#include<stdio.h>
#include<stdlib.h>


//num  conversion 


typedef struct stack_conversion
{
    int data;
    struct stack_conversion *st_nod;

}stack,*st_nod;

void init_stack(st_nod nod){
    nod->data=-1;
}

void push_stack(st_nod nod,int value ){

    
        int flag=0;// is the first or is go to the new            
        if (nod->data == -1){
            // first
            flag=-1;// is the first
            printf(" 1 add adta  %d \n\n",value);
            nod->data=value;
            nod->st_nod=(st_nod)malloc(sizeof(stack));
            nod->st_nod->data=-1;
        }
        if(flag==0){

            while (nod->data != -1)// has value  and not the first
            {
                printf("tt %d \n",nod->data);
                nod=nod->st_nod;
                
                flag=1;// go to the next is ok
            }
        }
        if (flag==1){
            printf(" 2 add adta  %d \n\n",value);
            nod->data=value;
            nod->st_nod=(st_nod)malloc(sizeof(stack));
            nod->st_nod->data = -1;
        }
        

    
    
}

int serch (st_nod nod){

    //printf("the answer is ___>>> :");
    while (nod->st_nod->data != -1)
        {
            // printf("5555");
            // printf("\n pop_stack --**  %d   ",nod->data);
            nod=nod->st_nod;
        }
        printf("\n end pop_stack --**  %d   ",nod->data);
        //printf("the answer is ___>>> :");
        int tt= nod->data;
        nod->data=-1;
        return tt;


        //return nod;

}

void pop_stack(st_nod nod,int times){
    int  n=0;

    //  while(nod->data != NULL){
    //     printf("\n check data -- %d\n",nod->data);
    //     nod=nod->st_nod;
    // }

    // printf("\n test data -- %d\n",nod->st_nod->data);
    printf("\n\n    times-->  %d",times);
    printf("\n the answer is __  ");
    while (times)
    {
        //printf(" 5555+");
        printf("%d",serch(nod));
        
        
        //nod->data=-1;
        
        times=times-1;
    }
    


    for (int i=0;i<times;i=i+1){
        int t=times-i-1;
            for(int ii=0;ii<t ;ii=ii+1){
                nod= nod->st_nod;
            }
            printf("  %d -- ",nod->data);
    }

    // while (nod->st_nod->data != -1)
    // {
    //     //n=n+1;
    //    // printf("_-__s %d \n",nod->data);
    //     nod= nod->st_nod;
    //    // printf("_-__s %d \n",nod->data);
    // }
    // n=n+1;
    // printf(" \n end  pop  %d -- index %d",nod->data,n);
    

}



void in_put(st_nod nod,int value , int *times ){
    
    while(value) {
                *times=*times+1;
                printf("\n\n--> while  %d \n",value%2);
                push_stack( nod,value%2);
                value=value/2;
            }



}

int main (){
    stack ss;

    int value;
    int times=0;

    printf("Binary conversion -->  \n\n ");
    printf("   input your value-->  ");
    scanf("%d",&value);
    printf("\n your value === > %d",value);
    
    init_stack(&ss);
    in_put(&ss,value,&times);
    printf("times %d",times);
    pop_stack(&ss,times);

    printf("\n\n\n end");
  

    
    
    getchar();
    getchar();
    return 0;
}