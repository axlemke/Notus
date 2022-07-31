#include "Vector/Vector3.h"

#include "Matrix/Matrix3x3.h"
#include "Matrix/Matrix4x4.h"
#include "Vector/Vector2.h"
#include "Vector/Vector4.h"
#include <Framework/LibraryShell/Source/Public/CustomAssert.h>
#include <sstream>

using namespace Math;

void Vector3::SetXYZ(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

float Vector3::Magnitude() const
{
	return sqrtf(MagnitudeSquared());
}

float Vector3::MagnitudeSquared() const
{
	return (x * x + y * y + z * z);
}

void Vector3::Normalize()
{
	float magnitude = Magnitude();
	if (magnitude != 0.0f)
	{
		float inverseMagnitude = 1.0f / magnitude;
		x *= inverseMagnitude;
		y *= inverseMagnitude;
		z *= inverseMagnitude;
	}
}

void Vector3::ApplyTransformation(const Matrix4x4& transformation)
{
	float originalX = x;
	float originalY = y;
	float originalZ = z;

	x = (originalX * transformation.n[0][0]) + (originalY * transformation.n[0][1]) + (originalZ * transformation.n[0][2]) + transformation.n[0][3];
	y = (originalX * transformation.n[1][0]) + (originalY * transformation.n[1][1]) + (originalZ * transformation.n[1][2]) + transformation.n[1][3];
	z = (originalX * transformation.n[2][0]) + (originalY * transformation.n[2][1]) + (originalZ * transformation.n[2][2]) + transformation.n[2][3];
}

void Vector3::ApplyTransformation(const Matrix3x3& transformation)
{
	float originalX = x;
	float originalY = y;
	float originalZ = z;

	x = (originalX * transformation.n[0][0]) + (originalY * transformation.n[0][1]) + (originalZ * transformation.n[0][2]);
	y = (originalX * transformation.n[1][0]) + (originalY * transformation.n[1][1]) + (originalZ * transformation.n[1][2]);
	z = (originalX * transformation.n[2][0]) + (originalY * transformation.n[2][1]) + (originalZ * transformation.n[2][2]);
}

void Vector3::ApplyTransformationAndNormalize(const Matrix4x4& transformation)
{
	ApplyTransformation(transformation);
	Normalize();
}

void Vector3::ApplyTransformationAndNormalize(const Matrix3x3& transformation)
{
	ApplyTransformation(transformation);
	Normalize();
}

Vector3 Vector3::Zero()
{
	return Vector3(0.0f, 0.0f, 0.0f);
}

Vector3 Vector3::One()
{
	return Vector3(1.0f, 1.0f, 1.0f);
}

Vector3 Vector3::Forward()
{
	return Vector3(0.0f, 0.0f, -1.0f);
}

Vector3 Vector3::Right()
{
	return Vector3(1.0f, 0.0f, 0.0f);
}

Vector3 Vector3::Up()
{
	return Vector3(0.0f, 1.0f, 0.0f); 
}

Vector3 Vector3::Backward()
{
	return Vector3(0.0f, 0.0f, 1.0f);
}

Vector3 Vector3::Left()
{
	return Vector3(-1.0f, 0.0f, 0.0f);
}

Vector3 Vector3::Down()
{
	return Vector3(0.0f, -1.0f, 0.0f); 
}

std::string Vector3::ToString() const
{
	std::stringstream returnValueStream;
	returnValueStream <<  x << ", " << y << ", " << z << '\n';
	return returnValueStream.str();
}

Vector3& Vector3::operator=(const Vector2& rhs)
{
	x = rhs.x;
	y = rhs.y;
	return (*this);
}

Vector3& Vector3::operator=(const Vector3& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return (*this);
}

Vector3& Vector3::operator=(const Vector4& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return (*this);
}

bool Vector3::operator==(const Vector3& rhs) const
{
	return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
}

bool Vector3::operator!=(const Vector3& rhs) const
{
	return !(operator==(rhs));
}

Vector3& Vector3::operator+=(const Vector3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return (*this);
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return (*this);
}

Vector3& Vector3::operator*=(const Vector3& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return (*this);
}

Vector3& Vector3::operator/=(const Vector3& rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	return (*this);
}

Vector3& Vector3::operator*=(float scale)
{
	x *= scale;
	y *= scale;
	z *= scale;
	return (*this);
}

Vector3& Vector3::operator/=(float scale)
{
	HB_ASSERT(scale != 0.0f);
	float inverseScale = 1.0f / scale;
	x *= inverseScale;
	y *= inverseScale;
	z *= inverseScale;
	return (*this);
}

Vector3& Vector3::operator*=(const Matrix3x3& m)
{
	ApplyTransformation(m);

	return (*this);
}

float& Vector3::operator[](const unsigned int spot)
{
	if (spot == 0)
		return x;
	else if (spot == 1)
		return y;
	else if (spot == 2)
		return z;
	HB_ASSERT(false);
	return z;
}

float Vector3::operator[](const unsigned int spot) const
{
	if (spot == 0)
		return x;
	else if (spot == 1)
		return y;
	else if (spot == 2)
		return z;
	HB_ASSERT(false);
	return z;
}

float Math::Dot(const Vector3& a, const Vector3& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vector3 Math::Cross(const Vector3& a, const Vector3& b)
{
	return Vector3(
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x));
}

float Math::ScalarTriple(const Vector3& a, const Vector3& b, const Vector3& c)
{
	return Math::Dot(Math::Cross(a, b), c);
}

Vector3 Math::Project(const Vector3& a, const Vector3& b)
{
	return (b * (Math::Dot(a, b) / Math::Dot(b, b)));
}

Vector3 Math::UnitProject(const Vector3& a, const Vector3& b)
{
	HB_ASSERT(abs(1.0f - b.MagnitudeSquared()) < 0.00001f);
	return (b * Math::Dot(a, b));
}

Vector3 Math::Reject(const Vector3& a, const Vector3& b)
{
	return (a - b * (Math::Dot(a, b) / Math::Dot(b, b)));
}

Vector3 Math::Reflection(const Vector3& d, const Vector3& n)
{
	Vector3 unitN = Math::Normalize(n);
	return d - 2.0f * Math::Dot(d, unitN) * unitN;
}

Vector3 Math::Normalize(const Vector3& v)
{
	float magnitude = v.Magnitude();
	if (magnitude != 0.0f)
	{
		float inverseMagnitude = 1.0f / magnitude;
		return (inverseMagnitude * v);
	}
	return v;
}

Vector3 Math::RotateAroundAxis(const Vector3& v, const Vector3& axis, float angle)
{
	return (v * Matrix3x3::CreateRotationAxis(axis, angle));
}

Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

Vector3 operator*(const Math::Vector3& lhs, const Math::Vector3& rhs)
{
	return Vector3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

Vector3 operator*(const Vector3& lhs, float scale)
{
	return Vector3(lhs.x * scale, lhs.y * scale, lhs.z * scale);
}

Vector3 operator*(float scale, const Vector3& rhs)
{
	return Vector3(rhs.x * scale, rhs.y * scale, rhs.z * scale);
}

Vector3 operator/(const Vector3& lhs, float scale)
{
	HB_ASSERT(scale != 0.0f);
	float inverseScale = 1.0f / scale;
	return Vector3(lhs.x * inverseScale, lhs.y * inverseScale, lhs.z * inverseScale);
}

Vector3 operator-(const Vector3& lhs)
{
	return Vector3(-lhs.x, -lhs.y, -lhs.z);
}

Vector3 operator*(const Math::Vector3& v, const Matrix3x3& m)
{
	Vector3 result = v;
	result.ApplyTransformation(m);
	return result;
}
