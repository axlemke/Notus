#include "Ray/Ray2D.h"

using namespace Math;

Ray2D::Ray2D()
{
}

Ray2D::Ray2D(const Vector2& origin, const Vector2& direction)
	: m_origin(origin)
	, m_direction(direction)
{
	m_direction.Normalize();
}

const Vector2& Ray2D::Origin() const
{
	return m_origin;
}

const Vector2& Ray2D::Direction() const
{
	return m_direction;
}

Vector2 Ray2D::GetPositionAlongRay(float t) const
{
	return m_origin + t * m_direction;
}

