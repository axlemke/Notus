#pragma once

#include <string>
#include "MemoryCommon.h"

#include "Heaps/HeapInterface.h"

namespace MemorySystem
{ 
	class AllocationHeader;

	class Heap : public HeapInterface
	{
	public:
		friend class HeapManager;
		
		MEMORY_USAGE virtual ~Heap();

		MEMORY_USAGE void* AddAllocation(UINT64 allocationSize);
		MEMORY_USAGE void* AddAllocation(const char* allocationName, UINT64 allocationSize);

		MEMORY_USAGE static void RemoveAllocation(void* memory);

		MEMORY_USAGE virtual bool IsFixed() const;

		MEMORY_USAGE int ReportMemoryLeaks(UINT64 lowMark = 0, UINT64 highMark = 65535) const;

	private:
		Heap();
		virtual void Deallocate(AllocationHeader* header);
		virtual void Initialize();
		void Deinitialize();

		AllocationHeader* m_lastAllocation;
	};
}
