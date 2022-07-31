#include "Ray/Ray3D.h"

#include "Volumes/Sphere/Sphere3D.h"

using namespace Math;

Ray3D::Ray3D()
{
}

Ray3D::Ray3D(const Vector3& origin, const Vector3& direction)
	: m_origin(origin)
	, m_direction(direction)
{
	m_direction.Normalize();
}

const Vector3& Ray3D::Origin() const
{
	return m_origin;
}

const Vector3& Ray3D::Direction() const
{
	return m_direction;
}

Vector3 Ray3D::GetPositionAlongRay(float t) const
{
	return m_origin + t * m_direction;
}

bool Ray3D::Intersects(const Sphere3D& sphere) const
{
	return sphere.Intersects(*this);
}
