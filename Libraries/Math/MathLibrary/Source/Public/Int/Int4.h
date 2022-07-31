#pragma once

#include "MathCommon.h"

#pragma once

#include "MathCommon.h"
#include "Int/Int3.h"
#include <string>

typedef DirectX::XMFLOAT4 DirectXVector4;

namespace Math
{
	class Int4
	{
	public:
		MATH_USAGE constexpr Int4()
			: x(0)
			, y(0)
			, z(0)
			, w(0)
		{
		}

		MATH_USAGE constexpr Int4(int32_t newX, int32_t newY, int32_t newZ, int32_t newW)
			: x(newX)
			, y(newY)
			, z(newZ)
			, w(newW)
		{
		}

		MATH_USAGE constexpr Int4(int32_t newX, int32_t newY, int32_t newZ)
			: x(newX)
			, y(newY)
			, z(newZ)
			, w(0)
		{
		}

		MATH_USAGE constexpr Int4(int32_t newValue)
			: x(newValue)
			, y(newValue)
			, z(newValue)
			, w(newValue)
		{
		}


		MATH_USAGE bool operator==(const Int4& rhs) const;
		MATH_USAGE bool operator!=(const Int4& rhs) const;

		MATH_USAGE Int4& operator+=(const Int4& rhs);
		MATH_USAGE Int4& operator-=(const Int4& rhs);
		MATH_USAGE Int4& operator*=(const Int4& rhs);
		MATH_USAGE Int4& operator/=(const Int4& rhs);

		union
		{
			struct
			{
				union
				{
					Int3 m_xyz;

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

						union
						{
							int32_t z;
							int32_t b;
							int32_t k;
						};
					};
				};

				union
				{
					int32_t w;
					int32_t a;
				};
			};

			int32_t m_data[4];
		};
	};
}


MATH_USAGE Math::Int4 operator+(const Math::Int4& lhs, const Math::Int4& rhs);
MATH_USAGE Math::Int4 operator-(const Math::Int4& lhs, const Math::Int4& rhs);
MATH_USAGE Math::Int4 operator*(const Math::Int4& lhs, float scale);
MATH_USAGE Math::Int4 operator-(const Math::Int4& lhs);

static_assert((sizeof(int32_t) * 4) == sizeof(Math::Int4));