#pragma once

#include "MathCommon.h"
#include "Quaternion/Quaternion.h"
#include "Matrix/Matrix4x4.h"
#include "Vector/Vector3.h"

namespace Math
{
	class Transform
	{
	public:
		MATH_USAGE Transform();
		MATH_USAGE Transform(const Vector3& translation, const Quaternion& rotation, const Vector3& scale);

		MATH_USAGE const Vector3& GetScale() const;
		MATH_USAGE Vector3& GetScale();
		MATH_USAGE void SetScale(const Vector3& scale);
		MATH_USAGE void SetScale(float uniformScale);

		MATH_USAGE const Quaternion& GetRotation() const;
		MATH_USAGE Quaternion& GetRotation();
		MATH_USAGE void SetRotation(const Quaternion& rotation);
		MATH_USAGE void SetRotation(const Matrix4x4& matrix);

		MATH_USAGE const Vector3& GetTranslation() const;
		MATH_USAGE Vector3& GetTranslation();
		MATH_USAGE void SetTranslation(const Vector3& translation);
		MATH_USAGE void SetTranslation(float x, float y, float z);

		MATH_USAGE Matrix4x4 GetTransformMatrix4x4() const;

		Quaternion m_rotation;
		Vector3 m_scale;
		Vector3 m_translation;
	};

	MATH_USAGE Transform Lerp(const Transform& a, const Transform& b, float t);
	MATH_USAGE Transform Combine(const Transform& a, const Transform& b);
	MATH_USAGE Transform Inverse(const Transform& transform);
};

static_assert((sizeof(float) * 10) == sizeof(Math::Transform));