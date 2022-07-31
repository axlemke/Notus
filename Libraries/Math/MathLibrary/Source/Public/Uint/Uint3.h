#pragma once

#include "MathCommon.h"
#include "Uint/Uint2.h"

namespace Math
{
	class Uint3
	{
	public:
		MATH_USAGE constexpr Uint3()
			: x(0)
			, y(0)
			, z(0)
		{
		}

		MATH_USAGE constexpr Uint3(uint32_t newX, uint32_t newY, uint32_t newZ)
			: x(newX)
			, y(newY)
			, z(newZ)
		{
		}

		MATH_USAGE constexpr Uint3(uint32_t value)
			: x(value)
			, y(value)
			, z(value)
		{
		}

		MATH_USAGE bool operator==(const Uint3& rhs) const;
		MATH_USAGE bool operator!=(const Uint3& rhs) const;

		union
		{
			struct
			{
				union
				{
					Uint2 m_xy;

					struct
					{
						union
						{
							uint32_t x;
							uint32_t r;
							uint32_t i;
						};

						union
						{
							uint32_t y;
							uint32_t g;
							uint32_t j;
						};
					};
				};

				union
				{
					uint32_t z;
					uint32_t b;
					uint32_t k;
				};
			};

			uint32_t m_data[3];
		};
	};
}

static_assert((sizeof(uint32_t) * 3) == sizeof(Math::Uint3));