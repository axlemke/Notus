#pragma once

#include "Math\MathLibrary\Source\Public\MathCommon.h"

namespace Math
{
	MATH_USAGE float Remap(float value, float inputMin, float inputMax, float outputMin, float outputMax);
	MATH_USAGE float RemapZeroToOne(float value, float inputMin, float inputMax);
	MATH_USAGE float RemapNegativeOneToOne(float value, float inputMin, float inputMax);
}
