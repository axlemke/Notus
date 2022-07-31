#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"

namespace Math
{
	class Ray2D
	{
	public:
		MATH_USAGE Ray2D();
		MATH_USAGE Ray2D(const Vector2& origin, const Vector2& direction);

		MATH_USAGE const Vector2& Origin() const;
		MATH_USAGE const Vector2& Direction() const;
		MATH_USAGE Vector2 GetPositionAlongRay(float t) const;

		Vector2 m_origin;
		Vector2 m_direction;
	};
};

static_assert((sizeof(float) * 4) == sizeof(Math::Ray2D));