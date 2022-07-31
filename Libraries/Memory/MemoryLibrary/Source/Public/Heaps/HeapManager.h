#pragma once

#include <string>
#include "MemoryCommon.h"

class StringId;

namespace MemorySystem
{ 
	class FixedHeap;
	class Heap;

	constexpr UINT32 k_highWaterMark = 65535;

	constexpr unsigned long k_maxHeaps = 512;
	constexpr unsigned long k_maxFixedHeaps = 512;

	class HeapManager
	{
	public:
		MEMORY_USAGE static void Initialize();
		MEMORY_USAGE static void Deinitialize();
		
		MEMORY_USAGE static Heap* CreateHeap(const char* name);
		MEMORY_USAGE static FixedHeap* CreateFixedHeap(const char* name, UINT64 minimumBlockSize);

		MEMORY_USAGE static Heap* GetDefaultHeap();

		MEMORY_USAGE static void SetSelectedHeap(const char* name);
		MEMORY_USAGE static Heap* GetSelectedHeap();

		MEMORY_USAGE static Heap* FindHeap(const char* name);
		MEMORY_USAGE static FixedHeap* FindFixedHeap(const char* name);

		MEMORY_USAGE static Heap* GetHeapByIndex(unsigned long index);

		MEMORY_USAGE static unsigned long GetMaxHeapCount();


		MEMORY_USAGE static bool IsInitialized();
		MEMORY_USAGE static void ReportMemoryLeaks(UINT64 lowMark = 0, UINT64 highMark = k_highWaterMark);

	private:
		static Heap* CreateNewHeap(const char* name);
		static Heap* CreateNewHeap(const StringId& name);

		static Heap* s_defaultHeap;
		static Heap* s_selectedHeap;
		static Heap s_heaps[k_maxHeaps];

		static FixedHeap s_fixedHeaps[k_maxFixedHeaps];

		static bool s_initialized;
	};
}
