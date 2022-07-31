#include "Lines/Curves/Bezier/Cubic/CubicBezier3D.h"

#include "Lines/Curves/Bezier/Cubic/CubicBezierUtils.h"
#include "Operations/Interpolation.h"

using namespace Math;
using namespace Curves;

CubicBezier3D::CubicBezier3D()
{
}

CubicBezier3D::CubicBezier3D(const Vector3& start, const Vector3& controlPoint0, const Vector3& controlPoint1, const Vector3& end)
	: m_start(start)
	, m_controlPoint0(controlPoint0)
	, m_controlPoint1(controlPoint1)
	, m_end(end)
{
}

Vector3 CubicBezier3D::GetPoint(float t) const
{
	return GetCubicBezierPoint<Vector3>(m_start, m_controlPoint0, m_controlPoint1, m_end, t);
}

Vector3 CubicBezier3D::GetVelocity(float t) const
{
	return GetCubicBezierVelocity<Vector3>(m_start, m_controlPoint0, m_controlPoint1, m_end, t);
}
