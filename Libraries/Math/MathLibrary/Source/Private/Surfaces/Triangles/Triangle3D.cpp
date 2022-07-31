#include "Surfaces/Triangles/Triangle3D.h"

#include "Operations/Barycentric.h"
#include "Operations/Distance.h"
#include "Operations/Intersection.h"

using namespace Math;

Triangle3D::Triangle3D()
{
}

Triangle3D::Triangle3D(const Vector3& pointA, const Vector3& pointB, const Vector3& pointC)
	: m_pointA(pointA)
	, m_pointB(pointB)
	, m_pointC(pointC)
{
}

Vector3 Triangle3D::GetBarycentricCoords(const Vector3& point) const
{
	return Math::GetBarycentricCoords(*this, point);
}

bool Triangle3D::Intersects(const Vector3& point) const
{
	return Math::Intersects(*this, point);
}

Vector3 Triangle3D::ClosestPointOnTriangleToPoint(const Vector3& point) const
{
	return Math::GetClosestPointOnTriangleToPoint(*this, point);

	//Vector3 ab = m_pointB - m_pointA;
	//Vector3 ac = m_pointC - m_pointA;
	//Vector3 bc = m_pointC - m_pointB;

	//Vector3 n = Math::Cross(ab, ac);

	//float sNom = Math::Dot(point - m_pointA, ab);
	//float sDenom = Math::Dot(point - m_pointB, m_pointA - m_pointB); // Any reason why we can't use -ab here?

	//float tNom = Math::Dot(point - m_pointA, ac);
	//float tDenom = Math::Dot(point - m_pointC, m_pointA - m_pointC);

	//if ((sNom <= 0.0f) && (tNom <= 0.0f))
	//{
	//	return m_pointA;
	//}

	//float uNom = Math::Dot(point - m_pointB, bc);
	//float uDenom = Math::Dot(point - m_pointC, m_pointB - m_pointC);

	//if ((sDenom <= 0.0f) && (uNom <= 0.0f))
	//{
	//	return m_pointB;
	//}

	//if ((tDenom <= 0.0f) && (uDenom <= 0.0f))
	//{
	//	return m_pointC;
	//}

	//// If outside or on AB
	//float vc = Math::Dot(n, Math::Cross(m_pointA - point, m_pointB - point));

	//if ((vc <= 0.0f) && (sNom >= 0.0f) && (sDenom >= 0.0f))
	//{
	//	return m_pointA + sNom / (sNom + sDenom) * ab;
	//}

	//// If outside or on BC
	//float va = Math::Dot(n, Math::Cross(m_pointB - point, m_pointC - point));

	//if ((va <= 0.0f) && (uNom >= 0.0f) && (uDenom >= 0.0f))
	//{
	//	return m_pointB + uNom / (uNom + uDenom) * bc;
	//}


	//// If outside or on CA
	//float vb = Math::Dot(n, Math::Cross(m_pointC - point, m_pointA - point));

	//if ((vb <= 0.0f) && (tNom >= 0.0f) && (tDenom >= 0.0f))
	//{
	//	return m_pointA + tNom / (tNom + tDenom) * bc;
	//}

	//// Inside the triangle, use barycentric coordinates
	//float u = va / (va + vb + vc);
	//float v = vb / (va + vb + vc);
	//float w = 1.0f - u - v;

	//return u * m_pointA + v * m_pointB + w * m_pointC;
}

Vector3 Triangle3D::GetCentroid() const
{
	// Double check this
	float xCentroid = (m_pointA.x + m_pointB.x + m_pointC.x) / 3.0f;
	float yCentroid = (m_pointA.y + m_pointB.y + m_pointC.y) / 3.0f;
	float zCentroid = (m_pointA.z + m_pointB.z + m_pointC.z) / 3.0f;

	return Vector3(xCentroid, yCentroid, zCentroid);
}

void Triangle3D::CalculateSubtrianglesFromBarycentricCoords(
	const Vector3& subdivisionBarycentricCoords,
	Triangle3D& subTriangleA,
	Triangle3D& subTriangleB,
	Triangle3D& subTriangleC)
{
	Vector3 subdivisionPoint = subdivisionBarycentricCoords.x * m_pointA + subdivisionBarycentricCoords.y * m_pointB + subdivisionBarycentricCoords.z * m_pointC;

	CalculateSubtrianglesFromSubdivisionPoint(subdivisionPoint, subTriangleA, subTriangleB, subTriangleC);
}

void Triangle3D::CalculateSubtrianglesFromSubdivisionPoint(
	const Vector3& subdivisionPoint,
	Triangle3D& subTriangleA,
	Triangle3D& subTriangleB,
	Triangle3D& subTriangleC)
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

void Triangle3D::CalculateSubtrianglesFromCentroid(
	Triangle3D& subTriangleA,
	Triangle3D& subTriangleB,
	Triangle3D& subTriangleC)
{
	CalculateSubtrianglesFromSubdivisionPoint(GetCentroid(), subTriangleA, subTriangleB, subTriangleC);
}

void Triangle3D::CalculateSubtriangles(
	Triangle3D& subTriangleA,
	Triangle3D& subTriangleB,
	Triangle3D& subTriangleC,
	Triangle3D& subTriangleD)
{
	Vector3 subdivisionPoint0 = k_edgeMidpoint0BarycentricCoords.x * m_pointA + k_edgeMidpoint0BarycentricCoords.y * m_pointB + k_edgeMidpoint0BarycentricCoords.z * m_pointC;
	Vector3 subdivisionPoint1 = k_edgeMidpoint1BarycentricCoords.x * m_pointA + k_edgeMidpoint1BarycentricCoords.y * m_pointB + k_edgeMidpoint1BarycentricCoords.z * m_pointC;
	Vector3 subdivisionPoint2 = k_edgeMidpoint2BarycentricCoords.x * m_pointA + k_edgeMidpoint2BarycentricCoords.y * m_pointB + k_edgeMidpoint2BarycentricCoords.z * m_pointC;

	subTriangleA.m_pointA = subdivisionPoint0;
	subTriangleA.m_pointB = subdivisionPoint1;
	subTriangleA.m_pointC = subdivisionPoint2;

	subTriangleB.m_pointA = subdivisionPoint0;
	subTriangleB.m_pointB = subdivisionPoint1;
	subTriangleB.m_pointC = subdivisionPoint2;

	subTriangleC.m_pointA = subdivisionPoint0;
	subTriangleC.m_pointB = subdivisionPoint1;
	subTriangleC.m_pointC = subdivisionPoint2;

	subTriangleD.m_pointA = subdivisionPoint0;
	subTriangleD.m_pointB = subdivisionPoint1;
	subTriangleD.m_pointC = subdivisionPoint2;
}

const Vector3& Triangle3D::GetPointA() const
{
	return m_pointA;
}

const Vector3& Triangle3D::GetPointB() const
{
	return m_pointB;
}

const Vector3& Triangle3D::GetPointC() const
{
	return m_pointC;
}
