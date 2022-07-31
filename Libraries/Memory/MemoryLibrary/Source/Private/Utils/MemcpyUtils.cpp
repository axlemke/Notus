#include "Utils/MemcpyUtils.h"

#include "Libraries/Framework/LibraryShell/Source/Public/CustomAssert.h"

using namespace Memory;

void Memory::Memcpy(void* destination, const void* source, unsigned long size)
{
#if 0
	char* charDestination = reinterpret_cast<char*>(destination);
	const char* charSource = reinterpret_cast<const char*>(source);
	HB_ASSERT(charDestination != charSource);

	for (unsigned long i = 0; i < size; ++i)
	{
		charDestination[i] = charSource[i];
	}
#else
	memcpy(destination, source, static_cast<size_t>(size));
#endif
}

void Memory::Memmove(void* destination, const void* source, unsigned long size)
{
#if 0
	char* charDestination = reinterpret_cast<char*>(destination);
	const char* charSource = reinterpret_cast<const char*>(source);
	HB_ASSERT(charDestination != charSource);
#else
	memmove(destination, source, static_cast<size_t>(size));
#endif
}

void Memory::Memset(void* destination, int value, unsigned long size)
{
#if 0
#else
	memset(destination, value, static_cast<size_t>(size));
#endif
}

int Memory::Memcmp(const void* pointerA, const void* pointerB, unsigned long size)
{
#if 0
#else
	return memcmp(pointerA, pointerB, static_cast<size_t>(size));
#endif
}
