#include "unikey.h"

using namespace unikey;

#ifdef _MSC_VER
    #define BINDINGS_API __declspec(dllexport)
#else
    #define BINDINGS_API
#endif

extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>

    BINDINGS_API int unikey_new(lua_State *L) {
        SimpleUnikey* unikey = new SimpleUnikey();
        SimpleUnikey** u = (SimpleUnikey**)lua_newuserdata(L, sizeof(SimpleUnikey*));
        *u = unikey;

        luaL_getmetatable(L, "luaL_lunikey");
        lua_setmetatable(L, -2);
        
        return 1;
    }

    BINDINGS_API int unikey_process(lua_State *L) {
        luaL_argcheck(L, lua_isuserdata(L, 1), 1, "lunikey instance expected");
        luaL_argcheck(L, lua_isstring(L, 2), 2, "string expected");

        SimpleUnikey** u = (SimpleUnikey**)lua_touserdata(L, 1);
        const char* s = lua_tostring(L, 2);
        (*u)->process(s);
        return 0;
    }

    BINDINGS_API int unikey_get_result(lua_State *L) {
        luaL_argcheck(L, lua_isuserdata(L, 1), 1, "lunikey instance expected");

        SimpleUnikey** u = (SimpleUnikey**)lua_touserdata(L, 1);
        const char* s = (*u)->get_result().c_str();
        lua_pushstring(L, s);
        return 1;
    }

    BINDINGS_API int unikey_restore(lua_State *L) {
        luaL_argcheck(L, lua_isuserdata(L, 1), 1, "lunikey instance expected");

        SimpleUnikey** u = (SimpleUnikey**)lua_touserdata(L, 1);
        (*u)->restore();
        return 0;
    }

    BINDINGS_API int unikey_reset(lua_State *L) {
        luaL_argcheck(L, lua_isuserdata(L, 1), 1, "lunikey instance expected");

        SimpleUnikey** u = (SimpleUnikey**)lua_touserdata(L, 1);
        (*u)->reset();
        return 0;
    }

    BINDINGS_API int unikey_process_backspace(lua_State *L) {
        luaL_argcheck(L, lua_isuserdata(L, 1), 1, "lunikey instance expected");

        SimpleUnikey** u = (SimpleUnikey**)lua_touserdata(L, 1);
        (*u)->process_backspace();
        return 0;
    }

    BINDINGS_API int unikey_destroy(lua_State *L) {
        luaL_argcheck(L, lua_isuserdata(L, 1), 1, "lunikey instance expected");

        SimpleUnikey** u = (SimpleUnikey**)lua_touserdata(L, 1);
        delete *u;
        return 0;
    }

    const struct luaL_Reg unikey_methods[] = {
        {"process", unikey_process},
        {"text", unikey_get_result},
        {"restore", unikey_restore},
        {"reset", unikey_reset},
        {"process_backspace", unikey_process_backspace},
        {"new", unikey_new},
        {"__gc", unikey_destroy},
        {NULL, NULL}
    };

    BINDINGS_API int luaopen_lunikey(lua_State *L) {
        luaL_newmetatable(L, "luaL_lunikey");

        lua_pushstring(L, "__index");
        lua_pushvalue(L, -2);
        lua_settable(L, -3);

        for (int i = 0; unikey_methods[i].name; i++) {
            lua_pushstring(L, unikey_methods[i].name);
            lua_pushcfunction(L, unikey_methods[i].func);
            lua_settable(L, -3);
        }

        return 1;
    }
}