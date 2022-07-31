#include "Pointers/SharedPointer.h"

using namespace MemorySystem;

ReferenceCounter::ReferenceCounter()
	: m_count(0)
{
}

ReferenceCounter::ReferenceCounter(unsigned int count)
	: m_count(count)
{
}

ReferenceCounter::ReferenceCounter(const ReferenceCounter& rhs) 
	: m_count(rhs.m_count)
{
}

unsigned int ReferenceCounter::GetCount() const
{
	return m_count;
}

void ReferenceCounter::AddReference()
{
	m_count++;
}

unsigned int ReferenceCounter::ReleaseReference()
{
	if (m_count)
	{
		m_count--;
	}
	return m_count;
}
