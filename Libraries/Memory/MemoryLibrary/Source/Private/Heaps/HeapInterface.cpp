#include "Heaps/HeapInterface.h"

#include "Libraries/Framework/LibraryShell/Source/Public/CustomAssert.h"
#include "Heaps/AllocationHeader.h"
#include "Heaps/HeapManager.h"

#include <cstddef>

using namespace MemorySystem;

UINT64 HeapInterface::s_currentAllocationNumber = 0;

HeapInterface::HeapInterface()
	: m_active(false)
	, m_name("INVALID_HEAP_NAME")
	, m_bytesAllocated(0)
	, m_activeAllocations(0)
	, m_totalAllocations(0)
	, m_highWaterMark(0)
	, m_minBlockSize(0)
{
}

HeapInterface::~HeapInterface()
{
}

void HeapInterface::Activate(const char* heapName)
{
	HB_ASSERT(heapName != nullptr);

	if (m_active == false)
	{
		m_name = heapName;
		m_active = true;
	}
}

bool HeapInterface::IsActive() const
{
	return m_active;
}

const char* HeapInterface::GetName() const
{
	return m_name;
}

UINT64 HeapInterface::GetBytesAllocated() const
{
	return m_bytesAllocated;
}

bool HeapInterface::HasActiveAllocations() const
{
	return (GetNumberOfActiveAllocations() != 0);
}

UINT64 HeapInterface::GetNumberOfActiveAllocations() const
{
	return m_activeAllocations;
}

UINT64 HeapInterface::GetNumberOfTotalAllocations() const
{
	return m_totalAllocations;
}

UINT64 HeapInterface::GetHighWatermark() const
{
	return m_highWaterMark;
}

bool HeapInterface::RequiresMinimumBlockSize() const
{
	return (m_minBlockSize != 0);
}

UINT64 HeapInterface::GetMinimumBlockSize() const
{
	return m_minBlockSize;
}

UINT64 HeapInterface::AdjustAllocationSizeIfNeeded(UINT64 allocationSize) const
{
	if (RequiresMinimumBlockSize())
	{
		UINT64 minimumBlockSize = GetMinimumBlockSize();
		UINT64 remainder = allocationSize % minimumBlockSize;
		if (remainder != 0)
		{
			return (allocationSize + minimumBlockSize - remainder);
		}
	}
	return allocationSize;
}

void HeapInterface::SetMinimumBlockSize(UINT64 minimumBlockSize)
{
	m_minBlockSize = minimumBlockSize;
}

void HeapInterface::Initialize()
{
	HB_ASSERT(m_active == false);

	if (m_active == false)
	{
		m_bytesAllocated = 0;
		m_activeAllocations = 0;
		m_totalAllocations = 0;
		m_highWaterMark = 0;
	}
}

void HeapInterface::Deinitialize()
{
	m_active = false;
}

