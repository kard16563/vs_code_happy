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
    while (ch != EOF)
    {
        putchar(ch);
        ch=fgetc(fp);
    }
        fclose(fp);



    getchar();
    getchar();
    return 0;
}