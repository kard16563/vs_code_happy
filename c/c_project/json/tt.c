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


// A simple atoi() function---》 conver string to integer 从字符串到整数
int myAtoi(char* str) 
{ 
    int res = 0; // Initialize result 

    // Iterate through all characters of input string and 
    // update result 
    for (int i = 0; str[i] != '\0'; ++i) 
        res = res * 10 + str[i] - '0'; 

    // return result. 
    return res; 
} 


int main(){

    t_context c;
    t_value v;
    
    c.json ="null";
    v.type=T_NULL;
    
    
    t_parse_null(&c,&v);

    char str[] = "89789"; 
    int val = myAtoi(str); 
    printf("--->整数 %d -- str-> %s ", val,str); 

    char str1[30] = "20.30300 This is test";
    char *ptr;
    double ret;

   ret = strtod(str1, &ptr);
   printf("数字（double）是 %lf\n  %lf ", ret,*ptr);
   printf("字符串部分是 |%s|", ptr);

        int ta1 = 3;
        ta1 += ta1;
        printf("\n\n  ta1 %d \n",ta1);

        ta1 += ta1 *2;
         printf("\n\n  ta1 %d \n",ta1);
         ta1 += (ta1 * 2);//先乘在加
         printf("\n\n  ta1 %d \n",ta1);
//    char *str3;
//    str3 = (char *) realloc(str3, 25);
    


    getchar();


}