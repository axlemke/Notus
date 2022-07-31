#include "Matrix/Matrix3x4.h"

#include <Framework/LibraryShell/Source/Public/CustomAssert.h>
#include "Matrix/Matrix4x4.h"
#include "Vector/Vector3.h"
#include <sstream>

using namespace Math;

Matrix3x4::Matrix3x4()
{
	row[0] = Vector4();
	row[1] = Vector4();
	row[2] = Vector4();
}

Matrix3x4::Matrix3x4(const Matrix3x4& rhs)
{
	row[0] = rhs.row[0];
	row[1] = rhs.row[1];
	row[2] = rhs.row[2];
}

Matrix3x4::Matrix3x4(const Vector4& row0, const Vector4& row1, const Vector4& row2)
{
	row[0] = row0;
	row[1] = row1;
	row[2] = row2;
}

Matrix3x4::Matrix3x4(
	float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34)
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

Matrix3x4 Matrix3x4::Identity()
{
	return Matrix3x4(
		1.0, 0.0f, 0.0f, 0.0f,
		0.0, 1.0f, 0.0f, 0.0f,
		0.0, 0.0f, 1.0f, 0.0f);
}

bool Matrix3x4::operator==(const Matrix3x4& rhs) const
{
	return ((row[0] == rhs.row[0]) && (row[1] == rhs.row[1]) && (row[2] == rhs.row[2]));
}

bool Matrix3x4::operator!=(const Matrix3x4& matrix) const
{
	return (!operator==(matrix));
}

Matrix3x4& Matrix3x4::operator=(const Matrix3x4& rhs)
{
	row[0] = rhs.row[0];
	row[1] = rhs.row[1];
	row[2] = rhs.row[2];

	return (*this);
}

Matrix3x4& Matrix3x4::operator=(const Matrix4x4& rhs)
{
	row[0] = rhs.row[0];
	row[1] = rhs.row[1];
	row[2] = rhs.row[2];

	return (*this);
}

float& Matrix3x4::operator[](unsigned int index)
{
	return m[index];
}

const float& Matrix3x4::operator[](unsigned int index) const
{
	return m[index];
}

float& Matrix3x4::operator()(unsigned int i, unsigned int j)
{
	return n[i][j];
}

const float& Matrix3x4::operator()(unsigned int i, unsigned int j) const
{
	return n[i][j];
}
