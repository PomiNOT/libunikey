#include "unikey.h"

using namespace unikey;

extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>

    int unikey_new(lua_State *L) {
        SimpleUnikey* unikey = new SimpleUnikey();
        SimpleUnikey** u = (SimpleUnikey**)lua_newuserdata(L, sizeof(SimpleUnikey*));
        *u = unikey;

        luaL_getmetatable(L, "luaL_lunikey");
        lua_setmetatable(L, -2);
        
        return 1;
    }

    int unikey_process(lua_State *L) {
        SimpleUnikey** u = (SimpleUnikey**)lua_touserdata(L, 1);
        const char* s = lua_tostring(L, 2);
        (*u)->process(s);
        return 0;
    }

    int unikey_get_result(lua_State *L) {
        SimpleUnikey** u = (SimpleUnikey**)lua_touserdata(L, 1);
        const char* s = (*u)->get_result().c_str();
        lua_pushstring(L, s);
        return 1;
    }

    int unikey_restore(lua_State *L) {
        SimpleUnikey** u = (SimpleUnikey**)lua_touserdata(L, 1);
        (*u)->restore();
        return 0;
    }

    int unikey_reset(lua_State *L) {
        SimpleUnikey** u = (SimpleUnikey**)lua_touserdata(L, 1);
        (*u)->reset();
        return 0;
    }

    int unikey_process_backspace(lua_State *L) {
        SimpleUnikey** u = (SimpleUnikey**)lua_touserdata(L, 1);
        (*u)->process_backspace();
        return 0;
    }

    int unikey_destroy(lua_State *L) {
        SimpleUnikey** u = (SimpleUnikey**)lua_touserdata(L, 1);
        delete *u;
        return 0;
    }

    const struct luaL_Reg unikey_methods[] = {
        {"process", unikey_process},
        {"get_result", unikey_get_result},
        {"restore", unikey_restore},
        {"reset", unikey_reset},
        {"process_backspace", unikey_process_backspace},
        {"new", unikey_new},
        {NULL, NULL}
    };

    int luaopen_lunikey(lua_State *L) {
        luaL_newmetatable(L, "luaL_lunikey");
        lua_pushcfunction(L, unikey_destroy);
        lua_setfield(L, -2, "__gc");
        luaL_openlib(L, "lunikey", unikey_methods, 0);
        return 1;
    }
}