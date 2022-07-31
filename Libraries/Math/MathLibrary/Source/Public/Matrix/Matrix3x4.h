#pragma once

#include "MathCommon.h"
#include "Vector/Vector4.h"
#include <string>


namespace Math
{
	// Forward Declarations
	class Vector3;
	class Matrix4x4;

	class Matrix3x4
	{
	public:
		MATH_USAGE Matrix3x4();
		MATH_USAGE Matrix3x4(const Matrix3x4& rhs);
		MATH_USAGE Matrix3x4(const Vector4& row1, const Vector4& row2, const Vector4& row3);
		MATH_USAGE Matrix3x4(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34);

		MATH_USAGE static Matrix3x4 Identity();

		MATH_USAGE std::string ToString() const;

		MATH_USAGE bool operator==(const Matrix3x4& rhs) const;
		MATH_USAGE bool operator!=(const Matrix3x4& rhs) const;
		MATH_USAGE Matrix3x4& operator=(const Matrix3x4& rhs);
		MATH_USAGE Matrix3x4& operator=(const Matrix4x4& rhs);

		MATH_USAGE float& operator[](unsigned int index);
		MATH_USAGE const float& operator[](unsigned int index) const;
		MATH_USAGE float& operator()(unsigned int i, unsigned int j);
		MATH_USAGE const float& operator()(unsigned int i, unsigned int j) const;

		union
		{
			float m[12];
			float n[3][4];
			Vector4 row[3];
		};
	};
}

MATH_USAGE Math::Matrix3x4 operator*(const Math::Matrix3x4& lhs, const Math::Matrix3x4& rhs);

static_assert((sizeof(float) * 12) == sizeof(Math::Matrix3x4));