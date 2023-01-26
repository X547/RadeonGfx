#include "RadeonGfxAccelerant.h"

#include "../RadeonServer.h"
#include <Messenger.h>
#define _DEFAULT_SOURCE
extern "C" {
#include <xf86drm.h>
#include <libdrm/drm.h>
#include <libdrm/amdgpu_drm.h>
#include <libdrm/amdgpu.h>
}
#include <stdio.h>
#include <string.h>
#include <new>

//#define CheckRet(err) {status_t _err = (err); if (_err < B_OK) return _err;}

#define CheckRet(err) { \
	status_t _err = (err); \
	if (_err < B_OK) { \
		fprintf(stderr, "[!] %s:%d: error %#x (%s)\n", __FILE__, __LINE__, _err, strerror(_err)); \
		return _err; \
	} \
} \


RadeonGfxAccelerant::RadeonGfxAccelerant(int fd)
{
	fFd.SetTo(dup(fd));
	fcntl(fFd.Get(), F_SETFD, FD_CLOEXEC);
	fConn.SetMessenger(BMessenger(RADEON_GFX_SERVER_SIGNATURE));
}

status_t RadeonGfxAccelerant::InitCheck()
{
	if (!fFd.IsSet() || !fConn.Messenger().IsValid()) return B_ERROR;
	return B_OK;
}

void *RadeonGfxAccelerant::QueryInterface(const char *iface, uint32 version)
{
	if (strcmp(iface, B_ACCELERANT_IFACE_DRM) == 0 && version <= 0) {
		return static_cast<AccelerantDrm*>(this);
	}
	if (strcmp(iface, B_ACCELERANT_IFACE_AMDGPU) == 0 && version <= 0) {
		return static_cast<AccelerantAmdgpu*>(this);
	}
#if 0
	if (strcmp(iface, B_ACCELERANT_IFACE_DISPLAY) == 0 && version <= 0) {
		return static_cast<AccelerantDisplay*>(this);
	}
#endif
	return Accelerant::QueryInterface(iface, version);
}


// #pragma mark - DRM

void *RadeonGfxAccelerant::DrmMmap(void *addr, size_t length, int prot, int flags, off_t offset)
{
	(void)addr;
	(void)length;
	(void)prot;
	(void)flags;

	ThreadLinkHolder link(fConn);
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
	if (info.team == B_SYSTEM_TEAM && (info.protection & (B_READ_AREA | B_WRITE_AREA)) != 0) {
		adr = (uint8*)info.address;
	} else {
		AreaDeleter mappedArea(clone_area("cloned buffer", (void**)&adr, B_ANY_ADDRESS, B_READ_AREA | B_WRITE_AREA | B_CLONEABLE_AREA, area));
		if (!mappedArea.IsSet()) return NULL;
		mappedArea.Detach();
	}

	return adr + areaOfs;
}

int RadeonGfxAccelerant::DrmIoctl(uint32 request, void *arg)
{
	(void)request;
	(void)arg;
	return ENOSYS;
}


int RadeonGfxAccelerant::DrmVersion(struct drm_version *version)
{
	const char *name = "amdgpu";
	const char *date = "20150101";
	const char *desc = "AMD GPU";
	version->version_major = 3;
	version->version_minor = 42;
	version->version_patchlevel = 0;
	version->name_len = strlen(name);
	if (version->name != NULL) strcpy(version->name, name);
	version->date_len = strlen(date);
	if (version->date != NULL) strcpy(version->date, date);
	version->desc_len = strlen(desc);
	if (version->desc != NULL) strcpy(version->desc, desc);
	return B_OK;
}


int RadeonGfxAccelerant::DrmCloseBufferHandle(uint32_t handle)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_IOCTL_GEM_CLOSE);
	link.Attach<uint32_t>(handle);
	link.Attach<uint32_t>(0); // pad
	status_t reply;
	link.FlushWithReply(reply);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::DrmPrimeHandleToFD(uint32_t handle, uint32_t flags, int *prime_fd)
{
	(void)flags;
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_IOCTL_PRIME_HANDLE_TO_FD);
	link.Attach<uint32_t>(handle);
	status_t reply;
	link.FlushWithReply(reply);
	link.Read(prime_fd);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::DrmPrimeFDToHandle(int prime_fd, uint32_t *handle)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_IOCTL_PRIME_FD_TO_HANDLE);
	link.Attach<int>(prime_fd);
	status_t reply;
	link.FlushWithReply(reply);
	link.Read(handle);
	CheckRet(reply);
	return B_OK;
}


