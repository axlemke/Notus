#pragma once

#include "MathCommon.h"

namespace Math
{
	class Int2
	{
	public:
		MATH_USAGE constexpr Int2()
			: x(0)
			, y(0)
		{
		}

		MATH_USAGE constexpr Int2(int32_t newX, int32_t newY)
			: x(newX)
			, y(newY)
		{
		}

		MATH_USAGE constexpr Int2(int32_t value)
			: x(value)
			, y(value)
		{
		}

		union
		{
			struct
			{
				int32_t x;
				int32_t y;
			};

			int32_t m_data[2];
		};
	};
}

static_assert((sizeof(uint32_t) * 2) == sizeof(Math::Int2));