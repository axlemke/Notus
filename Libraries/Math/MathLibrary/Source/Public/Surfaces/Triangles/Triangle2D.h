#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"

namespace Math
{
	class Vector3;

	class Triangle2D
	{
	public:
		MATH_USAGE Triangle2D();
		MATH_USAGE Triangle2D(const Vector2& pointA, const Vector2& pointB, const Vector2& pointC);

		MATH_USAGE Vector3 GetBarycentricCoords(const Vector2& point) const;
		MATH_USAGE bool Intersects(const Vector2& point) const;

		MATH_USAGE Vector2 GetCentroid() const;

		MATH_USAGE float GetArea() const;

		MATH_USAGE void CalculateSubtrianglesFromBarycentricCoords(
			const Vector3& subdivisionBarycentricCoords,
			Triangle2D& subTriangleA,
			Triangle2D& subTriangleB,
			Triangle2D& subTriangleC);

		MATH_USAGE void CalculateSubtrianglesFromSubdivisionPoint(
			const Vector2& subdivisionPoint,
			Triangle2D& subTriangleA,
			Triangle2D& subTriangleB,
			Triangle2D& subTriangleC);

		MATH_USAGE void CalculateSubtrianglesFromCentroid(
			Triangle2D& subTriangleA,
			Triangle2D& subTriangleB,
			Triangle2D& subTriangleC);

		MATH_USAGE const Vector2& GetPointA() const;
		MATH_USAGE const Vector2& GetPointB() const;
		MATH_USAGE const Vector2& GetPointC() const;

		Vector2 m_pointA;
		Vector2 m_pointB;
		Vector2 m_pointC;
	};
}

static_assert((sizeof(float) * 6) == sizeof(Math::Triangle2D));