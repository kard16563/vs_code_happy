#include<stdio.h>

    struct  
    {
        int num;
        char name[20];
        int on_hand;
    } part1,part2={914,"初始化",5};//声明结构变量


    struct 
    {
        int a [3];
    }a1,a2={0,1,2}; //数组传值
    
struct parts  // 结构标记 用于 标识某种特定结构类型的名字  可以用它来声明变量  
    {
        int nums;
        char names[20];
        int on_hands;
    } parta,*part_p;//part 型的变量 parta



struct person_name
{
    int age;
    int person_id;
    int grade;
};//结构中所有成员都有独自的储存空间且连续

struct student
{
    struct person_name  p_n;//嵌套上面的呢一个  上面结构体的参数可以一次性传递
    int school_id;
}stu1,stu2;


union //联合 
{
    int i;
    float f;//u 可以理解为储存f/u的地方 不能同时储存
}u ;//该成员全部都在同一个地址上

union //联合 
{
    int i;
    float f;
}u1={0};//初始化为0

struct test//定义变量名
{
    int a;
    union 
    {
        int b;
        int c;
    } uu;
    struct 
    {
        int d;
        int e;
    }st;
    
};


typedef struct 
{
    int a;
    union 
    {
        int b;
        int c;
    } uu;
    struct 
    {
        int d;
        int e;
    }st;
    
}test,*tt;//这样更方便 定义变量名 和指针


typedef enum{happy,sad} em;// happy,sad 可以赋值给 em型的变量 就这2个其他的无法赋值

typedef enum{happys=1,sads=2,hh=3} emh;// happy=1 happy可以当用

void print_part(struct parts p){
    p.nums=555;
    printf("\n ----%c ",p.nums);
}

int main (){

    parts a;

    printf("op in struct ---> %d \n ",part2.num);

    part2.num=222;
    printf("change the value %d \n input the value -> \n",part2.num);

    scanf("%d",&part2.num);
    getchar();
    printf("\n\n");
    printf("get the value %d ",part2.num);

    part1 = part2 ;//结构体间可以这样赋值
    printf("the value -> part1 %s ---  %s \n",part1.name,part2.name);

    a1=a2;//数组间的赋值
    printf("\n a1--> %d, %d ,%d",a1.a[0],a1.a[1],a1.a[2]);

    /////////////////
    parts p;
    print_part(p);

    part_p=&p;//指针指向

    stu1.p_n.age=11;
    stu1.school_id=22;
    student pp[100];//数组的形式组织 结构体


    u.i=82;
    u.f=14.55;//i值以覆盖

    test aaa;//综合应用
    aaa.uu.b=1;

    em a =happy; //应用
    emh bb=happys;
    // bb=bb+1;





    getchar();
    getchar();
    getchar();
    getchar();

    return 1;
}