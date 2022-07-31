#pragma once

#include "MathCommon.h"

#pragma once

#include "MathCommon.h"
#include "Int/Int2.h"

namespace Math
{
	class Int3
	{
	public:
		MATH_USAGE constexpr Int3()
			: x(0)
			, y(0)
			, z(0)
		{
		}

		MATH_USAGE constexpr Int3(int32_t newX, int32_t newY, int32_t newZ)
			: x(newX)
			, y(newY)
			, z(newZ)
		{
		}

		MATH_USAGE constexpr Int3(uint32_t value)
			: x(value)
			, y(value)
			, z(value)
		{
		}

		MATH_USAGE bool operator==(const Int3& rhs) const;
		MATH_USAGE bool operator!=(const Int3& rhs) const;

		union
		{
			struct
			{
				union
				{
					Int2 m_xy;

					struct
					{
						union
						{
							int32_t x;
							int32_t r;
							int32_t i;
						};

						union
						{
							int32_t y;
							int32_t g;
							int32_t j;
						};
					};
				};

				union
				{
					int32_t z;
					int32_t b;
					int32_t k;
				};
			};

			int32_t m_data[3];
		};
	};
}

static_assert((sizeof(int32_t) * 3) == sizeof(Math::Int3));