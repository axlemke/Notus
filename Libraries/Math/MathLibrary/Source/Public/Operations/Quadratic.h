#pragma once

#include "MathCommon.h"

namespace Math
{
	MATH_USAGE float GetDiscriminant(float a, float b, float c);

	MATH_USAGE void SolveQuadratic(float a, float b, float c, float& solutionOne, float& solutionTwo);
};
