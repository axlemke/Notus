#pragma once

#include "MathCommon.h"

namespace Math
{
	class Quaternion;
	class Vector2;
	class Vector3;
	class Vector4;

	template<typename DataType>
	DataType Lerp(const DataType& start, const DataType& end, DataType t)
	{
		return (end - start) * t + start;
	}

	MATH_USAGE float Lerp(float start, float end, float t);
	MATH_USAGE double Lerp(double start, double end, double t);
	MATH_USAGE Vector2 Lerp(const Vector2& start, const Vector2& end, float t);
	MATH_USAGE Vector3 Lerp(const Vector3& start, const Vector3& end, float t);
	MATH_USAGE Vector4 Lerp(const Vector4& start, const Vector4& end, float t);
	MATH_USAGE Quaternion Lerp(const Quaternion& start, const Quaternion& end, float t);

	MATH_USAGE Vector2 Slerp(const Vector2& start, const Vector2& end, float t);
	MATH_USAGE Vector3 Slerp(const Vector3& start, const Vector3& end, float t);
	MATH_USAGE Vector4 Slerp(const Vector4& start, const Vector4& end, float t);
	MATH_USAGE Quaternion Slerp(const Quaternion& start, const Quaternion& end, float t);

	MATH_USAGE Vector2 NLerp(const Vector2& start, const Vector2& end, float t);
	MATH_USAGE Vector3 NLerp(const Vector3& start, const Vector3& end, float t);
	MATH_USAGE Vector4 NLerp(const Vector4& start, const Vector4& end, float t);
	MATH_USAGE Quaternion NLerp(const Quaternion& start, const Quaternion& end, float t);

	MATH_USAGE float CosineInterpolate(float start, float end, float t);
	MATH_USAGE double CosineInterpolate(double start, double end, double t);
};
