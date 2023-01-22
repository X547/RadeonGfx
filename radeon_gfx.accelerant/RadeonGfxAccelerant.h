#pragma once

#include "AccelerantRoster.h"
#include "AccelerantDrm.h"
#include "AccelerantAmdgpu.h"
#include "AccelerantDisplay.h"
#include <Messenger.h>
#include <AutoDeleterPosix.h>


class RadeonGfxAccelerant: public Accelerant, public AccelerantDrm, public AccelerantAmdgpu, public AccelerantDisplay {
private:
	FileDescriptorCloser fFd;
	BMessenger fServerMsgr;

public:
	RadeonGfxAccelerant(int fd);
	virtual ~RadeonGfxAccelerant() = default;
	status_t InitCheck();

	void *QueryInterface(const char *iface) final;

	/* DRM */
	void *DrmMmap(void *addr, size_t length, int prot, int flags, off_t offset) final;
	int DrmIoctl(unsigned long request, void *arg) final;

	int DrmVersion(struct drm_version *version) final;

	int DrmCloseBufferHandle(uint32_t handle) final;
	int DrmPrimeHandleToFD(uint32_t handle, uint32_t flags, int *prime_fd) final;
	int DrmPrimeFDToHandle(int prime_fd, uint32_t *handle) final;

	int DrmSyncobjCreate(uint32_t flags, uint32_t *handle) final;
	int DrmSyncobjDestroy(uint32_t handle) final;
	int DrmSyncobjHandleToFD(uint32_t handle, int *obj_fd) final;
	int DrmSyncobjFDToHandle(int obj_fd, uint32_t *handle) final;
	int DrmSyncobjImportSyncFile(uint32_t handle, int sync_file_fd) final;
	int DrmSyncobjExportSyncFile(uint32_t handle, int *sync_file_fd) final;
	int DrmSyncobjWait(uint32_t *handles, unsigned num_handles, int64_t timeout_nsec, unsigned flags, uint32_t *first_signaled) final;
	int DrmSyncobjReset(const uint32_t *handles, uint32_t handle_count) final;
	int DrmSyncobjSignal(const uint32_t *handles, uint32_t handle_count) final;
	int DrmSyncobjTimelineSignal(const uint32_t *handles, uint64_t *points, uint32_t handle_count) final;
	int DrmSyncobjTimelineWait(uint32_t *handles, uint64_t *points, unsigned num_handles, int64_t timeout_nsec, unsigned flags, uint32_t *first_signaled) final;
	int DrmSyncobjQuery(uint32_t *handles, uint64_t *points, uint32_t handle_count, uint32_t flags) final;
	int DrmSyncobjTransfer(uint32_t dst_handle, uint64_t dst_point, uint32_t src_handle, uint64_t src_point, uint32_t flags) final;
	int DrmSyncobjAccumulate(uint32_t syncobj1, uint32_t syncobj2, uint64_t point) final;

	/* AMDGPU */
	int AmdgpuQueryInfo(struct drm_amdgpu_info *info);
	int AmdgpuBoAlloc(struct amdgpu_bo_alloc_request *alloc_buffer, uint32_t *buf_handle);
	int AmdgpuCreateBoFromUserMem(void *cpu, uint64_t size, uint32_t *buf_handle);
	int AmdgpuBoQueryInfo(uint32_t bo, struct amdgpu_bo_info *info);
	int AmdgpuBoSetMetadata(uint32_t bo, struct amdgpu_bo_metadata *info);
	int AmdgpuBoVaOpRaw(uint32_t bo, uint64_t offset, uint64_t size, uint64_t addr, uint64_t flags, uint32_t ops);
	int AmdgpuBoCpuMap(uint32_t bo, void **cpu);
	int AmdgpuCsSubmitRaw(uint32_t context_id, uint32_t bo_list_handle, int num_chunks, struct drm_amdgpu_cs_chunk *chunks, uint64_t *seq_no);
	int AmdgpuWaitCs(uint32_t ctx_id, unsigned ip, unsigned ip_instance, uint32_t ring, uint64_t handle, uint64_t timeout_ns, bool *busy);
	int AmdgpuCtxRaw(union drm_amdgpu_ctx *args);

	/* Display */
	status_t DisplayGetConsumer(int32 crtc, BMessenger &consumer) final;
	status_t DisplayUpdateCursor(int32 crtc, const CursorUpdateInfo &info) final;
};
