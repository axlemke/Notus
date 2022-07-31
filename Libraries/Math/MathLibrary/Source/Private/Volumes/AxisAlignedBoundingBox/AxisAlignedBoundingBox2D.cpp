#include "Volumes/AxisAlignedBoundingBox/AxisAlignedBoundingBox2D.h"

#include "Operations/Clamp.h"
#include "Operations/Distance.h"
#include "Operations/Intersection.h"
#include "Operations/MinMax.h"
#include "Surfaces/Triangles/Triangle2D.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"

using namespace Math;

AxisAlignedBoundingBox2D::AxisAlignedBoundingBox2D()
	: m_min(-FLT_MAX)
	, m_max(FLT_MAX)
{
}

AxisAlignedBoundingBox2D::AxisAlignedBoundingBox2D(const Vector2& min, const Vector2& max)
	: m_min(min)
	, m_max(max)
{
}

AxisAlignedBoundingBox2D::AxisAlignedBoundingBox2D(float minX, float minY, float maxX, float maxY)
	: m_min(minX, minY)
	, m_max(maxX, maxY)
{
}

AxisAlignedBoundingBox2D::AxisAlignedBoundingBox2D(const Triangle2D& triangle)
	: m_min(Min3(triangle.m_pointA, triangle.m_pointB, triangle.m_pointC))
	, m_max(Max3(triangle.m_pointA, triangle.m_pointB, triangle.m_pointC))
{
}

const Vector2& AxisAlignedBoundingBox2D::GetMinBound() const
{
	return m_min;
}

const Vector2& AxisAlignedBoundingBox2D::GetMaxBound() const
{
	return m_max;
}

Vector2 AxisAlignedBoundingBox2D::GetCenter() const
{
	Vector2 halfExtents = GetHalfExtents();
	return (m_min + halfExtents);
}

Vector2 AxisAlignedBoundingBox2D::GetExtents() const
{
	return (m_max - m_min);
}

Vector2 AxisAlignedBoundingBox2D::GetHalfExtents() const
{
	Vector2 extents = GetExtents();
	return 0.5f * extents;
}

void AxisAlignedBoundingBox2D::SetMaxBounds(const Vector2& max)
{
	m_max = max;
}

void AxisAlignedBoundingBox2D::SetMinBounds(const Vector2& min)
{
	m_min = min;
}

bool AxisAlignedBoundingBox2D::Intersects(const AxisAlignedBoundingBox2D& box) const
{
	return Math::Intersects(*this, box);
}

bool AxisAlignedBoundingBox2D::Intersects(const Vector2& point) const
{
	return Math::Intersects(*this, point);
}

bool AxisAlignedBoundingBox2D::Intersects(const Vector3& point) const
{
	return Math::Intersects(*this, point.m_xy);
}

bool AxisAlignedBoundingBox2D::Intersects(const Vector4& point) const
{
	return Math::Intersects(*this,  point.m_xyz.m_xy);
}

Vector2 AxisAlignedBoundingBox2D::ClampWithin(const Vector2& point) const
{
	Vector2 clampedPoint;
	clampedPoint.x = Math::Clamp(point.x, m_min.x, m_max.x);
	clampedPoint.y = Math::Clamp(point.y, m_min.y, m_max.y);

	return clampedPoint;
}

Vector3 AxisAlignedBoundingBox2D::ClampWithin(const Vector3& point) const
{
	Vector3 clampedPoint;
	clampedPoint.x = Math::Clamp(point.x, m_min.x, m_max.x);
	clampedPoint.y = Math::Clamp(point.y, m_min.y, m_max.y);
	clampedPoint.z = point.z;

	return clampedPoint;
}

Vector4 AxisAlignedBoundingBox2D::ClampWithin(const Vector4& point) const
{
	Vector4 clampedPoint;
	clampedPoint.x = Math::Clamp(point.x, m_min.x, m_max.x);
	clampedPoint.y = Math::Clamp(point.y, m_min.y, m_max.y);
	clampedPoint.z = point.z;
	clampedPoint.w = point.w;

	return clampedPoint;
}

float AxisAlignedBoundingBox2D::DistanceSquaredToPoint(const Vector2& point) const
{
	return Math::DistanceSquared(*this, point);
}
