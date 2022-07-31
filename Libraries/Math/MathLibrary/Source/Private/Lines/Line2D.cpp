#include "Lines/Line2D.h"

#include "Operations/Clamp.h"
#include "Operations/Distance.h"
#include "Operations/Intersection.h"
#include "Operations/Saturate.h"

using namespace Math;

Line2D::Line2D()
{
}

Line2D::Line2D(const Vector2& start, const Vector2& end)
	: m_start(start)
	, m_end(end)
{
}

const Vector2& Line2D::GetStart() const
{
	return m_start;
}

const Vector2& Line2D::GetEnd() const
{
	return m_end;
}

Vector2 Line2D::GetLineDirection() const
{
	return (m_end - m_start);
}

void Line2D::GetClosestPointOnLineToPoint(const Vector2& point, Vector2& closestPoint, float& t) const
{
	Math::GetClosestPointOnLineToPoint(*this, point, closestPoint, t);
}

float Line2D::GetSlope() const
{
	// Slope is delta y over delta x
	float deltaX = m_end.x - m_start.x;

	if (deltaX != 0.0f)
	{
		float deltaY = m_end.y - m_start.y;
		return deltaY / deltaX;
	}
	return FLT_MAX;
}

float Line2D::GetYIntersection() const
{
	float slope = GetSlope();

	if (slope != FLT_MAX)
	{
		// y = mx + b, so solve for b
		// y - mx = b
		float yIntersection = m_start.y - slope * m_start.x;

		return yIntersection;
	}
	return FLT_MAX;
}
