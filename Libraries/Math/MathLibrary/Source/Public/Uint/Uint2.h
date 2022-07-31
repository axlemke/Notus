#pragma once

#include "MathCommon.h"

namespace Math
{
	class Uint2
	{
	public:
		MATH_USAGE constexpr Uint2()
			: x(0)
			, y(0)
		{
		}

		MATH_USAGE constexpr Uint2(uint32_t newX, uint32_t newY)
			: x(newX)
			, y(newY)
		{
		}

		MATH_USAGE constexpr Uint2(uint32_t value)
			: x(value)
			, y(value)
		{
		}

		MATH_USAGE bool operator==(const Uint2& rhs) const;
		MATH_USAGE bool operator!=(const Uint2& rhs) const;

		union
		{
			struct
			{
				uint32_t x;
				uint32_t y;
			};

			uint32_t m_data[2];
		};
	};
}

static_assert((sizeof(uint32_t) * 2) == sizeof(Math::Uint2));