#include "Operations/Colinear.h"

#include "Vector/Vector2.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"

using namespace Math;

bool Math::AreCollinear(const Vector2& a, const Vector2& b, const Vector2& c)
{
	return false; // (Cross((b - a), (c - a)).MagnitudeSquared() == 0.0f);
}

bool Math::AreCollinear(const Vector3& a, const Vector3& b, const Vector3& c)
{
	return (Cross((b - a), (c - a)).MagnitudeSquared() == 0.0f);
}

bool Math::AreCollinear(const Vector4& a, const Vector4& b, const Vector4& c)
{
	return (Cross((b - a), (c - a)).MagnitudeSquared() == 0.0f);
}
