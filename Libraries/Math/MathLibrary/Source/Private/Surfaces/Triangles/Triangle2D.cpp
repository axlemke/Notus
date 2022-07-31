#include "Surfaces/Triangles/Triangle2D.h"

#include "Operations/Barycentric.h"
#include "Operations/Distance.h"
#include "Operations/Intersection.h"
#include "Vector/Vector3.h"

using namespace Math;

Triangle2D::Triangle2D()
{
}

Triangle2D::Triangle2D(const Vector2& pointA, const Vector2& pointB, const Vector2& pointC)
	: m_pointA(pointA)
	, m_pointB(pointB)
	, m_pointC(pointC)
{
}

Vector3 Triangle2D::GetBarycentricCoords(const Vector2& point) const
{
	return Math::GetBarycentricCoords(*this, point);
}

bool Triangle2D::Intersects(const Vector2& point) const
{
	return Math::Intersects(*this, point);
}

Vector2 Triangle2D::GetCentroid() const
{
	// Double check this
	float xCentroid = (m_pointA.x + m_pointB.x + m_pointC.x) / 3.0f;
	float yCentroid = (m_pointA.y + m_pointB.y + m_pointC.y) / 3.0f;

	return Vector2(xCentroid, yCentroid);
}

float Triangle2D::GetArea() const
{
	return 0.5f * (m_pointA.x * (m_pointB.y - m_pointC.y) + m_pointB.x * (m_pointC.y - m_pointA.y) + m_pointC.x * (m_pointA.y - m_pointB.y));
}

void Triangle2D::CalculateSubtrianglesFromBarycentricCoords(
	const Vector3& subdivisionBarycentricCoords,
	Triangle2D& subTriangleA,
	Triangle2D& subTriangleB,
	Triangle2D& subTriangleC)
{
	Vector2 subdivisionPoint = subdivisionBarycentricCoords.x * m_pointA + subdivisionBarycentricCoords.y * m_pointB + subdivisionBarycentricCoords.z * m_pointC;

	CalculateSubtrianglesFromSubdivisionPoint(subdivisionPoint, subTriangleA, subTriangleB, subTriangleC);
}

void Triangle2D::CalculateSubtrianglesFromCentroid(
	Triangle2D& subTriangleA,
	Triangle2D& subTriangleB,
	Triangle2D& subTriangleC)
{
	constexpr Vector3 k_centroidBarycentricCoords(1.0f / 3.0f);

	CalculateSubtrianglesFromBarycentricCoords(k_centroidBarycentricCoords, subTriangleA, subTriangleB, subTriangleC);
}

void Triangle2D::CalculateSubtrianglesFromSubdivisionPoint(
	const Vector2& subdivisionPoint,
	Triangle2D& subTriangleA,
	Triangle2D& subTriangleB,
	Triangle2D& subTriangleC)
{
	subTriangleA.m_pointA = subdivisionPoint;
	subTriangleA.m_pointB = m_pointB;
	subTriangleA.m_pointC = m_pointC;

	subTriangleB.m_pointA = m_pointA;
	subTriangleB.m_pointB = subdivisionPoint;
	subTriangleB.m_pointC = m_pointC;

	subTriangleC.m_pointA = m_pointA;
	subTriangleC.m_pointB = m_pointB;
	subTriangleC.m_pointC = subdivisionPoint;
}

const Vector2& Triangle2D::GetPointA() const
{
	return m_pointA;
}

const Vector2& Triangle2D::GetPointB() const
{
	return m_pointB;
}

const Vector2& Triangle2D::GetPointC() const
{
	return m_pointC;
}

