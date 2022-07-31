#pragma once

#include "MathCommon.h"

namespace Math
{
	MATH_USAGE int GetSign(float value);
	MATH_USAGE int GetExponent(float value);
	MATH_USAGE int GetMantissa(float value);

	MATH_USAGE float FastInverseSqureRoot(float value);
};
