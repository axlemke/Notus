#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"

namespace Math
{
	class Line3D;

	class Cylinder
	{
	public:
		MATH_USAGE Cylinder();
		MATH_USAGE Cylinder(const Vector3& start, const Vector3& end, float radius);
		MATH_USAGE Cylinder(const Line3D& line, float radius);

		MATH_USAGE const Vector3& GetStart() const;
		MATH_USAGE const Vector3& GetEnd() const;
		MATH_USAGE float GetRadius() const;

		MATH_USAGE void SetStart(const Vector3& start);
		MATH_USAGE void SetEnd(const Vector3& end);
		MATH_USAGE void SetRadius(float radius);

		MATH_USAGE float GetHeight() const;

		Vector3 m_start;
		Vector3 m_end;
		float m_radius;
	};
};

static_assert((sizeof(float) * 7) == sizeof(Math::Cylinder));
