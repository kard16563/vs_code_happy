//c++
#include <stdio.h>
#include <string.h>

// using namespace std;
// #include <iostream>  这样导入

typedef struct 
{
    int i;//c
}a_1 ;

struct a_2
{
    int i;//C++  上下一样都表示新类型 
};

void swap(int *a,int *b){//传入ab 的指针
    int tem;
    tem=*a;
    *a=*b;
    *b=tem;//c
}


void swap_1(int &a,int &b){//c++   感觉传入的是地址

    
    int tem;
    printf("\n --- >swap a %p  b  %p  tem %p",&a,&b,&tem);

    tem=a;
    a=b;
    b=tem;
    printf("\n --- >swap a %p  b  %p  tem %p",&a,&b,&tem);
    //swap_1(i,j)调用
}



void fun (int n=1){
    printf( " \n \n  C++ 可以默认参数 %d",n);
}

class tt
{
private:
    /* data */
public:
    int a1;
    int a2;
};





class fun__1//数据一般为私有 函数来公开
{
private:
    int fun_1_a;
    void diao(){//可以定义在 类里面像这样
        printf("\n\n 初始化 diaoyongl \n\n");
    };
public:
    fun__1(int num = 0){//构造函数没有返回类型 且放在 public之中默认为0
        fun_1_a=num;
        diao();
    }
    //printf("ss");
    fun__1 mul(fun__1 f);

    void create(int num){
        fun_1_a=num;
        printf("\n   class- >  fun -> 放入私有变量");
    }

    void fun_print();


};

fun__1 fun__1::mul(fun__1 f1){
    fun__1 result(0) ;//新变量
    result.fun_1_a=f1.fun_1_a+100;
    printf("\n\n  --- 进行加 +100 操作 ----");
    return result;//将新变量复制到新变量中
}

void fun__1::fun_print(){//必须要加类名的前缀 fun__1:: --》 表示 fun_print 为该类的成员函数 成员函数会访问该类的所有成员 包括公有和私有
    printf("\n   class- >  fun -> 读取私有变量  -》 %d  ",fun_1_a);
}

class string
{
    private:
        char *text;
        int len;
    public:
        string(char *c,int shu):len(shu),text(c){} //构造函数也可以重载
        string(){text="无参数调用 ";len=20;};
        string(const char *s);//constructor 构造函数
        //printf(" %c  --  len -> %d", text,len);
       // ~string(){delete [] text;}//如果在函数中 有string s1 ("123")
                                //函数释放 仅仅释放了 text 与len的成员内存 但text所指的内存没有释放--》内存泄漏
                                //用析构函数 来回收 text 所指向所有的空间 119
        void print_str();
    
};
void string::print_str(){
        printf("\n\n char --- %c  --  len -> %d  \n\n", *text,len);
        printf("\n char-->");
        char *tt;
        tt=text;
        while (*tt != NULL)
        {
            printf("%c",*tt);
            tt=tt+1;
        }
        

}
string ::string( const char *s ){
    len=strlen(s);
    text=new char[len+1];//用new来动态分配空间 像malloc一样
    printf("\n\n char 分配空间--> %p ",text);
    strcpy(text,s);

}

void over_load_1 (int i){
    printf(" \n 重载 -》可以有同样的函数名 但 他所要的参数不同就可以 --》%d ",i);
}

void over_load_1 (double i){
    printf(" \n 重载 -》可以有同样的函数名 但 他所要的参数不同就可以 --》%lf ",i);
}


class shape  //基类   //继承 --派生
{
    private:
        int x;
        int y;
    public:
       // shape(int in_x,int in_y);
        void print_shape();
        void set(int in_x,int in_y);
         int *pp(int i,char *flag);
};
int *shape::pp(int i,char *flag){
        static int *tt=new int;
        printf("\n ---->> %p \n",tt);

        switch (i)
        {
        case 1:
        //    static int *m;
            // *tt=(int)(this->x);//这样指针可以传出去--》传到203行--->传的是内容-->ok
             //tt=(int*)(this->x);//这样指针传不出去---》地址就没了---->传的是地址->一结束就收回了
            this;
            this->x;
            


            printf("\n\n  地址验证 ---> this->: %p  this->x: %p == x的值 %d y的地址%p == y的值%d---->this->y==this指针访问成员变量y的值  \
            ",this,this->x,this->x,this->y,this->y);

            if (flag =="write" )
            {
                printf(" \n write");
                tt=&(this->x);//指向x的地址----->后面可以读取好直接修改x的值
                //tt=this;--->回来试一下

            }else if(flag =="read")
            {
                printf(" \n wrong--->");
                *tt=(int)(this->x);//保存x的值-->后面可以读取
            }
            
            
            
               // printf(" \n\n mmm-> %p \n",tt);
            //tt=(int*)(this->x);
            return tt;
            break;
        case 2:
            *tt=(int)(this->y);
            return tt;
            break;
        
        default:
            printf("输入有误");
            break;
        }

}


void shape ::set(int in_x,int in_y){
    x=in_x;
    y=in_y;
}

void shape::print_shape(){
    printf(" method of  shape --> prentf x->%d y->%d ",x,y);
}

class circle : public shape{
    private:
        int plus;
    public:
        int aa=10; 
        circle(){plus=0;};
        void add();
        void print_cir();
};

void circle::print_cir(){
    printf("void circle::print_cir() -> %d",plus);
}

void circle::add(){
   // int*tt_11= (this->pp(1));//---->ok

   int*tt_11;
   tt_11=(this->pp(1,"write"));

    printf("\n  --x的地址上访问--> %d---y的地址上访问->%d",*tt_11,*(tt_11+1));//从debug x y排列 看来为连续的

    *tt_11=*tt_11+1;


    // tt=(int*)(this->pp(1));
   // printf("%d", *(this->pp(1)) );
    printf("123");

    // printf("\n\n   circle::add--> %d  ",*tt);
}


int main(){

    fun();
    fun(66);

    int a=1,b=2;
    swap_1(a,b);

    int *int_ptr,*int_array;
    int_ptr=new int ;//分配空间
   // printf("\n int_ptr---> value->  %d addr-> %p \n ",*int_ptr,int_ptr);
   // int_array=new int[10];//分配空间

    tt ta1,ta2;
    ta1.a1=11;

    fun__1 funa1(12),funa2(12);//应用构造函数来初始化  --》funa1
    funa1.create(12);
    funa1.fun_print();

    funa2=funa1.mul(funa1);//funal的值会加一百 然后放到  funa2 中的 fun_1_a中
    funa2.fun_print();//112
    funa1.fun_print();//12

    string str1("123");
    str1.print_str();

    over_load_1(12);//重载仅仅传入参数不同 可以同名
    over_load_1(5.555);

    string str_over12("WSSS",20);//str_over.类的初始化可以重写
    str_over12.print_str();

    string str_over1("ni hao wo shi ");
    str_over1.print_str();

    string s;//可以调用但析构函数无法 起作用 报错
    s.print_str();
    //cout <<"4545"; //导入
    printf("hello123");

    circle ci_1;
    ci_1.set(12,23);
    ci_1.add();

    


    getchar();
    getchar();

    return 0;
}

// void create(int num){
//         printf("class- >  fun -> %d",num);
//     }