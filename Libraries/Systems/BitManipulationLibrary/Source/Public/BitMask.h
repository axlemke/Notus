#pragma once

#include "BitManipulation.h"

namespace BitManipulation
{
	template<typename IntergerType>
	class BitMask
	{
	public:
		BitMask()
			: m_value(0)
		{
		}

		BitMask(IntergerType bitMask)
			: m_value(bitMask)
		{
		}

		IntergerType GetBitMask() const
		{
			return m_value;
		}

		void MarkBits(IntergerType bitMask)
		{
			m_value |= bitMask;
		}

		void MarkBit(unsigned long bitIndex)
		{
			BitManipulation::MarkBit<IntergerType>(m_value, bitIndex);
		}

		bool AnyBitsSet() const
		{
			return (m_value != 0);
		}

		bool TestAnyBit(IntergerType bitMask) const
		{
			return (m_value & bitMask);
		}

		bool TestAllBits(IntergerType bitMask) const
		{
			return ((m_value & bitMask) == bitMask);
		}

		void ResetBits(IntergerType bitMask)
		{
			m_value &= ~bitMask;
		}

		void Clear()
		{
			m_value = 0;
		}

		void ClearBit(unsigned long bitIndex)
		{
			BitManipulation::ClearBit<IntergerType>(m_value, bitIndex);
		}

		void ToggleBit(unsigned long bitIndex)
		{
			BitManipulation::ToggleBit<IntergerType>(m_value, bitIndex);
		}

		void SetAll()
		{
			m_value = -1;
		}

		IntergerType operator&(const IntergerType& rhs) const
		{
			return GetBitMask() & rhs;
		}

		IntergerType operator|(const IntergerType& rhs) const
		{
			return GetBitMask() | rhs;
		}

		BitMask<IntergerType>& operator=(const IntergerType& rhs)
		{
			m_value = rhs;

			return (*this);
		}

		void operator&=(const IntergerType& rhs)
		{
			m_value &= rhs;
		}

		void operator|=(const IntergerType& rhs)
		{
			m_value |= rhs;
		}

		bool TestAnyBit(const BitMask<IntergerType>& rhs) const
		{
			return (m_value & rhs.GetBitMask());
		}

		bool TestAllBits(const BitMask<IntergerType>& rhs) const
		{
			IntergerType rhsBitMask = rhs.GetBitMask();
			return ((m_value & rhsBitMask) == rhsBitMask);
		}

		void ResetBits(const BitMask<IntergerType>& rhs)
		{
			m_value &= ~rhs.GetBitMask();
		}

		IntergerType operator&(const BitMask<IntergerType>& rhs) const
		{
			return GetBitMask() & rhs.GetBitMask();
		}

		IntergerType operator|(const BitMask<IntergerType>& rhs) const
		{
			return GetBitMask() | rhs.GetBitMask();
		}

		void operator&=(const BitMask<IntergerType>& rhs)
		{
			m_value &= rhs.GetBitMask();
		}

		void operator|=(const BitMask<IntergerType>& rhs)
		{
			m_value |= rhs.GetBitMask();
		}

	protected:
		IntergerType m_value;
	};

	using CharBitMask = BitMask<unsigned char>;
	using ShortBitMask = BitMask<unsigned short>;
	using IntBitMask = BitMask<unsigned int>;
	using LongBitMask = BitMask<unsigned long>;
};