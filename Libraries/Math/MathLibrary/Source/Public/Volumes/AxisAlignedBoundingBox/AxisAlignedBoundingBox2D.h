#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"

namespace Math
{
	class Triangle2D;
	class Vector3;
	class Vector4;

	class AxisAlignedBoundingBox2D
	{
	public:
		MATH_USAGE AxisAlignedBoundingBox2D();
		MATH_USAGE AxisAlignedBoundingBox2D(const Vector2& min, const Vector2& max);
		MATH_USAGE AxisAlignedBoundingBox2D(float minX, float minY, float maxX, float maxY);
		MATH_USAGE AxisAlignedBoundingBox2D(const Triangle2D& triangle);

		MATH_USAGE const Vector2& GetMinBound() const;
		MATH_USAGE const Vector2& GetMaxBound() const;

		MATH_USAGE Vector2 GetCenter() const;
		MATH_USAGE Vector2 GetExtents() const;
		MATH_USAGE Vector2 GetHalfExtents() const;

		MATH_USAGE void SetMaxBounds(const Vector2& max);
		MATH_USAGE void SetMinBounds(const Vector2& min);

		MATH_USAGE bool Intersects(const AxisAlignedBoundingBox2D& box) const;
		MATH_USAGE bool Intersects(const Vector2& point) const;
		MATH_USAGE bool Intersects(const Vector3& point) const;
		MATH_USAGE bool Intersects(const Vector4& point) const;

		MATH_USAGE Vector2 ClampWithin(const Vector2& point) const;
		MATH_USAGE Vector3 ClampWithin(const Vector3& point) const;
		MATH_USAGE Vector4 ClampWithin(const Vector4& point) const;

		MATH_USAGE float DistanceSquaredToPoint(const Vector2& point) const;

		Vector2 m_min;
		Vector2 m_max;
	};
	using AABB2D = AxisAlignedBoundingBox2D;
	using Rectangle2D = AxisAlignedBoundingBox2D;
};

static_assert((sizeof(float) * 4) == sizeof(Math::AxisAlignedBoundingBox2D));
