#include "RadeonGfxAccelerant.h"

#include "../RadeonServer.h"
#include <ServerThreadLink.h>
#include <Messenger.h>
#include <kernel.h>
#define _DEFAULT_SOURCE
extern "C" {
#include <xf86drm.h>
#include <libdrm/drm.h>
#include <libdrm/amdgpu_drm.h>
}
#include <stdio.h>
#include <new>

#define CheckRet(err) {status_t _err = (err); if (_err < B_OK) return _err;}


RadeonGfxAccelerant::RadeonGfxAccelerant(int fd)
{
	fFd.SetTo(dup(fd));
	fcntl(fFd.Get(), F_SETFD, FD_CLOEXEC);
	fServerMsgr = BMessenger(RADEON_GFX_SERVER_SIGNATURE);
}

status_t RadeonGfxAccelerant::InitCheck()
{
	if (!fFd.IsSet() || !fServerMsgr.IsValid()) return B_ERROR;
	return B_OK;
}

void *RadeonGfxAccelerant::DrmMmap(void *addr, size_t length, int prot, int flags, off_t offset)
{
	(void)addr;
	(void)length;
	(void)prot;
	(void)flags;

	ClientThreadLink *threadLink = GetClientThreadLink(fServerMsgr);
	auto &link = threadLink->Link();
	link.StartMessage(radeonMmapMsg);
	link.Attach<int32>((int32)offset);
	int32 reply;
	link.FlushWithReply(reply);
	if (reply < B_OK) return NULL;
	area_id area;
	uint64 areaOfs;
	link.Read<int32>(&area);
	link.Read<uint64>(&areaOfs);

	area_info info;
	if (get_area_info(area, &info) < B_OK)
		return NULL;

	uint8* adr{};
	if (IS_KERNEL_ADDRESS(info.address) && (info.protection & (B_READ_AREA | B_WRITE_AREA)) != 0) {
		adr = (uint8*)info.address;
	} else {
		AreaDeleter mappedArea(clone_area("cloned buffer", (void**)&adr, B_ANY_ADDRESS, B_READ_AREA | B_WRITE_AREA | B_CLONEABLE_AREA, area));
		if (!mappedArea.IsSet()) return NULL;
		mappedArea.Detach();
	}

	return adr + areaOfs;
}

