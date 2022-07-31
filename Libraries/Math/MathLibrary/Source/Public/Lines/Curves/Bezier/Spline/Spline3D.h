#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"
#include <vector>

namespace Math
{
	namespace Curves
	{
		class Spline3D
		{
		public:
			MATH_USAGE Spline3D();
			MATH_USAGE ~Spline3D();

			MATH_USAGE unsigned long GetNumberOfPoints() const;
			MATH_USAGE void ClearPoints();
			MATH_USAGE void AddPoint(const Math::Vector3& point);

		private:
			std::vector<Vector3> m_points;
		};
	}
}
