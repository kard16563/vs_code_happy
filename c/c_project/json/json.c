#ifdef _WINDOWS  // 内存泄漏检测
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif//在两个 .c 文件首行插入这一段代码  
//并在 main() 开始位置插入
//int main() {
//#ifdef _WINDOWS
//    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//#endif


#include "json.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include <errno.h>   /* errno, ERANGE */
#include <math.h>    /* HUGE_VAL */

#include <string.h>  /* memcpy() */

#ifndef T_PARSE_STACK_INIT_SIZE // stack
    #define T_PARSE_STACK_INIT_SIZE 256// stack 256
#endif


#ifndef T_PARSE_STRINGIFY_INIT_SIZE
#define T_PARSE_STRINGIFY_INIT_SIZE 256 //字符串化（stringify） 
#endif


#define expect(c,ch) do { assert(*c->json == (ch));c->json++; } while(0)

#define PUTS(c, s, len)     memcpy(t_contex_push(c, len), s, len) //将s的len 打入c的stack中

typedef struct{
    
    char* stack ; //引入堆栈 用作缓冲区
    int top,size ;// 堆栈的东西
    const char *json;

}t_context;

static void t_parse_ws(t_context *c){// parse_whitespace 解析空格
    const char *p = c->json;//测试第一个字符n
    while (*p==' ' || *p=='\t' ||*p=='\n'||*p=='\r' )
    {
        p++;//看看如果是字符串 就继续向后进行拨动字符串 直到不是为止
        printf("json.c 35 t_parse_ws 检测到空格正在进行过滤 -  ");
    }
    //printf("\njson.c 35 检测空格结束 为空格的位置 t_parse_ws_>  p - %c \n",p);
    c->json=p;//将位置进行保存
}



///////////////

// static int t_parse_null(t_context *c,t_value *v){//解析null

//     expect(c,'n');
//     if (c->json[0] != 'u' || c->json[1] != 'l' || c->json[2] != 'l'  )//测试剩下的ull
//     {//字符串判断前3个字母 null
//         return T_PARSE_INVALID_VALUE;//不是那三种字面值 null、false 或 true
//     }
//     // 反之有
//     c->json+=3;
//     //printf("\n  null 类型正确 \n ");
//     v->type = T_NULL;
//     return T_PARSE_OK;
    
// }


// static int t_parse_true(t_context *c,t_value *v){

//     expect(c,'t');// t? true
//     //printf(" \n  true is  %c,%c ,%c   \n ",c->json[0],c->json[1],c->json[2]);
//     if (c->json[0] != 'r' ||c->json[1] != 'u' || c->json[2] != 'e'  )
//     {
//         //printf(" \n  true is bad %c,%c ,%c   \n ",c->json[0],c->json[1],c->json[2]);
//         return T_PARSE_INVALID_VALUE;//反向判断 快速
//     }
//     c->json+=3;//指针指到最后
//     //printf(" \n  true is ok \n ");
//     v->type=T_TURE;                 //输出结果
//     return T_PARSE_OK;              //表示过程完毕   
// }

// static int t_parse_false(t_context *c,t_value *v){

//     expect(c,'f');
//     //printf(" \n  true is ok 2 \n ");
//     if( c->json[0] != 'a' || c->json[1] != 'l' || c->json[2] != 's' || c->json[3] != 'e' ){
//         return T_PARSE_INVALID_VALUE;
//     }
//     //printf(" \n  true is ok \n ");
//     c->json+=4;

//     v->type=T_FALSE;
//     return T_PARSE_OK;//成功解析

// }

// //这些null true Flase 函数非常的相似 违反编程中常说的 DRY（don't repeat yourself）原则
// //需要合并  但是 上述把 3 个函数合并后，优点是减少重复的代码，维护较容易，
// //但缺点可能是带来性能的少量影响。  软件的架构难以用单一标准评分，重构时要考虑平衡各种软件品质。

// 将 if( c->json[0] != 'a' || c->json[1] != 'l' || c->json[2] != 's' || c->json[3] != 'e' )
// 之类的收为上面操作
static int t_parse_literal(t_context *c ,t_value *v,const char *literal,t_type type){

//与int固定四个字节不同有所不同,size_t的取值range是目标平台下最大可能的数组尺寸,
//一些平台下size_t的范围小于int的正数范围,
//又或者大于unsigned int. 使用Int既有可能浪费，又有可能范围不够大。
    
    check_string(c->json);
    
    size_t i;
    expect(c,literal[0]);//第一个字母进行比较 成功并将c的指针后移
    for ( i = 0; literal[i+1] ; i++) // literal[i+1] 为空表示 没了----》将不定的字符变量向上收了 以 literal 为代替--》非常巧妙
        if ( c->json[i] != literal[i+1] )
            return T_PARSE_INVALID_VALUE;
    c->json += i;//指针移到最后
    v->type = type;

    
    printf("\n字符解析成功了 且当前的 i为 %d  并且已经写入v->type 且当前的最终的位置是 %p \n",i,c->json);
    
    return T_PARSE_OK;

}

////////////////////////////

void check_string(const char *ch2){
    int times= 0;

    printf("\n\ncheck_string  --json.c check_string 120--------当前*ch2 的值为 %d ------> begin\n",*ch2);
 while  ( *ch2 )
    {
        times+=1;
        //printf("%c",*ch2);
        printf("   ***>> 字符编码-》 %c  数字编码-> %d position :%p next position %p 当前的字符是第 %d 个  ",*ch2,*ch2,ch2,(ch2+1),times);
        printf("cut!! \n");
        ch2=ch2+1;
    }

    printf("\nend check --json.c check_string 128------当前*ch2 的值为 %d  字符总计 ： %d  ---字符串检查结果------->\n\n",*ch2,times);
    printf("\n\njson.c check_string 128  -> 字符串检查结果-->   \n");
}


static int  t_parse_end_not_null(t_context *t ){
    //if (*t->json != '\0')
    
    printf("\n json.c 解析工作的最后一步 当前的解析值为 ch22.json值 %d】ch22.json 位置 %p 结果 %d \n",*t->json,t->json,(t->json != '\0'));
    //if ( *ch22.json != '\0' ) {
    if (*t->json != '\0'){
        //check_string(*t->json);
        printf("\njson.c--->t_parse_end_not_null--> 138 T_PARSE_ROOT_NOT_SINGULAR -->ret 变为3！！ %d  解析的为 %c <---position %p 结果 %d  \n",*t->json,*t->json,t->json,(*t->json != '\0'));
        getchar();
        return  T_PARSE_ROOT_NOT_SINGULAR;
    }
    printf("\njson.c--->t_parse_end_not_null--> 138 T_PARSE_OK -->ret 变为0！！%d   解析的为 %c <---position %p \n",*t->json,*t->json,t->json);
        getchar();
    return T_PARSE_OK;//直接返回结果 一点也不臃肿 函数尽可能要求单功能尽可能 组合使用

}

// static double t_parse_number(t_context *c, t_value *v){
//     char *end;
//     v->n=strtod(c->json,&end);//进行结果转化
//     //printf("\n __> %s",*end);
//     if (c->json == end ) return T_PARSE_INVALID_VALUE;
//     printf("\n v->n %lf \n",v->n);
//     v->type=T_NUMBER;
//     c->json=end;//指到尾部
//     printf("\n t_parse_number--->ok  %d",T_PARSE_OK);
//     return T_PARSE_OK;//解析完毕 用于过程确认
// }
# define ISDIGIT(ch)         ((ch) >= '0' && (ch) <= '9')   // 判断是不是数字
# define ISDIGIT1TO9(ch)     ((ch) >= '1' && (ch) <= '9')   //判断是不是从1到9的数组

