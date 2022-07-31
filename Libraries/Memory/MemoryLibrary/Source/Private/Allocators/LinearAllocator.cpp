#include "Allocators/LinearAllocator.h"

LinearAllocator::LinearAllocator()
	: m_data(nullptr)
	, m_currentOffset(0)
	, m_maxSize(0)
{
}

LinearAllocator::LinearAllocator(unsigned int* data, unsigned long size)
	: m_data(data)
	, m_currentOffset(0)
	, m_maxSize(size)
{
}

LinearAllocator::~LinearAllocator()
{
}

unsigned int* LinearAllocator::Allocate(unsigned long allocationSize)
{
	if ((m_currentOffset + allocationSize) < m_maxSize)
	{
		unsigned int* returnValue = m_data + m_currentOffset;

		// Adjust offset
		m_currentOffset += allocationSize;

		return returnValue;
	}
	return nullptr;
}

void LinearAllocator::Reset()
{
	m_currentOffset = 0;
}

unsigned long LinearAllocator::GetCurrentOffset() const
{
	return m_currentOffset;
}

unsigned long LinearAllocator::GetMaxSize() const
{
	return m_maxSize;
}

unsigned int* LinearAllocator::GetData()
{
	return m_data;
}

const unsigned int* LinearAllocator::GetData() const
{
	return m_data;
}
