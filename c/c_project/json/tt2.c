#include<stdio.h>


typedef struct  t_value
{
    char *s;//用于是字符串处理
    int len;//size_t 没有
    double n;//用于数字的表达

    //t_type type; 

    struct t_value* array_e;//数组的内容
    int array_size;//size 是元素的个数

}; // pt_value 事实上是一种变体类型（variant type），

void check_string(char *ch2){
 while  ( *ch2 )
    {
        printf("%c",*ch2);
        ch2=ch2+1;
    }
}

int main(){
    // t_value a;
    // t_value b;

    // b.array_e=&b;
    
    char ch='\\';
    printf("------ > %p   %d \n\n\n",(unsigned char)ch,((unsigned char)ch -0x20 ) );
    char *ch2 = "22\"Hello\\nWorld\"";
    check_string(ch2);

     char *ch3= "a123456789";
    char *ch4;
    ch4 = &(*ch3);
    char cc= *ch3;

        for(int i=0; i<=8; i=i+1){
            
            //*ch3++;
             char cc= *ch3++;
            switch (cc)
            {
            case 'a' :
            printf("\n\n  aa-1 ---》b -> %c ch3 -> %c  \n\n",cc,ch3);
            //cc=cc+1;
                switch (*ch3++)
                {
                    case 'c':
                    printf("\n\n  aa-2 ---》c-> %c ch3 -> %c  \n\n",cc,*ch3);
                    break;
                
                default:
                printf("\n\n  aa-3 ---》default-> %c ch3 -> %c  \n\n",cc,ch3);
                if (*ch3++)
                {
                    printf("\n if ch3    %c",ch3);
                }
                
                check_string(ch4);
                    break;
                }
                

                break;
            case '\0'://有bug 上面的 ' a '选中之后这边还是会被选中   尽量不要出现0  
                    printf("\n------------------>\n");

                    break;
            case '2'://  
                    printf("\n----+++++++++++---->\n");

                    break;

            
            default:
                printf("\n\n  default---》cc-> %c ch3 -> %c  \n\n",cc,ch3);
                break;
            }
        }

    

    //printf("%s",*ch2);
    getchar();

    return 0;
}