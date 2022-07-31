#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"

namespace Math
{
	class Ray3D;
	class Triangle3D;
	class Vector4;

	class Sphere3D
	{
	public:
		MATH_USAGE Sphere3D();
		MATH_USAGE Sphere3D(const Vector3& center, float radius);
		MATH_USAGE Sphere3D(const Triangle3D& triangle);
		MATH_USAGE Sphere3D(const Vector4& values);

		MATH_USAGE void SetCenter(const Vector3& center);
		MATH_USAGE void SetRadius(float radius);

		MATH_USAGE float DistanceSquared(const Sphere3D& sphere) const;
		MATH_USAGE float DistanceSquared(const Vector3& point) const;

		MATH_USAGE bool Intersects(const Sphere3D& sphere) const;
		MATH_USAGE bool Intersects(const Vector3& point) const;
		MATH_USAGE bool Intersects(const Ray3D& ray) const;
		MATH_USAGE bool Intersects(const Ray3D& ray, float& t) const;
		MATH_USAGE bool Intersects(const Ray3D& ray, Vector3& intersectionPosition) const;

		MATH_USAGE const Math::Vector3& GetCenter() const;
		MATH_USAGE float GetRadius() const;

		Vector3 m_center;
		float m_radius;

	private:
		
	};
};

static_assert((sizeof(float) * 4) == sizeof(Math::Sphere3D));
