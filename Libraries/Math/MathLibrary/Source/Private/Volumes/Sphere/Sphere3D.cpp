#include "Volumes/Sphere/Sphere3D.h"

#include "Operations/Distance.h"
#include "Operations/Intersection.h"
#include "Operations/MinMax.h"
#include "Operations/Quadratic.h"
#include "Ray/Ray3D.h"
#include "Surfaces/Triangles/Triangle3D.h"
#include "Vector/Vector4.h"

using namespace Math;

Sphere3D::Sphere3D()
	: m_radius(0.0f)
{
}

Sphere3D::Sphere3D(const Vector3& center, float radius)
	: m_center(center)
	, m_radius(radius)
{
}

Sphere3D::Sphere3D(const Triangle3D& triangle)
	: m_center(triangle.GetCentroid())
	, m_radius(Math::Max3((m_center - triangle.m_pointA).Magnitude(), (m_center - triangle.m_pointB).Magnitude(), (m_center - triangle.m_pointC).Magnitude()))
{
}

Sphere3D::Sphere3D(const Vector4& values)
	: m_center(values.m_xyz)
	, m_radius(values.w)
{
}

void Sphere3D::SetCenter(const Vector3& center)
{
	m_center = center;
}

void Sphere3D::SetRadius(float radius)
{
	m_radius = radius;
}

float Sphere3D::DistanceSquared(const Sphere3D& sphere) const
{
	return Math::DistanceSquared(*this, sphere);
}

float Sphere3D::DistanceSquared(const Vector3& point) const
{
	return Math::DistanceSquared(*this, point);
}

bool Sphere3D::Intersects(const Sphere3D& sphere) const
{
	return Math::Intersects(*this, sphere);
}

bool Sphere3D::Intersects(const Vector3& point) const
{
	return Math::Intersects(*this, point);
}

bool Sphere3D::Intersects(const Ray3D& ray) const
{
	return Math::Intersects(*this, ray);
}

bool Sphere3D::Intersects(const Ray3D& ray, float& t) const
{
	return Math::Intersects(*this, ray, t);
}

bool Sphere3D::Intersects(const Ray3D& ray, Vector3& intersectionPosition) const
{
	return Math::GetIntersectionPosition(*this, ray, intersectionPosition);
}

const Math::Vector3& Sphere3D::GetCenter() const
{
	return m_center;
}

float Sphere3D::GetRadius() const
{
	return m_radius;
}
