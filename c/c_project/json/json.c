#include "json.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include <errno.h>   /* errno, ERANGE */
#include <math.h>    /* HUGE_VAL */

#include <string.h>  /* memcpy() */

#ifndef T_PARSE_STACK_INIT_SIZE // stack
    #define T_PARSE_STACK_INIT_SIZE 256// stack
#endif

#define expect(c,ch) do { assert(*c->json == (ch));c->json++; } while(0)

typedef struct{
    const char *json;
    char* stack ; //引入堆栈 用作缓冲区
    size_t size, top;// 堆栈的东西

}t_context;

static void t_parse_ws(t_context *c){// parse_whitespace 解析空格
    const char *p = c->json;//测试第一个字符n
    while (*p==' ' || *p=='\t' ||*p=='\n'||*p=='\r' )
    {
        p++;
    }
    //printf("\n fun->t_parse_ws_>  p - %d ",p);
    c->json=p;
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
    size_t i;
    expect(c,literal[0]);//第一个字母进行比较 成功并将c的指针后移
    for ( i = 0; literal[i+1] ; i++) // literal[i+1] 为空表示 没了----》将不定的字符变量向上收了 以 literal 为代替--》非常巧妙
        if ( c->json[i] != literal[i+1] )
            return T_PARSE_INVALID_VALUE;
    c->json += i;//指针移到最后
    v->type = type;
    return T_PARSE_OK;

}

////////////////////////////


static int  t_parse_end_not_null(t_context *t ){
    if (*t->json != '\0') 
        return  T_PARSE_ROOT_NOT_SINGULAR;
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
    v->n = strtod( c->json , &end );
    //printf(" --> %lf ",  v->n );
    if( errno == ERANGE && (v->n == HUGE_VAL || v->n == -HUGE_VAL) )
        return T_PARSE_NUMBER_TOO_BIG;
    v->type = T_NUMBER;
    c->json = end;//json指针 指向队尾
    return T_PARSE_OK;
    
    


}

//处理栈函数 缓冲区
#define PUTC(c,h) do { *(char*) t_contex_push(c,sizeof(char)) = (ch); } while(0)


void t_free(t_value *v){
    //printf("\n\n ----------> t_free - b   \n");
    assert (v != NULL);
    if (v->type == T_STRING)
        free(v->s);
    v->type = T_NULL;
    //printf("\n\n---------------> t_free - n   \n");
}

void t_init2 (t_context *c){//栈的初始化
    c->stack = (char*) malloc(0);//分部内存 指向一个内存 象征一下
    c->top = 0;// 顶部指向0
    c->size=0;
}

static void *t_contex_push(t_context *c,size_t size){
    

    void *ret;
    assert(size>0);//判断传入的数据是否出错大于0就通过 
    printf("\n\n t_contex_push  size-> %d c->size %d c->top %d \n",size, c->size, c->top);
    if ( c->top + size >= c->size ){// top 位置将超过 限定的高度  栈的容量比较小
        if ( c->size == 0 ){
            printf("\n\n  c->size   T_PARSE_STACK_INIT_SIZE \n ");
            c->size = T_PARSE_STACK_INIT_SIZE;
        }// 完全为空
        while ( c->top + size >= c->size ){
            //c->size +=  c->size * 1;
            c->size = c->size + 2;
            printf("\n----> push end 00 c->size %d top->  %d\n",c->size ,c->top);
        }//临界
        
        //通过上面确定好 栈的大小后 进行扩容操作
        printf("\n----> push end 01 c->size %d \n",c->size);
            c->stack = (char*) realloc (c->stack,c->size);//void *realloc(void *ptr, size_t size) ptr -- 指针指向一个要重新分配内存的内存块  size -- 内存块的新的大小，以字节为单位 
        printf("\n----> push end 02 \n");
    }
    ret = c->stack + c->top;//在限定内 top直接上移动   起始地址+top  一开始top为0
    c->top += size;//更新大小
    printf("\n----> push end 03 \n");
    return ret;
}

static void * t_context_pop( t_context *c,size_t size ){
    //size 为信息单元 的高度
    assert( c->top >= size );//为假就会报错 为真就会放行
    return c->stack +( c->top -= size );//下降
}



int t_get_boolean(const t_value* v) {
    /* \TODO */
    return 0;
}

void t_set_boolean(t_value* v, int b) {
    /* \TODO */
}

