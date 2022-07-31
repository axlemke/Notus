#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"

namespace Math
{
	namespace Curves
	{
		class CubicBezier2D
		{
		public:
			MATH_USAGE CubicBezier2D();
			MATH_USAGE CubicBezier2D(const Vector2& start, const Vector2& controlPoint0, const Vector2& controlPoint1, const Vector2& end);

			MATH_USAGE Vector2 GetPoint(float t) const;
			MATH_USAGE Vector2 GetVelocity(float t) const;

			Vector2 m_start;
			Vector2 m_controlPoint0;
			Vector2 m_controlPoint1;
			Vector2 m_end;
		};
	}
}

static_assert((sizeof(float) * 8) == sizeof(Math::Curves::CubicBezier2D));