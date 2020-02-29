//输入and输出
#include<stdio.h>
//流  是指输入源 键盘..或者任意的输出地址 屏幕...

int main(){
    FILE *fp1,*fp2;//文件指针
    
    //stdin为标准流入 默认为键盘 scanf之类的用它来实现的
    //stdout为标准流出 默认为屏幕 printf用它写的
    //stdin ;

    fp1=fopen("E:\\the_c_of_vs_code\\c\\c_study\\s_Large-scale program\\a1\\test.txt","r");
    if (fp1 == NULL){//判定
        printf("no");
    }

    // while ( *fp1 != NULL) 不能这样读
    // {
    //     fp1=fp1+1;
    // }
    //printf("___ %s ___ \n",*(fp1+1));

    fclose(fp1);//关上文件

    FILE *fp;
    char ch;
        if((fp=fopen("E:\\the_c_of_vs_code\\c\\c_study\\s_Large-scale program\\a1\\test.txt","rt"))==NULL)
{
    printf("Cannot open file strike any key exit!");
    getchar();

}
        ch=fgetc(fp);
    while (ch != EOF)//eof文件末尾
    {
        putchar(ch);//向显示器中写入一个字符 ==显示
        ch=fgetc(fp);//从文件中读取一个字符
    }
        fclose(fp);

        // FILE *tempptr;//创立临时文件
        // tempptr=tmpfile();
        FILE *stream=fopen("E:\\the_c_of_vs_code\\c\\c_study\\s_Large-scale program\\a1\\test.txt","a+");

        char buffer [10];
        //setvbuf(stream,buffer,_IOFBF,10);//文件流 缓冲区 缓冲区的类型 缓冲字节数

        //fprintf(stream,"\n writed %d by fprintf \0",100);//写入文件中
        //printf("\n  p-> %p  \n ",stream);
       

        fclose(stream);

        FILE *stream2=fopen("E:\\the_c_of_vs_code\\c\\c_study\\s_Large-scale program\\a1\\test.txt","rt");
        if ( ferror(stream2) ){
            printf(" \n 文件坏了 \n");
        }else
        {
            printf("文件正常");
        }
        if( feof(stream2) ){
            printf("\n 指针指到最后了 \n");
        }

        char a,b;
       int n=fscanf(stream2,"%c%c",&a,&b);
        printf(" %c %c 是否读取成功 -》 %d >0 ",a,b,n);//将文件中的数据读到变量中

        fclose(stream2);

 FILE *stream3=fopen("E:\\the_c_of_vs_code\\c\\c_study\\s_Large-scale program\\a1\\test.txt","rt");
    char str[60];
    char *aa_1=fgets(str,sizeof(char)*30,stream3);
    printf("\n\n\n\n 行输出 -》\n");
    while (aa_1 != NULL)
    {   printf("\n 行输出 英文的还可以中文的有问题 ");
        puts(str);
        aa_1=fgets(str,sizeof(char)*30,stream3);//aa_1 为下一行的数值量
        //printf("char *  %s",aa_1);

    }
     char str2[10];
     sprintf(str2,"%d/%d/%d",9,5,20);//格式化写入数组 并自己补上空符
     printf("\n  %s ",str2);//
    //sscanf(str,"%d%d",&i,&k);从str中读数赋值一次性操作很ok

        printf("\n 完了");//写入屏幕上




    getchar();
    getchar();
    return 0;
}