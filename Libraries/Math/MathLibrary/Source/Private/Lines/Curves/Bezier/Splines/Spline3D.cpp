#include "Lines/Curves/Bezier/Spline/Spline3D.h"

using namespace Math;
using namespace Curves;

Spline3D::Spline3D()
{
}

Spline3D::~Spline3D()
{
}

unsigned long Spline3D::GetNumberOfPoints() const
{
	return static_cast<unsigned long>(m_points.size());
}

void Spline3D::ClearPoints()
{
	m_points.clear();
}

void Spline3D::AddPoint(const Math::Vector3& point)
{
	m_points.push_back(point);
}
