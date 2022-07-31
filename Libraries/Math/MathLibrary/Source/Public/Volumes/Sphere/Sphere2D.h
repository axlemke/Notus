#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"

namespace Math
{
	class Ray2D;
	class Triangle2D;

	class Sphere2D
	{
	public:
		MATH_USAGE Sphere2D();
		MATH_USAGE Sphere2D(const Vector2& center, float radius);
		MATH_USAGE Sphere2D(const Triangle2D& triangle);

		MATH_USAGE bool Intersects(const Sphere2D& sphere) const;
		MATH_USAGE bool Intersects(const Vector2& point) const;
		MATH_USAGE bool Intersects(const Ray2D& ray) const;
		MATH_USAGE bool Intersects(const Ray2D& ray, float& t) const;
		MATH_USAGE bool Intersects(const Ray2D& ray, Vector2& intersectionPosition) const;

		MATH_USAGE const Math::Vector2& GetCenter() const;
		MATH_USAGE float GetRadius() const;

		Vector2 m_center;
		float m_radius;

	private:

	};

	using Circle = Sphere2D;
};

static_assert((sizeof(float) * 3) == sizeof(Math::Sphere2D));
