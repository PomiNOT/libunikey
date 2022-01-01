uk_sources = [
  'byteio.cpp',
  'charset.cpp',
  'convert.cpp',
	'data.cpp',
	'error.cpp',
	'inputproc.cpp',
	'mactab.cpp',
	'pattern.cpp',
	'ukengine.cpp',
	'usrkeymap.cpp'
]

ukinc = include_directories('.')

args = []

compiler = meson.get_compiler('cpp')

if compiler.get_id() == 'gcc'
	args = ['-funsigned-char']
endif

libukengine = static_library('ukengine',
  uk_sources,
  cpp_args : args,
  install : false
)


libukengine_dep = declare_dependency(
  link_with: libukengine,
  include_directories : ukinc
)