#pragma once

#include "MemoryCommon.h"
#include "Libraries/Framework/LibraryShell/Source/Public/CustomAssert.h"

namespace MemorySystem
{
	class ReferenceCounter
	{
	public:
		MEMORY_USAGE ReferenceCounter();
		MEMORY_USAGE ReferenceCounter(unsigned int count);
		MEMORY_USAGE ReferenceCounter(const ReferenceCounter& rhs);
		MEMORY_USAGE unsigned int GetCount() const;
		MEMORY_USAGE void AddReference();
		MEMORY_USAGE unsigned int ReleaseReference();

	private:
		unsigned int m_count;
	};

	template<typename TemplatedClass> 
	class SharedPointer
	{
	public:
		SharedPointer() 
			: m_data(nullptr)
			, m_referenceCounter(nullptr)
		{
		}

		SharedPointer(TemplatedClass* pointer) 
			: m_data(pointer)
			, m_referenceCounter(nullptr)
		{
			CreateReferenceCounter();
		}

		SharedPointer(TemplatedClass* pointer, ReferenceCounter* referenceCounter) 
			: m_data(pointer)
			, m_referenceCounter(referenceCounter)
		{
			AddReference();
		}

		~SharedPointer()
		{
			Release();
		}

		SharedPointer(const SharedPointer<TemplatedClass>& rhs) 
			: m_data(rhs.m_data)
			, m_referenceCounter(rhs.m_referenceCounter)
		{
			AddReference();
		}

		TemplatedClass& operator*()
		{
			return *m_data;
		}

		TemplatedClass* operator->()
		{
			return m_data;
		}

		const TemplatedClass& operator*() const
		{
			return *m_data;
		}

		const TemplatedClass* operator->() const
		{
			return m_data;
		}

		//TemplatedClass** operator&() throw()
		//{
		//	return &mData;
		//}

		//const TemplatedClass** operator&() const throw()
		//{
		//	return &mData;
		//}

		bool IsValid() const
		{
			if (m_data)
			{
				return true;
			}
			return false;
		}

		bool IsInvalid() const
		{
			return !IsValid();
		}

		TemplatedClass* GetRawPointer()
		{
			return m_data;
		}

		const TemplatedClass* GetRawPointer() const
		{
			return m_data;
		}

		TemplatedClass& GetRawReference()
		{
			HB_ASSERT(m_data);
			return *m_data;
		}

		const TemplatedClass& GetRawReference() const
		{
			HB_ASSERT(m_data);
			return *m_data;
		}

		TemplatedClass** GetAddressOf()
		{
			return &m_data;
		}

		SharedPointer<TemplatedClass> &operator=(const SharedPointer<TemplatedClass>& rhs)
		{
			if (this != &rhs)
			{
				// Decrement the old reference count
				Release();

				// Copy the data and reference pointer
				// and increment the reference count
				m_data = rhs.m_data;
				m_referenceCounter = rhs.m_referenceCounter;
				AddReference();
			}
			return *this;
		}

		template<typename CastedTemplatedClass> 
		SharedPointer<CastedTemplatedClass> Cast()
		{
			SharedPointer<CastedTemplatedClass> castedSharedPointer(reinterpret_cast<CastedTemplatedClass*>(m_data), static_cast<ReferenceCounter*>(m_referenceCounter));
			return castedSharedPointer;
		}

		bool operator==(const SharedPointer<TemplatedClass>& rhs) const
		{
			return ((m_data != nullptr) && (rhs.m_data != nullptr) && (m_data == rhs.m_data));
		}

		bool operator!=(const SharedPointer<TemplatedClass>& rhs) const
		{
			return !operator==(rhs);
		}

		bool operator==(const TemplatedClass* rhs) const
		{
			if (m_data == rhs)
			{
				return true;
			}
			return false;
		}

		bool operator!=(const TemplatedClass* rhs) const
		{
			return !operator==(rhs);
		}

		unsigned int GetReferenceCount() const
		{
			if (m_referenceCounter)
			{
				return m_referenceCounter->GetCount();
			}
			return 0;
		}

		void Kill()
		{
			if (m_referenceCounter && !m_referenceCounter->ReleaseReference())
			{
				HaveBlueDelete(m_data);
				HaveBlueDelete(m_referenceCounter);
			}
			else
			{
				HaveBlueDelete(m_data);
				HaveBlueDelete(m_referenceCounter);
			}
		}

		void Release()
		{
			if (m_referenceCounter && !m_referenceCounter->ReleaseReference())
			{
				HaveBlueDelete(m_data);
				HaveBlueDelete(m_referenceCounter);
			}
			m_data = nullptr;
			m_referenceCounter = nullptr;
		}

	protected:
		void CreateReferenceCounter()
		{
			//HB_ASSERT(m_data != nullptr);
			if (m_data != nullptr)
			{
				if (m_referenceCounter == nullptr)
				{
					m_referenceCounter = HaveBlueNew(ReferenceCounter, "SharedPointersRefCounters") ReferenceCounter();

					AddReference();
				}
			}
		}

		void AddReference()
		{
			if (m_data)
			{
				CreateReferenceCounter();

				m_referenceCounter->AddReference();
			}
		}

		TemplatedClass* m_data;
		ReferenceCounter* m_referenceCounter;
	};
}

#define SkyfallAssetDelete(x) x.Release();