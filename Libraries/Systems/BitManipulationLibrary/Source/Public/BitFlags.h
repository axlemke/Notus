#pragma once

#include "BitMask.h"

namespace BitManipulation
{	
	template<typename FlagEnum, typename IntergerType>
	class BitFlags : public BitMask<IntergerType>
	{
	public:
		BitFlags()
			: BitMask<IntergerType>()
		{
		}

		BitFlags(IntergerType value)
			: BitMask<IntergerType>(value)
		{
		}

		BitFlags(FlagEnum flag)
			: BitMask<IntergerType>()
		{
			SetFlag(flag);
		}

		void SetFlag(FlagEnum flag)
		{
			this->MarkBits(static_cast<IntergerType>(flag));
		}

		bool TestFlag(FlagEnum flag) const
		{
			return TestBit(static_cast<IntergerType>(flag));
		}

		void ResetFlag(FlagEnum flag)
		{
			ClearBit(static_cast<IntergerType>(flag));
		}

		BitFlags<FlagEnum, IntergerType>& operator=(FlagEnum flag)
		{
			this->m_value = static_cast<IntergerType>(flag);

			return (*this);
		}

		void operator|=(FlagEnum flag);
	};

	template<typename FlagEnum>
	class CharFlags : public BitFlags<FlagEnum, unsigned char>
	{
	};

	template<typename FlagEnum>
	class ShortFlags : public BitFlags<FlagEnum, unsigned short>
	{
	};

	template<typename FlagEnum>
	class IntFlags : public BitFlags<FlagEnum, unsigned int>
	{
	};

	template<typename FlagEnum>
	class LongFlags : public BitFlags<FlagEnum, unsigned long>
	{
	};
}