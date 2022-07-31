#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"
#include <vector>

namespace Math
{
	namespace Curves
	{
		class CubicHermite2D
		{
		public:
			MATH_USAGE CubicHermite2D();
			MATH_USAGE CubicHermite2D(const Vector2& start, const Vector2& slopeStart, const Vector2& end, const Vector2& slopeEnd);

			MATH_USAGE Vector2 GetPoint(float t) const;

		private:
			Math::Vector2 m_start;
			Math::Vector2 m_slopeStart;
			Math::Vector2 m_end;
			Math::Vector2 m_slopeEnd;
		};
	}
}

static_assert((sizeof(float) * 8) == sizeof(Math::Curves::CubicHermite2D));
