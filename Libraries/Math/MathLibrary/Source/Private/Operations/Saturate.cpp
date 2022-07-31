#include "Operations/Saturate.h"

#include "Operations/Clamp.h"

using namespace Math;

unsigned long Math::Saturate(unsigned long value)
{
	return Math::Clamp(value, 0, 1);
}

float Math::Saturate(float value)
{
	return Math::Clamp(value, 0.0f, 1.0f);
}

double Math::Saturate(double value)
{
	return Math::Clamp(value, 0, 1);
}
