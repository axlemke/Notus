#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"
#include <string>

namespace Math
{
	// Forward Declarations
	class Matrix2x2;

	class Matrix3x3
	{
	public:
		MATH_USAGE Matrix3x3();
		MATH_USAGE Matrix3x3(const Vector3& row1, const Vector3& row2, const Vector3& row3);
		MATH_USAGE Matrix3x3(float m11, float m12, float m13,
			float m21, float m22, float m23,
			float m31, float m32, float m33);

		MATH_USAGE static Matrix3x3 Identity();

		MATH_USAGE static Matrix3x3 CreateLookAt(const Vector3& position, const Vector3& lookAt, const Vector3& up);

		MATH_USAGE static Matrix3x3 CreateProjection(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance);

		MATH_USAGE static Matrix3x3 CreateLeftHandOrtho(float width, float height, float nearPlaneDistance, float farPlaneDistance);
		MATH_USAGE static Matrix3x3 CreateLeftHandOrthoOffCenter(float left, float right, float bottom, float top, float nearPlaneDistance, float farPlaneDistance);

		MATH_USAGE static Matrix3x3 CreateScaling(float scale);
		MATH_USAGE static Matrix3x3 CreateScaling(float xScale, float yScale, float zScale);
		MATH_USAGE static Matrix3x3 CreateScaling(float scale, const Vector3& axis);

		MATH_USAGE static Matrix3x3 CreateSkew(float angle, const Vector3& directionA, const Vector3& directionB);

		MATH_USAGE static Matrix3x3 CreateRotationX(float angle);
		MATH_USAGE static Matrix3x3 CreateRotationY(float angle);
		MATH_USAGE static Matrix3x3 CreateRotationZ(float angle);
		MATH_USAGE static Matrix3x3 CreateRotationAxis(const Vector3& axis, float angle);

		MATH_USAGE static Matrix3x3 Inverse(const Matrix3x3& rhs);
		MATH_USAGE Matrix3x3 Inverse() const;

		MATH_USAGE static Matrix3x3 Transpose(const Matrix3x3& rhs);
		MATH_USAGE Matrix3x3 Transpose() const;

		MATH_USAGE static float Determinant(const Matrix3x3& matrix);
		MATH_USAGE float Determinant() const;

		MATH_USAGE void Multiply(const Matrix3x3& rhs);

		MATH_USAGE Matrix2x2 Minor(unsigned i, unsigned j) const;
		MATH_USAGE float Cofactor(unsigned i, unsigned j) const;

		MATH_USAGE std::string ToString() const;

		MATH_USAGE bool operator==(const Matrix3x3& rhs) const;
		MATH_USAGE bool operator!=(const Matrix3x3& rhs) const;
		MATH_USAGE Matrix3x3& operator=(const Matrix3x3& rhs);

		MATH_USAGE float& operator[](unsigned int index);
		MATH_USAGE const float& operator[](unsigned int index) const;
		MATH_USAGE float& operator()(unsigned int i, unsigned int j);
		MATH_USAGE const float& operator()(unsigned int i, unsigned int j) const;

		MATH_USAGE Matrix3x3& operator*(const Matrix3x3& rhs);
		
		MATH_USAGE Matrix3x3 operator*=(float rhs);

		union
		{
			float n[3][3];
			Vector3 row[3];
			float m[9];
		};
	};

	MATH_USAGE Matrix3x3 Inverse(const Matrix3x3& rhs);
}

MATH_USAGE Math::Matrix3x3 operator*(const Math::Matrix3x3& lhs, const Math::Matrix3x3& rhs);
MATH_USAGE Math::Vector3 operator*(const Math::Matrix3x3& lhs, const Math::Vector3 rhs);
MATH_USAGE Math::Matrix3x3 operator*(const Math::Matrix3x3& lhs, float rhs);

static_assert((sizeof(float) * 9) == sizeof(Math::Matrix3x3));