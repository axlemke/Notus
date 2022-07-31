#include "Operations/Interpolation.h"

#include "MathConstants.h"
#include "Operations/Clamp.h"
#include "Quaternion/Quaternion.h"
#include "Vector/Vector2.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"

using namespace Math;

float Math::Lerp(float start, float end, float t)
{
	return (end - start) * t + start;
}

double Math::Lerp(double start, double end, double t)
{
	return (end - start) * t + start;
}

Vector2 Math::Lerp(const Vector2& start, const Vector2& end, float t)
{
	return (end - start) * t + start;
}

Vector3 Math::Lerp(const Vector3& start, const Vector3& end, float t)
{
	return (end - start) * t + start;
}

Vector4 Math::Lerp(const Vector4& start, const Vector4& end, float t)
{
	return (end - start) * t + start;
}

Quaternion Math::Lerp(const Quaternion& start, const Quaternion& end, float t)
{
	return (end - start) * t + start;
}

Vector2 Math::Slerp(const Vector2& start, const Vector2& end, float t)
{
	float dot = Math::Dot(start, end);

	dot = Math::Clamp(dot, -1.0f, 1.0f);

	float theta = acos(dot) * t;

	Vector2 relativeVector = end - start * dot;
	relativeVector.Normalize();

	return ((start * cos(theta)) + (relativeVector * sin(theta)));
}

Vector3 Math::Slerp(const Vector3& start, const Vector3& end, float t)
{
	float dot = Math::Dot(start, end);

	dot = Math::Clamp(dot, -1.0f, 1.0f);

	float theta = acos(dot) * t;

	Vector3 relativeVector = end - start * dot;
	relativeVector.Normalize();

	return ((start * cos(theta)) + (relativeVector * sin(theta)));
}

Vector4 Math::Slerp(const Vector4& start, const Vector4& end, float t)
{
	float dot = Math::Dot(start, end);

	dot = Math::Clamp(dot, -1.0f, 1.0f);

	float theta = acos(dot) * t;

	Vector4 relativeVector = end - start * dot;
	relativeVector.Normalize();

	return ((start * cos(theta)) + (relativeVector * sin(theta)));
}

Quaternion Math::Slerp(const Quaternion& start, const Quaternion& end, float t)
{
	return start;
	//return (end * start.Inverse()) * t * start;
}

Vector2 Math::NLerp(const Vector2& start, const Vector2& end, float t)
{
	return Normalize(Lerp(start, end, t));
}

Vector3 Math::NLerp(const Vector3& start, const Vector3& end, float t)
{
	return Normalize(Lerp(start, end, t));
}

Vector4 Math::NLerp(const Vector4& start, const Vector4& end, float t)
{
	return Normalize(Lerp(start, end, t));
}

Quaternion Math::NLerp(const Quaternion& start, const Quaternion& end, float t)
{
	return Normalize(Lerp(start, end, t));
}

float Math::CosineInterpolate(float start, float end, float t)
{
	float mu2 = (1.0f - static_cast<float>(cos(static_cast<double>(t) * k_pi))) / 2.0f;
	return (start * (1 - mu2) + end * mu2);
}

double Math::CosineInterpolate(double start, double end, double t)
{
	double mu2 = (1.0 - (cos(t * k_pi))) / 2.0;
	return (start * (1 - mu2) + end * mu2);
}
