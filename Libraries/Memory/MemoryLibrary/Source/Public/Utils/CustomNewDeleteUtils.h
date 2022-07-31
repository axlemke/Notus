#pragma once

#include "MemoryCommon.h"

namespace MemorySystem
{
	class Heap;
};

#if SKYFALL_CUSTOM_NEW

namespace MemorySystem
{
	MEMORY_USAGE void* CustomNew(size_t allocationSize, const char* heapName, const char* allocationName);
	MEMORY_USAGE void* CustomNew(size_t allocationSize, const char* heapName);
	MEMORY_USAGE void* CustomNew(size_t allocationSize, MemorySystem::Heap* heap, const char* allocationName);
	MEMORY_USAGE void* CustomNew(size_t allocationSize, MemorySystem::Heap* heap);
	MEMORY_USAGE void* CustomNew(size_t allocationSize);

	MEMORY_USAGE void CustomDelete(void* memory);
	MEMORY_USAGE void CustomDelete(void* memory, const char* heapName);
	MEMORY_USAGE void CustomDelete(void* memory, MemorySystem::Heap* heap);

	// In this case where the generic class type T is used as a parameter for CustomDeleteInPlace the compiler can automatically din out what data type it needs to instantiate for without having to explicitly specify it within angle brackets
	template <class T>
	void CustomDeleteInPlace(T* object, MemorySystem::Heap* heap)
	{
		object->~T();
		MemorySystem::CustomDelete(reinterpret_cast<void*>(object), heap);
	}

	template <class T>
	void CustomDeleteInPlace(T* object)
	{
		object->~T();
		MemorySystem::CustomDelete(reinterpret_cast<void*>(object));
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
	return MemorySystem::CustomNew(allocationSize, heapName, allocationName);
}

inline void* operator new(size_t allocationSize, const char* heapName)
{
	return MemorySystem::CustomNew(allocationSize, heapName);
}

inline void* operator new(size_t allocationSize, MemorySystem::Heap* heap, const char* allocationName)
{
	return MemorySystem::CustomNew(allocationSize, heap, allocationName);
}

inline void* operator new(size_t allocationSize, MemorySystem::Heap* heap)
{
	return MemorySystem::CustomNew(allocationSize, heap);
}

inline void* operator new(size_t allocationSize)
{
	return MemorySystem::CustomNew(allocationSize);
}

inline void* operator new[](size_t allocationSize, const char* heapName, const char* allocationName)
{
	return MemorySystem::CustomNew(allocationSize, heapName, allocationName);
}

inline void* operator new[](size_t allocationSize, const char* heapName)
{
	return MemorySystem::CustomNew(allocationSize, heapName);
}

inline void* operator new[](size_t allocationSize, MemorySystem::Heap* heap, const char* allocationName)
{
	return MemorySystem::CustomNew(allocationSize, heap, allocationName);
}

inline void* operator new[](size_t allocationSize, MemorySystem::Heap* heap)
{
	return MemorySystem::CustomNew(allocationSize, heap);
}

inline void* operator new[](size_t allocationSize)
{
	return MemorySystem::CustomNew(allocationSize);
}

inline void operator delete(void* memory)
{
	return MemorySystem::CustomDelete(memory);
}

inline void operator delete(void* memory, const char* heapName)
{
	return MemorySystem::CustomDelete(memory, heapName);
}

inline void operator delete(void* memory, MemorySystem::Heap* heap)
{
	return MemorySystem::CustomDelete(memory, heap);
}

inline void operator delete[](void* memory)
{
	return MemorySystem::CustomDelete(memory);
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
#define HaveBlueNew(type, heap) ::new (MemorySystem::CustomNew(sizeof(type), heap, #type) )
#define HaveBlueDelete(object) MemorySystem::CustomDeleteInPlace(object); object = nullptr
#define HaveBlueNewArray(type, elementCount, heap) reinterpret_cast<type*>(MemorySystem::CustomNew(sizeof(type) * elementCount, heap, #type))
#define HaveBlueDeleteArray(object) MemorySystem::CustomDelete(reinterpret_cast<void*>(object)); object = nullptr
#else
#define HaveBlueNew(type, heap) ::new (MemorySystem::CustomNew(sizeof(type), heap) )
#define HaveBlueDelete(object) object->~type(); MemorySystem::CustomDelete(reinterpret_cast<void*>(object)); object = nullptr
#define HaveBlueNewArray(type, elementCount, heap) reinterpret_cast<type*>(MemorySystem::CustomNew(sizeof(type) * elementCount, heap))
#define HaveBlueDeleteArray(object) MemorySystem::CustomDelete(reinterpret_cast<void*>(object)); object = nullptr
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

#endif // SKYFALL_CUSTOM_NEW