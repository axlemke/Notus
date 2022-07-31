#pragma once

#include "MathCommon.h"

namespace Math
{
	class Vector2;
	class Vector3;
	class Vector4;

	MATH_USAGE unsigned long Clamp(unsigned long value, unsigned long minValue, unsigned long maxValue);
	MATH_USAGE float Clamp(float value, float minValue, float maxValue);
	MATH_USAGE double Clamp(double value, double minValue, double maxValue);

	MATH_USAGE Vector2 Clamp(const Vector2& value, const Vector2& minValue, const Vector2& maxValue);
	MATH_USAGE Vector3 Clamp(const Vector3& value, const Vector3& minValue, const Vector3& maxValue);
	MATH_USAGE Vector4 Clamp(const Vector4& value, const Vector4& minValue, const Vector4& maxValue);
};
