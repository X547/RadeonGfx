#pragma once

#include "RingBuffer.h"

struct amdgpu_device;


void InitGoldenRegisters();
status_t PreinitGfxRings();
status_t InitCP();
status_t InitGpu(amdgpu_device *dev);
status_t InitMC();
status_t FiniMC();
status_t ResetMC();
status_t InitRlc();