static double t_parse_number(t_context *c, t_value *v){
    //流水线式的处理
    //============》    》=========    ========
    //   正常      ||  ||         || ||  《-检查
    //             ===》          ====》
    //           异常抛出          异常抛出--》 return T_PARSE_INVALID_VALUE;
    
    
    const char *p = c->json;// 申请一个指针 让他指向json 并方便遍历 不影响json的指针
    //printf ( "   t_parse_number 1 %c  p->%x  c->json%x \n",*p,p ,c->json );
    if( *p == '-' ) p++;
    if( *p == '0' ) p++;
    else
    {    //printf("\n  t_parse_number -> a1 = %d %c \n",ISDIGIT1TO9(*p),*p);
        if (!ISDIGIT1TO9(*p)) return T_PARSE_INVALID_VALUE;
        //printf("\n  t_parse_number -> a1.1 = %d %c\n",ISDIGIT(*p),*p);
        for ( p++ ; ISDIGIT(*p) ; p++ );
        //if ( !ISDIGIT(*p) ) return T_PARSE_INVALID_VALUE;
    }

    if ( *p == '.' )

    {   //printf("\n  t_parse_number -> a2.0 %d %c \n",ISDIGIT1TO9(*p),*p);
        p=p+1; //指针下移动 跳开 .
        //printf("\n  t_parse_number -> a2 %d %c \n",ISDIGIT1TO9(*p),*p);
            if (!ISDIGIT(*p)) return T_PARSE_INVALID_VALUE;
        //printf("\n  t_parse_number -> a2.2 %d %c\n",ISDIGIT(*p),*p);
            for ( p++ ; ISDIGIT(*p) ; p++ );
    }

    if ( *p == 'e' || *p == 'E' )
    {
        p++;
        if (*p == '+' || *p == '-') p++;
        //printf("\n  t_parse_number -> a3 %d %c \n",ISDIGIT1TO9(*p),*p);
        if ( !ISDIGIT(*p) ) return T_PARSE_INVALID_VALUE;
         //printf("\n  t_parse_number -> a3.3 %d %c\n",ISDIGIT(*p),*p);
        for ( p++ ; ISDIGIT(*p) ; p++ );
    }
    //printf ( "    t_parse_number 2 %c  p->%x  c->json%x \n\n ",*p,p ,c->json );
    errno = 0; //errno 是记录系统的最后一次错误代码。代码是一个int型的值
    char *end;
    
    v->n = strtod( c->json , &end );//该函数返回转换后的双精度浮点数，如果没有执行有效的转换，则返回零（0.0）

    printf("\n\njson.c 217 数字解析函数解析的结果为 --> %lf  \n",  v->n );
    if( errno == ERANGE && (v->n == HUGE_VAL || v->n == -HUGE_VAL) )
        return T_PARSE_NUMBER_TOO_BIG;
    v->type = T_NUMBER;
    c->json = end;//json指针 指向队尾
    return T_PARSE_OK;
    
    


}

//处理栈函数 缓冲区
//------》一个字符空间 的申请 一个字符空间的填装
#define PUTC(c,ch) do { *(char*) t_contex_push(c,sizeof(char)) = (ch); } while(0)


void t_free(t_value *v){
    //printf("\n\n ----------> t_free - b   \n");
    assert (v != NULL);
    if (v->type == T_STRING)
        free(v->s);
    v->type = T_NULL;
    //printf("\n\n---------------> t_free - n   \n");
}

void t_init2 (t_context *c){//栈的初始化 c->stack = (char*)malloc(sizeof(char)*16);
    c->stack = (char*) malloc(sizeof(char)*13);//分部内存 指向一个内存 象征一下
    c->top = 0;// 顶部指向0
    c->size=0;
}









static void *t_contex_push(t_context *c,size_t size){
    //用于申请空间处理 返回的是 申请出 空间的 首地址 
    printf("\n\njson.c 227 t_contex_push-> 用于申请空间处理 返回的是 申请出 空间的 首地址  第一个参数含有栈空间  --------\n");
    void *ret;
    assert(size>0);//判断传入的数据是否出错大于0就通过 
    printf("\n\n  t_contex_push  入栈的数据大小size-> %d 当前堆栈的大小c->size %d  当前堆栈的指针位置c->top %d 本次初始值\n",size, c->size, c->top);
    if ( c->top + size >= c->size ){// top 位置将超过 限定的高度  栈的容量比较小
        if ( c->size == 0 ){
            printf("\n\n  top 位置将超过 限定的高度  栈的容量比较小 c->size   T_PARSE_STACK_INIT_SIZE 内存初始化设定为256\n ");
            c->size = T_PARSE_STACK_INIT_SIZE;
            //c->stack = (char*) realloc (c->stack,c->size);--->添加的这个为边判断边分配了
        }// 完全为空
        while ( c->top + size >= c->size ){
            //c->size +=  c->size * 1;
            c->size = c->size + 122;
           // printf("\n----> push end 00 c->size %d top->  %d 打算扩容已经达到临界 \n",c->size ,c->top);
        }//临界
        
        //通过上面确定好 栈的大小后 进行扩容操作
        //printf("\n----> push end 01 c->size %d 准备扩容 c->stack %d \n",c->size,c->stack);
            c->stack = (char*) realloc (c->stack,c->size);//void *realloc(void *ptr, size_t size) ptr -- 指针指向一个要重新分配内存的内存块  size -- 内存块的新的大小，以字节为单位 
        printf("\n----> push end 02 扩容完毕 当前的堆栈大小c->size %d   当前堆栈的起始位置 c->stack %p \n",c->size,c->stack);
        
    }
    ret = c->stack + c->top;//在限定内 top直接上移动   起始地址+top  一开始top为0
    c->top += size;//更新大小
    printf("\n----> push end 03 栈顶指针更新完毕 本次的栈顶指针的位置c->top: %d 本次生产的栈的大小c->size : %d 本次的栈的起始位置 c->stack %p  返回 本次栈的起始位置 ！！ \n",c->top,c->size,c->stack);
    return ret;
}

static void * t_context_pop( t_context *c,size_t size ){
    //返回第一个参数的 c->stack 的更新后的 地址 并修改 c-》top 的值
    //size 为信息单元 的高度
    printf("\n  json.c 261 -1->  t_context_pop  test2 c->stack 十进制表示 %d  16进制表示 %p c->top %d  size %d \n",c->stack,c->stack,c->top,size );
    assert( c->top >= size );//为假就会报错 为真就会放行
    printf("\n  json.c 261 -2->  t_context_pop  test2 c->stack 十进制表示 %d 16进制表示 %p c->top %d  size %d 返回的位置是 c->stack +( c->top - size ) \n",c->stack,c->stack,c->top,size );
    return c->stack +( c->top -= size );//下降 ---> c->stack +( c->top - size ) c->top =c->top-size
}//返回 要弹出栈的 起始位置  并不是真正的出栈 而是 从这个位置开始转移字符 转移完了
//将堆栈变为零  字符串 12345 以从左到右的顺序入栈  栈的起始指针指向 1 栈的top
// （借由1相对指向了5）指向5 





















int t_get_boolean(const t_value* v) {
    /* \TODO */
    assert(v != NULL && (v->type == T_TURE || v->type == T_FALSE));
    return v->type == T_TURE;
}

void t_set_boolean(t_value* v, int b) {
    /* \TODO */
    t_free(v);// 清零 全部释放
    v->type = b ? T_TURE : T_FALSE;
}


void t_set_number(t_value* v, double n) {
    /* \TODO */
    t_free(v);
    v->n = n;
    v->type = T_NUMBER;
}

const char* t_get_string(const t_value* v){
    assert(v != NULL && v->type == T_STRING);
    //printf("\n\n t_get_string---->  len  %d \n",v->len);
    return v->s;
}
int  t_get_string_length (const t_value *v ){
    //printf("\n\n t_get_string_length----->  len  %d \n",v->len);
    assert(v != NULL && v->type == T_STRING);
    return v->len;
}

void t_set_string(t_value* v, const char* s, int len){
//printf("\n\n t_set_string->  len 0  %d \n",len);
    assert(v != NULL && (s != NULL || len == 0));
//printf("\n\n\n ------------->t_set_string -1  \n\n");
//printf("\n\n\n -----> %c \n\n",v->s);
//printf("\n\n  json.c t_set_string 258----> test the first %c %c %c \n",v->s[0],v->s[1],v->s[2]);
    t_free(v);
//printf("\n\n\n ------------->t_set_string -2  \n\n");
//printf("\n\n  json.c t_set_string 260----> test the sec %c %c %c \n",v->s[0],v->s[1],v->s[2]);
    v->s = (char*) malloc (len+1);
    
    //第二次参数为 要被复制的指针发的始位置
    //第一个参数为  复制的新位置的指针起始位置
    memcpy(v->s, s, len);//将解析出来的东西生成一个字符串  写入v的s中
    // char ch2 = *(v->s);
    // check_string(&ch2);

    // printf("json.c  t_set_string 311 -> v->s %c ",v->s);
    // getchar();

    
    v->s[len] = '\0';
    //printf("\n\n\n ------------->t_set_string -5  \n\n");
    v->len = len;
    //printf("\n\n\n ------------->t_set_string -6  \n\n");
    v->type = T_STRING;
    //printf("\n\n\n ------------->t_set_string -7  \n\n");

}
//实现 \uXXXX 解析  Unicode