void t_set_number(t_value* v, double n) {
    /* \TODO */
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
    //printf("\n\n\n ------------->t_set_string -3  \n\n");
    memcpy(v->s, s, len);
    //printf("\n\n\n ------------->t_set_string -4  \n\n");
    v->s[len] = '\0';
    //printf("\n\n\n ------------->t_set_string -5  \n\n");
    v->len = len;
    //printf("\n\n\n ------------->t_set_string -6  \n\n");
    v->type = T_STRING;
    //printf("\n\n\n ------------->t_set_string -7  \n\n");

}


static int t_parse_string (t_context* c, t_value* v ){
    size_t head = c->top ,len;
    const char *p;
    //printf("\n\n p[0] %c p[1] %c p[2] %c p[3] %c  \n",c->json[0], c->json[1], c->json[2],c->json[3]);
    //printf("\n\n t_parse_string - > 257:p = c->json;  %c  asic %d 0--> %c - %d \n", c->json, c->json, '\0', '\0');
    expect (c, '\"');// 判断是不是字符串
    p = c->json;
    //printf("\n\n t_parse_string - > 258:p = c->json;  %c  asic %d 0--> %c - %d \n", p, p, '\0', '\0');
    for ( ; ; )
    {   
        char ch = *p++; // 向后拨动字符
        printf("\n\n t_parse_string - > for ->261 :char ch = *p ++;  %c ,asic %d\n",ch,ch);
        switch (ch)
        {
            
        case '\"' ://开头
            printf("\n\n t_parse_string---> case '\"'  \n");
            len = c->top - head;
            t_set_string (v , (const char *)t_context_pop(c , len), len);
            c->json = p;
            return T_PARSE_OK;

        case '\0' :
        printf("\n\n t_parse_string---> case 0  \n");
            c->top = head;
            return T_PARSE_MISS_QUOTATION_MARK;

        default:
            printf("\n\n t_parse_string---> default:  \n");
            PUTC(c, ch);
        }
    }
}


///// 一掉部分工具函数写完 下面从37-68 都是对上面的调用与封装




static int t_parse_value(t_context *t , t_value *v){//解析值
    t_init2(t);
    //char str[40];
    //sprintf(str," *t->json ,%s  *v , %s \n ",*t->json,*v);
    //printf("\n *t->json ,%s   \n",*t->json);
    switch (*t->json)

    {
    case 'n': // case "n" 就不行 因为不是常量
        printf("\n  ------> 1");
        //return t_parse_null(t,v);
        return t_parse_literal (t, v, "null", T_NULL);
        // break;

    case '\0': // case "n" 就不行 因为不是常量
    printf("\n  ------>  json.c  2 \n");
        return T_PARSE_EXPECT_VALUE; //任何字符串的背后都是 \0
    
    case 32: // 空格的阿斯克码为32
    printf("\n  ------> json.c 3 \n");
        return T_PARSE_EXPECT_VALUE; //任何字符串的背后都是 \0
    
        // break; 一个 JSON 只含有空白
    case 't':
    printf("\n  ------>  json.c 4 \n");
        //return t_parse_true(t,v);
        return t_parse_literal (t, v, "true", T_TURE);

    case 'f':
    printf("\n  ------> json.c 5 \n");
        //return t_parse_false(t,v);
        return t_parse_literal (t, v, "false", T_FALSE);
    case '"' :
    printf("\n  ------> json.c 6 \n");
        return t_parse_string(t, v);
    
    default:
    printf("\n  ------> json.c 7");
        return t_parse_number(t, v);
        //break;不是那三种字面值
    }
}

int t_parse(t_value *v, const char *json){//t_parse(&v,"null")

    t_context c;
    
    printf("\njson.c get -->num : %d, string : %c  \n ",*json,*json);
    assert( v !=NULL );
    c.json =json;
    v->type=T_NULL;

    int ret= t_parse_value(&c,v);

    //printf("\n___1 ret--> %d ___",ret);

    if ( ret == T_PARSE_OK)//虽然有很多的函数 要判断很多的类型但是都是有统一的调用入口 和 统一的出口 出口的东西都一样（指的是正确的情况下）
    //但是在错误的情况下返回的都是各自领域的错误
    {
        t_parse_ws(&c);
        ret=t_parse_end_not_null(&c);
    }
    //printf("2 ret--> %d",ret);
    return ret;
    
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


//E:\the_c_of_vs_code\c\c_project\json>gcc -c json.c
