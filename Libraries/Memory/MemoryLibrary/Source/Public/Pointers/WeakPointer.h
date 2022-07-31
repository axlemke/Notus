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

		void Release()
		{
			m_data = nullptr;
		}

	protected:
		TemplatedClass* m_data;
	};
}
