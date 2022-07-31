#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"

namespace Math
{
	class Sphere3D;
	class Triangle3D;
	class Vector4;

	class AxisAlignedBoundingBox3D
	{
	public:
		MATH_USAGE AxisAlignedBoundingBox3D();
		MATH_USAGE AxisAlignedBoundingBox3D(const Vector3& min, const Vector3& max);
		MATH_USAGE AxisAlignedBoundingBox3D(float minX, float minY, float minZ, float maxX, float maxY, float maxZ);
		MATH_USAGE AxisAlignedBoundingBox3D(const Triangle3D& triangle);
		MATH_USAGE AxisAlignedBoundingBox3D(const Sphere3D& sphere);

		MATH_USAGE const Vector3& GetMinBound() const;
		MATH_USAGE const Vector3& GetMaxBound() const;

		MATH_USAGE Vector3 GetCenter() const;
		MATH_USAGE Vector3 GetExtents() const;
		MATH_USAGE Vector3 GetHalfExtents() const;

		MATH_USAGE void SetMaxBounds(const Vector3& max);
		MATH_USAGE void SetMinBounds(const Vector3& min);

		MATH_USAGE bool Intersects(const AxisAlignedBoundingBox3D& box) const;
		MATH_USAGE bool Intersects(const Vector3& point) const;
		MATH_USAGE bool Intersects(const Vector4& point) const;

		MATH_USAGE Vector3 ClampWithin(const Vector3& point) const;
		MATH_USAGE Vector4 ClampWithin(const Vector4& point) const;

		MATH_USAGE float DistanceSquaredToPoint(const Vector3& point) const;

		MATH_USAGE void GetCorners(Vector3* corners) const;

		Vector3 m_min;
		Vector3 m_max;
	};
	using AABB3D = AxisAlignedBoundingBox3D;
};

static_assert((sizeof(float) * 6) == sizeof(Math::AxisAlignedBoundingBox3D));
