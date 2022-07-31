#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"
#include <vector>

namespace Math
{
	namespace Curves
	{
		class CubicHermite3D
		{
		public:
			MATH_USAGE CubicHermite3D();
			MATH_USAGE CubicHermite3D(const Vector3& start, const Vector3& slopeStart, const Vector3& end, const Vector3& slopeEnd);

			MATH_USAGE Vector3 GetPoint(float t) const;

		private:
			Math::Vector3 m_start;
			Math::Vector3 m_slopeStart;
			Math::Vector3 m_end;
			Math::Vector3 m_slopeEnd;
		};
	}
}

static_assert((sizeof(float) * 12) == sizeof(Math::Curves::CubicHermite3D));