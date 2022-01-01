project('lunikey', 'cpp', 'c')

ukincdir = include_directories('ukengine')

subdir('lua5')
subdir('ukengine')

sources = [
    'src/bindings.cpp',
    'src/unikey.cpp'
]

shared_library(
	'lunikey',
	sources,
	include_directories : ukincdir,
	dependencies : [libukengine_dep, liblua_dep]
)