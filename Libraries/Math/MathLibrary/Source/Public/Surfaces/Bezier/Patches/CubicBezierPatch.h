#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"

#include <vector>

namespace Math
{
	class CubicBezierPatch
	{
	public:
		MATH_USAGE CubicBezierPatch();
		MATH_USAGE CubicBezierPatch(unsigned long width, unsigned long height);
		MATH_USAGE ~CubicBezierPatch();

		MATH_USAGE void ReserveDimensions(unsigned long width, unsigned long height);
		MATH_USAGE void Clear();

		MATH_USAGE Vector3& GetPoint(unsigned long index);
		MATH_USAGE const Vector3& GetPoint(unsigned long index) const;
		MATH_USAGE Vector3& GetPoint(unsigned long x, unsigned long y);
		MATH_USAGE const Vector3& GetPoint(unsigned long x, unsigned long y) const;

		MATH_USAGE void SetPoint(unsigned long index, const Vector3& point);
		MATH_USAGE void SetPoint(unsigned long x, unsigned long y, const Vector3& point);

		MATH_USAGE unsigned long GetWidth() const;
		MATH_USAGE unsigned long GetHeight() const;

	private:
		Vector3* m_points;
		unsigned long m_width;
		unsigned long m_height;
	};
}
