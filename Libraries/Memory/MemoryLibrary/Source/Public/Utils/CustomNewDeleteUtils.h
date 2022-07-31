#pragma once

#include "MemoryCommon.h"

namespace Memory
{
	class Heap;
};

#if MEMORY_CUSTOM_NEW

namespace Memory
{
	MEMORY_USAGE void* CustomNew(size_t allocationSize, const char* heapName, const char* allocationName);
	MEMORY_USAGE void* CustomNew(size_t allocationSize, const char* heapName);
	MEMORY_USAGE void* CustomNew(size_t allocationSize, Memory::Heap* heap, const char* allocationName);
	MEMORY_USAGE void* CustomNew(size_t allocationSize, Memory::Heap* heap);
	MEMORY_USAGE void* CustomNew(size_t allocationSize);

	MEMORY_USAGE void CustomDelete(void* memory);
	MEMORY_USAGE void CustomDelete(void* memory, const char* heapName);
	MEMORY_USAGE void CustomDelete(void* memory, Memory::Heap* heap);

	// In this case where the generic class type T is used as a parameter for CustomDeleteInPlace the compiler can automatically din out what data type it needs to instantiate for without having to explicitly specify it within angle brackets
	template <class T>
	void CustomDeleteInPlace(T* object, Memory::Heap* heap)
	{
		object->~T();
		Memory::CustomDelete(reinterpret_cast<void*>(object), heap);
	}

	template <class T>
	void CustomDeleteInPlace(T* object)
	{
		object->~T();
		Memory::CustomDelete(reinterpret_cast<void*>(object));
	}

	//MEMORY_USAGE void operator delete[](void* memory);


	//#define SkyfallCustomNew(y, x, ...) ::new (::operator new(sizeof(x), y) ) x(__VA_ARGS__)
	//template<typename T>
	//void* Allocate<T>(size_t allocationSize, const char* heapName)
	//{
	//	return sizeof(T), heapName;
	//}

};

#if OVERRIDE_NEW

#pragma warning(push)
#pragma warning(disable:4595) // Arg can't store the new/delete overloads in .cpp file since it's a dll and it will complain the definition is different.  And inlining complains with C4595, so just disable that for now

inline void* operator new(size_t allocationSize, const char* heapName, const char* allocationName)
{
	return Memory::CustomNew(allocationSize, heapName, allocationName);
}

inline void* operator new(size_t allocationSize, const char* heapName)
{
	return Memory::CustomNew(allocationSize, heapName);
}

inline void* operator new(size_t allocationSize, Memory::Heap* heap, const char* allocationName)
{
	return Memory::CustomNew(allocationSize, heap, allocationName);
}

inline void* operator new(size_t allocationSize, Memory::Heap* heap)
{
	return Memory::CustomNew(allocationSize, heap);
}

inline void* operator new(size_t allocationSize)
{
	return Memory::CustomNew(allocationSize);
}

inline void* operator new[](size_t allocationSize, const char* heapName, const char* allocationName)
{
	return Memory::CustomNew(allocationSize, heapName, allocationName);
}

inline void* operator new[](size_t allocationSize, const char* heapName)
{
	return Memory::CustomNew(allocationSize, heapName);
}

inline void* operator new[](size_t allocationSize, Memory::Heap* heap, const char* allocationName)
{
	return Memory::CustomNew(allocationSize, heap, allocationName);
}

inline void* operator new[](size_t allocationSize, Memory::Heap* heap)
{
	return Memory::CustomNew(allocationSize, heap);
}

inline void* operator new[](size_t allocationSize)
{
	return Memory::CustomNew(allocationSize);
}

inline void operator delete(void* memory)
{
	return Memory::CustomDelete(memory);
}

inline void operator delete(void* memory, const char* heapName)
{
	return Memory::CustomDelete(memory, heapName);
}

inline void operator delete(void* memory, Memory::Heap* heap)
{
	return Memory::CustomDelete(memory, heap);
}

inline void operator delete[](void* memory)
{
	return Memory::CustomDelete(memory);
}

//#pragma warning restore C4595
#pragma warning(pop)

#endif

//inline void* __cdecl operator new(size_t allocationSize) 



#if OVERRIDE_NEW

#if SUPPORTS_ALLOCATION_TYPENAME
#define HaveBlueNew(type, heap) ::new (::operator new(sizeof(type), heap, #type) )
//#define HaveBlueDelete(object) object->~type(); delete(object); object = nullptr
#define HaveBlueNewArray(type, elementCount, heap) reinterpret_cast<type*>(::operator new[](sizeof(type) * elementCount, heap, #type))
#define HaveBlueDeleteArray(object) delete[](object); object = nullptr
#else
#define HaveBlueNew(type, heap) ::new (::operator new(sizeof(type), heap) )
//#define HaveBlueDelete(object) object->~type(); delete(object); object = nullptr
#define HaveBlueNewArray(type, elementCount, heap) reinterpret_cast<type*>(::operator new[](sizeof(type) * elementCount, heap))
#define HaveBlueDeleteArray(object) delete[](object); object = nullptr
#endif

#else

#include "Utils/CustomNewDeleteUtils.h"

#if SUPPORTS_ALLOCATION_TYPENAME
#define HaveBlueNew(type, heap) ::new (Memory::CustomNew(sizeof(type), heap, #type) )
#define HaveBlueDelete(object) Memory::CustomDeleteInPlace(object); object = nullptr
#define HaveBlueNewArray(type, elementCount, heap) reinterpret_cast<type*>(Memory::CustomNew(sizeof(type) * elementCount, heap, #type))
#define HaveBlueDeleteArray(object) Memory::CustomDelete(reinterpret_cast<void*>(object)); object = nullptr
#else
#define HaveBlueNew(type, heap) ::new (Memory::CustomNew(sizeof(type), heap) )
#define HaveBlueDelete(object) object->~type(); Memory::CustomDelete(reinterpret_cast<void*>(object)); object = nullptr
#define HaveBlueNewArray(type, elementCount, heap) reinterpret_cast<type*>(Memory::CustomNew(sizeof(type) * elementCount, heap))
#define HaveBlueDeleteArray(object) Memory::CustomDelete(reinterpret_cast<void*>(object)); object = nullptr
#endif

#endif

////#define HaveBlueNewArray(type, heap, elementCount) reinterpret_cast<type*>(::operator new[](sizeof(type) * elementCount, heap))
//#define HaveBlueNewArray(type, elementCount, heap) reinterpret_cast<type*>(::operator new[](sizeof(type) * elementCount, heap))
//#define HaveBlueDeleteArray(object) delete[](object); object = nullptr

#else

#define HaveBlueNew(type, heap) new
#define HaveBlueDelete(object) object->~type(); delete(object); object = nullptr
#define HaveBlueNewArray(type, elementCount, heap) new type[elementCount]
#define HaveBlueDeleteArray(object) delete[](object); object = nullptr

#endif // MEMORY_CUSTOM_NEW