#pragma once

#include "Libraries/Systems/StringHashLibrary/Source/Public/StringHashCommon.h"

#include <unordered_map>
#include <vector>
#include <bitset>
#include <string>
#include <utility>

// We use separate #define incase we ever want to enable in release/final or debugging
#if !defined(FINAL)
#define DEBUG_STRINGID
#endif

// We use constexpr constructors to make this a literal type and have it process at compile time

using StringIdHashType = unsigned long;

class StringId
{
private:
	constexpr unsigned long ComputeStringHash(const char* text) const
	{
		StringIdHashType hash = 0;

		while (*text)
		{
			hash += *text;
			hash += (hash << 10);
			hash ^= (hash >> 6);

			++text;
		}

		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);

		return hash;
	}

public:
	STRING_HASH_USAGE constexpr StringId()
		: m_hash(UINT_MAX)
#if defined(DEBUG_STRINGID)
		, m_string("INVALID")
#endif
	{
	}

	STRING_HASH_USAGE constexpr StringId(const char* text)
		: m_hash(ComputeStringHash(text))
#if defined(DEBUG_STRINGID)
		, m_string(text)
#endif
	{
	}

	STRING_HASH_USAGE constexpr StringId(std::string& text)
		: StringId(text.c_str())
	{
	}

	STRING_HASH_USAGE constexpr StringId(unsigned long hash)
		: m_hash(hash)
#if defined(DEBUG_STRINGID)
		, m_string("ONLY HASH WAS PROVIDED!")
#endif
	{
	}

	STRING_HASH_USAGE void operator=(const char* text);
	STRING_HASH_USAGE void operator=(const StringId& rhs);

	STRING_HASH_USAGE bool IsValid() const;
	STRING_HASH_USAGE bool IsInvalid() const;
	STRING_HASH_USAGE StringIdHashType GetHash() const;
	STRING_HASH_USAGE const char* GetText() const;

	STRING_HASH_USAGE bool operator==(const StringId& rhs) const;
	STRING_HASH_USAGE bool operator!=(const StringId& rhs) const;
	STRING_HASH_USAGE bool operator()(const StringId& lhs, const StringId& rhs) const;

private:
#if defined(DEBUG_STRINGID)
	const char* m_string;
#endif

	StringIdHashType m_hash;
};

struct StringIdKeyHash 
{
	std::size_t operator()(const StringId& lhs) const
	{
		return static_cast<std::size_t>(lhs.GetHash());
	}
};

struct StringIdKeyEqual 
{
public:
	bool operator()(const StringId& lhs, const StringId& rhs) const
	{
		return (lhs == rhs);
	}
};

#define StringIdMap(type) std::unordered_map<StringId, type, StringIdKeyHash, StringIdKeyEqual>
