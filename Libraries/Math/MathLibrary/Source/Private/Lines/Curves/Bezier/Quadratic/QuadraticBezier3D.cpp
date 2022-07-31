#include "Lines/Curves/Bezier/Quadratic/QuadraticBezier3D.h"

#include "Lines/Curves/Bezier/Quadratic/QuadraticBezierUtils.h"
#include "Operations/Interpolation.h"

using namespace Math;
using namespace Curves;

QuadraticBezier3D::QuadraticBezier3D()
{
}

QuadraticBezier3D::QuadraticBezier3D(const Vector3& start, const Vector3& controlPoint, const Vector3& end)
	: m_start(start)
	, m_controlPoint(controlPoint)
	, m_end(end)
{
}

Vector3 QuadraticBezier3D::GetPoint(float t) const
{
	return GetQuadraticBezierPointDeCastelaju<Vector3>(m_start, m_controlPoint, m_end, t);

	//// Just use de casteljau for now
	//Vector3 p0 = Lerp(m_start, m_controlPoint, t);
	//Vector3 p1 = Lerp(m_controlPoint, m_end, t);
	//return Lerp(p0, p1, t);
}
