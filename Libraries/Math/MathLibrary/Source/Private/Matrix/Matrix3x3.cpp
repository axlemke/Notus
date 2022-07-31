#include "Matrix/Matrix3x3.h"

#include "Framework/LibraryShell/Source/Public/CustomAssert.h"
#include "Matrix/Matrix2x2.h"
#include "Vector/Vector4.h"
#include <sstream>

using namespace Math;

Matrix3x3::Matrix3x3()
{
	row[0] = Vector3();
	row[1] = Vector3();
	row[2] = Vector3();
}

Matrix3x3::Matrix3x3(const Vector3& row0, const Vector3& row1, const Vector3& row2)
{
	row[0] = row0;
	row[1] = row1;
	row[2] = row2;
}

Matrix3x3::Matrix3x3(
	float m11, float m12, float m13,
	float m21, float m22, float m23,
	float m31, float m32, float m33)
{
	n[0][0] = m11;
	n[0][1] = m12;
	n[0][2] = m13;

	n[1][0] = m21;
	n[1][1] = m22;
	n[1][2] = m23;

	n[2][0] = m31;
	n[2][1] = m32;
	n[2][2] = m33;
}

Matrix3x3 Matrix3x3::Identity()
{
	Matrix3x3 returnValue(
		1.0, 0.0f, 0.0f,
		0.0, 1.0f, 0.0f,
		0.0, 0.0f, 1.0f);
	//#ifdef USE_DX11
		//Transpose(returnValue);
	//#endif
	return returnValue;
}

Matrix3x3 Matrix3x3::CreateLookAt(const Vector3& position, const Vector3& lookAt, const Vector3& up)
{
	Matrix3x3 returnValue;

	//returnValue = *(Matrix*)&DirectX::XMMatrixLookAtRH(XMLoadFloat3(&position), XMLoadFloat3(&lookAt), XMLoadFloat3(&up));
	//Transpose(returnValue);

	return returnValue;
}

Matrix3x3 Matrix3x3::CreateProjection(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance)
{
	Matrix3x3 returnValue;
	//returnValue = DirectX::XMMatrixPerspectiveFovRH(fieldOfView, aspectRatio, nearPlaneDistance, farPlaneDistance);
	return returnValue;
}

Matrix3x3 Matrix3x3::CreateLeftHandOrtho(float width, float height, float nearPlaneDistance, float farPlaneDistance)
{
	Matrix3x3 returnValue;
	//returnValue = DirectX::XMMatrixOrthographicLH(width, height, nearPlaneDistance, farPlaneDistance);
	return returnValue;
}

Matrix3x3 Matrix3x3::CreateLeftHandOrthoOffCenter(float left, float right, float bottom, float top, float nearPlaneDistance, float farPlaneDistance)
{
	Matrix3x3 returnValue;
	//returnValue = DirectX::XMMatrixOrthographicOffCenterLH(left, right, bottom, top, nearPlaneDistance, farPlaneDistance);
	return returnValue;
}

Matrix2x2 Matrix3x3::Minor(unsigned i, unsigned j) const
{
	Matrix2x2 minor;

	int yy = 0;

	for (int y = 0; y < 3; y++)
	{
		if (y == j)
		{
			continue;
		}

		int xx = 0;
		for (int x = 0; x < 3; x++)
		{
			if (x == i)
			{
				continue;
			}

			minor.row[xx][yy] = row[x][y];
			xx++;
		}
		y++;
	}

	return minor;
}

float Matrix3x3::Cofactor(unsigned i, unsigned j) const
{
	Matrix2x2 minor = Minor(i, j);
	float c = float(pow(-1.0f, i + 1 + j + 1)) * minor.Determinant();

	return c;
}

void Matrix3x3::Multiply(const Matrix3x3& rhs)
{
	//Matrix3x3 tempMatrix = *this;
	//XMStoreFloat4x4(this, XMMatrixMultiply(XMLoadFloat4x4(&tempMatrix), XMLoadFloat4x4(&matrix)));

	Matrix3x3 scratchMatrix = Matrix3x3(
		n[0][0] * rhs.n[0][0] + n[0][1] * rhs.n[1][0] + n[0][2] + rhs.n[2][0],
		n[0][0] * rhs.n[0][1] + n[0][1] * rhs.n[1][1] + n[0][2] + rhs.n[2][1],
		n[0][0] * rhs.n[0][2] + n[0][1] * rhs.n[1][2] + n[0][2] + rhs.n[2][2],
		n[1][0] * rhs.n[0][0] + n[1][1] * rhs.n[1][0] + n[1][2] + rhs.n[2][0],
		n[1][0] * rhs.n[0][1] + n[1][1] * rhs.n[1][1] + n[1][2] + rhs.n[2][1],
		n[1][0] * rhs.n[0][2] + n[1][1] * rhs.n[1][2] + n[1][2] + rhs.n[2][2],
		n[2][0] * rhs.n[0][0] + n[2][1] * rhs.n[1][0] + n[2][2] + rhs.n[2][0],
		n[2][0] * rhs.n[0][1] + n[2][1] * rhs.n[1][1] + n[2][2] + rhs.n[2][1],
		n[2][0] * rhs.n[0][2] + n[2][1] * rhs.n[1][2] + n[2][2] + rhs.n[2][2]);

	(*this) = scratchMatrix;
}

