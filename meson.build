project('lunikey', 'cpp', 'c')

ukincdir = include_directories('ukengine')

subdir('lua5')

sources = [
    'src/bindings.cpp',
    'src/unikey.cpp',
    'ukengine/byteio.cpp',
    'ukengine/charset.cpp',
    'ukengine/convert.cpp',
	'ukengine/data.cpp',
	'ukengine/error.cpp',
	'ukengine/inputproc.cpp',
	'ukengine/mactab.cpp',
	'ukengine/pattern.cpp',
	'ukengine/ukengine.cpp',
	'ukengine/usrkeymap.cpp'
]

library('lunikey', sources, include_directories : ukincdir, dependencies : liblua_dep, cpp_args : '-funsigned-char')