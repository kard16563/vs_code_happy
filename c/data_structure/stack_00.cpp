# include<stdio.h>
# include<stdlib.h>
# include<memory.h>

#define element_type  int
#define max_size 10

typedef struct{
    element_type data[max_size];
    int top=0;
}stack,*stack_node;


void input_stack( stack_node nod,element_type times ){
        printf(" input to stack  \n");
        if ( ((nod->top)+times) >= max_size ){
            printf("sorry stack is full now ..we apply for that \n ");
            nod =  (stack_node)realloc(nod,5*sizeof(element_type));
            printf("ok the application is satisfied..  \n");
        }

        for (int time=0;time<times;time=time+1){

            printf("please input you value fitted in stack ---> ");
            int value=0;
            scanf("%d",&value);
            printf("system capture the value %d \n",value);

            if (nod->top < max_size){//input__>> 
            printf("adding....\n");
            nod->data[(nod->top)] = value;
            nod->top=nod->top+1;//point to the last position +1
            }
            printf("  == op is end == value - %d \n",value);

        }
        nod->top=nod->top-1;//point to the last position as the number in this stack
        
        printf("  ====== input is end ==========> \n\n");
    }

void check_stack (stack_node nod){
        printf("------  checking  -------\n");
        int temp=0;
        printf("cheack!!  ___>  %d \n",nod->top);
        for (int i=(nod->top);i>=0;i=i-1 ){
            temp=nod->data[i];
            printf("value->  %d  i - %d \n",temp,i);
        }

        printf("============== check is end ======\n\n");
    }

void pop_stack(stack_node nod){
    printf("please input the value that you want to pop --->");
    int times=0;
    scanf("%d",&times);
    printf("capture value -- %d \n",times);
    
    if (times>(nod->top)){
        printf("  \nerror!!");
        exit(0);
    }else{
        printf(" pass the checking!! \n");
    }

    for(int i = (nod->top) ;i>=( (nod->top)-times ) ; i=i-1){
        printf("pop the value %d  -- i %d \n \n,",nod->data[i],i);

    }
    nod->top= nod->top - times;
    printf("==========  new top   =========  %d \n",nod->top );
    printf("   =================  pop end  =======>\n\n\n");



    }


int main(){
    stack pp;
    //addressof();
    //memcpy(&pp);
    
    
    
    input_stack(&pp,5);
    check_stack(&pp);
    pop_stack(&pp);

    printf("  ------- check again -------\n\n");

    check_stack(&pp);
    printf("ok\n\n\n");
    getchar();
    getchar();

   return 0; 
}