Matrix3x3& Matrix3x3::operator*(const Matrix3x3& rhs)
{
	Multiply(rhs);
	return (*this);
}

Matrix3x3 Matrix3x3::CreateScaling(float scale)
{
	return CreateScaling(scale, scale, scale);
}

Matrix3x3 Matrix3x3::CreateScaling(float xScale, float yScale, float zScale)
{
	return Matrix3x3(
		xScale, 0.0f, 0.0f, 
		0.0f, yScale, 0.0f, 
		0.0f, 0.0f, zScale);
}

Matrix3x3 Matrix3x3::CreateScaling(float scale, const Vector3& axis)
{
	scale -= 1.0f;
	float x = axis.x * scale;
	float y = axis.y * scale;
	float z = axis.z * scale;

	float axay = x * axis.y;
	float axaz = x * axis.z;
	float ayaz = y * axis.z;

	return Matrix3x3(
		x * axis.x + 1.0f, 
		axay,
		axaz,
		axay,
		y * axis.y + 1.0f,
		ayaz,
		axaz,
		ayaz,
		x * axis.z + 1.0f);
}

Matrix3x3 Matrix3x3::CreateSkew(float angle, const Vector3& directionA, const Vector3& directionB)
{
	return Matrix3x3();
}

Matrix3x3 Matrix3x3::CreateRotationX(float angle)
{
	float cosAngle = cos(angle);
	float sinAngle = sin(angle);

	return Matrix3x3(
		1.0f, 0.0f, 0.0f,
		0.0f, cosAngle, sinAngle,
		0.0f, -sinAngle, cosAngle);
}

Matrix3x3 Matrix3x3::CreateRotationY(float angle)
{
	float cosAngle = cos(angle);
	float sinAngle = sin(angle);

	return Matrix3x3(
		cosAngle, 0.0f, -sinAngle,
		0.0f, 1.0f, 0.0f,
		sinAngle, 0.0f, cosAngle);
}

Matrix3x3 Matrix3x3::CreateRotationZ(float angle)
{
	float cosAngle = cos(angle);
	float sinAngle = sin(angle);

	return Matrix3x3(
		cosAngle, sinAngle, 0.0f,
		-sinAngle, cosAngle, 0.0f,
		0.0f, 0.0f, 1.0f);
}

Matrix3x3 Matrix3x3::CreateRotationAxis(const Vector3& axis, float angle)
{
	float c = cosf(angle);
	float s = sinf(angle);
	float C = 1.0f - c;

	Matrix3x3 returnValue;
	returnValue.n[0][0] = axis.x * axis.x * C + c;
	returnValue.n[0][1] = axis.y * axis.x * C + axis.z * s;
	returnValue.n[0][2] = axis.z * axis.x * C - axis.y * s;

	returnValue.n[1][0] = axis.y * axis.x * C - axis.z * s;
	returnValue.n[1][1] = axis.y * axis.y * C + c;
	returnValue.n[1][2] = axis.z * axis.y * C + axis.x * s;

	returnValue.n[2][0] = axis.x * axis.z * C + axis.y * s;
	returnValue.n[2][1] = axis.z * axis.y * C - axis.x * s;
	returnValue.n[2][2] = axis.z * axis.z * C + c;

	return returnValue;
}

