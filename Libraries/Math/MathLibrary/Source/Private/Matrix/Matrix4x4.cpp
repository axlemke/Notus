#include "Matrix/Matrix4x4.h"

#include <Framework/LibraryShell/Source/Public/CustomAssert.h>
#include "Matrix/Matrix3x4.h"
#include "Vector/Vector3.h"
#include <sstream>

using namespace Math;

Matrix4x4::Matrix4x4()
{
	row[0] = Vector4();
	row[1] = Vector4();
	row[2] = Vector4();
	row[3] = Vector4();
}

Matrix4x4::Matrix4x4(const Matrix4x4& rhs)
{
	row[0] = rhs.row[0];
	row[1] = rhs.row[1];
	row[2] = rhs.row[2];
	row[3] = rhs.row[3];
}

Matrix4x4::Matrix4x4(const Vector4& row0, const Vector4& row1, const Vector4& row2, const Vector4& row3)
{
	row[0] = row0;
	row[1] = row1;
	row[2] = row2;
	row[3] = row3;
}

Matrix4x4::Matrix4x4(
	float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44)
{
	n[0][0] = m11;
	n[0][1] = m12;
	n[0][2] = m13;
	n[0][3] = m14;

	n[1][0] = m21;
	n[1][1] = m22;
	n[1][2] = m23;
	n[1][3] = m24;

	n[2][0] = m31;
	n[2][1] = m32;
	n[2][2] = m33;
	n[2][3] = m34;

	n[3][0] = m41;
	n[3][1] = m42;
	n[3][2] = m43;
	n[3][3] = m44;
}

/*Vector3 Matrix::Forward()
{
	return Vector3(-_31, -_32, -_33);
}

Vector3 Matrix::Right()
{
	return Vector3(_11, _12, _13);
}

Vector3 Matrix::Up()
{
	return Vector3(_21, _22, _23);
}*/	

Matrix4x4 Matrix4x4::Identity()
{
	return Matrix4x4(
		1.0, 0.0f, 0.0f, 0.0f, 
		0.0, 1.0f, 0.0f, 0.0f,
		0.0, 0.0f, 1.0f, 0.0f,
		0.0, 0.0f, 0.0f, 1.0f);
}

float Matrix4x4::Determinant(const Matrix4x4& matrix)
{
	float determinant;
		
	determinant = matrix.n[0][3] * matrix.n[1][2] * matrix.n[2][1] * matrix.n[3][0] - matrix.n[0][2] * matrix.n[1][3] * matrix.n[2][1] * matrix.n[3][0] -
		matrix.n[0][3] * matrix.n[1][1] * matrix.n[2][2] * matrix.n[3][0] + matrix.n[0][1] * matrix.n[1][3] * matrix.n[2][2] * matrix.n[3][0] +
		matrix.n[0][2] * matrix.n[1][1] * matrix.n[2][3] * matrix.n[3][0] - matrix.n[0][1] * matrix.n[1][2] * matrix.n[2][3] * matrix.n[3][0] -
		matrix.n[0][3] * matrix.n[1][2] * matrix.n[2][0] * matrix.n[3][1] + matrix.n[0][2] * matrix.n[1][3] * matrix.n[2][0] * matrix.n[3][1] +
		matrix.n[0][3] * matrix.n[1][0] * matrix.n[2][2] * matrix.n[3][1] - matrix.n[0][0] * matrix.n[1][3] * matrix.n[2][2] * matrix.n[3][1] -
		matrix.n[0][2] * matrix.n[1][0] * matrix.n[2][3] * matrix.n[3][1] + matrix.n[0][0] * matrix.n[1][2] * matrix.n[2][3] * matrix.n[3][1] +
		matrix.n[0][3] * matrix.n[1][1] * matrix.n[2][0] * matrix.n[3][2] - matrix.n[0][1] * matrix.n[1][3] * matrix.n[2][0] * matrix.n[3][2] -
		matrix.n[0][3] * matrix.n[1][0] * matrix.n[2][1] * matrix.n[3][2] + matrix.n[0][0] * matrix.n[1][3] * matrix.n[2][1] * matrix.n[3][2] +
		matrix.n[0][1] * matrix.n[1][0] * matrix.n[2][3] * matrix.n[3][2] - matrix.n[0][0] * matrix.n[1][1] * matrix.n[2][3] * matrix.n[3][2] -
		matrix.n[0][2] * matrix.n[1][1] * matrix.n[2][0] * matrix.n[3][3] + matrix.n[0][1] * matrix.n[1][2] * matrix.n[2][0] * matrix.n[3][3] +
		matrix.n[0][2] * matrix.n[1][0] * matrix.n[2][1] * matrix.n[3][3] - matrix.n[0][0] * matrix.n[1][2] * matrix.n[2][1] * matrix.n[3][3] -
		matrix.n[0][1] * matrix.n[1][0] * matrix.n[2][2] * matrix.n[3][3] + matrix.n[0][0] * matrix.n[1][1] * matrix.n[2][2] * matrix.n[3][3];

	return determinant;
}