//不合法的十六进位数
static const char *t_parse_hex4(const char *p, unsigned *u){

    int i;
    *u = 0;
    for(i=0; i<4; i++){
        char ch = *p++;
        *u<<=4;

        if      (ch >= '0' && ch <= '9')  *u |= ch - '0';
        else if (ch >= 'A' && ch <= 'F')  *u |= ch - ('A' - 10);
        else if (ch >= 'a' && ch <= 'f')  *u |= ch - ('a' - 10);
        else return NULL;
    }
    return p;
}

static void t_encode_utf8(t_context*c, unsigned u){

    if (u <= 0x7F)
        PUTC(c, u & 0xFF);
    else if(u <= 0x7FF)
    {
        PUTC(c, 0xC0 | ((u >> 6) & 0xFF));
        PUTC(c, 0x80 | ( u       & 0x3F));
    }else if (u <= 0xFFFF) {
        PUTC(c, 0xE0 | ((u >> 12) & 0xFF));
        PUTC(c, 0x80 | ((u >>  6) & 0x3F));
        PUTC(c, 0x80 | ( u        & 0x3F));
    }
    else {
        assert(u <= 0x10FFFF);
        PUTC(c, 0xF0 | ((u >> 18) & 0xFF));
        PUTC(c, 0x80 | ((u >> 12) & 0x3F));
        PUTC(c, 0x80 | ((u >>  6) & 0x3F));
        PUTC(c, 0x80 | ( u        & 0x3F));
    }
    

}
//////////////////////////////////////////////////////////////
//数组处理

int t_get_array_size(const t_value *v){
    assert(v != NULL && v->type == T_ARRAY);
    return v->array_size;
}

t_value *t_get_array_element(const t_value*v ,int index,int flag){
    assert(v!=NULL && v->type == T_ARRAY);
    assert(index < v->array_size);//不要越界
    //printf("\n json.c 381 t_get_array_element-> %d,%d  flag %d",&v->array_e[index].type,*(&v->array_e[index].type),flag,"\n");
    //getchar();
    if(flag == 1){
        //printf("\njson.c 385  t_get_array_element flag =1  %d \n", &v->array_e[index].n);
        return &v->array_e[index];//返回地址
    }else
    {
        //printf("\njson.c 387  t_get_array_element flag =0  %d \n", *(&v->array_e[index].type));
        return &v->array_e[index].type;//返回地址
        
    }
    }

int t_get_array_element_type(const t_value*v ,int index){
    assert(v!=NULL && v->type == T_ARRAY);
    assert(index < v->array_size);//不要越界
    //printf("\njson.c 397 t_get_array_element_type-> %d,%d  ",&v->array_e[index].type,*(&v->array_e[index].type),"\n");
    //printf("\njson.c 398  t_get_array_element_type flag =0  %d \n", *(&v->array_e[index].type));
    int aa =*(&v->array_e[index].type);
    return aa; //返回地址
}



///////////////////////////////////////////////////////
#define STRING_ERROR(ret) do { c->top = head; return ret; } while(0)














//预处理
static int t_parse_string_raw(t_context *c, char** str, int* len ){// int* len 这里接收到的是 int 形 的指针的地址  int *tmp_int=1--》 t_parse_string_raw(c,&str,&tmp_int);
    printf("\n\njson.c 470 进入 t_parse_string_raw 函数处理 -》 c->stack %p c->size %d  c->top %d \n",c->stack,c->top);
    size_t head = c->top ;
    unsigned u, u2;
    const char *p;
    long flag2=0;
    
    //*len=0;
    printf("\n\njson.c 477 进入  t_parse_string_raw 函数处理 -》 c->stack %p c->size %d  c->top %d \n",c->stack,c->top);
    //printf("len-> %d \n",*len );
    //getchar();


    //json---> "\"Hello\\nWorld\""
    //printf("\n\n p[0] %c p[1] %c p[2] %c p[3] %c  \n",c->json[0], c->json[1], c->json[2],c->json[3]);
    //printf("\n\n t_parse_string_raw - > 420:p = c->json;  %c  asic %d 0--> %c - %d \n", c->json, c->json, '\0', '\0');
    printf("\n******字符串检查*******\n");
    t_context ch2=*c;
    check_string(ch2.json);
    expect (c, '\"');// 判断是不是字符串
    p = c->json;
    printf("\n\njson.c 493 进入 t_parse_string_raw 函数处理 -》 c->stack %p c->size %d  c->top %d \n",c->stack,c->top);
    //ch2=*c;  //char **ch2= &(c->json);
    //check_string(ch2.json);

    printf("\njson.c 433  t_parse_string_raw  \n");
    //getchar();

    int flag = 0;
    int count=0;
    //printf("\n\n t_parse_string - > 258:p = c->json;  %c  asic %d 0--> %c - %d \n", p, p, '\0', '\0');
    for ( ; ; )
    {   
        char ch = *p++; // 向后拨动字符
        count= count+1;

        printf("\n\n t_parse_string - > for ->421 准备解析字符串 图形符号：%c  ,asic %d  p-->%p  \n",ch,ch,p);
        switch (ch)
        {
        case '\"' ://检索结束 字符串到头  “ .... ”
            printf("\n\n t_parse_string---> case '\"' 检索结束 字符串到头 c->top %d head %d c->stack %d  --  %d ----->  \n",c->top,head,((int)c->top - (int)head));
            //printf("------------->   json.c 491");
            if (c->top == 1 && head == 0 )
            {
                int tmp =1;
                *len= tmp;
                printf("\n json.c 493  t_parse_string---> case bug-------->\n");
                //getchar();
                
            }else
            {
                 *len = c->top - head;//src
            }
            
            
            //*len = 0;  //这样处理不行

            printf("\njson.c 516--------- 1.0 len %d------>",*len);
            //getchar();
            
            
            printf("\n--> 进入 t_context_pop 前堆栈大小  c->size %d 当前堆栈的起始位置 c->stack %p  c->top %d\n",c->size,c->stack,c->top );
            *str = t_context_pop(c , *len);//src  第一次的时候发现str的地址跟 通过push操作的 c->stack 堆栈的起始地址相同
                                            
            //*str = c->json;//add

            // char *ch22 = *str;
            // char *ch33 = c->json;
            // check_string(ch22);
            // check_string(ch33);

           // t_set_string (v , (const char *)t_context_pop(c , len), len);
            printf("\n-->  本次最终情况 进入 t_context_pop 后堆栈大小  c->size %d 当前堆栈的起始位置 c->stack %p c->top %d \n",c->size,c->stack,c->top);
            printf("\njson.c 524--------- 2.0 len %d--- top %d str %p json %p  ---> -----------------------------****\n\n\n",*len,c->top,*str,c->json);
            getchar();

            c->json = p;
            return T_PARSE_OK;//字符串解析完整的结束了
        
        case '\\':/*555 --> \ 单个斜杠 555*/
            printf("\n\n 384 ------->  work %d \n",p);
            //flag2 = p ;
            flag = 1;//---->1
            
            //char ch3= ; /* 看 \x x是啥 同时下一一个 */
            switch(*p++){//转义序列的解析
                
                    case '\"': printf("\n\n 384 ------->  work 403-1 p-> %p \n",p); PUTC(c, '\"'); break;
                    case '\\':printf("\n\n 384 ------->  work 404-2  p-> %p \n",p); PUTC(c, '\\'); break;
                    case '/':printf("\n\n 384 ------->  work /  p-> %p \n",p);  PUTC(c, '/' ); break;
                    case 'b':printf("\n\n 384 ------->  work b p-> %p \n",p);  PUTC(c, '\b'); break;
                    case 'f':printf("\n\n 384 ------->  work f p-> %p \n",p);  PUTC(c, '\f'); break;
                    case 'n':printf("\n\n 384 ------->  work n p-> %p \n",p);  PUTC(c, '\n');printf("384 ------->  work n p-> %p  count %d \n",p,count); break;
                    case 'r':printf("\n\n 384 ------->  work r p-> %p \n",p);  PUTC(c, '\r'); break;
                    case 't':printf("\n\n 384 ------->  work t p-> %p \n",p);  PUTC(c, '\t'); break;
                    case 'u':printf("\n\n 384 ------->  work u p-> %p \n",p);
                        if(!( p= t_parse_hex4(p, &u)))
                                STRING_ERROR(T_PARSE_INVALID_UNICODE_HEX);

                                if (u >= 0xD800 && u <= 0xDBFF) { /* surrogate pair */
                            printf("\n\n ------> add\n\n ");
                            if (*p++ != '\\')
                                STRING_ERROR(T_PARSE_INVALID_UNICODE_SURROGATE);
                            if (*p++ != 'u')
                                STRING_ERROR(T_PARSE_INVALID_UNICODE_SURROGATE);
                            if (!(p = t_parse_hex4(p, &u2)))
                                STRING_ERROR(T_PARSE_INVALID_UNICODE_HEX);
                            if (u2 < 0xDC00 || u2 > 0xDFFF)
                                STRING_ERROR(T_PARSE_INVALID_UNICODE_SURROGATE);
                            u = (((u - 0xD800) << 10) | (u2 - 0xDC00)) + 0x10000;
                        }

                        t_encode_utf8(c,u);
                        break;

                    case '\0':
                        STRING_ERROR(T_PARSE_MISS_QUOTATION_MARK);


                    default:
                        c->top = head;
                        STRING_ERROR(T_PARSE_INVALID_STRING_ESCAPE);

                        //c->top = head;
                        // return T_PARSE_INVALID_STRING_ESCAPE;
            }


        case '\0' :
                printf("\n 425 ->t_parse_string--->  0-->  T_PARSE_MISS_QUOTATION_MARK \n");        
                printf("\n\nch-> %c  stand-> %c \n",ch,'\0');
                printf("\n\nd->  %d  stand-> %d \n",ch,'\0');
                //printf("\n\n  flag2: %p p: %p   count : %d  \n\n  ",flag2,p,count);
                
                if(flag != 0 ){
                    flag = 0;
                    //printf()
                }else
                {
                    printf("\n 425 ->t_parse_string--->  0-->  T_PARSE_MISS_QUOTATION_MARK \n");
                    STRING_ERROR(T_PARSE_MISS_QUOTATION_MARK);
                }
                
                
                break;

        default:
            printf("\n\n t_parse_string---> 进入默认选项 default : return T_PARSE_INVALID_STRING_CHAR  \n");
            if ((unsigned char)ch < 0x20 )//进行字符检查 不符合条件的 不能通过
            {
                printf("\n 432  t_parse_string ->if char-> %s ch-> %p , loss %d \n",ch,(unsigned char)ch,((unsigned char)ch-0x20));
                c->top = head;
                return T_PARSE_INVALID_STRING_CHAR;
            }
            printf("\n json.c 623 t_parse_string--->->default 即将 进行入栈操作！ 当前数据 ：c->top %d head %d c->stack的大小 %d c->stack的位置 %p  \n",c->top,head,c->stack);
            PUTC(c,ch);
            printf("\n json.c 623 t_parse_string--->->default 进行入栈操作 完毕！ 本次数据 ：c->top %d head %d c->stack %d c->stack %p \n",c->top,head,c->stack,c->stack);
            // ch2=*c;
            // check_string(ch2.json);
        
        }
        printf("\n json.c 628 t_parse_string---->switch 结束 注意查看分类结果!! c->top %d head %d c->stack %d  c->stack的位置 %p \n\n\n\n",c->top,head,c->stack);
        // ch2=*c;
        // check_string(ch2.json);
        //getchar();
    }

}



























