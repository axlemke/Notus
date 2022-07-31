#pragma once

#include "MemoryCommon.h"

namespace Memory
{
	template<typename TemplatedClass>
	class WeakPointer
	{
	public:
		WeakPointer()
			: m_data(nullptr)
		{
		}

		WeakPointer(TemplatedClass* pointer)
			: m_data(pointer)
		{
		}

		~WeakPointer()
		{
			Release();
		}

		WeakPointer(WeakPointer<TemplatedClass>& rhs)
			: m_data(std::move(rhs.m_data))
		{
			rhs.m_data = nullptr;
		}

		WeakPointer(const WeakPointer<TemplatedClass>& rhs)
			: m_data(std::move(rhs.m_data))
		{
			const_cast<UniquePointer<TemplatedClass>&>(rhs).m_data = nullptr;
		}

		WeakPointer& operator=(WeakPointer<TemplatedClass>& rhs)
		{
			m_data = std::move(rhs.m_data);
			rhs.m_data = nullptr;

			return *this;
		}

		// Don't want these!
		//UniquePointer(UniquePointer const&) = delete;
		//UniquePointer& operator=(UniquePointer const&) = delete;

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

		bool IsValid()
		{
			if (m_data)
			{
				return true;
			}
			return false;
		}

		TemplatedClass* Get()
		{
			return m_data;
		}

		const TemplatedClass* Get() const
		{
			return m_data;
		}

		TemplatedClass** GetAddressOf()
		{
			return &m_data;
		}

		template<typename CastedTemplatedClass>
		UniquePointer<CastedTemplatedClass> Cast()
		{
			UniquePointer<CastedTemplatedClass> castedUniquePointer(reinterpret_cast<CastedTemplatedClass*>(m_data));
			return castedUniquePointer;
		}

		//bool operator==(UniquePointer<TemplatedClass> rhs)
		//{
		//	return ((m_data) && (rhs.mData) && (m_data == rhs.mData));
		//}

		//bool operator!=(UniquePointer<TemplatedClass> rhs)
		//{
		//	return !operator==(rhs);
		//}

		//bool operator==(TemplatedClass* rhs)
		//{
		//	if (m_data == rhs)
		//	{
		//		return true;
		//	}
		//	return false;
		//}

		//bool operator!=(TemplatedClass* rhs)
		//{
		//	return !operator==(rhs);
		//}

		void Release()
		{
			m_data = nullptr;
		}

	protected:
		TemplatedClass* m_data;
	};
};