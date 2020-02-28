#include<stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){


        int **p2;
        int *p1=new int;
        *p1=111;

        p2=&p1;
        *(*(p2)+1)=222;//p1的下一个位置定为2

        printf("访问一级指针所指 p1__ %d p2__%d p3 no-%d ", *(*(p2)),*(*(p2)+1), *(*(p2)+2)  );





printf("\n\n\n\n\n\n\n");
      const  char *yy="1000\0";
      const  char *yya="6\0";//字符串乱码------》
        //yya=(char *)malloc(sizeof(char)*10);
        //*yya="11111";

    const char **argv1;
     //argc = 5;
    const char*** tt1, ** tt2,**tt3,**tt4,**tt0; //方法ok

     argv1=&yy;
     tt1=(&argv1)+1;

     *( (&argv1)+1)=&yya;
     int add=&argv1[1]-&argv1[0];
//argv1[1],*(*(&argv1+2)),add  %s %s  add %d\n
     printf(" \n\n *(argv1[0]) ---> %s -->%s ,%s ",argv1[0],argv1[1],*(*(&argv1+1)) );
     printf("\n");

    //   char*tt1_1="E:\\yolo\\yolo-windows-master\\build\\darknet\\x64\\darknet_no_gpu.exe";
    //     tt0 = &argv1[0];
    //     *argv1[0]=*tt1_1;
       // *tt0 =  tt1_1;
     
     //tt1=&argv1[1];
    //*tt1="detect";

    //  tt2=&argv1[2];
    //  *tt2="cfg/yolov3-tiny.cfg";
    //  tt3= &argv1[3];
    //  *tt3 = "yolov3-tiny.weights";
    //  tt4= &argv1[4];
    //  *tt4 = NULL;

    //  char* s = *tt0;
    //  char *temp="aa";
    //  s[0] = *temp;




    printf("argc 是命令行 参数的数量 包括程序本身  -》%d \
    argv是指向命令行参数的指针 以字符串形式存储 \n \
     argv[0]指向程序名argv[1] 到argv[argc-1] 都是指令 argv[argc]为空指针\n ",argc);

    int i;
    for (i=0;i<argc;i=i+1){//读取指令
        printf(" %s \n ",argv[i]);
    }

    printf("\n 另外一种方法 \n");
     char **p;

    //const *argv[] ;
    //const *argv[2]="qqqqqqq";
     char **t;
     t=argv;
     const char *tt ="*****";
     *(t+1)="1000000";//这个有点可疑
     *(t+2)=NULL;


    *(*(t)+1)=*tt;
     //(*(t)+1)=tt;

    // char **tt2,**tt3; //方法ok
    // tt2=&argv[1];
    // *tt2="5555";
    // tt3=&argv[2];
    // *tt3=NULL;

    for(p=&argv[0]; *p!=NULL;p=p+1){
        printf("——————%s \n",*p);
    }

    printf("\n  end...");
   getchar();
    return 1;

}