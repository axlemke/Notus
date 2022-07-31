#include "Lines/Curves/Bezier/Spline/Spline2D.h"

using namespace Math;
using namespace Curves;

Spline2D::Spline2D()
{
}

Spline2D::~Spline2D()
{
}

unsigned long Spline2D::GetNumberOfPoints() const
{
	return m_points.size();
}

void Spline2D::ClearPoints()
{
	m_points.clear();
}

void Spline2D::AddPoint(const Math::Vector2& point)
{
	m_points.push_back(point);
}
