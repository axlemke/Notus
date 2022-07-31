#include "Heaps/FixedHeap.h"

#include "Libraries/Framework/LibraryShell/Source/Public/CustomAssert.h"
#include "Heaps/AllocationHeader.h"
#include "Heaps/HeapManager.h"

#include <cstddef>

using namespace MemorySystem;

constexpr UINT64 k_defaultFixedHeapMaxSize = 1024;

FixedHeap::FixedHeap()
	: FixedHeap(k_defaultFixedHeapMaxSize)
{
}

FixedHeap::FixedHeap(UINT64 maxSize)
	: HeapInterface()
	, m_lastAllocation(nullptr)
	, m_maxSize(maxSize)
{
}

FixedHeap::~FixedHeap()
{
}

void* FixedHeap::AddAllocation(UINT64 allocationSize)
{
	return nullptr;
}

void* FixedHeap::AddAllocation(const char* allocationName, UINT64 allocationSize)
{
	return nullptr;
}

void FixedHeap::RemoveAllocation(void* memory)
{
}

void FixedHeap::Deallocate(AllocationHeader* header)
{
}

bool FixedHeap::IsFixed() const
{
	return true;
}

int FixedHeap::ReportMemoryLeaks(UINT64 lowMark, UINT64 highMark) const
{
	return 0;
}

void FixedHeap::Initialize()
{
	m_lastAllocation = nullptr;

	HeapInterface::Initialize();
}

void FixedHeap::Deinitialize()
{
	HeapInterface::Deinitialize();
}
