#pragma once

typedef unsigned __int64    UINT64;

#define SUPPORT_ALLOCATION_TYPE 1
#define SUPPORT_ALLOCATION_NAME 1


namespace Memory
{
	class Heap;

	class AllocationHeader
	{
	public:
		AllocationHeader();
		
		bool operator==(const AllocationHeader& rhs) const;
		bool operator!=(const AllocationHeader& rhs) const;

		const char* GetAllocationTypeName() const;
		void SetAllocationTypeName(const char* allocationName);
		void ResetAllocationTypeName();

		template<typename TemplatedData>
		TemplatedData* GetDataAs()
		{
			return reinterpret_cast<TemplatedData*>(m_data);
		}

		template<typename TemplatedData>
		void SetData(TemplatedData* data)
		{
			m_data = reinterpret_cast<char*>(data);
		}

		char* m_data;
		AllocationHeader* m_next;
		AllocationHeader* m_previous;

		UINT64 m_size;
		UINT64 m_allocationNumber;

#if defined(SUPPORT_ALLOCATION_TYPE) && SUPPORT_ALLOCATION_TYPE
		static constexpr unsigned long k_maxTypeNameLength = 128;
		char m_typeName[k_maxTypeNameLength];
#endif

//#if defined(SUPPORT_ALLOCATION_TYPE) && SUPPORT_ALLOCATION_TYPE
//		static constexpr long k_maxAllocationNameLength = 128;
//		char m_allocationName[k_maxAllocationNameLength];
//#endif
	};

	const AllocationHeader* OffsetToAllocationHeader(const void* memory);
	AllocationHeader* OffsetToAllocationHeader(void* memory);
};

