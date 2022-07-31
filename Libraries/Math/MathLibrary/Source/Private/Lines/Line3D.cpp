#include "Lines//Line3D.h"

#include "Operations/Clamp.h"
#include "Operations/Distance.h"
#include "Operations/Intersection.h"
#include "Operations/Saturate.h"

using namespace Math;

Line3D::Line3D()
{
}

Line3D::Line3D(const Vector3& start, const Vector3& end)
	: m_start(start)
	, m_end(end)
{
}

const Vector3& Line3D::GetStart() const
{
	return m_start;
}

const Vector3& Line3D::GetEnd() const
{
	return m_end;
}

Vector3 Line3D::GetLineDirection() const
{
	return (m_end - m_start);
}

void Line3D::GetClosestPointOnLineToPoint(const Vector3& point, Vector3& closestPoint, float& t) const
{
	Math::GetClosestPointOnLineToPoint(*this, point, closestPoint, t);
}