Matrix4x4 Matrix4x4::Inverse(const Matrix4x4& matrix)
{
	Matrix4x4 inverse;

	float s0 = matrix.n[0][0] * matrix.n[1][1] - matrix.n[1][0] * matrix.n[0][1];
	float s1 = matrix.n[0][0] * matrix.n[1][2] - matrix.n[1][0] * matrix.n[0][2];
	float s2 = matrix.n[0][0] * matrix.n[1][3] - matrix.n[1][0] * matrix.n[0][3];
	float s3 = matrix.n[0][1] * matrix.n[1][2] - matrix.n[1][1] * matrix.n[0][2];
	float s4 = matrix.n[0][1] * matrix.n[1][3] - matrix.n[1][1] * matrix.n[0][3];
	float s5 = matrix.n[0][2] * matrix.n[1][3] - matrix.n[1][2] * matrix.n[0][3];

	float c5 = matrix.n[2][2] * matrix.n[3][3] - matrix.n[3][2] * matrix.n[2][3];
	float c4 = matrix.n[2][1] * matrix.n[3][3] - matrix.n[3][1] * matrix.n[2][3];
	float c3 = matrix.n[2][1] * matrix.n[3][2] - matrix.n[3][1] * matrix.n[2][2];
	float c2 = matrix.n[2][0] * matrix.n[3][3] - matrix.n[3][0] * matrix.n[2][3];
	float c1 = matrix.n[2][0] * matrix.n[3][2] - matrix.n[3][0] * matrix.n[2][2];
	float c0 = matrix.n[2][0] * matrix.n[3][1] - matrix.n[3][0] * matrix.n[2][1];

	// Should check for 0 determinant
	float inverseDeterminant = 1.0f / (s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0);

	inverse.n[0][0] = (matrix.n[1][1] * c5 - matrix.n[1][2] * c4 + matrix.n[1][3] * c3) * inverseDeterminant;
	inverse.n[0][1] = (-matrix.n[0][1] * c5 + matrix.n[0][2] * c4 - matrix.n[0][3] * c3) * inverseDeterminant;
	inverse.n[0][2] = (matrix.n[3][1] * s5 - matrix.n[3][2] * s4 + matrix.n[3][3] * s3) * inverseDeterminant;
	inverse.n[0][3] = (-matrix.n[2][1] * s5 + matrix.n[2][2] * s4 - matrix.n[2][3] * s3) * inverseDeterminant;

	inverse.n[1][0] = (-matrix.n[1][0] * c5 + matrix.n[1][2] * c2 - matrix.n[1][3] * c1) * inverseDeterminant;
	inverse.n[1][1] = (matrix.n[0][0] * c5 - matrix.n[0][2] * c2 + matrix.n[0][3] * c1) * inverseDeterminant;
	inverse.n[1][2] = (-matrix.n[3][0] * s5 + matrix.n[3][2] * s2 - matrix.n[3][3] * s1) * inverseDeterminant;
	inverse.n[1][3] = (matrix.n[2][0] * s5 - matrix.n[2][2] * s2 + matrix.n[2][3] * s1) * inverseDeterminant;

	inverse.n[2][0] = (matrix.n[1][0] * c4 - matrix.n[1][1] * c2 + matrix.n[1][3] * c0) * inverseDeterminant;
	inverse.n[2][1] = (-matrix.n[0][0] * c4 + matrix.n[0][1] * c2 - matrix.n[0][3] * c0) * inverseDeterminant;
	inverse.n[2][2] = (matrix.n[3][0] * s4 - matrix.n[3][1] * s2 + matrix.n[3][3] * s0) * inverseDeterminant;
	inverse.n[2][3] = (-matrix.n[2][0] * s4 + matrix.n[2][1] * s2 - matrix.n[2][3] * s0) * inverseDeterminant;

	inverse.n[3][0] = (-matrix.n[1][0] * c3 + matrix.n[1][1] * c1 - matrix.n[1][2] * c0) * inverseDeterminant;
	inverse.n[3][1] = (matrix.n[0][0] * c3 - matrix.n[0][1] * c1 + matrix.n[0][2] * c0) * inverseDeterminant;
	inverse.n[3][2] = (-matrix.n[3][0] * s3 + matrix.n[3][1] * s1 - matrix.n[3][2] * s0) * inverseDeterminant;
	inverse.n[3][3] = (matrix.n[2][0] * s3 - matrix.n[2][1] * s1 + matrix.n[2][2] * s0) * inverseDeterminant;

	//double A2323 = matrix(2, 2) * matrix(3, 3) - matrix(2, 3) * matrix(3, 2);
	//double A1323 = matrix(2, 1) * matrix(3, 3) - matrix(2, 3) * matrix(3, 1);
	//double A1223 = matrix(2, 1) * matrix(3, 2) - matrix(2, 2) * matrix(3, 1);
	//double A0323 = matrix(2, 0) * matrix(3, 3) - matrix(2, 3) * matrix(3, 0);
	//double A0223 = matrix(2, 0) * matrix(3, 2) - matrix(2, 2) * matrix(3, 0);
	//double A0123 = matrix(2, 0) * matrix(3, 1) - matrix(2, 1) * matrix(3, 0);
	//double A2313 = matrix(1, 2) * matrix(3, 3) - matrix(1, 3) * matrix(3, 2);
	//double A1313 = matrix(1, 1) * matrix(3, 3) - matrix(1, 3) * matrix(3, 1);
	//double A1213 = matrix(1, 1) * matrix(3, 2) - matrix(1, 2) * matrix(3, 1);
	//double A2312 = matrix(1, 2) * matrix(2, 3) - matrix(1, 3) * matrix(2, 2);
	//double A1312 = matrix(1, 1) * matrix(2, 3) - matrix(1, 3) * matrix(2, 1);
	//double A1212 = matrix(1, 1) * matrix(2, 2) - matrix(1, 2) * matrix(2, 1);
	//double A0313 = matrix(1, 0) * matrix(3, 3) - matrix(1, 3) * matrix(3, 0);
	//double A0213 = matrix(1, 0) * matrix(3, 2) - matrix(1, 2) * matrix(3, 0);
	//double A0312 = matrix(1, 0) * matrix(2, 3) - matrix(1, 3) * matrix(2, 0);
	//double A0212 = matrix(1, 0) * matrix(2, 2) - matrix(1, 2) * matrix(2, 0);
	//double A0113 = matrix(1, 0) * matrix(3, 1) - matrix(1, 1) * matrix(3, 0);
	//double A0112 = matrix(1, 0) * matrix(2, 1) - matrix(1, 1) * matrix(2, 0);

	//double determinant = matrix(0, 0) * (matrix(1, 1) * A2323 - matrix(1, 2) * A1323 + matrix(1, 3) * A1223)
	//	- matrix(0, 1) * (matrix(1, 0) * A2323 - matrix(1, 2) * A0323 + matrix(1, 3) * A0223)
	//	+ matrix(0, 2) * (matrix(1, 0) * A1323 - matrix(1, 1) * A0323 + matrix(1, 3) * A0123)
	//	- matrix(0, 3) * (matrix(1, 0) * A1223 - matrix(1, 1) * A0223 + matrix(1, 2) * A0123);

	//double inverseDeterminant = 1 / determinant;

	//inverse(0, 0) = inverseDeterminant * (matrix(1, 1) * A2323 - matrix(1, 2) * A1323 + matrix(1, 3) * A1223);
	//inverse(0, 1) = inverseDeterminant * -(matrix(0, 1) * A2323 - matrix(0, 2) * A1323 + matrix(0, 3) * A1223);
	//inverse(0, 2) = inverseDeterminant * (matrix(0, 1) * A2313 - matrix(0, 2) * A1313 + matrix(0, 3) * A1213);
	//inverse(0, 3) = inverseDeterminant * -(matrix(0, 1) * A2312 - matrix(0, 2) * A1312 + matrix(0, 3) * A1212);
	//inverse(1, 0) = inverseDeterminant * -(matrix(1, 0) * A2323 - matrix(1, 2) * A0323 + matrix(1, 3) * A0223);
	//inverse(1, 1) = inverseDeterminant * (matrix(0, 0) * A2323 - matrix(0, 2) * A0323 + matrix(0, 3) * A0223);
	//inverse(1, 2) = inverseDeterminant * -(matrix(0, 0) * A2313 - matrix(0, 2) * A0313 + matrix(0, 3) * A0213);
	//inverse(1, 3) = inverseDeterminant * (matrix(0, 0) * A2312 - matrix(0, 2) * A0312 + matrix(0, 3) * A0212);
	//inverse(2, 0) = inverseDeterminant * (matrix(1, 0) * A1323 - matrix(1, 1) * A0323 + matrix(1, 3) * A0123);
	//inverse(2, 1) = inverseDeterminant * -(matrix(0, 0) * A1323 - matrix(0, 1) * A0323 + matrix(0, 3) * A0123);
	//inverse(2, 2) = inverseDeterminant * (matrix(0, 0) * A1313 - matrix(0, 1) * A0313 + matrix(0, 3) * A0113);
	//inverse(2, 3) = inverseDeterminant * -(matrix(0, 0) * A1312 - matrix(0, 1) * A0312 + matrix(0, 3) * A0112);
	//inverse(3, 0) = inverseDeterminant * -(matrix(1, 0) * A1223 - matrix(1, 1) * A0223 + matrix(1, 2) * A0123);
	//inverse(3, 1) = inverseDeterminant * (matrix(0, 0) * A1223 - matrix(0, 1) * A0223 + matrix(0, 2) * A0123);
	//inverse(3, 2) = inverseDeterminant * -(matrix(0, 0) * A1213 - matrix(0, 1) * A0213 + matrix(0, 2) * A0113);
	//inverse(3, 3) = inverseDeterminant * (matrix(0, 0) * A1212 - matrix(0, 1) * A0212 + matrix(0, 2) * A0112);


	return inverse;
}

