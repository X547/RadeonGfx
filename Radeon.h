#pragma once

#include "RadeonDevice.h"
#include <radeon_gfx.h>

#define RADEON_MM_DATA                      0x0004
#define RADEON_MM_INDEX                     0x0000

#define CheckRet(err) {status_t _err = (err); if (_err < B_OK) return _err;}

template <typename T>
constexpr T RoundDown(T a, T b) {return ((a / b) * b);}
template <typename T>
constexpr T RoundUp(T a, T b) {return RoundDown(a + b - 1, b);}


inline uint32 ReadReg4(uint32 reg)
{
	return *(vuint32*)(gDevice.Regs() + reg);
}

inline uint64 ReadReg8LoHi(uint32 regLo, uint32 regHi)
{
	return
		*(vuint32*)(gDevice.Regs() + regLo) +
		(((uint64)(*(vuint32*)(gDevice.Regs() + regHi))) << 32)
	;
}

inline void WriteReg4(uint32 reg, uint32 val)
{
	*(vuint32*)(gDevice.Regs() + reg) = val;
}

inline void WriteReg8LoHi(uint32 regLo, uint32 regHi, uint64 val)
{
	*(vuint32*)(gDevice.Regs() + regLo) = (uint32)val;
	*(vuint32*)(gDevice.Regs() + regHi) = (uint32)(val >> 32);
}

inline void WriteRegIdx4(uint32 reg, uint32 val)
{
	// should be locked
	WriteReg4(RADEON_MM_INDEX, reg);
	WriteReg4(RADEON_MM_DATA, val);
}

inline void WriteReg4Mask(uint32 reg, uint32 val, uint32 mask)
{
	uint32 tmp = ReadReg4(reg);
	tmp &= mask;
	tmp |= (val & ~mask);
	WriteReg4(reg, tmp);
}

inline void WriteReg4Set(uint32 reg, uint32 bits)
{
	WriteReg4Mask(reg, bits, ~bits);
}

inline void WriteReg4Clear(uint32 reg, uint32 bits)
{
	WriteReg4Mask(reg, 0, ~bits);
}


//#pragma mark -

inline uint32 ReadReg4AmdGpu(uint32 reg) {return ReadReg4(4*reg);}
inline uint64 ReadReg8LoHiAmdGpu(uint32 regLo, uint32 regHi) {return ReadReg8LoHi(4*regLo, 4*regHi);}
inline void WriteReg4AmdGpu(uint32 reg, uint32 val) {WriteReg4(4*reg, val);}
inline void WriteReg8LoHiAmdGpu(uint32 regLo, uint32 regHi, uint64 val) {WriteReg8LoHi(4*regLo, 4*regHi, val);}
inline void WriteReg4MaskAmdGpu(uint32 reg, uint32 val, uint32 mask) {WriteReg4Mask(4*reg, val, mask);}