static int t_parse_string (t_context* c, t_value* v ){
    //t_set_string (v , (const char *)t_context_pop(c , len), len);

    int ret;
    char *s;
    int len;
    if ((ret=t_parse_string_raw(c, &s, &len)) == T_PARSE_OK )
    {
        t_set_string(v, s, len);
    }
    return ret; 
    
    
}


// static int t_parse_string (t_context* c, t_value* v ){
//     size_t head = c->top ,len;
//     unsigned u, u2;
//     const char *p;
//     long flag2=0;


//     //json---> "\"Hello\\nWorld\""
//     //printf("\n\n p[0] %c p[1] %c p[2] %c p[3] %c  \n",c->json[0], c->json[1], c->json[2],c->json[3]);
//     //printf("\n\n t_parse_string - > 257:p = c->json;  %c  asic %d 0--> %c - %d \n", c->json, c->json, '\0', '\0');
//     expect (c, '\"');// 判断是不是字符串
//     p = c->json;
    
//     t_context ch2=*c; 
//     //char **ch2= &(c->json);
//     check_string(ch2.json);
//     int flag = 0;
//     int count=0;
//     //printf("\n\n t_parse_string - > 258:p = c->json;  %c  asic %d 0--> %c - %d \n", p, p, '\0', '\0');
//     for ( ; ; )
//     {   
//         char ch = *p++; // 向后拨动字符
//         count= count+1;

//         printf("\n\n t_parse_string - > for ->361 :char ch = *p ++;  %c ,asic %d  p-->%p  \n",ch,ch,p);
//         switch (ch)
//         {
//         case '\"' ://检索接受 字符串到头  “ .... ”
//             printf("\n\n t_parse_string---> case '\"'  \n");
//             len = c->top - head;

//             t_set_string (v , (const char *)t_context_pop(c , len), len);
//             c->json = p;
//             return T_PARSE_OK;//字符串解析完整的结束了
        
//         case '\\':/*555 --> \ 单个斜杠 555*/
//             printf("\n\n 384 ------->  work %d \n",p);
//             //flag2 = p ;
//             flag = 1;//---->1
            
//             //char ch3= ; /* 看 \x x是啥 同时下一一个 */
//             switch(*p++){//转义序列的解析
                
//                     case '\"': printf("\n\n 384 ------->  work 403-1 p-> %p \n",p); PUTC(c, '\"'); break;
//                     case '\\':printf("\n\n 384 ------->  work 404-2  p-> %p \n",p); PUTC(c, '\\'); break;
//                     case '/':printf("\n\n 384 ------->  work /  p-> %p \n",p);  PUTC(c, '/' ); break;
//                     case 'b':printf("\n\n 384 ------->  work b p-> %p \n",p);  PUTC(c, '\b'); break;
//                     case 'f':printf("\n\n 384 ------->  work f p-> %p \n",p);  PUTC(c, '\f'); break;
//                     case 'n':printf("\n\n 384 ------->  work n p-> %p \n",p);  PUTC(c, '\n');printf("384 ------->  work n p-> %p  count %d \n",p,count); break;
//                     case 'r':printf("\n\n 384 ------->  work r p-> %p \n",p);  PUTC(c, '\r'); break;
//                     case 't':printf("\n\n 384 ------->  work t p-> %p \n",p);  PUTC(c, '\t'); break;
//                     case 'u':printf("\n\n 384 ------->  work u p-> %p \n",p);
//                         if(!( p= t_parse_hex4(p, &u)))
//                                 STRING_ERROR(T_PARSE_INVALID_UNICODE_HEX);

//                                 if (u >= 0xD800 && u <= 0xDBFF) { /* surrogate pair */
//                             printf("\n\n ------> add\n\n ");
//                             if (*p++ != '\\')
//                                 STRING_ERROR(T_PARSE_INVALID_UNICODE_SURROGATE);
//                             if (*p++ != 'u')
//                                 STRING_ERROR(T_PARSE_INVALID_UNICODE_SURROGATE);
//                             if (!(p = t_parse_hex4(p, &u2)))
//                                 STRING_ERROR(T_PARSE_INVALID_UNICODE_HEX);
//                             if (u2 < 0xDC00 || u2 > 0xDFFF)
//                                 STRING_ERROR(T_PARSE_INVALID_UNICODE_SURROGATE);
//                             u = (((u - 0xD800) << 10) | (u2 - 0xDC00)) + 0x10000;
//                         }

//                         t_encode_utf8(c,u);
//                         break;

