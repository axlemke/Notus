#include "Matrix/Matrix2x2.h"

#include <sstream>

using namespace Math;

Matrix2x2::Matrix2x2()
{
	row[0] = Vector2();
	row[1] = Vector2();
}

Matrix2x2::Matrix2x2(const Math::Vector2& row0, const Math::Vector2& row1)
{
	row[0] = row0;
	row[1] = row1;
}

Matrix2x2::Matrix2x2(float m11, float m12, float m21, float m22)
{
	n[0][0] = m11;
	n[0][1] = m12;

	n[1][0] = m21;
	n[1][1] = m22;
}

Matrix2x2 Matrix2x2::CreateRotation(float angle)
{
	float cosAngle = cos(angle);
	float sinAngle = sin(angle);

	return Matrix2x2(
		cosAngle, -sinAngle, 
		sinAngle, cosAngle);
}

float Matrix2x2::Determinant(const Matrix2x2& matrix)
{
	return (matrix.row[0].x * matrix.row[1].y) - (matrix.row[0].y * matrix.row[1].x);
}

float Matrix2x2::Determinant() const
{
	return Determinant(*this);
}

Math::Vector2 operator*(const Math::Matrix2x2& lhs, const Math::Vector2& rhs)
{
	return Vector2(
		(rhs.x * lhs.row[0].x) - (rhs.y * lhs.row[0].y),
		(rhs.x * lhs.row[1].x) + (rhs.y * lhs.row[1].y));
}

Math::Vector2 operator*(const Math::Vector2& lhs, const Math::Matrix2x2& rhs)
{
	return Vector2(
		(lhs.x * rhs.row[0].x) - (lhs.y * rhs.row[0].y),
		(lhs.x * rhs.row[1].x) + (lhs.y * rhs.row[1].y));
}

