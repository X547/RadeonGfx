libsync = static_library('sync',
	[
		'Fence.cpp',
		'FenceGroup.cpp',
		'Syncobj.cpp',
	],
	include_directories: [
		'..',
	],
	dependencies: [
		Locks,
		SADomains,
	],
	gnu_symbol_visibility: 'hidden',
)

dep_libsync = declare_dependency(
	link_with: libsync,
	include_directories: ['.'],
)