Matrix3x3 Matrix3x3::Inverse(const Matrix3x3& rhs)
{
	Matrix3x3 inverse;

	//for (unsigned i = 0; i < 3; ++i)
	//{
	//	for (unsigned j = 0; j < 3; ++j)
	//	{
	//		inverse.row[j][i] = rhs.Cofactor(i, j);
	//	}
	//}

	//float determinant = rhs.Determinant();
	//HB_ASSERT(determinant != 0.0f);
	//float inverseDeterminant = 1.0f / determinant;

	//inverse *= inverseDeterminant;

	float t1 = rhs.m[0] * rhs.m[4];
	float t2 = rhs.m[0] * rhs.m[5];
	float t3 = rhs.m[1] * rhs.m[3];
	float t4 = rhs.m[2] * rhs.m[3];
	float t5 = rhs.m[1] * rhs.m[6];
	float t6 = rhs.m[2] * rhs.m[6];

	float determinant = (t1 * rhs.m[8] - t2 * rhs.m[7] - t3 * rhs.m[8]
		+ t4 * rhs.m[7] + t5 * rhs.m[5] - t6 * rhs.m[4]);

	HB_ASSERT(determinant != 0.0f);

	if (determinant == 0.0f)
	{
		return rhs;
	}

	float inverseDeterminant = 1.0f / determinant;

	inverse.m[0] = (rhs.m[4] * rhs.m[8] - rhs.m[5] * rhs.m[7]) * inverseDeterminant;
	inverse.m[1] = -(rhs.m[1] * rhs.m[8] - rhs.m[2] * rhs.m[7]) * inverseDeterminant;
	inverse.m[2] = (rhs.m[1] * rhs.m[5] - rhs.m[2] * rhs.m[4]) * inverseDeterminant;
	inverse.m[3] = -(rhs.m[3] * rhs.m[8] - rhs.m[5] * rhs.m[6]) * inverseDeterminant;
	inverse.m[4] = (rhs.m[0] * rhs.m[8] - t6) * inverseDeterminant;
	inverse.m[5] = -(t2 - t4) * inverseDeterminant;
	inverse.m[6] = (rhs.m[3] * rhs.m[7] - rhs.m[4] * rhs.m[6]) * inverseDeterminant;
	inverse.m[7] = -(rhs.m[0] * rhs.m[7] - t5) * inverseDeterminant;
	inverse.m[8] = (t1 - t3) * inverseDeterminant;

	return inverse;
}

Matrix3x3 Matrix3x3::Inverse() const
{
	return Inverse(*this);
}

Matrix3x3 Matrix3x3::Transpose(const Matrix3x3& rhs)
{
	Matrix3x3 transpose;

	//for (unsigned i = 0; i < 3; ++i)
	//{
	//	for (unsigned j = 0; j < 3; ++j)
	//	{
	//		transpose.row[i][j] = rhs.row[j][i];
	//	}
	//}

	transpose.m[0] = rhs.m[0];
	transpose.m[1] = rhs.m[3];
	transpose.m[2] = rhs.m[6];
	transpose.m[3] = rhs.m[1];
	transpose.m[4] = rhs.m[4];
	transpose.m[5] = rhs.m[7];
	transpose.m[6] = rhs.m[2];
	transpose.m[7] = rhs.m[5];
	transpose.m[8] = rhs.m[8];

	return transpose;
}

Matrix3x3 Matrix3x3::Transpose() const
{
	return Transpose(*this);
}

float Matrix3x3::Determinant(const Matrix3x3& matrix)
{
	//return (matrix.n[0][0] * (matrix.n[1][1] * matrix.n[2][2] - matrix.n[1][2] * matrix.n[2][1])
	//	+ matrix.n[0][1] * (matrix.n[1][2] * matrix.n[2][0] - matrix.n[1][0] * matrix.n[2][2])
	//	+ matrix.n[0][2] * (matrix.n[1][0] * matrix.n[2][1] - matrix.n[1][1] * matrix.n[2][0]));

	return (matrix.n[0][0] * (matrix.n[1][1] * matrix.n[2][2] - matrix.n[1][2] * matrix.n[2][1])
		- matrix.n[0][1] * (matrix.n[1][2] * matrix.n[2][0] - matrix.n[1][0] * matrix.n[2][2])
		+ matrix.n[0][2] * (matrix.n[1][0] * matrix.n[2][1] - matrix.n[1][1] * matrix.n[2][0]));

	//float i = matrix.n[0][0] * (matrix.n[1][1] * matrix.n[2][2] - matrix.n[1][2] * matrix.n[2][1]);
	//float i = matrix.n[0][0] * (matrix.n[1][1] * matrix.n[2][2] - matrix.n[1][2] * matrix.n[2][1])
	//float i = matrix.n[0][0] * (matrix.n[1][1] * matrix.n[2][2] - matrix.n[1][2] * matrix.n[2][1]);
}

float Matrix3x3::Determinant() const
{
	return Determinant(*this);
}

Matrix3x3& Matrix3x3::operator=(const Matrix3x3& rhs)
{
	row[0] = rhs.row[0];
	row[1] = rhs.row[1];
	row[2] = rhs.row[2];

	return (*this);
}

float& Matrix3x3::operator[](unsigned int index)
{
	return m[index];
}

const float& Matrix3x3::operator[](unsigned int index) const
{
	return m[index];
}

