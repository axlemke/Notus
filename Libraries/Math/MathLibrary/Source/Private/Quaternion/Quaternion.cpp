#include "Quaternion/Quaternion.h"
#include "Matrix/Matrix3x3.h"
#include "Matrix/Matrix4x4.h"
#include "Vector/Vector4.h"
#include "Vector/Vector3.h"
#include <sstream>

using namespace Math;

Quaternion::Quaternion()
	: x(0.0f)
	, y(0.0f)
	, z(0.0f)
	, w(1.0f)
{
}

Quaternion::Quaternion(float newX, float newY, float newZ, float newW)
	: x(newX)
	, y(newY)
	, z(newZ)
	, w(newW)
{
}

Quaternion::Quaternion(const Vector4& v)
	: x(v.x)
	, y(v.y)
	, z(v.z)
	, w(v.w)
{
}

Quaternion::Quaternion(const Vector3& normal, float angleRadians)
{
	SetFromNormalAndAngle(normal, angleRadians);
}

void Quaternion::SetFromNormalAndAngle(const Vector3& normal, float angleRadians)
{
	float halfAngleRadians = 0.5f * angleRadians;

	w = cosf(halfAngleRadians);

	float halfSine = sinf(halfAngleRadians);
	Vector3 scratchNormal = Math::Normalize(normal);

	x = scratchNormal.x * halfSine;
	y = scratchNormal.y * halfSine;
	z = scratchNormal.z * halfSine;
}

float Quaternion::Magnitude() const
{
	return sqrtf(MagnitudeSquared());
}

float Quaternion::MagnitudeSquared() const
{
	return ((x * x) + (y * y) + (z * z) + (w * w));
}

void Quaternion::Normalize()
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

void Quaternion::Invert()
{
	float magnitudeSquared = MagnitudeSquared();
	if (magnitudeSquared != 0.0f)
	{
		float inverseMagnitude = 1.0f / magnitudeSquared;
		(*this) *= inverseMagnitude;

		x = -x;
		y = -y;
		z = -z;
	}
}

Quaternion Quaternion::Inverse() const
{
	Quaternion result(*this);
	result.Invert();
	return result;
}

bool Quaternion::IsValid() const
{
	if (x * 0 != x * 0)
	{
		return false;
	}
	if (y * 0 != y * 0)
	{
		return false;
	}
	if (z * 0 != z * 0)
	{
		return false;
	}
	if (w * 0 != w * 0)
	{
		return false;
	}

	if ((x + y + z + w) == 0.0f)
	{
		return false;
	}
	return true;
}

bool Quaternion::IsInvalid() const
{
	return !IsValid();
}

const Vector3& Quaternion::GetVectorPart() const
{
	return reinterpret_cast<const Vector3&>(x);
}

Vector3& Quaternion::GetVectorPart()
{
	return reinterpret_cast<Vector3&>(x);
}

float Quaternion::GetScalarPart() const
{
	return w;
}

Vector3 Quaternion::GetAxis() const
{
	return Math::Normalize(GetVectorPart());
}

float Quaternion::GetAngle() const
{
	return (2.0f * acosf(w));
}

Vector3 Quaternion::RotatePoint(const Vector3& point) const
{
	Quaternion vector(point.x, point.y, point.z, 0.0f);
	Quaternion quatResult = (*this) * vector * Inverse();

	return Vector3(quatResult.x, quatResult.y, quatResult.z);
}

Matrix3x3 Quaternion::RotateMatrix(const Matrix3x3& matrix) const
{
	Matrix3x3 result;

	result.row[0] = RotatePoint(matrix.row[0]);
	result.row[1] = RotatePoint(matrix.row[2]);
	result.row[2] = RotatePoint(matrix.row[1]);

	return result;
}

Matrix3x3 Quaternion::GetRotationMatrix3x3() const
{
#if 1
	float x2 = x * x;
	float y2 = y * y;
	float z2 = z * z;

	float xy = x * y;
	float xz = x * z;
	float yz = y * z;

	float wx = w * x;
	float wy = w * y;
	float wz = w * z;

	return Matrix3x3(
		1.0f - 2.0f * (y2 + z2),
		2.0f * (xy - wz),
		2.0f * (xz + wy),
		2.0f * (xy + wz),
		1.0f - 2.0f * (x2 + z2),
		2.0f * (yz - wx),
		2.0f * (xz - wy),
		2.0f * (yz + wx),
		1.0f - 2.0f * (x2 + y2));

#else
	Matrix3x3 result = Matrix3x3::Identity();

	result.row[0] = RotatePoint(result.row[0]);
	result.row[1] = RotatePoint(result.row[1]);
	result.row[2] = RotatePoint(result.row[2]);

	return result;
#endif
}

