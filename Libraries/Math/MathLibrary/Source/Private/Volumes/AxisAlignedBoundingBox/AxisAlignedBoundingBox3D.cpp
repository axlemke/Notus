#include "Volumes/AxisAlignedBoundingBox/AxisAlignedBoundingBox3D.h"

#include "Operations/Clamp.h"
#include "Operations/Distance.h"
#include "Operations/Intersection.h"
#include "Operations/MinMax.h"
#include "Surfaces/Triangles/Triangle3D.h"
#include "Vector/Vector4.h"
#include "Volumes/Sphere/Sphere3D.h"

using namespace Math;

AxisAlignedBoundingBox3D::AxisAlignedBoundingBox3D()
	: m_min(-FLT_MAX)
	, m_max(FLT_MAX)
{
}

AxisAlignedBoundingBox3D::AxisAlignedBoundingBox3D(const Vector3& min, const Vector3& max)
	: m_min(min)
	, m_max(max)
{
}

AxisAlignedBoundingBox3D::AxisAlignedBoundingBox3D(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
	: m_min(minX, minY, minZ)
	, m_max(maxX, maxY, maxZ)
{
}

AxisAlignedBoundingBox3D::AxisAlignedBoundingBox3D(const Triangle3D& triangle)
	: m_min(Min3(triangle.m_pointA, triangle.m_pointB, triangle.m_pointC))
	, m_max(Max3(triangle.m_pointA, triangle.m_pointB, triangle.m_pointC))
{
}

AxisAlignedBoundingBox3D::AxisAlignedBoundingBox3D(const Sphere3D& sphere)
	: m_min(sphere.GetCenter() - Vector3(sphere.GetRadius()))
	, m_max(sphere.GetCenter() + Vector3(sphere.GetRadius()))

{
}

const Vector3& AxisAlignedBoundingBox3D::GetMinBound() const
{
	return m_min;
}

const Vector3& AxisAlignedBoundingBox3D::GetMaxBound() const
{
	return m_max;
}

Vector3 AxisAlignedBoundingBox3D::GetCenter() const
{
	Vector3 halfExtents = GetHalfExtents();
	return (m_min + halfExtents);
}

Vector3 AxisAlignedBoundingBox3D::GetExtents() const
{
	return (m_max - m_min);
}

Vector3 AxisAlignedBoundingBox3D::GetHalfExtents() const
{
	Vector3 extents = GetExtents();
	return 0.5f * extents;
}

void AxisAlignedBoundingBox3D::SetMaxBounds(const Vector3& max)
{
	m_max = max;
}

void AxisAlignedBoundingBox3D::SetMinBounds(const Vector3& min)
{
	m_min = min;
}

bool AxisAlignedBoundingBox3D::Intersects(const AxisAlignedBoundingBox3D& box) const
{
	return Math::Intersects(*this, box);
}

bool AxisAlignedBoundingBox3D::Intersects(const Vector3& point) const
{
	return Math::Intersects(*this, point);
}

bool AxisAlignedBoundingBox3D::Intersects(const Vector4& point) const
{
	return Math::Intersects(*this, point.m_xyz);
}

Vector3 AxisAlignedBoundingBox3D::ClampWithin(const Vector3& point) const
{
	Vector3 clampedPoint;
	clampedPoint.x = Math::Clamp(point.x, m_min.x, m_max.x);
	clampedPoint.y = Math::Clamp(point.y, m_min.y, m_max.y);
	clampedPoint.z = Math::Clamp(point.z, m_min.z, m_max.z);

	return clampedPoint;
}

Vector4 AxisAlignedBoundingBox3D::ClampWithin(const Vector4& point) const
{
	Vector4 clampedPoint;
	clampedPoint.x = Math::Clamp(point.x, m_min.x, m_max.x);
	clampedPoint.y = Math::Clamp(point.y, m_min.y, m_max.y);
	clampedPoint.z = Math::Clamp(point.z, m_min.z, m_max.z);
	clampedPoint.w = point.w;

	return clampedPoint;
}

float AxisAlignedBoundingBox3D::DistanceSquaredToPoint(const Vector3& point) const
{
	return Math::DistanceSquared(*this, point);
}

void AxisAlignedBoundingBox3D::GetCorners(Vector3* corners) const
{
	corners[0] = m_min;
	corners[1] = Vector3(m_max.x, m_min.y, m_min.z);
	corners[2] = Vector3(m_min.x, m_max.y, m_min.z);
	corners[3] = Vector3(m_max.x, m_max.y, m_min.z);

	corners[4] = Vector3(m_min.x, m_min.y, m_max.z);
	corners[5] = Vector3(m_max.x, m_min.y, m_max.z);
	corners[6] = Vector3(m_min.x, m_min.y, m_max.z);
	corners[7] = m_max;
}