float& Matrix3x3::operator()(unsigned int i, unsigned int j)
{
	return n[i][j];
}

const float& Matrix3x3::operator()(unsigned int i, unsigned int j) const
{
	return n[i][j];
}

Matrix3x3 Matrix3x3::operator*=(float rhs)
{
	row[0] *= rhs;
	row[1] *= rhs;
	row[2] *= rhs;

	return (*this);
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

std::string Matrix3x3::ToString() const
{
	std::stringstream returnValueStream;
	returnValueStream << row[0].ToString() << ", ";
	returnValueStream << row[1].ToString() << ", ";
	returnValueStream << row[2].ToString();

	return returnValueStream.str();
}

bool Matrix3x3::operator==(const Matrix3x3& rhs) const
{
	return ((row[0] == rhs.row[0]) && (row[1] == rhs.row[1]) && (row[2] == rhs.row[2]));
}

bool Matrix3x3::operator!=(const Matrix3x3& rhs) const
{
	return (!operator==(rhs));
}

Matrix3x3 Math::Inverse(const Matrix3x3& rhs)
{
	const Vector3& a = rhs.row[0];
	const Vector3& b = rhs.row[1];
	const Vector3& c = rhs.row[2];

	Vector3 r0 = Cross(b, c);
	Vector3 r1 = Cross(c, a);
	Vector3 r2 = Cross(a, b);

	float inverseDeterminate = 1.0f / Dot(r2, c);

	return Matrix3x3(
		r0.x * inverseDeterminate, 
		r0.y * inverseDeterminate,
		r0.z * inverseDeterminate,
		r1.x * inverseDeterminate,
		r1.y * inverseDeterminate,
		r1.z * inverseDeterminate,
		r2.x * inverseDeterminate,
		r2.y * inverseDeterminate,
		r2.z * inverseDeterminate);
};

Math::Matrix3x3 operator*(const Math::Matrix3x3& lhs, const Math::Matrix3x3& rhs)
{
	return Math::Matrix3x3(
		lhs.n[0][0] * rhs.n[0][0] + lhs.n[0][1] * rhs.n[1][0] + lhs.n[0][2] + rhs.n[2][0],
		lhs.n[0][0] * rhs.n[0][1] + lhs.n[0][1] * rhs.n[1][1] + lhs.n[0][2] + rhs.n[2][1],
		lhs.n[0][0] * rhs.n[0][2] + lhs.n[0][1] * rhs.n[1][2] + lhs.n[0][2] + rhs.n[2][2],
		lhs.n[1][0] * rhs.n[0][0] + lhs.n[1][1] * rhs.n[1][0] + lhs.n[1][2] + rhs.n[2][0],
		lhs.n[1][0] * rhs.n[0][1] + lhs.n[1][1] * rhs.n[1][1] + lhs.n[1][2] + rhs.n[2][1],
		lhs.n[1][0] * rhs.n[0][2] + lhs.n[1][1] * rhs.n[1][2] + lhs.n[1][2] + rhs.n[2][2],
		lhs.n[2][0] * rhs.n[0][0] + lhs.n[2][1] * rhs.n[1][0] + lhs.n[2][2] + rhs.n[2][0],
		lhs.n[2][0] * rhs.n[0][1] + lhs.n[2][1] * rhs.n[1][1] + lhs.n[2][2] + rhs.n[2][1],
		lhs.n[2][0] * rhs.n[0][2] + lhs.n[2][1] * rhs.n[1][2] + lhs.n[2][2] + rhs.n[2][2]);
}

Math::Vector3 operator*(const Math::Matrix3x3& lhs, const Math::Vector3 rhs)
{
	//return Math::Vector3(
	//	lhs.n[0][0] * rhs.x + lhs.n[0][1] * rhs.y + lhs.n[0][2] * rhs.z,
	//	lhs.n[1][0] * rhs.x + lhs.n[1][1] * rhs.y + lhs.n[1][2] * rhs.z,
	//	lhs.n[2][0] * rhs.x + lhs.n[2][1] * rhs.y + lhs.n[2][2] * rhs.z);

	Vector3 result;

	result.x = Math::Dot(lhs.row[0], rhs);
	result.y = Math::Dot(lhs.row[1], rhs);
	result.z = Math::Dot(lhs.row[2], rhs);

	return result;
}

Math::Matrix3x3 operator*(const Math::Matrix3x3& lhs, float rhs)
{
	Math::Matrix3x3 result = lhs;

	result.row[0] *= rhs;
	result.row[0] *= rhs;
	result.row[0] *= rhs;
	result.row[0] *= rhs;

	return result;
}