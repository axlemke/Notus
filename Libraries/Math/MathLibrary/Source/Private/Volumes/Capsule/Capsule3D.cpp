#include "Volumes/Capsule/Capsule3D.h"

#include "Lines/Line3D.h"

using namespace Math;

Capsule3D::Capsule3D()
	: m_radius(0.0f)
{
}

Capsule3D::Capsule3D(const Vector3& start, const Vector3& end, float radius)
	: m_start(start)
	, m_end(end)
	, m_radius(radius)
{
}

Capsule3D::Capsule3D(const Line3D& line, float radius)
	: Capsule3D(line.GetStart(), line.GetEnd(), radius)
{
}

const Vector3& Capsule3D::GetStart() const
{
	return m_start;
}

const Vector3& Capsule3D::GetEnd() const
{
	return m_end;
}

float Capsule3D::GetRadius() const
{
	return m_radius;
}

void Capsule3D::SetStart(const Vector3& start)
{
	m_start = start;
}

void Capsule3D::SetEnd(const Vector3& end)
{
	m_end = end;
}

void Capsule3D::SetRadius(float radius)
{
	m_radius = radius;
}

float Capsule3D::GetCapsuleLength() const
{
	return Magnitude(m_end - m_start);
}
