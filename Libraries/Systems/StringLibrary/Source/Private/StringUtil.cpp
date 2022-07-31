#include "StringUtil.h"

#include <Memory/MemoryLibrary/Source/Public/Utils/MemcpyUtils.h>

void StringUtil::Swap(char& lhs, char& rhs)
{
	char scratch = lhs;
	lhs = rhs;
	rhs = scratch;
}

void StringUtil::Reverse(char* text)
{
	char* end = text;
	char temp;

	if (text)
	{
		// Find the end of the string
		while (*end)
		{
			++end;
		}
		--end; // Move back one character for the end

		// Swap characters from the start of the string with the end of the string until the pointer meets the middle
		while (text < end)
		{
			temp = *text;
			*text++;
			*end-- = temp;
		}
	}
}

void StringUtil::Reverse(char* text, unsigned long length)
{
	if (text && (length > 0))
	{
		// Swap the start and end characters going until we hit the middle
		for (unsigned long i = 0; i < length / 2; ++i)
		{
			StringUtil::Swap(text[i], text[length - i - 1]);
		}
	}
}

bool StringUtil::IsPalindrome(const char* text, unsigned long length)
{
	if (text && (length > 0))
	{
		for (unsigned long i = 0; i < length / 2; ++i)
		{
			if (text[i] != text[length - i - 1])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
