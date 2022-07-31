#include "Lines/Curves/Bezier/Quadratic/QuadraticBezier2D.h"

#include "Lines/Curves/Bezier/Quadratic/QuadraticBezierUtils.h"
#include "Operations/Interpolation.h"

using namespace Math;
using namespace Curves;

QuadraticBezier2D::QuadraticBezier2D()
{
}

QuadraticBezier2D::QuadraticBezier2D(const Vector2& start, const Vector2& controlPoint, const Vector2& end)
	: m_start(start)
	, m_controlPoint(controlPoint)
	, m_end(end)
{
}

Vector2 QuadraticBezier2D::GetPoint(float t) const
{
	return GetQuadraticBezierPointDeCastelaju<Vector2>(m_start, m_controlPoint, m_end, t);

	//// Just use de casteljau for now
	//Vector2 p0 = Lerp(m_start, m_controlPoint, t);
	//Vector2 p1 = Lerp(m_controlPoint, m_end, t);
	//return Lerp(p0, p1, t);




	// lerp = x*(1-s) + y*s or x + s(y-x)


	/**

	//Vector2 p0 = m_start * (1.0f - t) + m_controlPoint * t;
	//Vector2 p1 = m_controlPoint * (1.0f - t) + m_end * t;
	//return Lerp(p0, p1, t);

	float tSquared = t * t;
	float tCubed = tSquared * t;

	//Vector2 result = (m_start * (1.0f - t) + m_controlPoint * t) * (1.0f - t) + (m_controlPoint * (1.0f - t) + m_end) * t;
	//Vector2 result = (m_start * (1.0f - t) + m_controlPoint * t) * (1.0f - t) + (m_controlPoint * t * (t - tSquared) + m_end * t);
	//Vector2 result = (m_start * (1.0f - t) + m_controlPoint * t) * (1.0f - t) + (m_controlPoint * (tSquared - tCubed) + m_end * t);
	//Vector2 result = (m_start * (1.0f - t) * (1.0f - t) + m_controlPoint * t * (1.0f - t)) + (m_controlPoint * (tSquared - tCubed) + m_end * t);
	//Vector2 result = (m_start * (1.0f - t - t + tSquared) + m_controlPoint * t * (1.0f - t)) + (m_controlPoint * (tSquared - tCubed) + m_end * t);
	//Vector2 result = (m_start * (1.0f - t - t + tSquared) + m_controlPoint * (t - tSquared)) + (m_controlPoint * (tSquared - tCubed) + m_end * t);
	//Vector2 result = (m_start * (1.0f - 2.0f * t + tSquared) + m_controlPoint * (t - tSquared)) + (m_controlPoint * (tSquared - tCubed) + m_end * t);

	Vector2 result = m_start * (1.0f - 2.0f * t + tSquared)
		+ m_controlPoint * (t - tSquared)
		+ m_controlPoint * (tSquared - tCubed)
		+ m_end * t;
		*/
}

// The derivative of f(x) is mostly denoted by f'(x) or df/dx, and it is defined as follows:
// f'(x) = lim (f(x+h) - f(x))/h
