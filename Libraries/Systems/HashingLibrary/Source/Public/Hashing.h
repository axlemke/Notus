#pragma once

#include "Systems/HashingLibrary/Source/Public/HashingCommon.h"
#include <functional>

namespace Hashing
{
	//template <class T>
	//inline void HashCombine(std::size_t& seed, const T& v)
	//{
	//	std::hash<T> hasher;
	//	seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
	//}

	inline unsigned long HashCombine(unsigned long existingValue, unsigned long newValue)
	{
		std::hash<unsigned long> hasher;
		existingValue ^= hasher(newValue) + 0x9e3779b9 + (existingValue << 6) + (existingValue >> 2);
		return existingValue;
	}

	HASHING_USAGE unsigned long Morton3(unsigned long x, unsigned long y, unsigned long z);
	HASHING_USAGE unsigned long Part1By2(unsigned long x);
}