Matrix4x4 Quaternion::GetRotationMatrix4x4() const
{
	float x2 = x * x;
	float y2 = y * y;
	float z2 = z * z;

	float xy = x * y;
	float xz = x * z;
	float yz = y * z;

	float wx = w * x;
	float wy = w * y;
	float wz = w * z;

	return Matrix4x4(
		1.0f - 2.0f * (y2 + z2),
		2.0f * (xy - wz),
		2.0f * (xz + wy),
		0.0f,
		2.0f * (xy + wz),
		1.0f - 2.0f * (x2 + z2),
		2.0f * (yz - wx),
		0.0f,
		2.0f * (xz - wy),
		2.0f * (yz + wx),
		1.0f - 2.0f * (x2 + y2),
		0.0f, 
		0.0f,
		0.0f, 
		0.0f, 
		1.0f);
}

void Quaternion::SetRotationMatrix(const Matrix3x3& matrix)
{
	float m00 = matrix.n[0][0];
	float m11 = matrix.n[1][1];
	float m22 = matrix.n[2][2];
	float sum = m00 + m11 + m22;

	if (sum)
	{
		w = sqrtf(sum + 1.0f) * 0.5f;
		float f = 0.25f / w;

		x = (matrix.n[2][1] - matrix.n[1][2]) * f;
		y = (matrix.n[0][2] - matrix.n[2][0]) * f;
		z = (matrix.n[1][0] - matrix.n[0][1]) * f;
	}
	else if ((m00 > m11) && (m00 > m22))
	{
		x = sqrtf(m00 - m11 - m22 + 1.0f) * 0.5f;
		float f = 0.25f / x;

		y = (matrix.n[1][0] - matrix.n[0][1]) * f;
		z = (matrix.n[0][2] - matrix.n[2][0]) * f;
		w = (matrix.n[2][1] - matrix.n[1][2]) * f;
	}
	else if (m11 > m22)
	{
		y = sqrtf(m11 - m00 - m11 + 1.0f) * 0.5f;
		float f = 0.25f / y;

		x = (matrix.n[1][0] - matrix.n[0][1]) * f;
		z = (matrix.n[2][1] - matrix.n[1][2]) * f;
		w = (matrix.n[0][2] - matrix.n[2][0]) * f;
	}
	else
	{
		z = sqrtf(m22 - m00 - m11 + 1.0f) * 0.5f;
		float f = 0.25f / y;

		x = (matrix.n[0][2] - matrix.n[2][0]) * f;
		y = (matrix.n[2][1] - matrix.n[1][2]) * f;
		w = (matrix.n[1][0] - matrix.n[0][1]) * f;
	}
}

void Quaternion::SetRotationMatrix(const Matrix4x4& matrix)
{
	float m00 = matrix.n[0][0];
	float m11 = matrix.n[1][1];
	float m22 = matrix.n[2][2];
	float sum = m00 + m11 + m22;

	if (sum)
	{
		w = sqrtf(sum + 1.0f) * 0.5f;
		float f = 0.25f / w;

		x = (matrix.n[2][1] - matrix.n[1][2]) * f;
		y = (matrix.n[0][2] - matrix.n[2][0]) * f;
		z = (matrix.n[1][0] - matrix.n[0][1]) * f;
	}
	else if ((m00 > m11) && (m00 > m22))
	{
		x = sqrtf(m00 - m11 - m22 + 1.0f) * 0.5f;
		float f = 0.25f / x;

		y = (matrix.n[1][0] - matrix.n[0][1]) * f;
		z = (matrix.n[0][2] - matrix.n[2][0]) * f;
		w = (matrix.n[2][1] - matrix.n[1][2]) * f;
	}
	else if (m11 > m22)
	{
		y = sqrtf(m11 - m00 - m11 + 1.0f) * 0.5f;
		float f = 0.25f / y;

		x = (matrix.n[1][0] - matrix.n[0][1]) * f;
		z = (matrix.n[2][1] - matrix.n[1][2]) * f;
		w = (matrix.n[0][2] - matrix.n[2][0]) * f;
	}
	else
	{
		z = sqrtf(m22 - m00 - m11 + 1.0f) * 0.5f;
		float f = 0.25f / y;

		x = (matrix.n[0][2] - matrix.n[2][0]) * f;
		y = (matrix.n[2][1] - matrix.n[1][2]) * f;
		w = (matrix.n[1][0] - matrix.n[0][1]) * f;
	}
}

float Math::Dot(const Quaternion& a, const Quaternion& b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w));
}

