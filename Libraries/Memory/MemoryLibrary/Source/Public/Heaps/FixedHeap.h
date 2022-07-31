#pragma once

#include "MemoryCommon.h"

#include "Heaps/HeapInterface.h"
#include <stack>
#include <string>
#include <vector>

namespace Memory
{
	class AllocationHeader;

	class FixedHeap : public HeapInterface
	{
	public:
		friend class HeapManager;

		MEMORY_USAGE virtual ~FixedHeap();

		MEMORY_USAGE void* AddAllocation(UINT64 allocationSize);
		MEMORY_USAGE void* AddAllocation(const char* allocationName, UINT64 allocationSize);

		MEMORY_USAGE static void RemoveAllocation(void* memory);

		MEMORY_USAGE virtual bool IsFixed() const;

		MEMORY_USAGE int ReportMemoryLeaks(UINT64 lowMark = 0, UINT64 highMark = 65535) const;

	private:
		FixedHeap();
		FixedHeap(UINT64 maxSize);
		void Deallocate(AllocationHeader* header);
		virtual void Initialize();
		virtual void Deinitialize();

		AllocationHeader* m_lastAllocation;

		UINT64 m_maxSize;
	};
}
