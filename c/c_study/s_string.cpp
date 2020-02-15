# include<stdio.h>


int main(){
    char *p;
    p="abc \n";//p仅仅拿到了a的地址
    printf(p);

    printf("\n ---> 检查结果%c",*p);
    
    char date[] = "june 14";//正常的初始化 这里的=不是赋值 是初始化

    // char da;//错误的初始化
    // da="5555";
    //c语言认为是一个指针与另一个指针的非法赋值

    char *date1 = "june 14";


    getchar();
    getchar();

    return 0;
}