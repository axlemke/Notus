#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"

namespace Math
{
	class Line2D
	{
	public:
		MATH_USAGE Line2D();
		MATH_USAGE Line2D(const Vector2& start, const Vector2& end);

		MATH_USAGE const Vector2& GetStart() const;
		MATH_USAGE const Vector2& GetEnd() const;
		MATH_USAGE Vector2 GetLineDirection() const;

		MATH_USAGE void GetClosestPointOnLineToPoint(const Vector2& point, Vector2& closestPoint, float& t) const;

		MATH_USAGE float GetSlope() const;
		MATH_USAGE float GetYIntersection() const;

		Vector2 m_start;
		Vector2 m_end;
	};
};

static_assert((sizeof(float) * 4) == sizeof(Math::Line2D));