#include "Heaps/HeapManager.h"

#include "Libraries/Framework/LibraryShell/Source/Public/CustomAssert.h"
#include "Heaps/FixedHeap.h"
#include "Heaps/Heap.h"

using namespace Memory;

Heap HeapManager::s_heaps[];
Heap* HeapManager::s_defaultHeap = nullptr;
Heap* HeapManager::s_selectedHeap = nullptr;

FixedHeap HeapManager::s_fixedHeaps[];

bool HeapManager::s_initialized = false;

Heap* HeapManager::GetDefaultHeap()
{
	if (!s_defaultHeap)
	{
		Initialize();
	}
	return s_defaultHeap;
}

Heap* HeapManager::GetSelectedHeap()
{
	return GetDefaultHeap();
}

void HeapManager::SetSelectedHeap(const char* name)
{
	Heap* heap = FindHeap(name);
	if (heap)  
	{
		s_selectedHeap = heap;
	}
}

Heap* HeapManager::CreateHeap(const char* name)
{
	Heap* heap = FindHeap(name);
	if (heap)
	{
		return heap;
	}

	for (unsigned int i = 0; i < k_maxHeaps; i++)
	{
		heap = &s_heaps[i];
		if(heap && (heap->IsActive() == false))
		{
			heap->Activate(name);
			return heap;
		}
	}
	return heap;
}


FixedHeap* HeapManager::CreateFixedHeap(const char* name, UINT64 minimumBlockSize)
{
	FixedHeap* heap = FindFixedHeap(name);
	if (heap)
	{
		HB_ASSERT(minimumBlockSize != heap->GetMinimumBlockSize());
		return heap;
	}

	for (unsigned int i = 0; i < k_maxHeaps; i++)
	{
		heap = &s_fixedHeaps[i];
		if (heap && (heap->IsActive() == false))
		{
			heap->SetMinimumBlockSize(minimumBlockSize);
			heap->Activate(name);
			return heap;
		}
	}
	return heap;
}

Heap* HeapManager::FindHeap(const char* name)
{
	for (unsigned int i = 0; i < k_maxHeaps; i++)
	{
		Heap* heap = &s_heaps[i];
		if (heap)
		{
			if (strcmp(name, heap->GetName()) == 0)
			{
				return heap;
			}
		}
	}
	return nullptr;
}

FixedHeap* HeapManager::FindFixedHeap(const char* name)
{
	for (unsigned int i = 0; i < k_maxFixedHeaps; i++)
	{
		FixedHeap* heap = &s_fixedHeaps[i];
		if (heap)
		{
			if (strcmp(name, heap->GetName()) == 0)
			{
				return heap;
			}
		}
	}
	return nullptr;
}

Heap* HeapManager::GetHeapByIndex(unsigned long index)
{
	if (index < k_maxHeaps)
	{
		return &s_heaps[index];
	}
	return nullptr;
}

unsigned long HeapManager::GetMaxHeapCount()
{
	return k_maxHeaps;
}

void HeapManager::Initialize()
{
	for (unsigned int i = 0; i < k_maxHeaps; i++)
	{
		s_heaps[i].Initialize();
	}

	if (!s_defaultHeap)
	{
		s_defaultHeap = CreateNewHeap("Default");
	}

	s_initialized = true;
}

void HeapManager::Deinitialize()
{
	for (unsigned int i = 0; i < k_maxHeaps; i++)
	{
		s_heaps[i].Deinitialize();
	}
	s_defaultHeap = nullptr;
	s_initialized = false;
}

bool HeapManager::IsInitialized()
{
	return s_initialized;
}

void HeapManager::ReportMemoryLeaks(UINT64 lowMark, UINT64 highMark)
{
	printf("\n");
	printf("***********************************************************\n");
	printf("Reporting Memory Leaks\n");
	printf("***********************************************************\n");
	printf("\n");

	for (unsigned int i = 0; i < k_maxHeaps; i++)
	{
		const Heap& heap = s_heaps[i];
		if (heap.IsActive())
		{
			heap.ReportMemoryLeaks(lowMark, highMark);
		}
	}
}

Heap* HeapManager::CreateNewHeap(const char* name)
{
	for (unsigned int i = 0; i < k_maxHeaps; ++i)
	{
		Heap* heap = &s_heaps[i];
		if (heap->IsActive() == false)
		{
			heap->Activate(name);
			return heap;
		}
	}
	return nullptr;
}

Heap* HeapManager::CreateNewHeap(const StringId& name)
{
	for (unsigned int i = 0; i < k_maxHeaps; ++i)
	{
		Heap* heap = &s_heaps[i];
		if (heap->IsActive() == false)
		{
			//heap->Activate(name);
			//return heap;
		}
	}
	return nullptr;
}