#include "Volumes/Capsule/Capsule2D.h"

#include "Lines/Line2D.h"

using namespace Math;

Capsule2D::Capsule2D()
	: m_radius(0.0f)
{
}

Capsule2D::Capsule2D(const Vector2& start, const Vector2& end, float radius)
	: m_start(start)
	, m_end(end)
	, m_radius(radius)
{
}

Capsule2D::Capsule2D(const Line2D& line, float radius)
	: Capsule2D(line.GetStart(), line.GetEnd(), radius)
{
}

const Vector2& Capsule2D::GetStart() const
{
	return m_start;
}

const Vector2& Capsule2D::GetEnd() const
{
	return m_end;
}

float Capsule2D::GetRadius() const
{
	return m_radius;
}

void Capsule2D::SetStart(const Vector2& start)
{
	m_start = start;
}

void Capsule2D::SetEnd(const Vector2& end)
{
	m_end = end;
}

void Capsule2D::SetRadius(float radius)
{
	m_radius = radius;
}

float Capsule2D::GetCapsuleLength() const
{
	return Magnitude(m_end - m_start);
}

