#include "Heaps/AllocationHeader.h"

#include "Utils/MemcpyUtils.h"
#include <algorithm>
#include <cstring>

using namespace Memory;

const AllocationHeader* Memory::OffsetToAllocationHeader(const void* memory)
{
	// Need to back up to the allocation header
	return reinterpret_cast<const AllocationHeader*>(static_cast<const char*>(memory) - sizeof(AllocationHeader));
}

AllocationHeader* Memory::OffsetToAllocationHeader(void* memory)
{
	// Need to back up to the allocation header
	return reinterpret_cast<AllocationHeader*>(static_cast<char*>(memory) - sizeof(AllocationHeader));
}

AllocationHeader::AllocationHeader()
	: m_size(0)
	, m_allocationNumber(0)
	, m_data(nullptr)
	, m_next(nullptr)
	, m_previous(nullptr)
{
	ResetAllocationTypeName();
}

bool AllocationHeader::operator==(const AllocationHeader& rhs) const
{
	if ((m_allocationNumber == rhs.m_allocationNumber) && (m_allocationNumber != 0))
	{
		return true;
	}
	return false;
}

bool AllocationHeader::operator!=(const AllocationHeader& rhs) const
{
	return !operator==(rhs);
}

const char* AllocationHeader::GetAllocationTypeName() const
{
#if defined(SUPPORT_ALLOCATION_TYPE) && SUPPORT_ALLOCATION_TYPE
	return m_typeName;
#else
	return nullptr;
#endif
}

void AllocationHeader::SetAllocationTypeName(const char* allocationName)
{
#if defined(SUPPORT_ALLOCATION_TYPE) && SUPPORT_ALLOCATION_TYPE
	if (allocationName)
	{
		size_t allocationNameLength = std::strlen(allocationName);
		size_t size = std::min<size_t>(static_cast<const size_t>(k_maxTypeNameLength - 1), allocationNameLength);
		Memory::Memcpy(m_typeName, allocationName, size);
		m_typeName[allocationNameLength] = '\0';
	}
#endif
}

void AllocationHeader::ResetAllocationTypeName()
{
#if defined(SUPPORT_ALLOCATION_TYPE) && SUPPORT_ALLOCATION_TYPE
	m_typeName[0] = '\0';
#endif
}
