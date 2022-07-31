#pragma once

#include "MathCommon.h"
#include "Vector/Vector4.h"
#include <string>

namespace Math
{
	// Forward Declarations
	class Matrix3x4;
	class Vector3;

	class Matrix4x4
	{
	public:
		MATH_USAGE Matrix4x4();
		MATH_USAGE Matrix4x4(const Matrix4x4& rhs);
		MATH_USAGE Matrix4x4(const Vector4& row1, const Vector4& row2, const Vector4& row3, const Vector4& row4);
		MATH_USAGE Matrix4x4(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);

		MATH_USAGE static Matrix4x4 Identity();

		MATH_USAGE static Matrix4x4 CreateLeftHandedLookAt(const Vector3& position, const Vector3& lookAt, const Vector3& up);	
		MATH_USAGE static Matrix4x4 CreateLeftHandedPerspectiveFovProjection(float verticalFieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance);
		MATH_USAGE static Matrix4x4 CreateLeftHandOrtho(float width, float height, float nearPlaneDistance, float farPlaneDistance);
		MATH_USAGE static Matrix4x4 CreateLeftHandOrthoOffCenter(float left, float right, float bottom, float top, float nearPlaneDistance, float farPlaneDistance);



		MATH_USAGE static Matrix4x4 CreateScaling(float scale);
		MATH_USAGE static Matrix4x4 CreateScaling(float xScale, float yScale, float zScale);
		MATH_USAGE static Matrix4x4 CreateScaling(const Vector3& scale);

		MATH_USAGE static Matrix4x4 CreateTranslation(float x, float y, float z);
		MATH_USAGE static Matrix4x4 CreateTranslation(const Vector3& translation);

		MATH_USAGE static Matrix4x4 CreateRotationX(float angle);
		MATH_USAGE static Matrix4x4 CreateRotationY(float angle);
		MATH_USAGE static Matrix4x4 CreateRotationZ(float angle);
		MATH_USAGE static Matrix4x4 CreateRotationAxis(const Vector3& axis, float angle);

		MATH_USAGE static Matrix4x4 CreateShearingXY(float shear);
		MATH_USAGE static Matrix4x4 CreateShearingXZ(float shear);
		MATH_USAGE static Matrix4x4 CreateShearingYX(float shear);
		MATH_USAGE static Matrix4x4 CreateShearingYZ(float shear);
		MATH_USAGE static Matrix4x4 CreateShearingZX(float shear);
		MATH_USAGE static Matrix4x4 CreateShearingZY(float shear);

		MATH_USAGE static Matrix4x4 Transpose(const Matrix4x4& rhs);
		MATH_USAGE Matrix4x4 Transpose() const;

		MATH_USAGE static Matrix4x4 Inverse(const Matrix4x4& matrix);
		MATH_USAGE Matrix4x4 Inverse() const;

		MATH_USAGE void Multiply(const Matrix4x4& rhs);

		MATH_USAGE static float Determinant(const Matrix4x4& matrix);
		MATH_USAGE float Determinant() const;

		MATH_USAGE Matrix3x4 GetMatrix3x4() const;

		MATH_USAGE std::string ToString() const;

		MATH_USAGE bool operator==(const Matrix4x4& rhs) const;
		MATH_USAGE bool operator!=(const Matrix4x4& rhs) const;
		MATH_USAGE Matrix4x4& operator=(const Matrix4x4& rhs);

		MATH_USAGE float& operator[](unsigned int index);
		MATH_USAGE const float& operator[](unsigned int index) const;
		MATH_USAGE float& operator()(unsigned int i, unsigned int j);
		MATH_USAGE const float& operator()(unsigned int i, unsigned int j) const;

		MATH_USAGE Matrix4x4& operator*=(const Matrix4x4& rhs);

		

		union
		{
			float m[16];
			float n[4][4];
			Vector4 row[4];
		};
	};
}
 
MATH_USAGE Math::Matrix4x4 operator+(const Math::Matrix4x4& lhs, const Math::Matrix4x4& rhs);
MATH_USAGE Math::Matrix4x4 operator-(const Math::Matrix4x4& lhs, const Math::Matrix4x4& rhs);
MATH_USAGE Math::Matrix4x4 operator*(const Math::Matrix4x4& lhs, const Math::Matrix4x4& rhs);


static_assert((sizeof(float) * 16) == sizeof(Math::Matrix4x4));