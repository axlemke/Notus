#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"
#include <string>

namespace Math
{
	class Matrix2x2
	{
	public:
		MATH_USAGE Matrix2x2();
		MATH_USAGE Matrix2x2(const Math::Vector2& row0, const Math::Vector2& row1);
		MATH_USAGE Matrix2x2(float m11, float m12, float m21, float m22);

		MATH_USAGE static Matrix2x2 CreateRotation(float angle);

		MATH_USAGE static float Determinant(const Matrix2x2& matrix);
		MATH_USAGE float Determinant() const;

		union
		{
			float n[2][2];
			Vector2 row[2];
			float m[4];
		};
	};
}

MATH_USAGE Math::Vector2 operator*(const Math::Matrix2x2& lhs, const Math::Vector2& rhs);
MATH_USAGE Math::Vector2 operator*(const Math::Vector2& lhs, const Math::Matrix2x2& rhs);

static_assert((sizeof(float) * 4) == sizeof(Math::Matrix2x2));