//                     case '\0':
//                         STRING_ERROR(T_PARSE_MISS_QUOTATION_MARK);


//                     default:
//                         c->top = head;
//                         STRING_ERROR(T_PARSE_INVALID_STRING_ESCAPE);

//                         //c->top = head;
//                         // return T_PARSE_INVALID_STRING_ESCAPE;
//             }


//         case '\0' :
//                 printf("\n 425 ->t_parse_string--->  0-->  T_PARSE_MISS_QUOTATION_MARK \n");        
//                 printf("\n\nch-> %c  stand-> %c \n",ch,'\0');
//                 printf("\n\nd->  %d  stand-> %d \n",ch,'\0');
//                 //printf("\n\n  flag2: %p p: %p   count : %d  \n\n  ",flag2,p,count);
                
//                 if(flag != 0 ){
//                     flag = 0;
//                     //printf()
//                 }else
//                 {
//                     printf("\n 425 ->t_parse_string--->  0-->  T_PARSE_MISS_QUOTATION_MARK \n");
//                     STRING_ERROR(T_PARSE_MISS_QUOTATION_MARK);
//                 }
                
                
//                 break;

//         default:
//             printf("\n\n t_parse_string---> default : return T_PARSE_INVALID_STRING_CHAR  \n");
//             if ((unsigned char)ch < 0x20 )//进行字符检查 不符合条件的 不能通过
//             {
//                 printf("\n 432  t_parse_string ->if char-> %s ch-> %p , loss %d \n",ch,(unsigned char)ch,((unsigned char)ch-0x20));
//                 c->top = head;
//                 return T_PARSE_INVALID_STRING_CHAR;
//             }
//             PUTC(c,ch);
//         }
//     }
// }




///////////////////////////////////////////////
static int t_parse_value(t_context* c, t_value* v,int flag);//先给下面的声明一下 下面的呢个函数 【t_parse_array】要用
//这两个函数有点 互相调用的意思 但是 要调用的话必须要出现在前面所以 前项 声明一下
static int t_parse_array(t_context *c, t_value*v ){
    //c->stack = (char*)malloc(sizeof(char)*16);
    int size=0;
    int ret;
    expect(c,'[');//["abc",[1,2],3]--->判定为数组

    t_parse_ws(c);// 解析空白字符  解析出来是空的将json指针 相向后移动直到不是为空为止

    if (*c->json == ']'){// [] 完了为空
        c->json++ ;
        v->type = T_ARRAY;
        v->array_size = 0;
        v->array_e=NULL; 
        return T_PARSE_OK;
    }
    // 如果为 【1，【2,3】，4】----》解析第二个 【时 会 中断再次调用该函数 所以知道处理完这个后再执行第一个
    //同过下面的e把它们都串起来  进入第二层就变为了 v 从而  memcpy(v->array_e = (t_value*)malloc(size), t_context_pop(c, size), size);//连接
    //
   // t_context* tmp= t_contex_push(c, sizeof(t_value));

    printf("\n\n 0 json.c 660  t_parse_array ->  c->size %d c->top %d \n", c->size ,c->top);

    for ( ; ; )
    {
        t_value e;
        
        t_init(&e);

        printf("\n\n 1 json.c 667  t_parse_array ->  c->size %d c->top %d \n", c->size ,c->top);
        //t_context tmp = *c;

        if((ret = t_parse_value(c,&e,1)) != T_PARSE_OK) break;//这里会对 c的进行刷新--->进入主调用在进行分类
        //解析的结果存放到e中 e->type ,e->s,e->num....
        printf("\njson.c 837 数组解析函数 中的for 解析结果e的----------->e.type： %d , e.s ：%c（第一个字符） , e.n ：%d , e.len ：%d \n",e.type,e.s,e.n,e.len);
        //getchar();
        printf("\n\n 1.5 json.c 839 数组解析函数  t_parse_array -> 中的for:第一个参数c（待分析的数据的基本值）  c->size %d c->top %d \n", c->size ,c->top);

        
        
        memcpy(t_contex_push(c, sizeof(t_value)), &e, sizeof(t_value));//将解析的结果value 放到 加入到原有的堆栈当中
        //memcpy(t_contex_push(c, sizeof(t_value)), &e, sizeof(t_value));
        size++;

        t_parse_ws(c);// 解析空白字符

        if(*c->json == ',') {
            c->json++;//继续处理 继续解析
            t_parse_ws(c);//  解析空白字符 看上面向后移动的是不是 空字符串 是的话 继续向后拨动 

            printf("\n\n 3 json.c 680 指针开始移动到 ，号的后面 t_parse_array ->  c->size %d c->top %d  当前的位置c-json %p \n", c->size ,c->top,c->json);

            }
        else if (*c->json == ']'){//解析结束
            c->json++;
            v->type = T_ARRAY;
            v->array_size = size;
            size *= sizeof(t_value);
            memcpy(v->array_e = (t_value*)malloc(size), t_context_pop(c, size), size);//连接
            
            printf("\n\n json.c 863 t_parse_array-> 解析结束 数组的第一个 类型 结果： %d  数组的第二个 类型 %d 第三个 类型 %d 第四个 类型 %d \n",v->array_e[0].type,v->array_e[1].type,v->array_e[2].type,v->array_e[3].type,v->array_e[4].type);
            printf("\n\n json.c 863 t_parse_array-> 解析结束 数组的第一个 num  结果： %d  数组的第二个 num %d 第三个 num %d 第四个 mun %d \n",v->array_e[0].n,v->array_e[1].n,v->array_e[2].n,v->array_e[3].n,v->array_e[4].n);
            //getchar();
            
            return T_PARSE_OK;
        } 

        else {
            return T_PARSE_MISS_COMMA_OR_SQUARE_BRACKET;
            break;
            }

        printf("\n\n 4 json.c 874 数组解析函数的for本次循环结束 即将开始新一轮的循环处理   t_parse_array ->  c->size %d c->top %d \n", c->size ,c->top);

    }

    //出栈  数组已经被放入 v->array_e  指针中
    //将c释放掉
    for(int i=0; i<size ; i++){
        t_free((t_value*)t_context_pop(c, sizeof(t_value) ));
        return ret;
    }

    getchar();
    
}
//t_parse_value




///////////////////////////////////////////// 对象 object
// static int t_parse_object(t_context* c, t_value* v){
//     printf("\njson.c 769 t_parse_object  \n");

//     int size;
    
//     t_object_member m;
//     int ret;

//     expect(c,'{');
//     t_parse_ws(c);
//     if(*c->json == "}"){
//         c->json++;
//         v->type = T_OBJ;
//         v->obj_member=0;
//         v->obj_size=0;
//         return 0;
//     }

//     //normal
//     m.key_value_string=NULL;
//     size = 0;
//     for(;;){

//         t_init(&m.v);
//         if((ret= t_parse_value(c,&m.v,0)) != T_PARSE_OK)break;
//         t_parse_ws(c);
//         memcpy(t_contex_push(c,sizeof(t_object_member)), &m, sizeof(t_object_member));
//         size++;
//         m.key_value_string = NULL;
        

//     }
//     return ret;



// }

































static int isFistTimeInOBJ = 1;//在解析对象的过程中 是不是第一次进行解析 1代表是
static int  back_size;
static int *back_size_p;
static int *back_top_p;
static int  back_top;


void checkPositionAndValue(t_context*c,int lineNumber,int isShowBack){
    if(isShowBack == 1){
    printf("\n json.c %d 行 之前的 值    c->stack %p c->size %d  c->top %d \n",lineNumber,c->stack,back_size,back_top);
    printf(" json.c %d 行 之前的 地址  c->json %p ,c->size %p ,c->stack %p ,c->top %p  \n",lineNumber,c->json,back_size_p,c->stack,back_top_p);
    }
    
    back_size = c->size;
    back_top = c->top;

    back_top_p = &c->top;
    back_size_p = &c->size;
    
    printf(" json.c %d 行 现在的 值  c->stack %p c->size %d  c->top %d  \n",lineNumber,c->stack,c->size,c->top);
    printf(" json.c %d 行 现在的 地址 c->json %p ,c->size %p ,c->stack %p ,c->top %p -------------------------------------> \n\n\n",lineNumber,c->json,&c->size,c->stack,&c->top);

}

