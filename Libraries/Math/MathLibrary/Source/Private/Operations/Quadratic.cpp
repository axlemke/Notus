#include "Operations/Quadratic.h"

float Math::GetDiscriminant(float a, float b, float c)
{
	return (b * b) - (4.0f * a * c);
}

void Math::SolveQuadratic(float a, float b, float c, float& solutionOne, float& solutionTwo)
{
	float denominator = 2.0f * a;
	float discriminat = GetDiscriminant(a, b, c);
	float nominatorRight = sqrtf(discriminat);

	solutionOne = (-b + nominatorRight) / denominator;
	solutionTwo = (-b - nominatorRight) / denominator;
}
