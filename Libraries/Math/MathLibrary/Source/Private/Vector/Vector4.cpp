#include "Vector/Vector4.h"

#include <Framework/LibraryShell/Source/Public/CustomAssert.h>
#include "Matrix/Matrix4x4.h"
#include "Vector/Vector3.h"
#include "Vector/Vector2.h"
#include <sstream>

using namespace Math;

Vector4 Vector4::Zero()
{
	return Vector4(0.0f, 0.0f, 0.0f, 0.0f);
}

Vector4 Vector4::One()
{
	return Vector4(1.0f, 1.0f, 1.0f, 1.0f);
}

std::string Vector4::ToString() const
{
	std::stringstream returnValueStream;
	returnValueStream <<  x << ", " << y << ", " << z << ", " << w << '\n';
	return returnValueStream.str();
}

void Vector4::SetXYZW(float newX, float newY, float newZ, float newW)
{
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

void Vector4::SetXYZ(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

const Vector3& Vector4::GetXYZ() const
{
	return m_xyz;
}

float Vector4::Magnitude() const
{
	return sqrtf(MagnitudeSquared());
}

float Vector4::MagnitudeSquared() const
{
	return (x * x + y * y + z * z + w * w);
}

void Vector4::Normalize()
{
	float magnitude = Magnitude();
	if (magnitude != 0.0f)
	{
		float inverseMagnitude = 1.0f / magnitude;
		x *= inverseMagnitude;
		y *= inverseMagnitude;
		z *= inverseMagnitude;
		w *= inverseMagnitude;
	}
}

float Vector4::Dot(const Vector4& rhs) const
{
	return (x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w);
}

Vector4 Vector4::Cross(const Vector4& rhs) const
{
	return Vector4(
		(y * rhs.z) - (rhs.y * z),
		(rhs.x * z) - (x * rhs.z),
		(x * rhs.y) - (y * rhs.x),
		1.0f);
}

bool Vector4::operator==(const Vector4& rhs) const
{
	return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w));
}

bool Vector4::operator!=(const Vector4& rhs) const
{
	return(!operator==(rhs));
}

Vector4& Vector4::operator=(const Vector2& rhs)
{
	x = rhs.x;
	y = rhs.y;
	return (*this);
}

Vector4& Vector4::operator=(const Vector3& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return (*this);
}

Vector4& Vector4::operator=(const Vector4& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;
	return (*this);
}

Vector4& Vector4::operator+=(const Vector4& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return (*this);
}

Vector4& Vector4::operator-=(const Vector4& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;
	return (*this);
}

Vector4& Vector4::operator*=(const Vector4& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;
	return (*this);
}

Vector4& Vector4::operator/=(const Vector4& rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	w /= rhs.w;
	return (*this);
}

Vector4& Vector4::operator*=(float scale)
{
	x *= scale;
	y *= scale;
	z *= scale;
	w *= scale;
	return (*this);
}

Vector4& Vector4::operator/=(float scale)
{
	HB_ASSERT(scale != 0.0f);
	float inverseScale = 1.0f / scale;
	x *= inverseScale;
	y *= inverseScale;
	z *= inverseScale;
	w *= inverseScale;
	return (*this);
}

void Vector4::ApplyTransformation(const Matrix4x4& transformation)
{
	//Math::Vector4 result;
	//result.x = transformation.row[0].Dot(*this);
	//result.y = transformation.row[1].Dot(*this);
	//result.z = transformation.row[2].Dot(*this);
	//result.w = transformation.row[3].Dot(*this);
	//
	//(*this) = result;

	float originalX = x;
	float originalY = y;
	float originalZ = z;
	float originalW = w;
	
	x = (originalX * transformation.n[0][0]) + (originalY * transformation.n[0][1]) + (originalZ * transformation.n[0][2]) + (originalW * transformation.n[0][3]);
	y = (originalX * transformation.n[1][0]) + (originalY * transformation.n[1][1]) + (originalZ * transformation.n[1][2]) + (originalW * transformation.n[1][3]);
	z = (originalX * transformation.n[2][0]) + (originalY * transformation.n[2][1]) + (originalZ * transformation.n[2][2]) + (originalW * transformation.n[2][3]);
	w = (originalX * transformation.n[3][0]) + (originalY * transformation.n[3][1]) + (originalZ * transformation.n[3][2]) + (originalW * transformation.n[3][3]);
}

float Math::Dot(const Vector4& a, const Vector4& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

Vector4 Math::Cross(const Vector4& a, const Vector4& b)
{
	return Vector4(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
		1.0f);
}

Vector4 Math::Normalize(const Vector4& v)
{
	float magnitude = v.Magnitude();
	if (magnitude != 0.0f)
	{
		float inverseMagnitude = 1.0f / magnitude;
		return (inverseMagnitude * v);
	}
	return v;
}

float Math::Magnitude(const Vector4& v)
{
	return v.Magnitude();
}

float Math::MagnitudeSquared(const Vector4& v)
{
	return v.MagnitudeSquared();
}

Vector4 operator+(const Vector4& lhs, const Vector4& rhs)
{
	return Vector4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

Vector4 operator-(const Vector4& lhs, const Vector4& rhs)
{
	return Vector4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

Vector4 operator*(const Vector4& lhs, const Vector4& rhs)
{
	return Vector4(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
}

Vector4 operator*(const Vector4& lhs, float scale)
{
	return Vector4(lhs.x * scale, lhs.y * scale, lhs.z * scale, lhs.w * scale);
}

Vector4 operator*(float scale, const Vector4& lhs)
{
	return Vector4(lhs.x * scale, lhs.y * scale, lhs.z * scale, lhs.w * scale);
}

Vector4 operator/(const Vector4& lhs, const Vector4& rhs)
{
	HB_ASSERT(rhs.x != 0.0f);
	HB_ASSERT(rhs.y != 0.0f);
	HB_ASSERT(rhs.z != 0.0f);
	HB_ASSERT(rhs.w != 0.0f);
	return Vector4(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
}

Vector4 operator/(const Vector4& lhs, float scale)
{
	HB_ASSERT(scale != 0.0f);
	float inverseScale = 1.0f / scale;
	return Vector4(lhs.x * inverseScale, lhs.y * inverseScale, lhs.z * inverseScale, lhs.w * inverseScale);
}

Vector4 operator-(const Vector4& lhs)
{
	return Vector4(-lhs.x, -lhs.y, -lhs.z, -lhs.w);
}
