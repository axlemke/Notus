#include "Operations/Barycentric.h"

#include "Surfaces/Triangles/Triangle2D.h"
#include "Surfaces/Triangles/Triangle3D.h"
#include "Vector/Vector2.h"
#include "Vector/Vector3.h"

using namespace Math;

namespace
{
	template<typename TemplatedVectorType>
	Math::Vector3 GetBarycentricCoordsInternal(const TemplatedVectorType& pointA, const TemplatedVectorType& pointB, const TemplatedVectorType& pointC, const TemplatedVectorType& pointP)
	{
		TemplatedVectorType v0 = pointB - pointA;
		TemplatedVectorType v1 = pointC - pointA;
		TemplatedVectorType v2 = pointP - pointA;

		float d00 = Math::Dot(v0, v0);
		float d01 = Math::Dot(v0, v1);
		float d11 = Math::Dot(v1, v1);
		float d20 = Math::Dot(v2, v0);
		float d21 = Math::Dot(v2, v1);

		float denom = d00 * d11 - d01 * d01;

		Math::Vector3 barycentricCoords(
			1.0f,
			(d11 * d20 - d01 * d21) / denom,
			(d00 * d21 - d01 * d20) / denom);

		barycentricCoords.i = 1.0f - barycentricCoords.j - barycentricCoords.k;

		return barycentricCoords;
	}
};

Vector3 Math::GetBarycentricCoords(const Vector2& pointA, const Vector2& pointB, const Vector2& pointC, const Vector2& pointP)
{
	return GetBarycentricCoordsInternal<Math::Vector2>(pointA, pointB, pointC, pointP);
}

Vector3 Math::GetBarycentricCoords(const Triangle2D& triangle, const Vector2& pointP)
{
	return Math::GetBarycentricCoords(triangle.m_pointA, triangle.m_pointB, triangle.m_pointC, pointP);
}

Vector3 Math::GetBarycentricCoords(const Vector3& pointA, const Vector3& pointB, const Vector3& pointC, const Vector3& pointP)
{	
	return GetBarycentricCoordsInternal<Math::Vector3>(pointA, pointB, pointC, pointP);
}

Vector3 Math::GetBarycentricCoords(const Triangle3D& triangle, const Vector3& pointP)
{
	return Math::GetBarycentricCoords(triangle.m_pointA, triangle.m_pointB, triangle.m_pointC, pointP);
}