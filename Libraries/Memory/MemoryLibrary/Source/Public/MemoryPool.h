#pragma once

#include "MemoryCommon.h"

namespace Memory
{
	class MemoryPool
	{
	public:
		MEMORY_USAGE MemoryPool(unsigned int poolSize);
		MEMORY_USAGE ~MemoryPool();

		//void* Alloc(unsigned int size);
		//void Free(void* memory, unsigned int size);
	};
};