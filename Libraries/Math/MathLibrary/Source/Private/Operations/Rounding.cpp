#include "Operations/Rounding.h"

#include "Vector/Vector2.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"
#include <cmath>

using namespace Math;

unsigned long Math::RoundUp(unsigned long value, unsigned long multiple)
{
	if (multiple == 0)
	{
		return value;
	}

	int remainder = value % multiple;
	if (remainder == 0)
	{
		return value;
	}

	return value + multiple - remainder;
}

unsigned long Math::Align(unsigned long size, unsigned long alignment)
{
	return (size + (alignment - 1)) & ~(alignment - 1);
}

Vector2 Math::Floor(const Vector2& value)
{
	return Vector2(floor(value.x), floor(value.y));
}

Vector3 Math::Floor(const Vector3& value)
{
	return Vector3(floor(value.x), floor(value.y), floor(value.z));
}

Vector4 Math::Floor(const Vector4& value)
{
	return Vector4(floor(value.x), floor(value.y), floor(value.z), floor(value.w));
}

Vector2 Math::Ceil(const Vector2& value)
{
	return Vector2(ceil(value.x), ceil(value.y));
}

Vector3 Math::Ceil(const Vector3& value)
{
	return Vector3(ceil(value.x), ceil(value.y), ceil(value.z));
}

Vector4 Math::Ceil(const Vector4& value)
{
	return Vector4(ceil(value.x), ceil(value.y), ceil(value.z), ceil(value.w));
}
