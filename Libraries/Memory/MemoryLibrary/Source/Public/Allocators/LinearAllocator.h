#pragma once

#include "MemoryCommon.h"

class LinearAllocator
{
public:
	MEMORY_USAGE LinearAllocator();
	MEMORY_USAGE LinearAllocator(unsigned int* data, unsigned long size);
	MEMORY_USAGE ~LinearAllocator();

	MEMORY_USAGE bool CanAllocate(unsigned long allocationSize) const;
	MEMORY_USAGE unsigned int* Allocate(unsigned long allocationSize);
	MEMORY_USAGE void Reset();

	MEMORY_USAGE unsigned long GetCurrentOffset() const;
	MEMORY_USAGE unsigned long GetMaxSize() const;

	MEMORY_USAGE unsigned int* GetData();
	MEMORY_USAGE const unsigned int* GetData() const;

private:
	unsigned int* m_data;
	unsigned long m_currentOffset;
	unsigned long m_maxSize;
};

