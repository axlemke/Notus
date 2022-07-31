#include "Surfaces/Plane/Plane.h"

#include "Surfaces/Triangles/Triangle3D.h"

using namespace Math;

// Notes:  If we were providing with a ax + by + cz + d = 0 plane equation that was not normalized
// and we'd want to normalize it we'd have to also divide d by the length of the normal.
// This is ignored in this example for simplicity

// Positive half space is side normal points

Plane::Plane()
	: m_normal()
	, m_d(0.0f)
{
}

Plane::Plane(const Vector3& normal, float distanceFromOrigin)
	: m_normal(normal)
	, m_d(distanceFromOrigin)
{
}

Plane::Plane(const Vector4& plane)
	: m_planeEquation(plane)
{
}

Plane::Plane(float a, float b, float c, float distanceFromOrigin)
	: m_planeEquation(a, b, c, distanceFromOrigin)
{
}

Plane::Plane(const Vector3& pointA, const Vector3& pointB, const Vector3& pointC)
	: m_normal(Math::Normalize(Cross(pointB - pointC, pointC - pointA)))
	, m_d(Math::Dot(m_normal, pointA))
{
}

Plane::Plane(const Triangle3D& triangle)
	: Plane(triangle.m_pointA, triangle.m_pointB, triangle.m_pointC)
{
}

const Vector3& Plane::GetNormal() const
{
	return m_normal;
}

float Plane::GetDistanceFromOrigin() const
{
	return m_d;
}

float Plane::D() const
{
	return GetDistanceFromOrigin();
}
 
float Plane::DistanceToPoint(const Vector3& point) const
{
	//return (Math::Dot(point, m_normal) - d) / Math::Dot(m_normal, m_normal);

	// Since our plane normal is normalize we can just do this
	return (Math::Dot(point, m_normal) - m_d);
}

Vector3 Plane::ClosestPointOnPlaneToPoint(const Vector3& point) const
{
	// Since our normal is normalized we can simplify a bit
	float t = Math::Dot(m_normal, point) - m_d;
	return point - t * m_normal;
}

bool Plane::Intersects(const Plane& plane) const
{
	// if the dot of the two plane normals are 1 that means they're parallel
	return (abs(Dot(plane.m_normal, m_normal)) != 1.0f);
}

bool Plane::Intersects(const Vector3& point) const
{
	return (Math::Dot(point, m_normal) == m_d);
}

Plane Math::CreatePlane(const Vector3& pointA, const Vector3& pointB, const Vector3& pointC)
{
	Plane plane;

	plane.m_normal = Cross(pointB - pointC, pointC - pointA);
	plane.m_normal.Normalize();

	plane.m_d = Dot(plane.m_normal, pointA);

	return plane;
}

Plane Math::CreatePlane(const Triangle3D& triangle)
{
	return CreatePlane(triangle.m_pointA, triangle.m_pointB, triangle.m_pointC);
}