int RadeonGfxAccelerant::DrmSyncobjCreate(uint32_t flags, uint32_t *handle)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_IOCTL_SYNCOBJ_CREATE);
	link.Attach<uint32_t>(flags);
	status_t reply;
	link.FlushWithReply(reply);
	link.Read(handle);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjDestroy(uint32_t handle)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_IOCTL_SYNCOBJ_DESTROY);
	drm_syncobj_destroy args {.handle = handle};
	link.Attach(args);
	status_t reply;
	link.FlushWithReply(reply);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjHandleToFD(uint32_t handle, int *obj_fd)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_IOCTL_SYNCOBJ_HANDLE_TO_FD);
	link.Attach<uint32_t>(handle);
	status_t reply;
	link.FlushWithReply(reply);
	link.Read(obj_fd);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjFDToHandle(int obj_fd, uint32_t *handle)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_IOCTL_SYNCOBJ_FD_TO_HANDLE);
	link.Attach<int>(obj_fd);
	status_t reply;
	link.FlushWithReply(reply);
	link.Read(handle);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjImportSyncFile(uint32_t handle, int sync_file_fd)
{
	(void)handle;
	(void)sync_file_fd;
	CheckRet(ENOSYS);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjExportSyncFile(uint32_t handle, int *sync_file_fd)
{
	(void)handle;
	(void)sync_file_fd;
	CheckRet(ENOSYS);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjWait(uint32_t *handles, unsigned num_handles, int64_t timeout_nsec, unsigned flags, uint32_t *first_signaled)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_IOCTL_SYNCOBJ_WAIT);
	link.Attach<uint64_t>(0);
	link.Attach<uint64_t>(timeout_nsec);
	link.Attach<uint32_t>(num_handles);
	link.Attach<uint32_t>(flags);
	link.Attach(handles, sizeof(uint32_t)*num_handles);
	status_t reply;
	link.FlushWithReply(reply);
	link.Read(first_signaled);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjReset(const uint32_t *handles, uint32_t handle_count)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_IOCTL_SYNCOBJ_RESET);
	link.Attach<uint32_t>(handle_count);
	link.Attach(handles, sizeof(uint32_t)*handle_count);
	status_t reply;
	link.FlushWithReply(reply);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjSignal(const uint32_t *handles, uint32_t handle_count)
{
	(void)handles;
	(void)handle_count;
	CheckRet(ENOSYS);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjTimelineSignal(const uint32_t *handles, uint64_t *points, uint32_t handle_count)
{
	(void)handles;
	(void)points;
	(void)handle_count;
	CheckRet(ENOSYS);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjTimelineWait(uint32_t *handles, uint64_t *points, unsigned num_handles, int64_t timeout_nsec, unsigned flags, uint32_t *first_signaled)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_IOCTL_SYNCOBJ_TIMELINE_WAIT);
	link.Attach<uint64_t>(0); // handles
	link.Attach<uint64_t>(0); // points
	link.Attach<uint64_t>(timeout_nsec);
	link.Attach<uint32_t>(num_handles);
	link.Attach<uint32_t>(flags);
	link.Attach(handles, sizeof(uint32_t)*num_handles);
	link.Attach(points, sizeof(uint64_t)*num_handles);
	status_t reply;
	link.FlushWithReply(reply);
	link.Read(first_signaled);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjQuery(uint32_t *handles, uint64_t *points, uint32_t handle_count, uint32_t flags)
{
	(void)handles;
	(void)points;
	(void)handle_count;
	(void)flags;
	CheckRet(ENOSYS);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjTransfer(uint32_t dst_handle, uint64_t dst_point, uint32_t src_handle, uint64_t src_point, uint32_t flags)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_IOCTL_SYNCOBJ_TRANSFER);
	link.Attach<uint32_t>(src_handle);
	link.Attach<uint32_t>(dst_handle);
	link.Attach<uint64_t>(src_point);
	link.Attach<uint64_t>(dst_point);
	link.Attach<uint32_t>(flags);
	link.Attach<uint64_t>(0); // pad
	status_t reply;
	link.FlushWithReply(reply);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::DrmSyncobjAccumulate(uint32_t syncobj1, uint32_t syncobj2, uint64_t point)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_IOCTL_SYNCOBJ_ACCUMULATE);
	link.Attach<uint32_t>(syncobj1);
	link.Attach<uint32_t>(syncobj2);
	link.Attach<uint64_t>(point);
	status_t reply;
	link.FlushWithReply(reply);
	CheckRet(reply);
	return B_OK;
}


