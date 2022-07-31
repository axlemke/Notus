#pragma once

#include "MathCommon.h"

namespace Math
{
	class Vector2;
	class Vector3;
	class Vector4;

	MATH_USAGE unsigned long RoundUp(unsigned long value, unsigned long multiple);

	MATH_USAGE unsigned long Align(unsigned long size, unsigned long alignment);

	MATH_USAGE Vector2 Floor(const Vector2& value);
	MATH_USAGE Vector3 Floor(const Vector3& value);
	MATH_USAGE Vector4 Floor(const Vector4& value);

	MATH_USAGE Vector2 Ceil(const Vector2& value);
	MATH_USAGE Vector3 Ceil(const Vector3& value);
	MATH_USAGE Vector4 Ceil(const Vector4& value);
};