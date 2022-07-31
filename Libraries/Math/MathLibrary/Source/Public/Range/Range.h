#pragma once

#include "MathCommon.h"

namespace Math
{
	class Range
	{
	public:
		MATH_USAGE Range();
		MATH_USAGE Range(float min, float max);

		MATH_USAGE float GetMin() const;
		MATH_USAGE float GetMax() const;
		MATH_USAGE float GetRange() const;

		MATH_USAGE bool IsWithinRange(float value) const;

		float m_min;
		float m_max;
	};

	MATH_USAGE bool operator<(const Range& a, const Range& b);
};
