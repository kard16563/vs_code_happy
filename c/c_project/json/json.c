#include "json.h"
#include <assert.h>
#include <stdlib.h>

//#define expect(c,ch) do { assert(*c->json == (ch)); c->json++; } while(0)
typedef struct{
    const char *json;
}t_context;

static void t_parse_ws(t_context *c){
    const char *p = c->json;
    while (*p==" " || *p=="\t" ||*p=="\n"||*p=="\r" )
    {
        p++;
    }
    c->json=p;
}


