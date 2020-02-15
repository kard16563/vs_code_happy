#include <stdio.h>
#include <stdlib.h>



typedef struct link_tab
{
    int  data;
    //int  len;
    struct link_tab *next;
    
};


link_tab initialize(link_tab &nod,int guard=100){
    nod.data=guard;
    nod.next=NULL;
    return nod;
}

link_tab creat_link_tab( link_tab nod){
    int num ,data,i;
    i=0;
    link_tab *temp;
    link_tab *end;
    temp=&nod;
    scanf("%d",&num);
    printf("----> %d\n",num);
    for ( i=0; i<num;i=i+1){
        
        scanf("%d",&data);
        printf("=====> %d\n",data);
        link_tab  *tem=(link_tab*)malloc(sizeof(link_tab));
        tem->data=data;
        tem->next=NULL;
        temp->next=tem;
        temp=temp->next;
    
        printf(" 1- >>  %d ---- %d---- %d *** %d\n ",temp->data,temp->next,tem->data,tem->next);
        }


    printf("   creat is over\n");
    return nod;

}

void check(link_tab nod ){
    printf("\n\n------->begin check\n  ");
    link_tab *nod_1=&nod;
    int i=0;
    while (nod_1)
    {
        printf(" _ %d ---\n",nod_1->data);
        nod_1=nod_1->next;
        i=i+1;

    }

    printf("total--》%d \n",i);
    printf("----->check is over\n");
}

link_tab insert_value(int position ,int value ,link_tab nod,int flag=0){
    position=2;//2
    flag=0;//

    printf("---------->insert %d  state-> %d\n",position-1,flag);
    position=position-2;
    printf("---------->insert-fromer %d \n",position);
    link_tab *nod1;//former
    
    nod1=&nod;
      printf("11========++++%d %d %d\n",nod1->data,nod1->next,nod1->next->data);

    if (position && flag==0){
    printf("inner\n");
    for (int i=0;i!=position;i=i+1){   //find  former
        printf("----**> %d \n",nod1->data);
        nod1=nod1->next;
    }

    printf("target-> data  %d",nod1->data);
    }

    if (flag==1){  //insert in below
    while (nod1->next)
    {
        printf(" _ %d ---\n",nod1->data);
        nod1=nod1->next; }
        printf("333========++++ %d \n",nod1->data);
        link_tab *below=(link_tab*)malloc(sizeof(link_tab));
        below->data=value;
        below->next=NULL;
        nod1->next=below;
        return nod;
    
    }

    
    
    link_tab *new_node=(link_tab*)malloc( sizeof(link_tab));
    new_node->data = value;
    new_node->next = nod1->next;
    nod1->next=new_node;
    printf("22========++++%d %d %d\n",nod1->data,nod1->next,nod1->next->data);
    
    return nod;
    
    }

link_tab del_tab(link_tab nod,int position=3,int flag=0 ){
printf("del position _> %d---->former %d\n",position,position-1);
link_tab *former = &nod;
position=position-1;
for (int i=0;i<position;i=i+1){
    printf("---->%d\n",former->data);
    former=former->next;
    }
//former->next=former->next->next;
//link_tab *dell=former->next;//
//free(dell);

link_tab *dell=former->next;//
former->next=dell->next;

free(dell);
printf(" %d  ",former->next);
former=NULL;

return nod;

/*
link_tab *dell=former->next;//
former->next=dell->next;

free(dell);
printf(" %d  ",former->next);
former=NULL*/

}


int main (){
    link_tab nod,head;

    head=initialize(nod,100);
    nod=creat_link_tab(nod);
    check(nod);
    link_tab pp=insert_value(2,666,nod);
    //insert_value(2,5,nod);
    //check(head);

    check(pp);
    pp=del_tab(pp);
    check(pp);

    getchar();
    getchar();


    return 1;
}