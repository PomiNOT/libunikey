luainc = include_directories('src')

lua_sources = [
    'src/lapi.c',
    'src/lcode.c',
    'src/ldebug.c',
    'src/ldo.c',
    'src/ldump.c',
    'src/lfunc.c',
    'src/lgc.c',
    'src/llex.c',
    'src/lmem.c',
    'src/lobject.c',
    'src/lopcodes.c',
    'src/lparser.c',
    'src/lstate.c',
    'src/lstring.c',
    'src/ltable.c',
    'src/ltm.c',
    'src/lundump.c',
    'src/lvm.c',
    'src/lzio.c',

    'src/lauxlib.c',
    'src/lbaselib.c',
    'src/ldblib.c',
    'src/liolib.c',
    'src/lmathlib.c',
    'src/loslib.c',
    'src/ltablib.c',
    'src/lstrlib.c',
    'src/loadlib.c',
    'src/linit.c'
]

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

liblua = shared_library('lua51',
  lua_sources,
  include_directories : luainc,
  dependencies : [m_dep],
  c_args : '-DLUA_BUILD_AS_DLL',
  install : false
)

liblua_dep = declare_dependency(
  link_with: liblua,
  include_directories : luainc
)