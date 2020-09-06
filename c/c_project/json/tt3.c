#include<stdio.h>
#include <string.h>



typedef struct{
    
    char* stack ; //引入堆栈 用作缓冲区
    int top,size ;// 堆栈的东西
    const char *json;

}t_context;


static int test_err_1(int*len){
    *len = 2;// *len = 2 --->back -->a=2 len这个指针一开始指向 a 但是 给了值为2 所以指向2了
    return 1;
}

static int check(char *c){
    printf("\n");
    while (*c)
    {
        printf(" %c ",*c);
        c++;
    }
    return 1;
    

}
static int flaga =22222;
static int  read(){
    printf( " \n  read---->flaga %d \n\n",flaga);
    return 1 ;
}

void cc(t_context *tt){
    tt->top=999;
}



int main(){
    int a=1; 
    int *ch_a ;
    ch_a =&a;
    *ch_a =66;//改变a的值

    t_context tt;
    tt.top=10;
    tt.top=20;
    cc(&tt);
    printf("tt.top %d",tt.top);

    
    printf("\n\n static int f  %d\n\n",a);
    printf("\n\n static int flag %d  %d\n\n",flaga,a);
    read();
    
    test_err_1(&a);
    printf("\n-->  ans a : %d not 2  \n",a);
    getchar();

    
    // char *firstName = "Theo";
    // char *lastName = "Tsao";
    // char *name = (char *) malloc(strlen(firstName) + strlen(lastName));
    // sprintf(name, "%s%s", firstName, lastName);
    // printf("%s\n", name);
    getchar();





}

// err->{""}---> " a" : b ,---> ""static int lept_parse_object(lept_context* c, lept_value* v) {
//     size_t i, size;
//     lept_member m;
//     int ret;
//     EXPECT(c, '{');
//     lept_parse_whitespace(c);
//     if (*c->json == '}') {
//         c->json++;
//         v->type = LEPT_OBJECT;
//         v->u.o.m = 0;
//         v->u.o.size = 0;
//         return LEPT_PARSE_OK;
//     }
//     m.k = NULL;
//     size = 0;
//     for (;;) {
//         char* str;
//         lept_init(&m.v);
//         /* parse key */
//         if (*c->json != '"') {
//             ret = LEPT_PARSE_MISS_KEY;
//             break;
//         }
//         if ((ret = lept_parse_string_raw(c, &str, &m.klen)) != LEPT_PARSE_OK)
//             break;
//         memcpy(m.k = (char*)malloc(m.klen + 1), str, m.klen);
//         m.k[m.klen] = '\0';
//         /* parse ws colon ws */
//         lept_parse_whitespace(c);
//         if (*c->json != ':') {
//             ret = LEPT_PARSE_MISS_COLON;
//             break;
//         }
//         c->json++;
//         lept_parse_whitespace(c);
//         /* parse value */
//         if ((ret = lept_parse_value(c, &m.v)) != LEPT_PARSE_OK)
//             break;
//         memcpy(lept_context_push(c, sizeof(lept_member)), &m, sizeof(lept_member));
//         size++;
//         m.k = NULL; /* ownership is transferred to member on stack */
//         /* parse ws [comma | right-curly-brace] ws */
//         lept_parse_whitespace(c);
//         if (*c->json == ',') {
//             c->json++;
//             lept_parse_whitespace(c);
//         }
//         else if (*c->json == '}') {
//             size_t s = sizeof(lept_member) * size;
//             c->json++;
//             v->type = LEPT_OBJECT;
//             v->u.o.size = size;
//             memcpy(v->u.o.m = (lept_member*)malloc(s), lept_context_pop(c, s), s);
//             return LEPT_PARSE_OK;
//         }
//         else {
//             ret = LEPT_PARSE_MISS_COMMA_OR_CURLY_BRACKET;
//             break;
//         }
//     }
//     /* Pop and free members on the stack */
//     free(m.k);
//     for (i = 0; i < size; i++) {
//         lept_member* m = (lept_member*)lept_context_pop(c, sizeof(lept_member));
//         free(m->k);
//         lept_free(&m->v);
//     }
//     v->type = LEPT_NULL;
//     return ret;
// }