int RadeonGfxAccelerant::DrmIoctl(unsigned long request, void *arg)
{
	ClientThreadLink *threadLink = GetClientThreadLink(fServerMsgr);
	auto &link = threadLink->Link();
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach(request);
	unsigned long requestCmd = request%0x100;
	if (requestCmd >= DRM_COMMAND_BASE && requestCmd < DRM_COMMAND_END) {
		requestCmd -= DRM_COMMAND_BASE;
		switch (requestCmd) {
			case DRM_AMDGPU_INFO: {
				auto &args = *(struct drm_amdgpu_info*)arg;
				switch (args.query) {
					case AMDGPU_INFO_ACCEL_WORKING:
					case AMDGPU_INFO_VRAM_USAGE:
					case AMDGPU_INFO_GTT_USAGE:
					case AMDGPU_INFO_GDS_CONFIG:
					case AMDGPU_INFO_VRAM_GTT:
					case AMDGPU_INFO_DEV_INFO:
					case AMDGPU_INFO_VIS_VRAM_USAGE:
						link.Attach(args.return_size);
						link.Attach(args.query);
						// no input arguments
						break;
					case AMDGPU_INFO_READ_MMR_REG: {
						link.Attach(args.return_size);
						link.Attach(args.query);
						link.Attach(&args.read_mmr_reg, sizeof(args.read_mmr_reg));
						break;
					}
/*
					case AMDGPU_INFO_CRTC_FROM_ID:
					case AMDGPU_INFO_HW_IP_INFO:
					case AMDGPU_INFO_HW_IP_COUNT:
					case AMDGPU_INFO_TIMESTAMP:
					case AMDGPU_INFO_FW_VERSION:
					case AMDGPU_INFO_NUM_BYTES_MOVED:
					case AMDGPU_INFO_NUM_EVICTIONS:
					case AMDGPU_INFO_MEMORY:
					case AMDGPU_INFO_VCE_CLOCK_TABLE:
					case AMDGPU_INFO_VBIOS:
					case AMDGPU_INFO_SENSOR:
					case AMDGPU_INFO_NUM_VRAM_CPU_PAGE_FAULTS:
					case AMDGPU_INFO_VRAM_LOST_COUNTER:
					case AMDGPU_INFO_RAS_ENABLED_FEATURES:
					case AMDGPU_INFO_VIDEO_CAPS:
						break;
*/
					default:
						return ENOSYS;
				}
				status_t reply;
				link.FlushWithReply(reply);
				uint32 replySize;
				link.Read<uint32>(&replySize);
				link.Read((void*)(addr_t)args.return_pointer, replySize);
				return reply;
			}
			case DRM_AMDGPU_GEM_METADATA: {
				auto &args = *(struct drm_amdgpu_gem_metadata*)arg;
				switch (args.op) {
					case AMDGPU_GEM_METADATA_OP_SET_METADATA: {
						link.Attach(&args, sizeof(args));
						status_t reply;
						link.FlushWithReply(reply);
						return reply;
					}
					case AMDGPU_GEM_METADATA_OP_GET_METADATA: {
						link.Attach(&args, offsetof(struct drm_amdgpu_gem_metadata, data));
						status_t reply;
						link.FlushWithReply(reply);
						link.Read(&args.data, sizeof(args.data));
						return reply;
					}
				}
				break;
			}
			case DRM_AMDGPU_CTX: {
				auto &args = *(union drm_amdgpu_ctx*)arg;
				link.Attach(&args.in, sizeof(args.in));
				status_t reply;
				link.FlushWithReply(reply);
				link.Read(&args.out, sizeof(args.out));
				return reply;
			}
			case DRM_AMDGPU_GEM_CREATE: {
				auto &args = *(union drm_amdgpu_gem_create*)arg;
				link.Attach(&args.in, sizeof(args.in));
				status_t reply;
				link.FlushWithReply(reply);
				link.Read(&args.out, sizeof(args.out));
				return reply;
			}
			case DRM_AMDGPU_GEM_OP: {
				auto &args = *(struct drm_amdgpu_gem_op*)arg;
				switch (args.op) {
					case AMDGPU_GEM_OP_GET_GEM_CREATE_INFO: {
						auto boInfo = (struct drm_amdgpu_gem_create_in*)(uintptr_t)args.value;
						link.Attach(&args, offsetof(struct drm_amdgpu_gem_op, value));
						status_t reply;
						link.FlushWithReply(reply);
						link.Read(boInfo, sizeof(*boInfo));
						return reply;
					}
					default:
						return ENOSYS;
				}
			}
			case DRM_AMDGPU_GEM_USERPTR: {
				auto &args = *(struct drm_amdgpu_gem_userptr*)arg;
				area_id area = area_for((void*)(addr_t)args.addr);
				if (area < B_OK) return B_ERROR;
				area_info info;
				if (get_area_info(area, &info) < B_OK) return B_ERROR;
				args.addr -= (addr_t)info.address;
				args.handle = area;
				link.Attach(&args, sizeof(args));
				status_t reply;
				link.FlushWithReply(reply);
				link.Read(&args.handle, sizeof(args.handle));
				return reply;
			}
			case DRM_AMDGPU_GEM_VA: {
				auto &args = *(struct drm_amdgpu_gem_va*)arg;
				link.Attach(&args, sizeof(args));
				status_t reply;
				link.FlushWithReply(reply);
				return reply;
			}
			case DRM_AMDGPU_GEM_MMAP: {
				auto &args = *(union drm_amdgpu_gem_mmap*)arg;
				link.Attach(&args.in, sizeof(args.in));
				status_t reply;
				link.FlushWithReply(reply);
				link.Read(&args.out, sizeof(args.out));
				return reply;
			}
			case DRM_AMDGPU_CS: {
				auto &args = *(union drm_amdgpu_cs*)arg;
				link.Attach(&args.in, sizeof(args.in));
				for (size_t i = 0; i < args.in.num_chunks; i++) {
					struct drm_amdgpu_cs_chunk *chunk = (struct drm_amdgpu_cs_chunk*)(((uint64_t*)args.in.chunks)[i]);
					link.Attach(chunk, sizeof(struct drm_amdgpu_cs_chunk));
				}
				for (size_t i = 0; i < args.in.num_chunks; i++) {
					struct drm_amdgpu_cs_chunk *chunk = (struct drm_amdgpu_cs_chunk*)(((uint64_t*)args.in.chunks)[i]);
					switch(chunk->chunk_id) {
						case AMDGPU_CHUNK_ID_IB:
						case AMDGPU_CHUNK_ID_FENCE:
						case AMDGPU_CHUNK_ID_DEPENDENCIES:
						case AMDGPU_CHUNK_ID_SYNCOBJ_IN:
						case AMDGPU_CHUNK_ID_SYNCOBJ_OUT:
						case AMDGPU_CHUNK_ID_SYNCOBJ_TIMELINE_WAIT:
						case AMDGPU_CHUNK_ID_SYNCOBJ_TIMELINE_SIGNAL:
						{
							link.Attach((void*)chunk->chunk_data, 4*chunk->length_dw);
							break;
						}
						case AMDGPU_CHUNK_ID_BO_HANDLES: {
							auto chunk_data_handles = (drm_amdgpu_bo_list_in*)chunk->chunk_data;
							link.Attach(chunk_data_handles, sizeof(struct drm_amdgpu_bo_list_in));
							link.Attach((void*)chunk_data_handles->bo_info_ptr, chunk_data_handles->bo_info_size*chunk_data_handles->bo_number);
							break;
						}
					}
				}
				status_t reply;
				link.FlushWithReply(reply);
				link.Read(&args.out, sizeof(args.out));
				return reply;
			}
			case DRM_AMDGPU_WAIT_CS: {
				auto &args = *(union drm_amdgpu_wait_cs*)arg;
				link.Attach(&args.in, sizeof(args.in));
				status_t reply;
				link.FlushWithReply(reply);
				link.Read(&args.out, sizeof(args.out));
				return reply;
			}
		}
	}
	switch (request) {
		case DRM_IOCTL_GEM_CLOSE: {
			auto &args = *(struct drm_gem_close*)arg;
			link.Attach(&args, sizeof(args));
			status_t reply;
			link.FlushWithReply(reply);
			return reply;
		}
		case DRM_IOCTL_PRIME_HANDLE_TO_FD: {
			auto &args = *(struct drm_prime_handle*)arg;
			link.Attach(&args.handle, sizeof(args.handle));
			status_t reply;
			link.FlushWithReply(reply);
			link.Read(&args.fd, sizeof(args.fd));
			return reply;
		}
		case DRM_IOCTL_PRIME_FD_TO_HANDLE: {
			auto &args = *(struct drm_prime_handle*)arg;
			link.Attach(&args.fd, sizeof(args.fd));
			status_t reply;
			link.FlushWithReply(reply);
			link.Read(&args.handle, sizeof(args.handle));
			return reply;
		}

		// syncobj
		case DRM_IOCTL_SYNCOBJ_CREATE: {
			auto &args = *(struct drm_syncobj_create*)arg;
			link.Attach(&args.flags, sizeof(args.flags));
			status_t reply;
			link.FlushWithReply(reply);
			link.Read(&args.handle, sizeof(args.handle));
			return reply;
		}
		case DRM_IOCTL_SYNCOBJ_DESTROY: {
			auto &args = *(struct drm_syncobj_destroy*)arg;
			link.Attach(&args, sizeof(args));
			status_t reply;
			link.FlushWithReply(reply);
			return reply;
		}
		case DRM_IOCTL_SYNCOBJ_HANDLE_TO_FD: {
			auto &args = *(struct drm_syncobj_handle*)arg;
			link.Attach(&args.handle, sizeof(args.handle));
			status_t reply;
			link.FlushWithReply(reply);
			link.Read(&args.fd, sizeof(args.fd));
			return reply;
		}
		case DRM_IOCTL_SYNCOBJ_FD_TO_HANDLE: {
			auto &args = *(struct drm_syncobj_handle*)arg;
			link.Attach(&args.fd, sizeof(args.fd));
			status_t reply;
			link.FlushWithReply(reply);
			link.Read(&args.handle, sizeof(args.handle));
			return reply;
		}
		case DRM_IOCTL_SYNCOBJ_WAIT: {
			auto &args = *(struct drm_syncobj_wait*)arg;
			uint32_t *handles = (uint32_t*)args.handles;
			link.Attach(&args, offsetof(drm_syncobj_wait, first_signaled));
			link.Attach(handles, sizeof(uint32_t)*args.count_handles);
			status_t reply;
			link.FlushWithReply(reply);
			link.Read(&args.first_signaled, sizeof(args.first_signaled));
			return reply;
		}
		case DRM_IOCTL_SYNCOBJ_TIMELINE_WAIT: {
			auto &args = *(struct drm_syncobj_timeline_wait*)arg;
			uint32_t *handles = (uint32_t*)args.handles;
			uint64_t *points = (uint64_t*)args.points;
			link.Attach(&args, offsetof(drm_syncobj_timeline_wait, first_signaled));
			link.Attach(handles, sizeof(uint32_t)*args.count_handles);
			link.Attach(points, sizeof(uint64_t)*args.count_handles);
			status_t reply;
			link.FlushWithReply(reply);
			link.Read(&args.first_signaled, sizeof(args.first_signaled));
			return reply;
		}
		case DRM_IOCTL_SYNCOBJ_TRANSFER: {
			auto &args = *(struct drm_syncobj_transfer*)arg;
			link.Attach(&args, sizeof(args));
			status_t reply;
			link.FlushWithReply(reply);
			return reply;
		}
		case DRM_IOCTL_SYNCOBJ_RESET: {
			auto &args = *(struct drm_syncobj_array*)arg;
			uint32_t *handles = (uint32_t*)args.handles;
			link.Attach(&args.count_handles, sizeof(args.count_handles));
			link.Attach(handles, sizeof(uint32_t)*args.count_handles);
			status_t reply;
			link.FlushWithReply(reply);
			return reply;
		}
		case DRM_IOCTL_SYNCOBJ_ACCUMULATE: {
			auto &args = *(struct drm_syncobj_accumulate*)arg;
			link.Attach(&args, sizeof(args));
			status_t reply;
			link.FlushWithReply(reply);
			return reply;
		}
	}
	return ENOSYS;
}


