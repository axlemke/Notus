#pragma once

#include "MathCommon.h"
#include "Matrix/Matrix4x4.h"

namespace Math
{
	class Transform4 : public Matrix4x4
	{
	public:
		MATH_USAGE Transform4();

		MATH_USAGE Transform4(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);

		MATH_USAGE Transform4(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34);

		MATH_USAGE const Vector3& GetTranslation() const;
		MATH_USAGE void SetTranslation(const Vector3& translation);
	};
};

static_assert((sizeof(float) * 16) == sizeof(Math::Transform4));