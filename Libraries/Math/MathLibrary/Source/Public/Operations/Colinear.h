#pragma once

#include "MathCommon.h"

namespace Math
{
	class Vector2;
	class Vector3;
	class Vector4;

	MATH_USAGE bool AreCollinear(const Vector2& a, const Vector2& b, const Vector2& c);
	MATH_USAGE bool AreCollinear(const Vector3& a, const Vector3& b, const Vector3& c);
	MATH_USAGE bool AreCollinear(const Vector4& a, const Vector4& b, const Vector4& c);
};