status_t RadeonGfxAccelerant::DisplayGetConsumer(int32 crtc, BMessenger &consumer)
{
	ClientThreadLink *threadLink = GetClientThreadLink(fServerMsgr);
	auto &link = threadLink->Link();
	link.StartMessage(radeonGetDisplayConsumer);
	link.Attach(crtc);
	status_t reply;
	link.FlushWithReply(reply);
	link.Read(&consumer);
	return reply;
}

status_t RadeonGfxAccelerant::DisplayUpdateCursor(int32 crtc, const CursorUpdateInfo &info)
{
	ClientThreadLink *threadLink = GetClientThreadLink(fServerMsgr);
	auto &link = threadLink->Link();
	link.StartMessage(radeonUpdateCursor);
	link.Attach(crtc);
	link.Attach(info.valid.val);
	if (info.valid.enabled) {
		link.Attach(info.enabled);
	}
	if (info.valid.pos) {
		link.Attach(info.x);
		link.Attach(info.y);
	}
	if (info.valid.org) {
		link.Attach(info.orgX);
		link.Attach(info.orgY);
	}
	if (info.valid.format) {
		link.Attach(info.bytesPerRow);
		link.Attach(info.width);
		link.Attach(info.height);
		link.Attach<int32>(info.colorSpace);
	}
	if (info.valid.format) {
		size_t size = info.bytesPerRow*info.height;
		link.Attach(info.buffer, size);
	}
	status_t reply;
	link.FlushWithReply(reply);
	return reply;
}


status_t instantiate_accelerant(Accelerant **outAcc, int fd)
{
	ObjectDeleter<RadeonGfxAccelerant> acc(new(std::nothrow) RadeonGfxAccelerant(fd));
	if (!acc.IsSet()) return B_NO_MEMORY;
	CheckRet(acc->InitCheck());
	*outAcc = acc.Detach();
	return B_OK;
}
