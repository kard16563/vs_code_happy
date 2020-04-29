#include "json.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define expect(c,ch) do {\
                            assert(*c->json == (ch));\
                            printf("\n __ %c \n",*c->json);\
                            c->json++;} while(0)//指针下移动


typedef struct{
    const char *json;
}t_context;


static int t_parse_null(t_context *c,t_value *v){//解析null

    expect(c,'n');
    if (c->json[0] != 'u' || c->json[1] != 'l' || c->json[2] != 'l'  )//测试剩下的ull
    {//字符串判断前3个字母 null
        return T_PARSE_INVALID_VALUE;//不是那三种字面值 null、false 或 true
    }
    // 反之有

    printf("%c,%c,%c",c->json[0]  , c->json[1] ,c->json[2] );
    c->json+=3;
    printf("\n  null 类型正确  \n ");
    v->type = T_NULL;
    return T_PARSE_OK;
    
}

int main(){

    t_context c;
    t_value v;
    
    c.json ="null";
    v.type=T_NULL;
    
    
    t_parse_null(&c,&v);

    getchar();


}