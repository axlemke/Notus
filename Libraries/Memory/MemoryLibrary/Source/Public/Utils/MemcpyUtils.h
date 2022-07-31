#pragma once

#include "MemoryCommon.h"

namespace Memory
{
	MEMORY_USAGE void Memcpy(void* destination, const void* source, unsigned long size);
	MEMORY_USAGE void Memmove(void* destination, const void* source, unsigned long size);
	MEMORY_USAGE void Memset(void* destination, int value, unsigned long size);
	MEMORY_USAGE int Memcmp(const void* pointerA, const void* pointerB, unsigned long size);
};
