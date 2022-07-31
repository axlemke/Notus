#include "Operations/Clamp.h"

#include "Operations/MinMax.h"
#include "Vector/Vector2.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"

using namespace Math;

namespace
{
	template<typename TemplatedType>
	TemplatedType ClampInternal(const TemplatedType& value, const TemplatedType& minValue, const TemplatedType& maxValue)
	{
		return Math::Min(Math::Max(value, minValue), maxValue);
	}
};

unsigned long Math::Clamp(unsigned long value, unsigned long minValue, unsigned long maxValue)
{
	return ClampInternal<unsigned long>(value, minValue, maxValue);
}

float Math::Clamp(float value, float minValue, float maxValue)
{
	return ClampInternal<float>(value, minValue, maxValue);
}

double Math::Clamp(double value, double minValue, double maxValue)
{
	return ClampInternal<double>(value, minValue, maxValue);
}

Vector2 Math::Clamp(const Vector2& value, const Vector2& minValue, const Vector2& maxValue)
{
	Vector2 returnValue;

	returnValue.x = Math::Clamp(value.x, minValue.x, maxValue.x);
	returnValue.y = Math::Clamp(value.y, minValue.y, maxValue.y);

	return returnValue;
}

Vector3 Math::Clamp(const Vector3& value, const Vector3& minValue, const Vector3& maxValue)
{
	Vector3 returnValue;

	returnValue.m_xy = Math::Clamp(value.m_xy, minValue.m_xy, maxValue.m_xy);
	returnValue.z = Math::Clamp(value.z, minValue.z, maxValue.z);

	return returnValue;
}

Vector4 Math::Clamp(const Vector4& value, const Vector4& minValue, const Vector4& maxValue)
{
	Vector4 returnValue;

	returnValue.m_xyz = Math::Clamp(value.m_xyz, minValue.m_xyz, maxValue.m_xyz);
	returnValue.w = Math::Clamp(value.w, minValue.w, maxValue.w);

	return returnValue;
}
