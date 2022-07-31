#include "Operations/Remap.h"

#include "Operations/Clamp.h"
#include "Operations/Saturate.h"

using namespace Math;

float Math::Remap(float value, float inputMin, float inputMax, float outputMin, float outputMax)
{
	return outputMin + (value - inputMin) * (outputMax - outputMin) / (inputMax - inputMin);
}

float Math::RemapZeroToOne(float value, float inputMin, float inputMax)
{
	return Math::Saturate((value - inputMin) / (inputMax - inputMin));
}

float Math::RemapNegativeOneToOne(float value, float inputMin, float inputMax)
{
	return -1.0f + (value - inputMin) * 2.0f / (inputMax - inputMin);
}