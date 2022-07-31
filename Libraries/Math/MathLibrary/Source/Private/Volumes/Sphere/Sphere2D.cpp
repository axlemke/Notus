#include "Volumes/Sphere/Sphere2D.h"

#include "Operations/Distance.h"
#include "Operations/Intersection.h"
#include "Operations/MinMax.h"
#include "Operations/Quadratic.h"
#include "Ray/Ray2D.h"
#include "Surfaces/Triangles/Triangle2D.h"

using namespace Math;

Sphere2D::Sphere2D()
	: m_radius(0.0f)
{
}

Sphere2D::Sphere2D(const Vector2& center, float radius)
	: m_center(center)
	, m_radius(radius)
{
}

Sphere2D::Sphere2D(const Triangle2D& triangle)
	: m_center(triangle.GetCentroid())
	, m_radius(Math::Max3((m_center - triangle.m_pointA).Magnitude(), (m_center - triangle.m_pointB).Magnitude(), (m_center - triangle.m_pointC).Magnitude()))
{
}

bool Sphere2D::Intersects(const Sphere2D& sphere) const
{
	return Math::Intersects(*this, sphere);
}

bool Sphere2D::Intersects(const Vector2& point) const
{
	return Math::Intersects(*this, point);
}

bool Sphere2D::Intersects(const Ray2D& ray) const
{
	return Math::Intersects(*this, ray);
}

bool Sphere2D::Intersects(const Ray2D& ray, float& t) const
{
	return Math::Intersects(*this, ray, t);
}

bool Sphere2D::Intersects(const Ray2D& ray, Vector2& intersectionPosition) const
{
	return Math::GetIntersectionPosition(*this, ray, intersectionPosition);
}

const Math::Vector2& Sphere2D::GetCenter() const
{
	return m_center;
}

float Sphere2D::GetRadius() const
{
	return m_radius;
}
