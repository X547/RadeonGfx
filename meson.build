project('RadeonGfx', 'cpp',
	version : '0.1',
	default_options : ['warning_level=3', 'cpp_std=c++2a']
)

compiler = meson.get_compiler('cpp')

add_project_arguments('-Wno-narrowing', language: 'cpp')
add_project_arguments('-Wno-pedantic', language: 'cpp')
add_project_arguments('-Wno-missing-field-initializers', language: 'cpp')


dep_libbe = compiler.find_library('be')
dep_libgame = compiler.find_library('game')
dep_libaccelerant = dependency('libaccelerant')
dep_libdrm0 = dependency('libdrm').partial_dependency(compile_args : true)

SADomainsProj = subproject('SADomains')
SADomains = SADomainsProj.get_variable('SADomains')

LocksProj = subproject('Locks')
Locks = LocksProj.get_variable('Locks')

ThreadLinkProj = subproject('ThreadLink')
ThreadLink = ThreadLinkProj.get_variable('ThreadLink')

#VideoStreamsProj = subproject('VideoStreams')
#VideoStreams = VideoStreamsProj.get_variable('VideoStreams')
VideoStreams = dependency('libvideostreams')


subdir('firmware')
subdir('radeon_gfx.accelerant')

executable('RadeonGfx',
	[
		'RadeonGfx.cpp',
		'RadeonDevice.cpp',
		'RadeonUnit.cpp',
		'RadeonTests.cpp',
		'RadeonInit.cpp',
		'RadeonInit2.cpp',
		'RadeonFirmware.cpp',
		'RadeonMemory.cpp',
		'Fence.cpp',
		'FenceGroup.cpp',
		'RingBuffer.cpp',
		'RadeonInterrupts.cpp',
		'Poke.cpp',
		'util/AVLTreeBase.cpp',
		'ExternalAllocator.cpp',
		'BitfieldAllocator.cpp',
		'FdObject.cpp',
		'TeamState.cpp',
		'CommandSubmission.cpp',
		'Syncobj.cpp',
		'RadeonServer.cpp',
		'RadeonPower.cpp',
		'Atombios.cpp',
		'drm/DrmInterface.cpp',
		'drm/RadeonServerDrm.cpp',
		'atombios/atom.cpp',
		'display/DisplayRoster.cpp',
		'display/DisplayTests.cpp',
		'display/CursorData.cpp',
		'display/DisplayConsumer.cpp',
		'display/RadeonServerDisplay.cpp',
		'Units/InstantiateUnits.cpp',
		'Units/DmaV1Unit.cpp',
		'Units/GfxV6Unit.cpp',
	],
	include_directories: [
		'headers',
		'drm',
		'atombios',
		'display',
		'kernel/radeon_gfx/headers/radeon_gfx',
		'/boot/system/develop/headers/private/shared',
		'/boot/system/develop/headers/private/graphics/common',
		'/boot/system/develop/headers/private/system',
		'/boot/system/develop/headers/private/system/arch/x86_64',
	],
	dependencies: [
		dep_libbe,
		dep_libgame,
		dep_libdrm0,
		Locks,
		SADomains,
		ThreadLink,
		VideoStreams
	],
	gnu_symbol_visibility: 'hidden',
	install : true
)