Matrix4x4 Matrix4x4::Inverse() const
{
	return Matrix4x4::Inverse(*this);
}

Matrix4x4 Matrix4x4::CreateLeftHandedLookAt(const Vector3& position, const Vector3& lookAt, const Vector3& up)
{
	Vector3 zAxis = Normalize(lookAt - position);
	Vector3	xAxis = Normalize(Cross(up, zAxis));
	Vector3	yAxis = Cross(zAxis, xAxis);

	return Matrix4x4(
		xAxis.x, yAxis.x, zAxis.x, 0.0f,
		xAxis.y, yAxis.y, zAxis.y, 0.0f,
		xAxis.z, yAxis.z, zAxis.z, 0.0f,
		-Dot(xAxis, position), -Dot(yAxis, position), -Dot(zAxis, position), 1.0f);
}

Matrix4x4 Matrix4x4::CreateLeftHandedPerspectiveFovProjection(float verticalFieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance)
{
	float zRange = farPlaneDistance - nearPlaneDistance;
	HB_ASSERT(zRange != 0.0f);
	float h = 1.0f / tanf(verticalFieldOfView * 0.5f);

	HB_ASSERT(aspectRatio != 0.0f);
	float w = h / aspectRatio;

	return Matrix4x4(
		w, 0.0f, 0.0f, 0.0f,
		0.0f, h, 0.0f, 0.0f,
		0.0f, 0.0f, farPlaneDistance / zRange, 1.0f,
		0.0f, 0.0f, (-nearPlaneDistance * farPlaneDistance) / zRange, 0.0f);
}

