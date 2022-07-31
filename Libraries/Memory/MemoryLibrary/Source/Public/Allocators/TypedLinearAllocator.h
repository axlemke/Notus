#pragma once

#include "Allocators/LinearAllocator.h"
#include "MemoryCommon.h"

template<typename TemplatedDataType>
class TypedLinearAllocator : public LinearAllocator
{
public:
	TemplatedDataType* Allocate()
	{
		unsigned int* data = Allocate(sizeof(TemplatedDataType));
		if (data)
		{
			return reinterpret_cast<TemplatedDataType*>(data);
		}
		return nullptr;
	}

	TemplatedDataType* AllocateArray(unsigned long numberOfElements)
	{
		unsigned int* data = Allocate(sizeof(TemplatedDataType) * numberOfElements);
		if (data)
		{
			return reinterpret_cast<TemplatedDataType*>(data);
		}
		return nullptr;
	}

	TemplatedDataType* GetData()
	{
		return reinterpret_cast<TemplatedDataType*>(m_data);
	}

	const TemplatedDataType* GetData() const
	{
		return reinterpret_cast<const TemplatedDataType*>(m_data);
	}
};
