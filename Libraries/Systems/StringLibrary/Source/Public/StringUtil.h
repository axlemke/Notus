#pragma once

#include "Libraries/Framework/LibraryShell/Source/Public/CustomAssert.h"
#include "Libraries/Systems/StringLibrary/Source/Public/StringCommon.h"

namespace StringUtil
{
	STRING_USAGE void Swap(char& lhs, char& rhs);

	STRING_USAGE void Reverse(char* text);
	STRING_USAGE void Reverse(char* text, unsigned long length);

	STRING_USAGE bool IsPalindrome(const char* text, unsigned long length);

	template<typename FloatingPointNumberType>
	void ConvertStringToFloatingPointNumber(const char* text, FloatingPointNumberType& value)
	{
		HB_ASSERT(text != nullptr);
		value = static_cast<FloatingPointNumberType>(atof(text));
	}

	template<typename IntegerNumberType>
	void ConvertStringToIntegerPointNumber(const char* text, IntegerNumberType& value)
	{
		HB_ASSERT(text != nullptr);
		value = static_cast<IntegerNumberType>(atoll(text));
	}
}