Matrix4x4 Matrix4x4::CreateLeftHandOrtho(float width, float height, float nearPlaneDistance, float farPlaneDistance)
{
	return Matrix4x4(2.0f / width,  0.0f, 0.0f, 0.0f,
		0.0f, 2.0f / height, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f / (farPlaneDistance - nearPlaneDistance), 0.0f,
		0.0f, 0.0f, -nearPlaneDistance / (farPlaneDistance - nearPlaneDistance), 1.0f);
}

Matrix4x4 Matrix4x4::CreateLeftHandOrthoOffCenter(float left, float right, float bottom, float top, float nearPlaneDistance, float farPlaneDistance)
{
	float width = right - left;
	float height = top - bottom;
	float length = farPlaneDistance - nearPlaneDistance;

	return Matrix4x4(
		2.0f / width, 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f / height, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f / length, 0.0f,
		(left + right) / width, (top + bottom) / height, nearPlaneDistance / (nearPlaneDistance - farPlaneDistance), 1.0f);
}

void Matrix4x4::Multiply(const Matrix4x4& rhs)
{
	Matrix4x4 resultMatrix = Matrix4x4(
		n[0][0] * rhs.n[0][0] + n[0][1] * rhs.n[1][0] + n[0][2] * rhs.n[2][0] + n[0][3] * rhs.n[3][0],
		n[0][0] * rhs.n[0][1] + n[0][1] * rhs.n[1][1] + n[0][2] * rhs.n[2][1] + n[0][3] * rhs.n[3][1],
		n[0][0] * rhs.n[0][2] + n[0][1] * rhs.n[1][2] + n[0][2] * rhs.n[2][2] + n[0][3] * rhs.n[3][2],
		n[0][0] * rhs.n[0][3] + n[0][1] * rhs.n[1][3] + n[0][2] * rhs.n[2][3] + n[0][3] * rhs.n[3][3],
		n[1][0] * rhs.n[0][0] + n[1][1] * rhs.n[1][0] + n[1][2] * rhs.n[2][0] + n[1][3] * rhs.n[3][0],
		n[1][0] * rhs.n[0][1] + n[1][1] * rhs.n[1][1] + n[1][2] * rhs.n[2][1] + n[1][3] * rhs.n[3][1],
		n[1][0] * rhs.n[0][2] + n[1][1] * rhs.n[1][2] + n[1][2] * rhs.n[2][2] + n[1][3] * rhs.n[3][2],
		n[1][0] * rhs.n[0][3] + n[1][1] * rhs.n[1][3] + n[1][3] * rhs.n[2][3] + n[1][3] * rhs.n[3][3],
		n[2][0] * rhs.n[0][0] + n[2][1] * rhs.n[1][0] + n[2][2] * rhs.n[2][0] + n[2][3] * rhs.n[3][0], 
		n[2][0] * rhs.n[0][1] + n[2][1] * rhs.n[1][1] + n[2][2] * rhs.n[2][1] + n[2][3] * rhs.n[3][1],
		n[2][0] * rhs.n[0][2] + n[2][1] * rhs.n[1][2] + n[2][2] * rhs.n[2][2] + n[2][3] * rhs.n[3][2],
		n[2][0] * rhs.n[0][3] + n[2][1] * rhs.n[1][3] + n[2][2] * rhs.n[2][3] + n[2][3] * rhs.n[3][3],
		n[3][0] * rhs.n[0][0] + n[3][1] * rhs.n[1][0] + n[3][2] * rhs.n[2][0] + n[3][3] * rhs.n[3][0],
		n[3][0] * rhs.n[0][1] + n[3][1] * rhs.n[1][1] + n[3][2] * rhs.n[2][1] + n[3][3] * rhs.n[3][1],
		n[3][0] * rhs.n[0][2] + n[3][1] * rhs.n[1][2] + n[3][2] * rhs.n[3][2] + n[3][3] * rhs.n[3][2],
		n[3][0] * rhs.n[0][3] + n[3][1] * rhs.n[1][3] + n[3][2] * rhs.n[3][3] + n[3][3] * rhs.n[3][3]);

	*this = resultMatrix;
}

