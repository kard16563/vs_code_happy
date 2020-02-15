# include <stdio.h>
# include <stdlib.h>

// first-fit algorithms 
typedef struct space {

    int data;
    int state;
    int len;
    space *next;
    space *prior;


} space , *space_prt;

void insert(space_prt pp ){
    int num=0;

    printf("please give the total of your space ---> ");
    scanf("%d",&num);
    printf(" \n system capture the value-> %d \n",num);

    for (int i=0;i<num ;i=i+1 ){
    int temp = 0;
    printf("\n space -> ");
    scanf("%d",&temp);
    printf("  == system capture value=> %d \n",temp);
    printf("----> batch %d \n",i);

    if (i==0){
            pp->data=temp;
            printf("first -- %d \n",pp->data);
        }else
        {
            space_prt s=(space_prt)malloc(sizeof(space));
            s->data=temp;
            printf(" s->  %d\n",s->data);
            s->prior=pp;
            pp->next=s;
            pp=pp->next;
        }
     }
     printf("====== input is end ======>\n");
}

void swap(space_prt pp ,int times ){//from small to big
    for (int i=0;i<times ;i=i+1 ){
        space_prt pir= pp ;
        space_prt lat=pp->next;
        if ((pir->data)>(lat->data)){
            lat->prior=pir->prior; // change prior
            pir->prior=lat;

            pir->next=lat->next;// change next
            lat->next=pir;



        }
        pp=pp->next;//move the loop  



    }


}

void check(space_prt pp){
    printf("===== check ====\n");
    for (int i =0 ;pp; i=i+1)
    {   
        printf(" -batch- %d --value-- %d \n ",i,pp->data );
        //printf(" -- %d",i);
        pp=pp->next;
    }
    





}




int main (){
printf(" \n\n------ first-fit algorithms ------ \n\n   ");

space pp;
insert(&pp);
check(&pp);
printf("\n\n\n hello ");
getchar();
getchar();


return 1;
}