static int t_parse_obj(t_context*c, t_value* v){
    
    //t_init2(c);
    

    
    // printf("\n json.c 964 对象解析工作即将开始  t_parse_obj obj----->c->stack %p c->size %d  c->top %d  isFistTimeInOBJ %d \n",c->stack,c->size,c->top,isFistTimeInOBJ+0);
    // printf("\n json.c 972 对象解析工作即将开始 查看c的结构体 的地址空间 c->json %p ,c->size %p ,c->stack %p ,c->top %p isFistTimeInOBJ %d \n\n\n",c->json,&c->size,c->stack,&c->top,isFistTimeInOBJ+1);
    checkPositionAndValue(c,995,1);
    getchar();
    

   // c->stack = (char*)malloc(sizeof(char)*16);
    //语法格式 分析
    //member = string ws %x3A ws value
    //object = %x7B ws [ member *( ws %x2C ws member ) ] ws %x7D
    // %x3A-->U+003A-> :  Unicode编码解释

    int i,size;
    t_object_member m;
    int ret;

    expect(c,'{');
    
    t_parse_ws(c);
                                        // printf("\ntest!! 0  %c %d %d",*c->json,*c->json,(*c->json == '}'));
                                        // getchar();

    
    if (*c->json == '}')//为空的情况 或者 为结束了
    {
        c->json++;
        v->type = T_OBJ;
        v->obj_member = 0;
        v->obj_size = 0;
        printf("\njson.c 933  t_parse_obj-> 为空的情况back T_PARSE_OK \n");
        return T_PARSE_OK;
    }
    
    
    m.key_value_string=NULL;
    //m.key_length = 0 ;//处理正常的进行相关的初始化
    //t_context bbb;
    size=0;
    

    int tmp_i=0;
    for (;;)
    {
        tmp_i +=1 ;
        // printf("\njson.c   1020 for 查看c的结构体 的地址空间 c->json %p ,c->size %p ,c->stack %p ,c->top %p \n",c->json,&c->size,c->stack,&c->top);
        // printf("json.c 1021  进入 解析 对象  赋值后  的for循环开始 0 -》 c->stack %p c->size %d  c->top %d times ：%d  isFistTimeInOBJ %d \n\n\n",c->stack,c->top,tmp_i,isFistTimeInOBJ);
        // printf("\n\njson.c 1007  进入 解析 对象  赋值后  的for循环开始 0 -》 c->stack %p c->size %d  c->top %d times ：%d  isFistTimeInOBJ %d \n",c->stack,c->top,tmp_i,isFistTimeInOBJ);
        printf("\n json.c   1020  对象解析函数的 进入 for 刚刚开始 \n");
        checkPositionAndValue(c,1041,1);
        getchar();
                char* str;
                t_init(&m.v);
        

                if(*c->json != '"'){// err->{""}---> " a" : b ,---> ""
                    printf("\n json.c 1011 T_PARSE_MISS_KEY! c->json %p \n",c->json);
                    getchar();
                    ret = T_PARSE_MISS_KEY;
                    break;
                }
                                                    // t_context ch2=*c;
                                                    // check_string(ch2.json);
                                                    // int tmp_int=6; 
                                                    //(**tmp_int)=0;
                                                    // printf(" \n test----**tmp_int------->\n");
                                                    // printf(" \n --->**tmp_int %d ",tmp_int);//---------》len的值无法得到有效的传递
                                                    //c->stack = c->json;//add 

                ret = t_parse_string_raw(c,&str,&m.key_length);// src
                                                //ret = t_parse_string_raw(c,&str,&tmp_int);
                                                // printf("\n json.c-> t_parse_obj 997 刚刚接收到的len值为 -> %d \n",m.key_length);
                                                // getchar();
                
                if(ret != T_PARSE_OK )break;
                
                
                memcpy( (m.key_value_string=(char*)malloc(m.key_length+1) ),str,m.key_length );
                                                            // printf("\n ----==========---0 添加之前 ---》---------  本次开始从头开始重查 ------------>>>>> \n");
                                                            // t_context ch331 = *c;
                                                            // check_string(ch331.json);
                                                            
                                                            // printf("\n ----==========---0 添加之前 ---》------- m.key_value_string  %p  -------------->>>>> \n",m.key_value_string);
                                                            // char *ch22=m.key_value_string;
                                                            // check_string(ch22);
                
                m.key_value_string[m.key_length] = '\0';//添加最后一个字符
                //memcpy 新位置的指针 指向了 str上面内容的位置 所以  m.key_value_string[m.key_length]-》在stack上面进行的操作
                
                
                
                if(m.key_length == 0){
                    printf(" \n 加在了 0  id %d \n",tmp_i);
                                                            //getchar();
                }else
                {
                    printf(" \n 加在了 %d 且不是0  id %d \n", m.key_length,tmp_i);
                                                            //getchar();
                }

                            t_object_member ch22 =m;
                            char* ch33 = ch22.key_value_string;
                            check_string(ch33);
                printf("\n-->json.c 1057 当前堆栈大小  c->size %d 当前堆栈的起始位置 c->stack %p  c->top %d  \n",c->size,c->stack,c->top );
                printf("\n ----==========---/0 添加之后 ---》------------加在了m.key_length %d\
                \n - m.key_value_string[m.key_length]> %c ,&m.key_value_string[m.key_length]> %p  m.key_value_string[m.key_length-1]> %c  m.key_value_string[m.key_length-2]>%c; m.key_value_string[m.key_length+1]>%c; 当前的迭代次数为 id %d- ---------------------------------**** \n\n\n",m.key_length,m.key_value_string[m.key_length],&m.key_value_string[m.key_length],m.key_value_string[m.key_length-1],m.key_value_string[m.key_length-2],m.key_value_string[m.key_length+1],tmp_i);
                // 在这里 m.key_value_string 添加了 如：n:null,中的 n + 字符串的终止符号\0 -->n\0
                getchar();//m.key_value_string[m.key_length-1],m.key_value_string[m.key_length-2]  m.key_value_string[m.key_length+1],tmp_i


                                                                            // printf("\n 0 添加之后 aa ---》-------===================================----1045------------  \n");
                                                                            // *ch22=m.key_value_string;
                                                                            // check_string(ch22);
                                                                            // getchar();
                                                                            // getchar();
                                                                            
                                                                            //t_context ch33 = *c;
                                                                            
                                                                            // printf("\n ----==========---0 添加之后 ---》------------加在了 %d  本次开始从头开始重查 看看到底插在哪里了  --------->>>>> \n",m.key_length);
                                                                            // check_string(ch33.json);
                                                                            // printf("\n ----==========---0 添加之后 ---》------------加在了 %d  本次开始从头开始重查 看看到底插在哪里了- 结束  --------->>>>> \n",m.key_length);
                                                                            // getchar();
                                                                            
                                                                            
                                                                            
                                                                            
                
                t_parse_ws(c);//处理 "n" : null中的 : 前面的空格
                
                
                if(*c->json != ':'){ // err->{""}---> " a" : b ,---> :
                    ret = T_PARSE_MISS_COLON;
                    printf("\n 没有找到 ：！！即将break 当前的指针位置是 %p \n",c->json);
                    getchar();
                    break;
                }
                
                c->json++;//src
                printf("\njson.c 1084 指针移动的位置 移动到:之后的那个位置上 position -> c->json++ %p 当前堆栈大小  c->size %d 当前堆栈的起始位置 c->stack %p c->top %d \n",c->json,c->size,c->stack,c->top );
                //printf("\njson.c 1084 指针移动的位置 移动到:之后的那个位置上 position -> c->json++ %p 当前堆栈大小  c->size %d 当前堆栈的起始位置 c->stack %p c->top %d \n",bbb.json,bbb.size,bbb.stack,bbb.top );
                
                                                                      //getchar();
                t_parse_ws(c);//处理 "n" : null , "f" ....中的 : 后面的空格
                                                                        // t_parse_ws(c);
                                                                        // char *ch44=c->json;
                                                                        // check_string(ch44);
                                                                        // getchar();
                
                
                ret = t_parse_value(c,&m.v,1);// 解析  "n" : null , "f" ....中的 null字符 并将 处理的 null写入 m.v.type
                
                printf("\n-->json.c 1101 处理完：号后 当前堆栈大小  c->size %d 当前堆栈的起始位置 c->stack %p c->top %d \n",c->size,c->stack,c->top);
                if( ret != T_PARSE_OK ){
                    break;
                }
                printf("\n  json.c 1100 ret解析成功 ==字典中的value字符解析成功   t_parse_obj-> 即将进入push t_contex_push -----------> m:%p \n",&m);
                
                
                memcpy((t_contex_push(c,sizeof(t_object_member))) ,&m,sizeof(t_object_member));//void *memcpy(void *str1, const void *str2, size_t n) 
                                                                                                 //将 str2 n个字节 放到 str1中---》在该工程下就是把 key 存起来 （key ：value）
                                                                        //getchar();
                printf("\n-->json.c 1109 push之后 当前堆栈大小  c->size %d 当前堆栈的起始位置 c->stack %p c->top %d  \n",c->size,c->stack,c->top );
                size++;
                m.key_value_string = NULL;//将key归零
                t_parse_ws(c);

                                            //printf("\n test!! 1 -----------");
                                            //c->json;
                                            // printf("\n test!! 1  %c %d  t_parse_obj -》循环的次数： %d \n",*c->json,*c->json,tmp_i);
                                            // getchar();
                printf("\n json.c 1166 对象解析函数的 for中 的 逗号探测前的 指针位置 %p \n",c->json);
                char c_json =*c->json;//原来为 c->json 所以报错  Segmentation fault (core dumped) 访问了原本就没有的东西
                
                
                
                if(c_json == ','){// err->{""}---> " a" : b ,--->  ,  
                                ///处理 "n" : null , "f" ....中的 ,发现之后处理，将指针移动到，后面的位置
                printf("\n json.c 1166 对象解析函数的 for中 的 逗号探测后的 指针位置 %p \n",c->json);

                                                // printf("\n test!! 2 -----------");
                                                // printf("\n test!! 2  %c %d  times  %d \n",*c->json,*c->json,tmp_i);
                                                //getchar();
                c->json++;
                                                // char *ch55= c->json;
                                                // ch55 ='\0'; 
                                                // check_string(ch55);
                    
                printf("\n-->json.c 1134  当前堆栈大小  c->size %d 当前堆栈的起始位置 c->stack %p c->top %d \n",c->size,c->stack,c->top);
                printf("\njson.c 1046 指针移动的位置 position -> c->json++ %p 当前的size 值 %d 到此 ‘n’ : null ,为例子 已经处理基本结束了 接下来重新走循环 或者 找到 } 跳出循环 c->stack %p c->stack %d--------------****    \n\n\n",c->json,size,c->stack,c->size);
                //printf("\njson.c 1046 指针移动的位置 position -> c->json++ %p 当前的size 值 %d 到此 ‘n’ : null ,为例子 已经处理基本结束了 接下来重新走循环 或者 找到 } 跳出循环 c->stack %p c->stack %d--------------****    \n\n\n",bbb.json,size,bbb.stack,bbb.size);
                //printf("\njson.c 1084 指针移动的位置 移动到:之后的那个位置上 position -> c->json++ %p 当前堆栈大小  c->size %d 当前堆栈的起始位置 c->stack %p c->top %d \n",bbb.json,bbb.size,bbb.stack,bbb.top );
                
                t_parse_ws(c);
                printf("\n-->json.c 1141  当前堆栈大小  c->size %d 当前堆栈的起始位置 c->stack %p c->top %d \n",c->size,c->stack,c->top);
                //printf("\n-->json.c 1141  当前堆栈大小  c->size %d 当前堆栈的起始位置 c->stack %p c->top %d \n",bbb.size,bbb.stack,bbb.top);
                getchar();//到此 "n" : null ,已经处理基本结束了
                                        // printf("\n test!! 2.5 -----------");
                }
                else if(c_json == '}'){//结束的标志 {} -》 }
                                    // printf("\n test!! 3 -----------");
                                    // printf("\n test!! 3  %c %d  times  %d \n",*c->json,*c->json,tmp_i);
                                    //getchar();
                    getchar();
                    int s = sizeof(t_object_member)*size;
                    

                    c->json ++;
                    printf(" \n json.c 1139 发现}本次 即将 结束！在pop之后 开始  回到总解析 函数进行处理  当前的指针位置是 %p \n",c->json);
                    //printf(" \n json.c 1139 发现}本次结束！开始 回到总解析 函数进行处理  当前的指针位置是 %p \n",bbb.json);
                                // printf("\njson.c 1059 指针移动的位置 position -> c->json++ %p  \n",c->json);
                    getchar();

                    v->type=T_OBJ;
                    v->obj_size = size;

                    memcpy(v->obj_member = (t_object_member*)malloc(s),t_context_pop(c,s),s);
                    printf(" \n json.c 1139 发现}本次 正式 结束！ pop工作已经完成 开始 回到总解析 函数进行处理  当前的指针位置是 %p \n",c->json);

                    return T_PARSE_OK;
                }
                else
                {
                                                                // printf("\n test!! 4 -----------");
                                                                // printf("\n test!! 4  %c %d  times  %d \n",*c->json,*c->json,tmp_i);
                                                                //getchar();
                    ret = T_PARSE_MISS_COMMA_OR_CURLY_BRACKET;
                    
                    printf("\njson.c 1156 没有找到 } 进入break 本次循环结束 目前的位置是 %p \n",c->json);
                    //printf("\njson.c 1156 没有找到 } 进入break 本次循环结束 目前的位置是 %p \n",bbb.json);
                    getchar();
                    
                    break;
                }//单句处理完毕
        //printf("\n sizeof(c) %d sizeof(c->stack) %d  sizeof(c->top) %d sizeof(c->size) %d \n",sizeof(c),sizeof(c->stack),sizeof(c->top),sizeof(c->size));
                printf("\n json.c 1173 单句处理完毕 !!!\n");
                checkPositionAndValue(c,1221,0);
                getchar();
        }//循环处理直到全部完成有效的语句
        
        
        
        // printf("\n test!! 5 -----------");
        printf("\n 循环处理直到全部完成有效的语句 test!! 5   %c %d  %p  times  %d \n",*c->json,*c->json,c->json,tmp_i);
        //printf("\n 循环处理直到全部完成有效的语句 test!! 5   %c %d  %p  times  %d \n",bbb.json,bbb.json,bbb.json,tmp_i);
        getchar();
        
        printf("\njson.c 1164  下面要关于size 进行处理size--> %d \n",size);
        free(m.key_value_string);
        for (int i = 0; i < size; i++)
        {
                    // t_object_member *m;
                    // if (isFistTimeInOBJ == 1)
                    //     {
                    //         isFistTimeInOBJ=0;//如果是第一次为1 那就把 他变为0
                    //         printf("\n  isFistTimeInOBJ 是第一次为1 那就把 他变为0 \n");
                    //         m = (t_object_member*)t_context_pop(&bbb,sizeof(t_object_member));
                    //     }else
                    //     {
                    //         m = (t_object_member*)t_context_pop(&bbb,sizeof(t_object_member));
                    //     }
            t_object_member *m = (t_object_member*)t_context_pop(c,sizeof(t_object_member));
            free(m->key_value_string);
            t_free(&m->v);
        }
    
    printf("\njson.c 1100 *最终* 指针移动的位置 position -> c->json++ %p  \n",c->json);
    getchar();
    v->type = T_NULL;
    return ret;
}






























