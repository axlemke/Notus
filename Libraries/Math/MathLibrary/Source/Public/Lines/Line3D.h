#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"

namespace Math
{
	class Line3D
	{
	public:
		MATH_USAGE Line3D();
		MATH_USAGE Line3D(const Vector3& start, const Vector3& end);

		MATH_USAGE const Vector3& GetStart() const;
		MATH_USAGE const Vector3& GetEnd() const;
		MATH_USAGE Vector3 GetLineDirection() const;

		MATH_USAGE void GetClosestPointOnLineToPoint(const Vector3& point, Vector3& closestPoint, float& t) const;

		Vector3 m_start;
		Vector3 m_end;
	};
};

static_assert((sizeof(float) * 6) == sizeof(Math::Line3D));