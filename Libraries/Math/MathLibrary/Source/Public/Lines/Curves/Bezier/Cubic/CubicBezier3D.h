#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"

namespace Math
{
	namespace Curves
	{
		class CubicBezier3D
		{
		public:
			MATH_USAGE CubicBezier3D();
			MATH_USAGE CubicBezier3D(const Vector3& start, const Vector3& controlPoint0, const Vector3& controlPoint1, const Vector3& end);

			MATH_USAGE Vector3 GetPoint(float t) const;
			MATH_USAGE Vector3 GetVelocity(float t) const;

			Vector3 m_start;
			Vector3 m_controlPoint0;
			Vector3 m_controlPoint1;
			Vector3 m_end;
		};
	}
}

static_assert((sizeof(float) * 12) == sizeof(Math::Curves::CubicBezier3D));