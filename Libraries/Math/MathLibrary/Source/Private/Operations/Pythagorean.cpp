#include "Operations/Pythagorean.h"

float Math::GetHypotenuse(float a, float b)
{
	return sqrt(GetHypotenuseSquared(a, b));
}

float Math::GetHypotenuseSquared(float a, float b)
{
	return ((a * a) + (b * b));
}
