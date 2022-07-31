#include "Lines/Curves/Hermite/Cubic/CubicHermite3D.h"

#include "Lines/Curves/Hermite/Cubic/CubicHermiteUtils.h"
#include "Operations/Interpolation.h"

using namespace Math;
using namespace Curves;

CubicHermite3D::CubicHermite3D()
{
}

CubicHermite3D::CubicHermite3D(const Vector3& start, const Vector3& slopeStart, const Vector3& end, const Vector3& slopeEnd)
	: m_start(start)
	, m_slopeStart(slopeStart)
	, m_end(end)
	, m_slopeEnd(slopeEnd)
{
}

Vector3 CubicHermite3D::GetPoint(float t) const
{
	return GetCubicHermitePoint<Vector3>(m_start, m_slopeStart, m_end, m_slopeEnd, t);
}