// #pragma mark - AMDGPU

int RadeonGfxAccelerant::AmdgpuQueryInfo(struct drm_amdgpu_info *info)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_COMMAND_BASE + DRM_AMDGPU_INFO);
	link.Attach(info->return_size);
	link.Attach(info->query);
	switch (info->query) {
		case AMDGPU_INFO_ACCEL_WORKING:
		case AMDGPU_INFO_VRAM_USAGE:
		case AMDGPU_INFO_GTT_USAGE:
		case AMDGPU_INFO_GDS_CONFIG:
		case AMDGPU_INFO_VRAM_GTT:
		case AMDGPU_INFO_DEV_INFO:
		case AMDGPU_INFO_VIS_VRAM_USAGE:
		case AMDGPU_INFO_MEMORY:
		case AMDGPU_INFO_TIMESTAMP:
		case AMDGPU_INFO_NUM_BYTES_MOVED:
		case AMDGPU_INFO_NUM_EVICTIONS:
		case AMDGPU_INFO_VCE_CLOCK_TABLE:
		case AMDGPU_INFO_NUM_VRAM_CPU_PAGE_FAULTS:
		case AMDGPU_INFO_VRAM_LOST_COUNTER:
		case AMDGPU_INFO_RAS_ENABLED_FEATURES:
			// no input arguments
			break;
		case AMDGPU_INFO_CRTC_FROM_ID:
			link.Attach(info->mode_crtc);
			break;
		case AMDGPU_INFO_HW_IP_INFO:
		case AMDGPU_INFO_HW_IP_COUNT:
			link.Attach(info->query_hw_ip);
			break;
		case AMDGPU_INFO_READ_MMR_REG:
			link.Attach(info->read_mmr_reg);
			break;
		case AMDGPU_INFO_FW_VERSION:
			link.Attach(info->query_fw);
			break;
		case AMDGPU_INFO_VBIOS:
			link.Attach(info->vbios_info);
			break;
		case AMDGPU_INFO_SENSOR:
			link.Attach(info->sensor_info);
			break;
		case AMDGPU_INFO_VIDEO_CAPS:
			link.Attach(info->video_cap);
			break;
		default:
			fprintf(stderr, "RadeonGfxAccelerant::AmdgpuQueryInfo: unknown info->query: %" PRIu32 "\n", info->query);
			CheckRet(ENOSYS);
	}
	status_t reply;
	link.FlushWithReply(reply);
	uint32 replySize;
	link.Read(&replySize);
	link.Read((void*)(addr_t)info->return_pointer, replySize);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::AmdgpuBoAlloc(struct amdgpu_bo_alloc_request *alloc_buffer, uint32_t *buf_handle)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_COMMAND_BASE + DRM_AMDGPU_GEM_CREATE);
	link.Attach<uint64_t>(alloc_buffer->alloc_size);
	link.Attach<uint64_t>(alloc_buffer->phys_alignment);
	link.Attach<uint64_t>(alloc_buffer->preferred_heap);
	link.Attach<uint64_t>(alloc_buffer->flags);
	status_t reply;
	link.FlushWithReply(reply);
	link.Read(buf_handle);
	uint32_t pad;
	link.Read(&pad);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::AmdgpuCreateBoFromUserMem(void *cpu, uint64_t size, uint32_t *buf_handle)
{
	ThreadLinkHolder link(fConn);

	area_id area = area_for(cpu);
	CheckRet(area);
	area_info info;
	CheckRet(get_area_info(area, &info));

	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_COMMAND_BASE + DRM_AMDGPU_GEM_USERPTR);

	link.Attach<uint64_t>((addr_t)cpu - (addr_t)info.address);
	link.Attach<uint64_t>(size);
	link.Attach<uint32_t>(0); // flags
	link.Attach<uint32_t>(area);
	status_t reply;
	link.FlushWithReply(reply);
	link.Read(buf_handle);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::AmdgpuBoQueryInfo(uint32_t bo, struct amdgpu_bo_info *info)
{
	ThreadLinkHolder link(fConn);
	struct drm_amdgpu_gem_metadata metadata {};
	struct drm_amdgpu_gem_create_in bo_info {};
	status_t reply;

	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_COMMAND_BASE + DRM_AMDGPU_GEM_METADATA);
	link.Attach<uint32_t>(bo);
	link.Attach<uint32_t>(AMDGPU_GEM_METADATA_OP_GET_METADATA);
	link.FlushWithReply(reply);
	link.Read(&metadata.data);
	CheckRet(reply);

	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_COMMAND_BASE + DRM_AMDGPU_GEM_OP);
	link.Attach<uint32_t>(bo);
	link.Attach<uint32_t>(AMDGPU_GEM_OP_GET_GEM_CREATE_INFO);
	link.FlushWithReply(reply);
	link.Read(&bo_info);

	memset(info, 0, sizeof(*info));
	info->alloc_size = bo_info.bo_size;
	info->phys_alignment = bo_info.alignment;
	info->preferred_heap = bo_info.domains;
	info->alloc_flags = bo_info.domain_flags;
	info->metadata.flags = metadata.data.flags;
	info->metadata.tiling_info = metadata.data.tiling_info;

	info->metadata.size_metadata = metadata.data.data_size_bytes;
	memcpy(info->metadata.umd_metadata, metadata.data.data, metadata.data.data_size_bytes);

	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::AmdgpuBoSetMetadata(uint32_t bo, struct amdgpu_bo_metadata *info)
{
	ThreadLinkHolder link(fConn);
	struct drm_amdgpu_gem_metadata args {};

	args.handle = bo;
	args.op = AMDGPU_GEM_METADATA_OP_SET_METADATA;
	args.data.flags = info->flags;
	args.data.tiling_info = info->tiling_info;

	if (info->size_metadata > sizeof(args.data.data))
		return EINVAL;

	args.data.data_size_bytes = info->size_metadata;
	memcpy(args.data.data, info->umd_metadata, info->size_metadata);

	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_COMMAND_BASE + DRM_AMDGPU_GEM_METADATA);
	link.Attach(args);
	status_t reply;
	link.FlushWithReply(reply);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::AmdgpuBoVaOpRaw(uint32_t bo, uint64_t offset, uint64_t size, uint64_t addr, uint64_t flags, uint32_t ops)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_COMMAND_BASE + DRM_AMDGPU_GEM_VA);
	link.Attach<uint32_t>(bo);
	link.Attach<uint32_t>(0); // pad
	link.Attach<uint32_t>(ops);
	link.Attach<uint32_t>(flags);
	link.Attach<uint64_t>(addr);
	link.Attach<uint64_t>(offset);
	link.Attach<uint64_t>(size);
	status_t reply;
	link.FlushWithReply(reply);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::AmdgpuBoCpuMap(uint32_t bo, void **cpu)
{
	void *adr = DrmMmap(NULL, 0, 0, 0, (off_t)bo);
	if (adr == NULL) return B_ERROR;
	*cpu = adr;
	return B_OK;
}

