#include "Lines/Curves/Hermite/Cubic/CubicHermite2D.h"

#include "Lines/Curves/Hermite/Cubic/CubicHermiteUtils.h"
#include "Operations/Interpolation.h"

using namespace Math;
using namespace Curves;

CubicHermite2D::CubicHermite2D()
{
}

CubicHermite2D::CubicHermite2D(const Vector2& start, const Vector2& slopeStart, const Vector2& end, const Vector2& slopeEnd)
	: m_start(start)
	, m_slopeStart(slopeStart)
	, m_end(end)
	, m_slopeEnd(slopeEnd)
{
}

Vector2 CubicHermite2D::GetPoint(float t) const
{
	return GetCubicHermitePoint<Vector2>(m_start, m_slopeStart, m_end, m_slopeEnd, t);
}

