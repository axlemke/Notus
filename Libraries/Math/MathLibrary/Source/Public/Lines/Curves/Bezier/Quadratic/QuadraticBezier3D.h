#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"

namespace Math
{
	namespace Curves
	{
		class QuadraticBezier3D
		{
		public:
			MATH_USAGE QuadraticBezier3D();
			MATH_USAGE QuadraticBezier3D(const Vector3& start, const Vector3& controlPoint, const Vector3& end);

			MATH_USAGE Vector3 GetPoint(float t) const;

			Vector3 m_start;
			Vector3 m_controlPoint;
			Vector3 m_end;
		};
	}
}

static_assert((sizeof(float) * 9) == sizeof(Math::Curves::QuadraticBezier3D));
