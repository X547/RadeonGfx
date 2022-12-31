project('RadeonGfx', 'cpp',
	version : '0.1',
	default_options : ['warning_level=3', 'cpp_std=c++2a']
)

compiler = meson.get_compiler('cpp')

add_project_arguments('-Wno-narrowing', language: 'cpp')
add_project_arguments('-Wno-pedantic', language: 'cpp')
add_project_arguments('-Wno-missing-field-initializers', language: 'cpp')


SADomainsProj = subproject('SADomains')
SADomains = SADomainsProj.get_variable('SADomains')

LocksProj = subproject('Locks')
Locks = LocksProj.get_variable('Locks')

ThreadLinkProj = subproject('ThreadLink')
ThreadLink = ThreadLinkProj.get_variable('ThreadLink')

#VideoStreamsProj = subproject('VideoStreams')
#VideoStreams = VideoStreamsProj.get_variable('VideoStreams')
VideoStreams = dependency('libvideostreams')


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
		'/boot/system/develop/headers/libdrm',
	],
	dependencies: [
		compiler.find_library('be'),
		compiler.find_library('game'),
		Locks,
		SADomains,
		ThreadLink,
		VideoStreams
	],
	gnu_symbol_visibility: 'hidden',
	install : true
)
