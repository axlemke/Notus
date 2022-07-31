#pragma once

#include "MathCommon.h"

#pragma once

#include "MathCommon.h"
#include "Uint/Uint3.h"
#include <string>

typedef DirectX::XMFLOAT4 DirectXVector4;

namespace Math
{
	class Uint4
	{
	public:
		MATH_USAGE constexpr Uint4()
			: x(0)
			, y(0)
			, z(0)
			, w(0)
		{
		}

		MATH_USAGE constexpr Uint4(uint32_t newX, uint32_t newY, uint32_t newZ, uint32_t newW)
			: x(newX)
			, y(newY)
			, z(newZ)
			, w(newW)
		{
		}

		MATH_USAGE constexpr Uint4(uint32_t newX, uint32_t newY, uint32_t newZ)
			: x(newX)
			, y(newY)
			, z(newZ)
			, w(0)
		{
		}

		MATH_USAGE constexpr Uint4(uint32_t newValue)
			: x(newValue)
			, y(newValue)
			, z(newValue)
			, w(newValue)
		{
		}


		MATH_USAGE bool operator==(const Uint4& rhs) const;
		MATH_USAGE bool operator!=(const Uint4& rhs) const;

		MATH_USAGE Uint4& operator+=(const Uint4& rhs);
		MATH_USAGE Uint4& operator-=(const Uint4& rhs);
		MATH_USAGE Uint4& operator*=(const Uint4& rhs);
		MATH_USAGE Uint4& operator/=(const Uint4& rhs);

		union
		{
			struct
			{
				union
				{
					Uint3 m_xyz;

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

						union
						{
							uint32_t z;
							uint32_t b;
							uint32_t k;
						};
					};
				};

				union
				{
					uint32_t w;
					uint32_t a;
				};
			};

			uint32_t m_data[4];
		};
	};
}


MATH_USAGE Math::Uint4 operator+(const Math::Uint4& lhs, const Math::Uint4& rhs);
MATH_USAGE Math::Uint4 operator-(const Math::Uint4& lhs, const Math::Uint4& rhs);
MATH_USAGE Math::Uint4 operator*(const Math::Uint4& lhs, float scale);
MATH_USAGE Math::Uint4 operator-(const Math::Uint4& lhs);

static_assert((sizeof(uint32_t) * 4) == sizeof(Math::Uint4));