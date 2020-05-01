#include "json.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



#define expect(c,ch) do { assert(*c->json == (ch)); c->json++; } while(0)

typedef struct{
    const char *json;
}t_context;

static void t_parse_ws(t_context *c){// parse_whitespace 解析空格
    const char *p = c->json;//测试第一个字符n
    while (*p==' ' || *p=='\t' ||*p=='\n'||*p=='\r' )
    {
        p++;
    }
    printf("\n fun->t_parse_ws_>  p - %d ",p);
    c->json=p;
}

static int t_parse_null(t_context *c,t_value *v){//解析null

    expect(c,'n');
    if (c->json[0] != 'u' || c->json[1] != 'l' || c->json[2] != 'l'  )//测试剩下的ull
    {//字符串判断前3个字母 null
        return T_PARSE_INVALID_VALUE;//不是那三种字面值 null、false 或 true
    }
    // 反之有
    c->json+=3;
    printf("\n  null 类型正确 \n ");
    v->type = T_NULL;
    return T_PARSE_OK;
    
}


static int t_parse_true(t_context *c,t_value *v){

    expect(c,'t');// t?
    if (c->json[0] != 'r' ||c->json[1] != 'u' || c->json[2] != 'e'  )
    {
        return T_PARSE_INVALID_VALUE;//反向判断 快速
    }
    c->json+=3;//指针指到最后
    return T_PARSE_OK;
}

static int t_parse_false(t_context *c,t_value *v){

    expect(c,'f');
    if( c->json[0] != 'a' || c->json[1] != 'l' || c->json[2] != 's' || c->json[3] != 'e' ){
        return T_PARSE_INVALID_VALUE;
    }
    c->json+=4;
    return T_PARSE_OK;//成功解析

}

static int  t_parse_end_not_null(t_context *t ){
    if (t->json != '\0') 
        return  T_PARSE_ROOT_NOT_SINGULAR;
    return T_PARSE_OK;//直接返回结果 一点也不臃肿 函数尽可能要求单功能尽可能 组合使用

}


///// 一掉部分工具函数写完 下面从37-68 都是对上面的调用与封装

static int t_parse_value(t_context *t ,t_value *v){//解析值
    //char str[40];
    //sprintf(str," *t->json ,%s  *v , %s \n ",*t->json,*v);
    //printf("\n *t->json ,%s   \n",*t->json);
    switch (*t->json)

    {
    case 'n': // case "n" 就不行 因为不是常量
        return t_parse_null(t,v);
        // break;

    case '\0': // case "n" 就不行 因为不是常量
        return T_PARSE_EXPECT_VALUE; //任何字符串的背后都是 \0
        // break; 一个 JSON 只含有空白
    case 'r':
        return t_parse_true(t,v);

    case 'f':
        return t_parse_false(t,v);
    
    default:
        return T_PARSE_INVALID_VALUE;
        //break;不是那三种字面值
    }
}

int t_parse(t_value *v, const char *json){//t_parse(&v,"null")

    t_context c;
    assert( v !=NULL );
    c.json =json;
    v->type=T_NULL;

    int ret= t_parse_value(&c,v);
    

    if ( ret == T_PARSE_OK)//虽然有很多的函数 要判断很多的类型但是都是有统一的调用入口 和 统一的出口 出口的东西都一样（指的是正确的情况下）
    //但是在错误的情况下返回的都是各自领域的错误
    {
        t_parse_ws(&c,v);
        ret=t_parse_end_not_null(&c,v);
    }

    return t_parse_value(&c,v);
    
}

t_type t_get_type(const t_value *v){
    assert(v!=NULL);
    return v->type;
}
//E:\the_c_of_vs_code\c\c_project\json>gcc -c json.c
