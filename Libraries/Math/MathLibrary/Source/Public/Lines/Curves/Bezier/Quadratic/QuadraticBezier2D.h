#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"

namespace Math
{
	namespace Curves
	{
		class QuadraticBezier2D
		{
		public:
			MATH_USAGE QuadraticBezier2D();
			MATH_USAGE QuadraticBezier2D(const Vector2& start, const Vector2& controlPoint, const Vector2& end);

			MATH_USAGE Vector2 GetPoint(float t) const;

			Vector2 m_start;
			Vector2 m_controlPoint;
			Vector2 m_end;
		};
	}
}

static_assert((sizeof(float) * 6) == sizeof(Math::Curves::QuadraticBezier2D));