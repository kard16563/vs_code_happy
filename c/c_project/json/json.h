#ifndef T_JSON_H_
#define T_JSON_H_
//先写需要什么函数  然后去写函数 最后再去写测试单元
//json 包含 6 种数据类型
//类型及函数则用小写 通常枚举值用全大写
typedef enum {T_NULL,T_FALSE,T_TURE,T_NUMBER,T_STRING,T_ARRAY,T_OBJ} t_type;

typedef struct 
{
    t_type type;
}t_value;

enum{
    T_PARSE_OK = 0,
    T_PARSE_EXPECT_VALUE,//一个 JSON 只含有空白
    T_PARSE_INVALID_VALUE,//不是null、false 或 true那三种字面值
    T_PARSE_ROOT_NOT_SINGULAR//一个值之后，在空白之后还有其他字符
};

int t_parse(t_value *v,const char* json);//解析 JSON
t_type t_get_type(const t_value *v);//访问结果的函数

#endif