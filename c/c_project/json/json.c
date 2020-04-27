#include "json.h"
#include <assert.h>
#include <stdlib.h>

#define expect(c,ch) do { assert(*c->json == (ch)); c->json++; } while(0)

typedef struct{
    const char *json;
}t_context;

static void t_parse_ws(t_context *c){// parse_whitespace 解析空格
    const char *p = c->json;
    while (*p==' ' || *p=='\t' ||*p=='\n'||*p=='\r' )
    {
        p++;
    }
    printf("\n fun->t_parse_ws_>  p - %d ",p);
    c->json=p;
}

static int t_parse_null(t_context *c,t_value *v){//解析null

    expect(c,"n");
    if (c->json[0] != 'u' || c->json[1] != 'l' || c->json[2] != 'l'  )
    {//字符串判断前3个字母 null
        return T_PARSE_INVALID_VALUE;//不是那三种字面值 null、false 或 true
    }
    // 反之有
    c->json+=3;
    v->type = T_NULL;
    return T_PARSE_OK;
    
}

///// 一掉部分工具函数写完 下面从37-68 都是对上面的调用与封装

static int t_parse_value(t_context *t ,t_value *v){//解析值
    switch (*t->json)
    {
    case 'n': // case "n" 就不行 因为不是常量
        return t_parse_null(t,v);
        // break;

    case '\0': // case "n" 就不行 因为不是常量
        return T_PARSE_EXPECT_VALUE;
        // break; 一个 JSON 只含有空白
    
    default:
        return T_PARSE_INVALID_VALUE;
        //break;不是那三种字面值
    }
}

int t_parse(t_value *v, const char *json){

    t_context c;
    assert( v !=NULL );
    c.json =json;
    v->type=T_NULL;

    return t_parse_value(&c,v);
    
}

t_type t_get_type(const t_value *v){
    assert(v!=NULL);
    return v->type;
}
