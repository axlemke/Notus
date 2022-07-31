#include "Lines/Curves/Bezier/Cubic/CubicBezier2D.h"

#include "Lines/Curves/Bezier/Cubic/CubicBezierUtils.h"
#include "Operations/Interpolation.h"

using namespace Math;
using namespace Curves;

CubicBezier2D::CubicBezier2D()
{
}

CubicBezier2D::CubicBezier2D(const Vector2& start, const Vector2& controlPoint0, const Vector2& controlPoint1, const Vector2& end)
	: m_start(start)
	, m_controlPoint0(controlPoint0)
	, m_controlPoint1(controlPoint1)
	, m_end(end)
{
}

Vector2 CubicBezier2D::GetPoint(float t) const
{
	return GetCubicBezierPoint<Vector2>(m_start, m_controlPoint0, m_controlPoint1, m_end, t);
}

Vector2 CubicBezier2D::GetVelocity(float t) const
{
	return GetCubicBezierVelocity<Vector2>(m_start, m_controlPoint0, m_controlPoint1, m_end, t);
}