/////////////////////////////////////////////////////////////

///// 一掉部分工具函数写完 下面从37-68 都是对上面的调用与封装




static int t_parse_value(t_context *t , t_value *v, int flag ){
//解析值 将样本t_context *t中要解析的 文本 解析到第二个参数 v  里面 比如写到 v->type v->s v->num...中 第三个参数为1 表示对t进行重置
    if (flag == 1)
    {
        printf("\n\njson.c 863 -> t_parse_value 不会对其进行初始化 \n");
    }
    else
    {
        t_init2(t);
    }
    
    
    
    //char str[40];
    //sprintf(str," *t->json ,%s  *v , %s \n ",*t->json,*v);
    //printf("\n *t->json ,%s   \n",*t->json);
    switch (*t->json)
    {
    case 'n': // case "n" 就不行 因为不是常量
        printf("\n  json.c 1206 t_parse_value------> n -> null");
        //return t_parse_null(t,v);
        return t_parse_literal (t, v, "null", T_NULL);//成功返回 T_PARSE_OK 
        // break;

    case '\0': // case "n" 就不行 因为不是常量
        printf("\n  json.c 1206 t_parse_value ------>  \\0 \n");
        
        return T_PARSE_EXPECT_VALUE; //任何字符串的背后都是 \0
    
    case 32: // 空格的阿斯克码为32
        printf("\n  json.c 1206 t_parse_value ------>  解析空格的阿斯克码 \n");
        
        return T_PARSE_EXPECT_VALUE; //任何字符串的背后都是 \0
        //break;// 一个 JSON 只含有空白

    case 't':
        printf("\n  json.c 1206 t_parse_value ------> t开头字符 解析判断是不是 true  \n");
        //return t_parse_true(t,v);
        return t_parse_literal (t, v, "true", T_TURE);

    case 'f':
        printf("\n  json.c 1206 t_parse_value ------> f开头字符 解析判断是不是 false \n");
        
        //return t_parse_false(t,v);
        return t_parse_literal (t, v, "false", T_FALSE);
    case '"' :
        printf("\n json.c 1206 t_parse_value ------> “开头字符 解析判断是不是 字符串 ------> json.c 6 \n");
        
        return t_parse_string(t, v);
    
    case '[':
        printf("\n json.c 1206 t_parse_value ------> 【开头字符 解析判断是不是 数组 json.c 7\n");
        
        return t_parse_array(t, v);
    
    case '{':  
        
        printf("\n json.c 1206 t_parse_value ------> {开头字符 判断是不是 对象 ------> json.c 8\n");
        return t_parse_obj(t, v);
    
    default:
        printf("\n  ------> json.c 9");
        
        return t_parse_number(t, v);
        //break;不是那三种字面值
    }
    // printf("\n t_parse_value -> end in t= %d\n",t);
    // getchar();
}


