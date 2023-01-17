#pragma once

#include <stddef.h>
#include <stdint.h>


template <class T, class M>
static inline constexpr ptrdiff_t OffsetOf(const M T::*member)
{
	return reinterpret_cast<ptrdiff_t>(&(reinterpret_cast<T*>(0)->*member));
}

template <class T, class M>
static inline constexpr T& ContainerOf(M &ptr, const M T::*member)
{
	return *reinterpret_cast<T*>(reinterpret_cast<intptr_t>(&ptr) - OffsetOf(member));
}

template <typename Ptr, typename Deleter>
void FreeObjectPtr(Ptr &ptr, Deleter deleter)
{
	if (ptr != NULL) {
		deleter();
		ptr = NULL;
	}
}