float Matrix4x4::Determinant() const 
{
	return Matrix4x4::Determinant(*this);
}

Matrix3x4 Matrix4x4::GetMatrix3x4() const
{
	Matrix3x4 result;

	result.row[0] = Math::Vector4(n[0][0], n[1][0], n[2][0], n[3][0]);
	result.row[1] = Math::Vector4(n[0][1], n[1][1], n[2][1], n[3][1]);
	result.row[2] = Math::Vector4(n[0][2], n[1][2], n[2][2], n[3][2]);

	return result;
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& rhs)
{
	//Multiply(rhs);

	Matrix4x4 resultMatrix;

	for (unsigned i = 0; i < 4; ++i)
	{
		for (unsigned j = 0; j < 4; ++j)
		{
			resultMatrix.n[i][j] = 0.0f;

			for (unsigned k = 0; k < 4; ++k)
			{
				resultMatrix.n[i][j] += n[i][k] * rhs.n[k][j];
			}
		}
	}

	//Matrix4x4 returnValue = Matrix4x4(
	//	n[0][0] * rhs.n[0][0] + n[0][1] * rhs.n[1][0] + n[0][2] * rhs.n[2][0] + n[0][3] * rhs.n[3][0],
	//	n[0][0] * rhs.n[0][1] + n[0][1] * rhs.n[1][1] + n[0][2] * rhs.n[2][1] + n[0][3] * rhs.n[3][1],
	//	n[0][0] * rhs.n[0][2] + n[0][1] * rhs.n[1][2] + n[0][2] * rhs.n[2][2] + n[0][3] * rhs.n[3][2],
	//	n[0][0] * rhs.n[0][3] + n[0][1] * rhs.n[1][3] + n[0][2] * rhs.n[2][3] + n[0][3] * rhs.n[3][3],
	//	n[1][0] * rhs.n[0][0] + n[1][1] * rhs.n[1][0] + n[1][2] * rhs.n[2][0] + n[1][3] * rhs.n[3][0],
	//	n[1][0] * rhs.n[0][1] + n[1][1] * rhs.n[1][1] + n[1][2] * rhs.n[2][1] + n[1][3] * rhs.n[3][1],
	//	n[1][0] * rhs.n[0][2] + n[1][1] * rhs.n[1][2] + n[1][2] * rhs.n[2][2] + n[1][3] * rhs.n[3][2],
	//	n[1][0] * rhs.n[0][3] + n[1][1] * rhs.n[1][3] + n[1][3] * rhs.n[2][3] + n[1][3] * rhs.n[3][3],
	//	n[2][0] * rhs.n[0][0] + n[2][1] * rhs.n[1][0] + n[2][2] * rhs.n[2][0] + n[2][3] * rhs.n[3][0],
	//	n[2][0] * rhs.n[0][1] + n[2][1] * rhs.n[1][1] + n[2][2] * rhs.n[2][1] + n[2][3] * rhs.n[3][1],
	//	n[2][0] * rhs.n[0][2] + n[2][1] * rhs.n[1][2] + n[2][2] * rhs.n[2][2] + n[2][3] * rhs.n[3][2],
	//	n[2][0] * rhs.n[0][3] + n[2][1] * rhs.n[1][3] + n[2][2] * rhs.n[2][3] + n[2][3] * rhs.n[3][3],
	//	n[3][0] * rhs.n[0][0] + n[3][1] * rhs.n[1][0] + n[3][2] * rhs.n[2][0] + n[3][3] * rhs.n[3][0],
	//	n[3][0] * rhs.n[0][1] + n[3][1] * rhs.n[1][1] + n[3][2] * rhs.n[2][1] + n[3][3] * rhs.n[3][1],
	//	n[3][0] * rhs.n[0][2] + n[3][1] * rhs.n[1][2] + n[3][2] * rhs.n[3][2] + n[3][3] * rhs.n[3][2],
	//	n[3][0] * rhs.n[0][3] + n[3][1] * rhs.n[1][3] + n[3][2] * rhs.n[3][3] + n[3][3] * rhs.n[3][3]);

	// 	return resultMatrix;

	//DirectX::FXMMATRIX m0;
	//m0.r[0].m128_f32[0] = row[0].x;
	//m0.r[0].m128_f32[1] = row[0].y;
	//m0.r[0].m128_f32[2] = row[0].z;
	//m0.r[0].m128_f32[3] = row[0].w;

	//DirectX::CXMMATRIX m1;

	//DirectX::XMMATRIX xmReturnValue = DirectX::XMMatrixMultiply(m0, m1);

	//returnValue.row[0] = Vector4(xmReturnValue.r[0].m128_f32[0], xmReturnValue.r[0].m128_f32[1], xmReturnValue.r[0].m128_f32[2], xmReturnValue.r[0].m128_f32[3]);
	//returnValue.row[1] = Vector4(xmReturnValue.r[1].m128_f32[0], xmReturnValue.r[1].m128_f32[1], xmReturnValue.r[1].m128_f32[2], xmReturnValue.r[1].m128_f32[3]);
	//returnValue.row[2] = Vector4(xmReturnValue.r[2].m128_f32[0], xmReturnValue.r[2].m128_f32[1], xmReturnValue.r[2].m128_f32[2], xmReturnValue.r[2].m128_f32[3]);
	//returnValue.row[3] = Vector4(xmReturnValue.r[3].m128_f32[0], xmReturnValue.r[3].m128_f32[1], xmReturnValue.r[3].m128_f32[2], xmReturnValue.r[3].m128_f32[3]);

	(*this) = resultMatrix;

	return (*this);
}

 Matrix4x4 Matrix4x4::CreateScaling(float scale)
{
	 return CreateScaling(scale, scale, scale);
}