int RadeonGfxAccelerant::AmdgpuCsSubmitRaw(uint32_t context_id, uint32_t bo_list_handle, int num_chunks, struct drm_amdgpu_cs_chunk *chunks, uint64_t *seq_no)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_COMMAND_BASE + DRM_AMDGPU_CS);
	link.Attach<uint32_t>(context_id);
	link.Attach<uint32_t>(bo_list_handle);
	link.Attach<uint32_t>(num_chunks);
	link.Attach<uint32_t>(0); // flags
	link.Attach<uint64_t>(0); // chunks
	for (int i = 0; i < num_chunks; i++) {
		link.Attach(chunks[i]);
	}
	for (int i = 0; i < num_chunks; i++) {
		auto &chunk = chunks[i];
		switch(chunk.chunk_id) {
			case AMDGPU_CHUNK_ID_IB:
			case AMDGPU_CHUNK_ID_FENCE:
			case AMDGPU_CHUNK_ID_DEPENDENCIES:
			case AMDGPU_CHUNK_ID_SYNCOBJ_IN:
			case AMDGPU_CHUNK_ID_SYNCOBJ_OUT:
			case AMDGPU_CHUNK_ID_SYNCOBJ_TIMELINE_WAIT:
			case AMDGPU_CHUNK_ID_SYNCOBJ_TIMELINE_SIGNAL: {
				link.Attach((void*)chunk.chunk_data, 4*chunk.length_dw);
				break;
			}
			case AMDGPU_CHUNK_ID_BO_HANDLES: {
				auto &chunk_data_handles = *(drm_amdgpu_bo_list_in*)chunk.chunk_data;
				link.Attach(chunk_data_handles);
				link.Attach((void*)chunk_data_handles.bo_info_ptr, chunk_data_handles.bo_info_size*chunk_data_handles.bo_number);
				break;
			}
		}
	}
	status_t reply;
	link.FlushWithReply(reply);
	link.Read(seq_no);
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::AmdgpuWaitCs(uint32_t ctx_id, unsigned ip, unsigned ip_instance, uint32_t ring, uint64_t handle, uint64_t timeout_ns, bool *busy)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonIoctlMsg);
	link.Attach<int>(fFd.Get());
	link.Attach<uint32_t>(DRM_COMMAND_BASE + DRM_AMDGPU_WAIT_CS);
	link.Attach<uint64_t>(handle);
	link.Attach<uint64_t>(timeout_ns);
	link.Attach<uint32_t>(ip);
	link.Attach<uint32_t>(ip_instance);
	link.Attach<uint32_t>(ring);
	link.Attach<uint32_t>(ctx_id);
	status_t reply;
	link.FlushWithReply(reply);
	uint64_t status;
	link.Read(&status);
	*busy = status != 0;
	CheckRet(reply);
	return B_OK;
}

