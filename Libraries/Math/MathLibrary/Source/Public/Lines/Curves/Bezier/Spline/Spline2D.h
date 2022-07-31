#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"
#include <vector>

namespace Math
{
	namespace Curves
	{
		class Spline2D
		{
		public:
			MATH_USAGE Spline2D();
			MATH_USAGE ~Spline2D();

			MATH_USAGE unsigned long GetNumberOfPoints() const;
			MATH_USAGE void ClearPoints();
			MATH_USAGE void AddPoint(const Math::Vector2& point);

		private:
			std::vector<Vector2> m_points;
		};
	};
}
