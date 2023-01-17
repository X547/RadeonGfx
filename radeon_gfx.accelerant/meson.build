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