/////////////////////////////////////////////


////////////////////////////////////////////////



int t_parse(t_value *v, const char *json){//t_parse(&v,"null")

    t_context c;
    //  error--> json---> "\"Hello\\nWorld\""
    printf("\njson.c 981 t_parse开始主函数开始解析 接受到的内容-数字表现形式num : %d,字符串表现形式string : %c  \n ",*json,*json);
    assert( v !=NULL );
    c.json =json;
    v->type=T_NULL;

    int ret= t_parse_value(&c,v,0);
    printf("\n 解析主函数工作 基本结束 ........\n");
    getchar();

    //printf("\n___1 ret--> %d ___",ret);

    if ( ret == T_PARSE_OK)//虽然有很多的函数 要判断很多的类型但是都是有统一的调用入口 和 统一的出口 出口的东西都一样（指的是正确的情况下）
    //但是在错误的情况下返回的都是各自领域的错误
    {
        printf("\njson.c 1400 t_parse 最后一步解析操作 解析发现空格  空格处理中 \n");
        t_parse_ws(&c);
        //c.json++;//--->

        // char *tmp_test_c = c.json;
        // check_string(tmp_test_c);
        ret=t_parse_end_not_null(&c);
    }
    printf("\n\n json.c t_parse 1203 解析主函数工作结束返回的结果 ret--> %d \n\n\n",ret);
    return ret;
    
}





////JSON 生成器（generator），就是把树形数据结构转换成 JSON 文本。这个过程又称为「字符串化（stringify）」

static void t_stringify_string(t_context *c, const char*s, int len){//JSON 生成器（generator） 生称字符串
    static const char hex_digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    int i,size;
    char* head,*p;
    assert(s != NULL);
    p = head = t_contex_push(c,size = len * 6 +2);
    *p++ = '"';
    for ( i = 0; i < len; i++)
    {
        unsigned char ch = (unsigned char) s[i];
        switch (ch)
        {
            case '\"': *p++ = '\\'; *p++ = '\"'; break;
            case '\\': *p++ = '\\'; *p++ = '\\'; break;
            case '\b': *p++ = '\\'; *p++ = 'b';  break;
            case '\f': *p++ = '\\'; *p++ = 'f';  break;
            case '\n': *p++ = '\\'; *p++ = 'n';  break;
            case '\r': *p++ = '\\'; *p++ = 'r';  break;
            case '\t': *p++ = '\\'; *p++ = 't';  break;
        
        default:
                if (ch < 0x20) {
                    *p++ = '\\'; *p++ = 'u'; *p++ = '0'; *p++ = '0';
                    *p++ = hex_digits[ch >> 4];
                    *p++ = hex_digits[ch & 15];
                }else *p++ = s[i];
        }
    }

    *p++ = '"';
    c->top -= size -(p-head); 
    

}

static void t_stringify_value(t_context *c, const t_value*v ){//解析 value 将里面的值赋给c的里面
    char* buffer;
    int length;

    switch (v->type)
    {
        int i ;
        case T_NULL: PUTS(c,"null",4) ;break;
        case T_FALSE: PUTS(c,"false",5) ;break;
        case T_TURE: PUTS(c,"true",4) ;break;
        case T_NUMBER: 
                        buffer = t_contex_push(c,32) ;
                        length = sprintf(buffer,"%.17g",v->n);
                        c->top -= 32 - length;
                    // char* buffer = t_contex_push(c,32) ; // 美化（prettify）-> c->top -= 32 - sprintf(lept_context_push(c, 32), "%.17g", v->n);
                    // int length = sprintf(buffer,"%.17g",v->n);
                    // c->top -= 32 - length;     //在switch语句里定义了新的变量 --报错  -》error: a label can only be part of a statement and a declaration is not a statemen
                    break;
        case T_STRING: t_stringify_string(c,v->s,v->len) ;break;

        case T_ARRAY:
                PUTC(c,'[');
                for ( i = 0; i < v->array_size; i++)
                {
                    if(i>0) PUTC(c,',');
                    t_stringify_value(c, &v->array_e[i]);
                }
                PUTC(c,']');
                
                break;
        case T_OBJ:
                PUTC(c,'{');
                for ( i = 0; i < v->obj_size; i++)
                {
                    if(i>0) PUTC(c,',');
                    t_stringify_string(c,v->obj_member[i].key_value_string , v->obj_member[i].key_length);
                    PUTC(c,':');
                    t_stringify_value(c,&v->obj_member[i].v);
                }
                PUTC(c,'}');
                break;
        default: assert(0 && "invalid type");

    }
}



char* t_stringify(const t_value* v, int* length) {//生成器 主函数  传入的值和长度
    t_context c;
    assert(v != NULL);
    c.stack = (char*) malloc (c.size = T_PARSE_STRINGIFY_INIT_SIZE);
    c.top = 0;
    t_stringify_value(&c, v);
    if(length) *length = c.top;
    PUTC(&c,'\0');
    return c.stack;

}




t_type t_get_type(const t_value *v){
    assert(v!=NULL);
    //printf("\n t_get_type--->%d \n",v->type);
    return v->type;
}

double t_get_number(const t_value *v){
    //printf(" t_get_number  %lf \n",v->n);
    assert(v != NULL && v->type == T_NUMBER);
    return v->n;
}

// t_value* t_get_array_element(const t_value* v, int index) {
//     assert(v != NULL && v->type == T_ARRAY);
//     assert(index < v->array_size);
//     return &v->array_e[index];
// }



int t_get_object_size(const t_value* v) {
    assert(v != NULL && v->type == T_OBJ);
    return v->obj_size;
}

const char* t_get_object_key(const t_value* v, int index) {
    assert(v != NULL && v->type == T_OBJ);
    assert(index < v->obj_size);
    //return v->u.o.m[index].k;
    return v->obj_member[index].key_value_string;
}

int t_get_object_key_length(const t_value* v, int index) {
    assert(v != NULL && v->type == T_OBJ);
   //assert(index < v->u.o.size);
    assert(index < v->obj_size);
    //return v->u.o.m[index].klen;
    return v->obj_member[index].key_length;
}

t_value* t_get_object_value(const t_value* v, int index) {
    assert(v != NULL && v->type == T_OBJ);
    assert(index < v->obj_size);
    //return &v->u.o.m[index].v;
    return &v->obj_member[index].v;
}

//E:\the_c_of_vs_code\c\c_project\json>gcc -c json.c
