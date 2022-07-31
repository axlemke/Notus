#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"

namespace Math
{
	class Triangle3D
	{
	public:
		MATH_USAGE Triangle3D();
		MATH_USAGE Triangle3D(const Vector3& pointA, const Vector3& pointB, const Vector3& pointC);

		MATH_USAGE Vector3 GetBarycentricCoords(const Vector3& point) const;
		MATH_USAGE bool Intersects(const Vector3& point) const;

		MATH_USAGE Vector3 ClosestPointOnTriangleToPoint(const Vector3& point) const;

		MATH_USAGE Vector3 GetCentroid() const;

		MATH_USAGE void CalculateSubtrianglesFromBarycentricCoords(
			const Vector3& subdivisionBarycentricCoords,
			Triangle3D& subTriangleA,
			Triangle3D& subTriangleB,
			Triangle3D& subTriangleC);

		MATH_USAGE void CalculateSubtrianglesFromSubdivisionPoint(
			const Vector3& subdivisionPoint,
			Triangle3D& subTriangleA,
			Triangle3D& subTriangleB,
			Triangle3D& subTriangleC);

		MATH_USAGE void CalculateSubtrianglesFromCentroid(
			Triangle3D& subTriangleA,
			Triangle3D& subTriangleB,
			Triangle3D& subTriangleC);

		MATH_USAGE void CalculateSubtriangles(
			Triangle3D& subTriangleA,
			Triangle3D& subTriangleB,
			Triangle3D& subTriangleC,
			Triangle3D& subTriangleD);

		MATH_USAGE const Vector3& GetPointA() const;
		MATH_USAGE const Vector3& GetPointB() const;
		MATH_USAGE const Vector3& GetPointC() const;

		Vector3 m_pointA;
		Vector3 m_pointB;
		Vector3 m_pointC;
	};
};

static_assert((sizeof(float) * 9) == sizeof(Math::Triangle3D));