#include "Operations/MinMax.h"

#include "Vector/Vector2.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"

using namespace Math;

namespace
{
	template<typename TemplatedType>
	TemplatedType MinInternal(const TemplatedType& lhs, const TemplatedType& rhs)
	{
		return ((lhs < rhs) ? lhs : rhs);
	}

	template<typename TemplatedType>
	TemplatedType MaxInternal(const TemplatedType& lhs, const TemplatedType& rhs)
	{
		return ((lhs > rhs) ? lhs : rhs);
	}

	template<typename TemplatedType>
	TemplatedType Min3Internal(const TemplatedType& value0, const TemplatedType& value1, const TemplatedType& value2)
	{
		return MinInternal<TemplatedType>(value0, MinInternal<TemplatedType>(value1, value2));
	}

	template<typename TemplatedType>
	TemplatedType Max3Internal(const TemplatedType& value0, const TemplatedType& value1, const TemplatedType& value2)
	{
		return MaxInternal<TemplatedType>(value0, MaxInternal<TemplatedType>(value1, value2));
	}
};

long Math::Min(long lhs, long rhs)
{
	return MinInternal<long>(lhs, rhs);
}

unsigned int Math::Min(unsigned int lhs, unsigned int rhs)
{
	return MinInternal<unsigned int>(lhs, rhs);
}

unsigned long Math::Min(unsigned long lhs, unsigned long rhs)
{
	return MinInternal<unsigned long>(lhs, rhs);
}

float Math::Min(float lhs, float rhs)
{
	return MinInternal<float>(lhs, rhs);
}

double Math::Min(double lhs, double rhs)
{
	return MinInternal<double>(lhs, rhs);
}

Vector2 Math::Min(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(Math::Min(lhs.x, rhs.x), Math::Min(lhs.y, rhs.y));
}

Vector3 Math::Min(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(Math::Min(lhs.x, rhs.x), Math::Min(lhs.y, rhs.y), Math::Min(lhs.z, rhs.z));
}

Vector4 Math::Min(const Vector4& lhs, const Vector4& rhs)
{
	return Vector4(Math::Min(lhs.x, rhs.x), Math::Min(lhs.y, rhs.y), Math::Min(lhs.z, rhs.z), Math::Min(lhs.w, rhs.w));
}

long Math::Max(long lhs, long rhs)
{
	return MaxInternal<long>(lhs, rhs);
}

unsigned long Math::Max(unsigned long lhs, unsigned long rhs)
{
	return MaxInternal<unsigned long>(lhs, rhs);
}

float Math::Max(float lhs, float rhs)
{
	return MaxInternal<float>(lhs, rhs);
}

double Math::Max(double lhs, double rhs)
{
	return MaxInternal<double>(lhs, rhs);
}

Vector2 Math::Max(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(Math::Max(lhs.x, rhs.x), Math::Max(lhs.y, rhs.y));
}

Vector3 Math::Max(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(Math::Max(lhs.x, rhs.x), Math::Max(lhs.y, rhs.y), Math::Max(lhs.z, rhs.z));
}

Vector4 Math::Max(const Vector4& lhs, const Vector4& rhs)
{
	return Vector4(Math::Max(lhs.x, rhs.x), Math::Max(lhs.y, rhs.y), Math::Max(lhs.z, rhs.z), Math::Max(lhs.w, rhs.w));
}

long Math::Min3(long value0, long value1, long value2)
{
	return Min3Internal<unsigned long>(value0, value1, value2);
}

unsigned long Math::Min3(unsigned long value0, unsigned long value1, unsigned long value2)
{
	return Min3Internal<unsigned long>(value0, value1, value2);
}

float Math::Min3(float value0, float value1, float value2)
{
	return Min3Internal<float>(value0, value1, value2);
}

double Math::Min3(double value0, double value1, double value2)
{
	return Min3Internal<double>(value0, value1, value2);
}

Vector2 Math::Min3(const Vector2& value0, const Vector2& value1, const Vector2& value2)
{
	Vector2 returnValue;

	returnValue.x = Math::Min3(value0.x, value1.x, value2.x);
	returnValue.y = Math::Min3(value0.y, value1.y, value2.y);

	return returnValue;
}

Vector3 Math::Min3(const Vector3& value0, const Vector3& value1, const Vector3& value2)
{
	Vector3 returnValue;

	returnValue.x = Math::Min3(value0.x, value1.x, value2.x);
	returnValue.y = Math::Min3(value0.y, value1.y, value2.y);
	returnValue.z = Math::Min3(value0.z, value1.z, value2.z);

	return returnValue;
}

Vector4 Math::Min3(const Vector4& value0, const Vector4& value1, const Vector4& value2)
{
	Vector4 returnValue;

	returnValue.x = Math::Min3(value0.x, value1.x, value2.x);
	returnValue.y = Math::Min3(value0.y, value1.y, value2.y);
	returnValue.z = Math::Min3(value0.z, value1.z, value2.z);
	returnValue.w = Math::Min3(value0.w, value1.w, value2.w);

	return returnValue;
}

long Math::Max3(long value0, long value1, long value2)
{
	return Max3Internal<unsigned long>(value0, value1, value2);
}

unsigned long Math::Max3(unsigned long value0, unsigned long value1, unsigned long value2)
{
	return Max3Internal<unsigned long>(value0, value1, value2);
}

float Math::Max3(float value0, float value1, float value2)
{
	return Max3Internal<float>(value0, value1, value2);
}

double Math::Max3(double value0, double value1, double value2)
{
	return Max3Internal<double>(value0, value1, value2);
}

Vector2 Math::Max3(const Vector2& value0, const Vector2& value1, const Vector2& value2)
{
	Vector2 returnValue;

	returnValue.x = Math::Max3(value0.x, value1.x, value2.x);
	returnValue.y = Math::Max3(value0.y, value1.y, value2.y);

	return returnValue;
}

Vector3 Math::Max3(const Vector3& value0, const Vector3& value1, const Vector3& value2)
{
	Vector3 returnValue;

	returnValue.x = Math::Max3(value0.x, value1.x, value2.x);
	returnValue.y = Math::Max3(value0.y, value1.y, value2.y);
	returnValue.z = Math::Max3(value0.z, value1.z, value2.z);

	return returnValue;
}

Vector4 Math::Max3(const Vector4& value0, const Vector4& value1, const Vector4& value2)
{
	Vector4 returnValue;

	returnValue.x = Math::Max3(value0.x, value1.x, value2.x);
	returnValue.y = Math::Max3(value0.y, value1.y, value2.y);
	returnValue.z = Math::Max3(value0.z, value1.z, value2.z);
	returnValue.w = Math::Max3(value0.w, value1.w, value2.w);

	return returnValue;
}
