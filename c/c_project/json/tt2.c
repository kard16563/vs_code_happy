#include<stdio.h>

void check_string(char *ch2){
 while  ( *ch2 )
    {
        printf("%c",*ch2);
        ch2=ch2+1;
    }
}

int main(){
    
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