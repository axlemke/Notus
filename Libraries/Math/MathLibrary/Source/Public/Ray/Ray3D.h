#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"

namespace Math
{
	class Sphere3D;

	class Ray3D
	{
	public:
		MATH_USAGE Ray3D();
		MATH_USAGE Ray3D(const Vector3& origin, const Vector3& direction);

		MATH_USAGE const Vector3& Origin() const;
		MATH_USAGE const Vector3& Direction() const;
		MATH_USAGE Vector3 GetPositionAlongRay(float t) const;

		MATH_USAGE bool Intersects(const Sphere3D& sphere) const;

		Vector3 m_origin;
		Vector3 m_direction;
	};
};

static_assert((sizeof(float) * 6) == sizeof(Math::Ray3D));