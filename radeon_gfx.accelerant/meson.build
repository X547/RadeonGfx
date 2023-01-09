project('radeon_gfx.accelerant', 'cpp',
	version : '0.1',
	default_options : ['warning_level=3', 'cpp_std=c++2a']
)

cpp = meson.get_compiler('cpp')

LocksProj = subproject('Locks')
Locks = LocksProj.get_variable('Locks')

ThreadLinkProj = subproject('ThreadLink')
ThreadLink = ThreadLinkProj.get_variable('ThreadLink')

dep_libbe = cpp.find_library('be')
dep_libaccelerant = dependency('libaccelerant')
dep_libdrm0 = dependency('libdrm').partial_dependency(compile_args : true)

shared_library('radeon_gfx',
	[
		'RadeonGfxAccelerant.cpp',
	],
	dependencies: [
		dep_libbe,
		dep_libaccelerant,
		Locks,
		ThreadLink,
		dep_libdrm0
	],
	name_prefix: '',
	name_suffix: 'accelerant',
	gnu_symbol_visibility: 'hidden',
	install_dir: 'add-ons/accelerants',
	install: true
)
