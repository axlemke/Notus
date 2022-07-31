#include "Vector/Vector2.h"

#include <Framework/LibraryShell/Source/Public/CustomAssert.h>
#include "Matrix/Matrix2x2.h"
#include <sstream>

using namespace Math;

void Vector2::SetXY(float newX, float newY)
{
	x = newX;
	y = newY;
}

Vector2 Vector2::Zero()
{
	return Vector2(0.0f, 0.0f);
}

Vector2 Vector2::One()
{
	return Vector2(1.0f, 1.0f);
}

float Vector2::GetValueByIndex(unsigned index) const
{
	return (index == 0) ? x : y;
}

float Vector2::Magnitude() const
{
	return sqrtf(MagnitudeSquared());
}

float Vector2::MagnitudeSquared() const
{
	return (x * x + y * y);
}

void Vector2::Normalize()
{
	float magnitude = Magnitude();
	if (magnitude != 0.0f)
	{
		float inverseMagnitude = 1.0f / magnitude;
		x *= inverseMagnitude;
		y *= inverseMagnitude;
	}
}

std::string Vector2::ToString() const
{
	std::stringstream returnValueStream;
	returnValueStream <<  x << ", " << y << '\n';
	return returnValueStream.str();
}

Vector2& Vector2::operator=(const Vector2& rhs)
{
	x = rhs.x;
	y = rhs.y;
	return (*this);
}

bool Vector2::operator==(const Vector2& rhs) const
{
	return ((x == rhs.x) && (y == rhs.y));
}

bool Vector2::operator!=(const Vector2& rhs) const
{
	return!(operator==(rhs));
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return (*this);
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return (*this);
}

Vector2& Vector2::operator*=(const Vector2& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return (*this);
}

Vector2& Vector2::operator/=(const Vector2& rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	return (*this);
}

Vector2& Vector2::operator*=(float scale)
{
	x *= scale;
	y *= scale;
	return (*this);
}

Vector2& Vector2::operator/=(float scale)
{
	HB_ASSERT(scale != 0.0f);
	float inverseScale = 1.0f / scale;
	x *= inverseScale;
	y *= inverseScale;
	return (*this);
}

float& Vector2::operator[](const unsigned int spot)
{
	if (spot == 0)
		return x;
	else if (spot == 1)
		return y;
	HB_ASSERT(false);
	return y;
}

float Vector2::operator[](const unsigned int spot) const
{
	if (spot == 0)
		return x;
	else if (spot == 1)
		return y;
	HB_ASSERT(false);
	return y;
}

float Math::Dot(const Vector2& a, const Vector2& b)
{
	return (a.x * b.x) + (a.y * b.y);
}

Vector2 Math::Project(const Vector2& a, const Vector2& b)
{
	return (b * (Math::Dot(a, b) / Math::Dot(b, b)));
}

Vector2 Math::UnitProject(const Vector2& a, const Vector2& b)
{
	HB_ASSERT(abs(1.0f - b.MagnitudeSquared()) < 0.00001f);
	return (b * Math::Dot(a, b));
}

Vector2 Math::Reflection(const Vector2& d, const Vector2& n)
{
	Vector2 unitN = Math::Normalize(n);
	return d - 2.0f * Math::Dot(d, unitN) * unitN;
}

Vector2 Math::Normalize(const Vector2& v)
{
	float magnitude = v.Magnitude();
	if (magnitude != 0.0f)
	{
		float inverseMagnitude = 1.0f / magnitude;
		return (inverseMagnitude * v);
	}
	return v;
}

float Math::Magnitude(const Vector2& v)
{
	return v.Magnitude();
}

float Math::MagnitudeSquared(const Vector2& v)
{
	return v.MagnitudeSquared();
}

Vector2 Math::RotateAroundZAxis(const Vector2& v, float angle)
{
	return (v * Matrix2x2::CreateRotation(angle));
}

Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

Vector2 operator*(const Math::Vector2& lhs, const Math::Vector2& rhs)
{
	return Vector2(lhs.x * rhs.x, lhs.y * rhs.y);
}

Vector2 operator*(const Vector2& lhs, float scale)
{
	return Vector2(lhs.x * scale, lhs.y * scale);
}

Vector2 operator/(const Vector2& lhs, const Vector2& rhs)
{
	HB_ASSERT(rhs.x != 0.0f);
	HB_ASSERT(rhs.y != 0.0f);
	return Vector2(lhs.x / rhs.x, lhs.y / rhs.y);
}

Vector2 operator*(float scale, const Vector2& lhs)
{
	return Vector2(lhs.x * scale, lhs.y * scale);
}

Vector2 operator/(const Vector2& lhs, float scale)
{
	HB_ASSERT(scale != 0.0f);
	float inverseScale = 1.0f / scale;
	return Vector2(lhs.x * inverseScale, lhs.y * inverseScale);
}

Vector2 operator-(const Vector2& lhs)
{
	return Vector2(-lhs.x, -lhs.y);
}
