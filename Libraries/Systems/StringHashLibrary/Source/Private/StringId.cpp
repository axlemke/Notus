#include "Libraries/Systems/StringHashLibrary/Source/Public/StringId.h"
#include "Libraries/Framework/LibraryShell/Source/Public/CustomAssert.h"

//constexpr StringId::StringId()
//	: m_hash(UINT_MAX)
//#if defined(DEBUG_STRINGID)
//	, m_string("INVALID")
//#endif
//{
//}
//
//constexpr StringId::StringId(const char* text)
//	: m_hash(ComputeStringHash(text))
//#if defined(DEBUG_STRINGID)
//	, m_string(text)
//#endif
//{
//}
//
//constexpr StringId::StringId(unsigned long hash)
//	: m_hash(hash)
//#if defined(DEBUG_STRINGID)
//	, m_string("ONLY HASH WAS PROVIDED!")
//#endif
//{
//}

void StringId::operator=(const char* text)
{
	m_hash = ComputeStringHash(text);
#if defined(DEBUG_STRINGID)
	m_string = text;
#endif
}

void StringId::operator=(const StringId& rhs)
{
	m_hash = rhs.m_hash;
#if defined(DEBUG_STRINGID)
	m_string = rhs.m_string;
#endif
}

bool StringId::IsValid() const
{
	return (m_hash != UINT_MAX);
}

bool StringId::IsInvalid() const
{
	return !IsValid();
}

StringIdHashType StringId::GetHash() const
{
	return m_hash;
}

const char* StringId::GetText() const
{
#if defined(DEBUG_STRINGID)
	return m_string;
#else
	return nullptr;
#endif
}

bool StringId::operator==(const StringId& rhs) const
{
	return (m_hash == rhs.m_hash);
}

bool StringId::operator!=(const StringId& rhs) const
{
	return !(operator==(rhs));
}

bool StringId::operator()(const StringId& lhs, const StringId& rhs) const
{
	if (lhs.m_hash == rhs.m_hash)
	{
		return true;
	}
	return false;
}

