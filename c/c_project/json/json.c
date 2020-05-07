#include "json.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



#define expect(c,ch) do { assert(*c->json == (ch));c->json++; } while(0)

typedef struct{
    const char *json;
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

static double t_parse_number(t_context *c, t_value *v){
    char *end;
    v->n=strtod(c->json,&end);//进行结果转化
    //printf("\n __> %s",*end);
    if (c->json == end ) return T_PARSE_INVALID_VALUE;
    printf("\n v->n %lf \n",v->n);
    v->type=T_NUMBER;
    c->json=end;//指到尾部
    printf("\n t_parse_number--->ok  %d",T_PARSE_OK);
    return T_PARSE_OK;//解析完毕 用于过程确认
}


///// 一掉部分工具函数写完 下面从37-68 都是对上面的调用与封装

static int t_parse_value(t_context *t ,t_value *v){//解析值
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
    printf("\n  ------> 2");
        return T_PARSE_EXPECT_VALUE; //任何字符串的背后都是 \0
    
    case 32: // 空格的阿斯克码为32
    printf("\n  ------> 3");
        return T_PARSE_EXPECT_VALUE; //任何字符串的背后都是 \0
    
        // break; 一个 JSON 只含有空白
    case 't':
    printf("\n  ------> 4");
        //return t_parse_true(t,v);
        return t_parse_literal (t, v, "true", T_TURE);

    case 'f':
    printf("\n  ------> 5");
        //return t_parse_false(t,v);
        return t_parse_literal (t, v, "false", T_FALSE);
    
    default:
    printf("\n  ------> 6");
        return t_parse_number(t,v);
        //break;不是那三种字面值
    }
}

int t_parse(t_value *v, const char *json){//t_parse(&v,"null")

    t_context c;
    printf("\njson.c get -->num%d, string%c ,\n,",*json,*json);
    assert( v !=NULL );
    c.json =json;
    v->type=T_NULL;

    int ret= t_parse_value(&c,v);

    printf("\n___1 ret--> %d ___",ret);

    if ( ret == T_PARSE_OK)//虽然有很多的函数 要判断很多的类型但是都是有统一的调用入口 和 统一的出口 出口的东西都一样（指的是正确的情况下）
    //但是在错误的情况下返回的都是各自领域的错误
    {
        t_parse_ws(&c);
        ret=t_parse_end_not_null(&c);
    }
    printf("2 ret--> %d",ret);
    return ret;
    
}

t_type t_get_type(const t_value *v){
    assert(v!=NULL);
    //printf("\n t_get_type--->%d \n",v->type);
    return v->type;
}

double t_get_number(const t_value *v){
    assert(v != NULL && v->type == T_NUMBER);
    return v->n;
}


//E:\the_c_of_vs_code\c\c_project\json>gcc -c json.c
