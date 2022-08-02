#pragma once

#include <Framework/LibraryShell/Source/Public/CustomAssert.h>

namespace BitManipulation
{
	template<typename T>
	T LeftShift(T value, unsigned long amount)
	{
		return (value << amount);
	}

	template<typename T>
	T RightShift(T value, unsigned long amount)
	{
		return (value >> amount);
	}

	template<typename T>
	bool TestBit(T value, unsigned long bitIndex)
	{
		return (value >> bitIndex) & 1UL;
	}

	template<typename T>
	void MarkBit(T& value, unsigned long bitIndex)
	{
		value |= 1UL << bitIndex;
	}		

	template<typename T>
	void ClearBits(T& value, T& bitMask)
	{
		value &= bitMask;
	}

	template<typename T>
	void ClearBit(T& value, unsigned long bitIndex)
	{
		// ClearBits<T>(~(1UL << bitIndex));
		value &= ~(1UL << bitIndex);
	}

	template<typename T>
	void ToggleBit(T& value, unsigned long bitIndex)
	{
		value ^= 1UL << bitIndex;
	}

	template<typename T>
	void SetBit(T& value, unsigned long bitvalue, unsigned long bitIndex)
	{
		value = (value & ~(1UL << bitIndex)) | (bitvalue << bitIndex);
	}

	template<typename T>
	void ClearBitsThrough(T& value, unsigned long startingBitIndex, unsigned long endingBitIndex)
	{
		// Should assert they are within bounds?

		T allOnes = ~0;
			
		T leftSet = (allOnes << (endingBitIndex + startingBitIndex));

		T rightSet = ((1 << startingBitIndex) - 1);

		T bitMask = leftSet | rightSet;

		ClearBits<T>(value, bitMask);
	}

	template<typename T>
	T MultiplyByTwo(T value)
	{
		return LeftShift<T>(value, 1);
	}

	template<typename T>
	T DivideByTwo(T value)
	{
		return RightShift<T>(value, 1);
	}
}
