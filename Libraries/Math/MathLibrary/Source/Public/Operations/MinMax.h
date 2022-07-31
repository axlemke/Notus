#pragma once

#include "MathCommon.h"

namespace Math
{
	class Vector2;
	class Vector3;
	class Vector4;

	MATH_USAGE long Min(long lhs, long rhs);
	MATH_USAGE unsigned Min(unsigned int lhs, unsigned int rhs);
	MATH_USAGE unsigned long Min(unsigned long lhs, unsigned long rhs);
	MATH_USAGE float Min(float lhs, float rhs);
	MATH_USAGE double Min(double lhs, double rhs);
	MATH_USAGE Vector2 Min(const Vector2& lhs, const Vector2& rhs);
	MATH_USAGE Vector3 Min(const Vector3& lhs, const Vector3& rhs);
	MATH_USAGE Vector4 Min(const Vector4& lhs, const Vector4& rhs);

	MATH_USAGE long Max(long lhs, long rhs);
	MATH_USAGE unsigned long Max(unsigned long lhs, unsigned long rhs);
	MATH_USAGE float Max(float lhs, float rhs);
	MATH_USAGE double Max(double lhs, double rhs);
	MATH_USAGE Vector2 Max(const Vector2& lhs, const Vector2& rhs);
	MATH_USAGE Vector3 Max(const Vector3& lhs, const Vector3& rhs);
	MATH_USAGE Vector4 Max(const Vector4& lhs, const Vector4& rhs);

	MATH_USAGE long Min3(long value0, long value1, long value2);
	MATH_USAGE unsigned long Min3(unsigned long value0, unsigned long value1, unsigned long value2);
	MATH_USAGE float Min3(float value0, float value1, float value2);
	MATH_USAGE double Min3(double value0, double value1, double value2);
	MATH_USAGE Vector2 Min3(const Vector2& value0, const Vector2& value1, const Vector2& value2);
	MATH_USAGE Vector3 Min3(const Vector3& value0, const Vector3& value1, const Vector3& value2);
	MATH_USAGE Vector4 Min3(const Vector4& value0, const Vector4& value1, const Vector4& value2);

	MATH_USAGE long Max3(long value0, long value1, long value2);
	MATH_USAGE unsigned long Max3(unsigned long value0, unsigned long value1, unsigned long value2);
	MATH_USAGE float Max3(float value0, float value1, float value2);
	MATH_USAGE double Max3(double value0, double value1, double value2);
	MATH_USAGE Vector2 Max3(const Vector2& value0, const Vector2& value1, const Vector2& value2);
	MATH_USAGE Vector3 Max3(const Vector3& value0, const Vector3& value1, const Vector3& value2);
	MATH_USAGE Vector4 Max3(const Vector4& value0, const Vector4& value1, const Vector4& value2);
}