int RadeonGfxAccelerant::AmdgpuCtxRaw(union drm_amdgpu_ctx *args)
{
	switch (args->in.op) {
		case AMDGPU_CTX_OP_ALLOC_CTX: {
			static uint32_t newCtx = 1;
			args->out.alloc.ctx_id = newCtx++;
			return 0;
		}
		case AMDGPU_CTX_OP_FREE_CTX: {
			return 0;
		}
		case AMDGPU_CTX_OP_QUERY_STATE: {
			return 0;
		}
		case AMDGPU_CTX_OP_QUERY_STATE2: {
			return 0;
		}
		default:
			;
	}
	return EINVAL;
}


// #pragma mark - Display

status_t RadeonGfxAccelerant::DisplayGetConsumer(int32 crtc, BMessenger &consumer)
{
	ThreadLinkHolder link(fConn);
	link.StartMessage(radeonGetDisplayConsumer);
	link.Attach(crtc);
	status_t reply;
	link.FlushWithReply(reply);
	link.Read(&consumer);
	CheckRet(reply);
	return B_OK;
}

status_t RadeonGfxAccelerant::DisplayUpdateCursor(int32 crtc, const CursorUpdateInfo &info)
{
	ThreadLinkHolder link(fConn);
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
	CheckRet(reply);
	return B_OK;
}


// #pragma mark -

status_t instantiate_accelerant(Accelerant **outAcc, int fd)
{
	ObjectDeleter<RadeonGfxAccelerant> acc(new(std::nothrow) RadeonGfxAccelerant(fd));
	if (!acc.IsSet()) return B_NO_MEMORY;
	CheckRet(acc->InitCheck());
	*outAcc = acc.Detach();
	return B_OK;
}