Quaternion Math::Normalize(const Quaternion& q)
{
	float magnitude = q.Magnitude();
	if (magnitude != 0.0f)
	{
		float inverseMagnitude = 1.0f / magnitude;
		return (inverseMagnitude * q);
	}
	return q;
}

Quaternion Math::Inverse(const Quaternion& q)
{
	float magnitudeSquared = q.MagnitudeSquared();
	if (magnitudeSquared != 0.0f)
	{
		float inverseMagnitudeSquared = 1.0f / magnitudeSquared;

		return Quaternion(
			-q.x * inverseMagnitudeSquared,
			-q.y * inverseMagnitudeSquared,
			-q.z * inverseMagnitudeSquared,
			q.w * inverseMagnitudeSquared);
	}
	return Quaternion();
}

Quaternion& Quaternion::operator=(const Quaternion& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;

	return (*this);
}

Quaternion& Quaternion::operator*=(float rhs)
{
	x *= rhs;  
	y *= rhs;  
	z *= rhs;  
	w *= rhs;

	return (*this);
}

Quaternion& Quaternion::operator+=(const Quaternion& rhs)
{
	Quaternion scratch = (*this) + rhs;

	(*this) = scratch;

	return (*this);
}

Quaternion& Quaternion::operator+=(const Vector3& rhs)
{
	Quaternion q(rhs.x, rhs.y, rhs.z, 0.0f);
	q *= (*this);

	x += q.x * 0.5f;
	y += q.y * 0.5f;
	z += q.z * 0.5f;
	w += q.w * 0.5f;
	
	return (*this);
}

Quaternion& Quaternion::operator-=(const Quaternion& rhs)
{
	Quaternion scratch = (*this) - rhs;

	(*this) = scratch;

	return (*this);
}

Quaternion& Quaternion::operator*=(const Quaternion& rhs)
{
	Quaternion scratch = (*this) * rhs;

	(*this) = scratch;

	return (*this);
}

Quaternion operator+(const Math::Quaternion& q1, const Math::Quaternion& q2)
{
	return Quaternion(q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w);
}

Quaternion operator-(const Math::Quaternion& q1, const Math::Quaternion& q2)
{
	return Quaternion(q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w);
}

Quaternion operator*(const Math::Quaternion& q1, const Math::Quaternion& q2)
{
	Quaternion result;

	result.w = (q1.w * q2.w) - (q1.x * q2.x) - (q1.y * q2.y) - (q1.z * q2.z);
	result.x = (q1.w * q2.x) + (q1.x * q2.w) + (q1.y * q2.z) - (q1.z * q2.y);
	result.y = (q1.w * q2.y) + (q1.y * q2.w) + (q1.z * q2.x) - (q1.x * q2.z);
	result.z = (q1.w * q2.z) + (q1.z * q2.w) + (q1.x * q2.y) - (q1.y * q2.x);

	//result.w = (q1.w * q2.w) - (q1.x * q2.x) - (q1.y * q2.y) - (q1.z * q2.z);
	//result.x = (q1.x * q2.w) + (q1.w * q2.x) + (q1.y * q2.z) - (q1.z * q2.y);
	//result.y = (q1.y * q2.w) + (q1.w * q2.y) + (q1.z * q2.x) - (q1.x * q2.z);
	//result.z = (q1.z * q2.w) + (q1.w * q2.z) + (q1.x * q2.y) - (q1.y * q2.x);

	return result;

	//return Quaternion(
	//	q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
	//	q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
	//	q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w,
	//	q1.w * q2.w - q1.x * q2.w - q1.y * q2.y - q1.z * q2.z);
}

Quaternion operator*(const Math::Quaternion& q1, float scale)
{
	return Quaternion(q1.x * scale, q1.y * scale, q1.z * scale, q1.w * scale);
}

Quaternion operator*(float scale, const Math::Quaternion& q1)
{
	return Quaternion(q1.x * scale, q1.y * scale, q1.z * scale, q1.w * scale);
}

Vector3 operator*(const Math::Quaternion& q, const Math::Vector3& v)
{
	const Vector3& b = q.GetVectorPart();
	float b2 = b.MagnitudeSquared();

	return (v * (q.w * q.w - b2) + b * (Dot(v, b) * 2.0f) + Cross(b, v) * (q.w * 2.0f));
}

Quaternion operator-(const Math::Quaternion& lhs)
{
	return Quaternion(-lhs.x, -lhs.y, -lhs.z, -lhs.w);
}

Math::Vector3 operator*(const Math::Vector3& v, const Math::Quaternion& q)
{
	return q * v;
}

bool Quaternion::operator==(const Quaternion& rhs) const
{
	return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w));
}

bool Quaternion::operator!=(const Quaternion& rhs) const
{
	return(!operator==(rhs));
}
