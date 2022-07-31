//#include "MemoryCommon.h"
//#include "Heaps/HeapManager.h"
//#include "Heaps/Heap.h"
//#include "Libraries/Framework/LibraryShell/Source/Public/CustomAssert.h"
//#include <new>
//
//using namespace Memory;
//
//#if SKYFALL_CUSTOM_NEW
//
//#pragma region CustomNew
//
//void* Memory::CustomNew(size_t allocationSize)
//{
//	return operator new(allocationSize, HeapManager::GetDefaultHeap());
//}
//
//void* Memory::CustomNew(size_t allocationSize, const char* heapName, const char* allocationName)
//{
//	Heap* heap = Memory::HeapManager::FindHeap(heapName);
//	if (!heap)
//	{
//		heap = Memory::HeapManager::CreateHeap(heapName);
//	}
//	return Memory::CustomNew(allocationSize, heap, allocationName);
//}
//
//void* Memory::CustomNew(size_t allocationSize, const char* heapName)
//{
//	Heap* heap = Memory::HeapManager::FindHeap(heapName);
//	if (!heap)
//	{
//		heap = Memory::HeapManager::CreateHeap(heapName);
//	}
//	return Memory::CustomNew(allocationSize, heap);
//}
//
//void* Memory::CustomNew(size_t allocationSize, Memory::Heap* heap, const char* allocationName)
//{
//	HB_ASSERT(heap);
//	if (heap)
//	{
//		return heap->AddAllocation(allocationName, allocationSize);
//	}
//	return nullptr;
//}
//
//void* Memory::CustomNew(size_t allocationSize, Memory::Heap* heap)
//{
//	HB_ASSERT(heap);
//	if (heap)
//	{
//		return heap->AddAllocation(allocationSize);
//	}
//	return nullptr;
//}
//
//#pragma endregion CustomNew
//
//#pragma region CustomDelete
//
//void Memory::CustomDelete(void* memory)
//{
//	if (memory)
//	{
//		Memory::Heap::RemoveAllocation(memory);
//	}
//}
//
//void Memory::CustomDelete(void* memory, const char* heapName)
//{
//	if (memory)
//	{
//		Memory::Heap::RemoveAllocation(memory);
//	}
//}
//
//void Memory::CustomDelete(void* memory, Memory::Heap* heap)
//{
//	if (memory)
//	{
//		Memory::Heap::RemoveAllocation(memory);
//	}
//}
//
//#pragma endregion CustomDelete
//
//#endif // SKYFALL_CUSTOM_NEW
//
