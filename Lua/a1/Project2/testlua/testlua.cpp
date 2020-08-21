

#include <iostream>
using namespace std;
#include <lua.hpp>


int main(void)



{

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "main.lua");
    lua_close(L);
    cin.get();
  //n.get();
    return 0;



    return 0;



}
