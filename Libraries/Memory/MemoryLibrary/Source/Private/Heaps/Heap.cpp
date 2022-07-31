#include "Heaps/Heap.h"

#include "Libraries/Framework/LibraryShell/Source/Public/CustomAssert.h"
#include "Heaps/AllocationHeader.h"
#include "Heaps/HeapManager.h"

#include <cstddef>

using namespace Memory;

Heap::Heap()
	: HeapInterface()
	, m_lastAllocation(nullptr)
{
}

Heap::~Heap()
{
}

void* Heap::AddAllocation(UINT64 allocationSize)
{
	HB_ASSERT(HeapManager::IsInitialized());

	// Need to request extra space so we can include the allocation header
	constexpr UINT64 k_allocationHeaderSize = sizeof(AllocationHeader);
	UINT64 requestedSize = allocationSize + k_allocationHeaderSize;
	
	// Adjust the allocation size if we have a minimum block size 
	requestedSize = AdjustAllocationSizeIfNeeded(requestedSize);

	char* memory = static_cast<char*>(malloc(requestedSize));
	HB_ASSERT(memory);

	if (memory == nullptr)
	{
		// We ran out of memory...
		HeapManager::ReportMemoryLeaks();
		return nullptr;
	}
	
	AllocationHeader* header = reinterpret_cast<AllocationHeader*>(memory);
	HB_ASSERT(header);
	header->SetData<Heap>(this);
	header->m_size = allocationSize;
	header->m_allocationNumber = ++s_currentAllocationNumber;
	
	// Used to walk the heap
	header->m_next = m_lastAllocation;
	header->m_previous = nullptr;

	header->ResetAllocationTypeName();

	if (m_lastAllocation)
	{
		m_lastAllocation->m_previous = header;
	}
	m_lastAllocation = header;

	// Keep track how many bytes we've asked for (excluding headers)
	m_bytesAllocated += allocationSize;

	// Keep track of the most bytes this heap ever used
	m_highWaterMark = max(m_highWaterMark, m_bytesAllocated);

	// Keep track of how many active allocations and how many times this heap allocates during it's lifetime
	m_activeAllocations++;
	m_totalAllocations++;

	void* startMemoryBlock = memory + k_allocationHeaderSize;
	return startMemoryBlock;
}

void* Heap::AddAllocation(const char* allocationName, UINT64 allocationSize)
{
	constexpr UINT64 k_allocationHeaderSize = sizeof(AllocationHeader);

	void* startMemoryBlock = AddAllocation(allocationSize);
	void* allocationHeaderAddress = static_cast<char*>(startMemoryBlock) - k_allocationHeaderSize;
	AllocationHeader* header = reinterpret_cast<AllocationHeader*>(allocationHeaderAddress);
	
	header->SetAllocationTypeName(allocationName);

	return startMemoryBlock;
}

void Heap::RemoveAllocation(void* memory)
{
	AllocationHeader* header = OffsetToAllocationHeader(memory);
	if (header && header->m_data)
	{
		header->GetDataAs<Heap>()->Deallocate(header);
	}
}

void Heap::Deallocate(AllocationHeader* header)
{
	HB_ASSERT(HeapManager::IsInitialized()); // If this is hit that likely means a smart pointer was released after we shutdown our memory tracking, that's bad!
	HB_ASSERT(header);
	HB_ASSERT(m_active);
	HB_ASSERT(m_activeAllocations > 0);

	if (header->m_previous == nullptr)
	{
		HB_ASSERT(header == m_lastAllocation);
		m_lastAllocation = header->m_next;
	}
	else
	{
		header->m_previous->m_next = header->m_next;
	}

	if (header->m_next)
	{
		header->m_next->m_previous = header->m_previous;
	}

	m_bytesAllocated -= header->m_size;
	m_activeAllocations--;
	free(header);
}

bool Heap::IsFixed() const
{
	return false;
}

int Heap::ReportMemoryLeaks(UINT64 lowMark, UINT64 highMark) const
{
	int numberOfLeaks = 0;
	const AllocationHeader* header = m_lastAllocation;

	UINT64 activeAllocations = GetNumberOfActiveAllocations();

	if (activeAllocations == 0)
	{
		//system("Color 0A");
	}
	else
	{
		//system("Color 0C");
	}

	printf("***********************************************************\n");
	printf("Heap: %s    Active Allocations: %I64u    Remaining Bytes Allocated: %I64u    Lifetime # of Allocations: %I64u    High Watermark: %I64u\n", GetName(), activeAllocations, GetBytesAllocated(), GetNumberOfTotalAllocations(), GetHighWatermark());
	printf("\n");

	while (header != nullptr)
	{
		if ((header->m_allocationNumber >= lowMark) && (header->m_allocationNumber < highMark))
		{
			const char* allocationTypeName = nullptr;
			if (header)
			{
				allocationTypeName = header->GetAllocationTypeName();
			}

			if (allocationTypeName)
			{
				printf("Allocation: %I64u, Size: %I64u, Address: %p Type: %s\n", header->m_allocationNumber, header->m_size, reinterpret_cast<const void*>(header + sizeof(AllocationHeader)), allocationTypeName);
			}
			else
			{
				printf("Allocation: %I64u, Size: %I64u, Address: %p\n", header->m_allocationNumber, header->m_size, reinterpret_cast<const void*>(header + sizeof(AllocationHeader)));
			}
			numberOfLeaks++;
		}
		header = header->m_next;
	}
	printf("\n");

	return numberOfLeaks;
}

void Heap::Initialize()
{
	m_lastAllocation = nullptr;

	HeapInterface::Initialize();
}

void Heap::Deinitialize()
{
	HeapInterface::Deinitialize();
}
