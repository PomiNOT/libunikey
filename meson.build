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

args = []

compiler = meson.get_compiler('cpp')

if compiler.get_id() == 'gcc'
	args = ['-funsigned-char']
endif

shared_library(
	'lunikey',
	sources,
	include_directories : ukincdir,
	dependencies : liblua_dep,
	cpp_args : args
)