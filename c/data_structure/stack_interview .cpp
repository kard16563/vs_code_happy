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