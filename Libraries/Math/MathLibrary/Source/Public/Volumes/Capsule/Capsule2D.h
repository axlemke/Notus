#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"

namespace Math
{
	class Line2D;

	class Capsule2D
	{
	public:
		MATH_USAGE Capsule2D();
		MATH_USAGE Capsule2D(const Vector2& start, const Vector2& end, float radius);
		MATH_USAGE Capsule2D(const Line2D& line, float radius);

		MATH_USAGE const Vector2& GetStart() const;
		MATH_USAGE const Vector2& GetEnd() const;
		MATH_USAGE float GetRadius() const;

		MATH_USAGE void SetStart(const Vector2& start);
		MATH_USAGE void SetEnd(const Vector2& end);
		MATH_USAGE void SetRadius(float radius);

		MATH_USAGE float GetCapsuleLength() const;

		Vector2 m_start;
		Vector2 m_end;
		float m_radius;
	};
};

static_assert((sizeof(float) * 5) == sizeof(Math::Capsule2D));
