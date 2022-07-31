#pragma once

#include <string>
#include "MemoryCommon.h"

namespace Memory
{
	class AllocationHeader;

	class HeapInterface
	{
	public:
		friend class HeapManager;

		MEMORY_USAGE virtual ~HeapInterface();

		MEMORY_USAGE void Activate(const char* heapName);
		MEMORY_USAGE bool IsActive() const;
		MEMORY_USAGE const char* GetName() const;

		MEMORY_USAGE UINT64 GetBytesAllocated() const;
		MEMORY_USAGE bool HasActiveAllocations() const;
		MEMORY_USAGE UINT64 GetNumberOfActiveAllocations() const;
		MEMORY_USAGE UINT64 GetNumberOfTotalAllocations() const;
		MEMORY_USAGE UINT64 GetHighWatermark() const;

		MEMORY_USAGE bool RequiresMinimumBlockSize() const;
		MEMORY_USAGE UINT64 GetMinimumBlockSize() const;

		MEMORY_USAGE virtual bool IsFixed() const = 0;

	protected:
		HeapInterface();
		virtual void Initialize();
		virtual void Deinitialize();

		UINT64 AdjustAllocationSizeIfNeeded(UINT64 allocationSize) const;
		void SetMinimumBlockSize(UINT64 minimumBlockSize);

		static UINT64 s_currentAllocationNumber;

		const char* m_name;

		UINT64 m_activeAllocations;
		UINT64 m_totalAllocations;
		UINT64 m_bytesAllocated;
		UINT64 m_highWaterMark;
		UINT64 m_minBlockSize;
		bool m_active;
	};
}