Matrix4x4 Matrix4x4::CreateScaling(float xScale, float yScale, float zScale)
{
	return Matrix4x4(
		xScale, 0.0f, 0.0f, 0.0f, 
		0.0f, yScale, 0.0f, 0.0f, 
		0.0f, 0.0f, zScale, 0.0f, 
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateScaling(const Vector3& scale)
{
	return CreateScaling(scale.x, scale.y, scale.z);
}

Matrix4x4 Matrix4x4::CreateTranslation(float x, float y, float z)
{
	return Matrix4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		x, y, z, 1.0f);
}

Matrix4x4 Matrix4x4::CreateTranslation(const Vector3& translation)
{
	return CreateTranslation(translation.x, translation.y, translation.z);
}

Matrix4x4 Matrix4x4::CreateRotationX(float angle)
{
	float cosAngle = cos(angle);
	float sinAngle = sin(angle);

	return Matrix4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cosAngle, -sinAngle, 0.0f,
		0.0f, sinAngle, cosAngle, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateRotationY(float angle)
{
	float cosAngle = cos(angle);
	float sinAngle = sin(angle);

	return Matrix4x4(
		cosAngle, 0.0f, sinAngle, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		-sinAngle, 0.0f, cosAngle, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateRotationZ(float angle)
{
	float cosAngle = cos(angle);
	float sinAngle = sin(angle);

	return Matrix4x4(
		cosAngle, -sinAngle, 0.0f, 0.0f,
		sinAngle, cosAngle, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateRotationAxis(const Vector3& axis, float angle)
{
	Matrix4x4 returnValue;
	//returnValue = DirectX::XMMatrixRotationAxis(XMLoadFloat3(&axis), angle);
	return returnValue;
}

Matrix4x4 Matrix4x4::CreateShearingXY(float shear)
{
	return Matrix4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		shear, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateShearingXZ(float shear)
{
	return Matrix4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		shear, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateShearingYX(float shear)
{
	return Matrix4x4(
		1.0f, shear, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateShearingYZ(float shear)
{
	return Matrix4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, shear, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateShearingZX(float shear)
{
	return Matrix4x4(
		1.0f, 0.0f, shear, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateShearingZY(float shear)
{
	return Matrix4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, shear, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::Transpose(const Matrix4x4& rhs)
{
	Matrix4x4 returnValue;
	//XMStoreFloat4x4(&returnValue, XMMatrixTranspose(XMLoadFloat4x4(&matrix)));

	for (unsigned i = 0; i < 4; ++i)
	{
		for (unsigned j = 0; j < 4; ++j)
		{
			returnValue.n[j][i] = rhs.n[i][j];
		}
	}
	return returnValue;
}

Matrix4x4 Matrix4x4::Transpose() const
{
	return Transpose(*this);
}

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& rhs)
{
	row[0] = rhs.row[0];
	row[1] = rhs.row[1];
	row[2] = rhs.row[2];
	row[3] = rhs.row[3];

	return (*this);
}

float& Matrix4x4::operator[](unsigned int index)
{
	return m[index];
}

const float& Matrix4x4::operator[](unsigned int index) const
{
	return m[index];
}

float& Matrix4x4::operator()(unsigned int i, unsigned int j)
{
	return n[i][j];
}

const float& Matrix4x4::operator()(unsigned int i, unsigned int j) const
{
	return n[i][j];
}

//Matrix& Matrix::operator=(const DirectX::XMMATRIX& rhs)
//{
//	DirectX::XMFLOAT4X4& matrixTemp = (DirectX::XMFLOAT4X4&)(rhs);
//
//	//MathAssert(false);
//	this->_11 = matrixTemp._11;
//	this->_12 = matrixTemp._12;
//	this->_13 = matrixTemp._13;
//	this->_14 = matrixTemp._14;
//
//	this->_21 = matrixTemp._21;
//	this->_22 = matrixTemp._22;
//	this->_23 = matrixTemp._23;
//	this->_24 = matrixTemp._24;
//
//	this->_31 = matrixTemp._31;
//	this->_32 = matrixTemp._32;
//	this->_33 = matrixTemp._33;
//	this->_34 = matrixTemp._34;
//
//	this->_41 = matrixTemp._41;
//	this->_42 = matrixTemp._42;
//	this->_43 = matrixTemp._43;
//	this->_44 = matrixTemp._44;
//
//	return *this;
//}

std::string Matrix4x4::ToString() const
{
	std::stringstream returnValueStream;
	returnValueStream << row[0].ToString() << ", ";
	returnValueStream << row[1].ToString() << ", ";
	returnValueStream << row[2].ToString() << ", ";
	returnValueStream << row[3].ToString();

	return returnValueStream.str();
}

bool Matrix4x4::operator==(const Matrix4x4& rhs) const
{
	return ((row[0] == rhs.row[0]) && (row[1] == rhs.row[1]) && (row[2] == rhs.row[2]) && (row[3] == rhs.row[3]));
}

bool Matrix4x4::operator!=(const Matrix4x4& matrix) const
{
	return (!operator==(matrix));
}

Matrix4x4 operator+(const Matrix4x4& lhs, const Matrix4x4& rhs)
{
	Matrix4x4 resultMatrix;

	resultMatrix.row[0] = lhs.row[0] + rhs.row[0];
	resultMatrix.row[1] = lhs.row[1] + rhs.row[1];
	resultMatrix.row[2] = lhs.row[2] + rhs.row[2];
	resultMatrix.row[3] = lhs.row[3] + rhs.row[3];

	return resultMatrix;
}

Matrix4x4 operator-(const Matrix4x4& lhs, const Matrix4x4& rhs)
{
	Matrix4x4 resultMatrix;

	resultMatrix.row[0] = lhs.row[0] - rhs.row[0];
	resultMatrix.row[1] = lhs.row[1] - rhs.row[1];
	resultMatrix.row[2] = lhs.row[2] - rhs.row[2];
	resultMatrix.row[3] = lhs.row[3] - rhs.row[3];

	return resultMatrix;
}

Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs)
{
	Matrix4x4 resultMatrix;

	for (unsigned i = 0; i < 4; ++i)
	{
		for (unsigned j = 0; j < 4; ++j)
		{
			resultMatrix.n[i][j] = 0.0f;

			for (unsigned k = 0; k < 4; ++k)
			{
				resultMatrix.n[i][j] += lhs.n[i][k] * rhs.n[k][j];
			}
		}
	}
	return resultMatrix;
}
