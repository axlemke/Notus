#include "Utils/CustomNewDeleteUtils.h"

#include "MemoryCommon.h"
#include "Heaps/HeapManager.h"
#include "Heaps/Heap.h"
#include "Libraries/Framework/LibraryShell/Source/Public/CustomAssert.h"
#include <new>

using namespace MemorySystem;

#if SKYFALL_CUSTOM_NEW

#pragma region CustomNew

void* MemorySystem::CustomNew(size_t allocationSize)
{
	return operator new(allocationSize, HeapManager::GetDefaultHeap());
}

void* MemorySystem::CustomNew(size_t allocationSize, const char* heapName, const char* allocationName)
{
	Heap* heap = MemorySystem::HeapManager::FindHeap(heapName);
	if (!heap)
	{
		heap = MemorySystem::HeapManager::CreateHeap(heapName);
	}
	return MemorySystem::CustomNew(allocationSize, heap, allocationName);
}

void* MemorySystem::CustomNew(size_t allocationSize, const char* heapName)
{
	Heap* heap = MemorySystem::HeapManager::FindHeap(heapName);
	if (!heap)
	{
		heap = MemorySystem::HeapManager::CreateHeap(heapName);
	}
	return MemorySystem::CustomNew(allocationSize, heap);
}

void* MemorySystem::CustomNew(size_t allocationSize, MemorySystem::Heap* heap, const char* allocationName)
{
	HB_ASSERT(heap);
	if (heap)
	{
		return heap->AddAllocation(allocationName, allocationSize);
	}
	return nullptr;
}

void* MemorySystem::CustomNew(size_t allocationSize, MemorySystem::Heap* heap)
{
	HB_ASSERT(heap);
	if (heap)
	{
		return heap->AddAllocation(allocationSize);
	}
	return nullptr;
}

#pragma endregion CustomNew

#pragma region CustomDelete

void MemorySystem::CustomDelete(void* memory)
{
	if (memory)
	{
		MemorySystem::Heap::RemoveAllocation(memory);
	}
}

void MemorySystem::CustomDelete(void* memory, const char* heapName)
{
	if (memory)
	{
		MemorySystem::Heap::RemoveAllocation(memory);
	}
}

void MemorySystem::CustomDelete(void* memory, MemorySystem::Heap* heap)
{
	if (memory)
	{
		MemorySystem::Heap::RemoveAllocation(memory);
	}
}

#pragma endregion CustomDelete

#endif // SKYFALL_CUSTOM_NEW

