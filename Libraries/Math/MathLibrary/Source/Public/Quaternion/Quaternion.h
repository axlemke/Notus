#pragma once

#include "MathCommon.h"

namespace Math
{
	// Forward Declarations
	class Matrix3x3;
	class Matrix4x4;
	class Vector4;
	class Vector3;
	
	class Quaternion
	{
	public:
		MATH_USAGE Quaternion();
		MATH_USAGE Quaternion(float newX, float newY, float newZ, float newW);
		MATH_USAGE Quaternion(const Vector4& v);
		MATH_USAGE Quaternion(const Vector3& normal, float angleRadians);

		MATH_USAGE void SetFromNormalAndAngle(const Vector3& normal, float angleRadians);

		MATH_USAGE float Magnitude() const;
		MATH_USAGE float MagnitudeSquared() const;

		MATH_USAGE void Normalize();

		MATH_USAGE void Invert();
		MATH_USAGE Quaternion Inverse() const;

		MATH_USAGE bool IsValid() const;
		MATH_USAGE bool IsInvalid() const;

		MATH_USAGE const Vector3& GetVectorPart() const;
		MATH_USAGE Vector3& GetVectorPart();
		MATH_USAGE float GetScalarPart() const;

		MATH_USAGE Vector3 GetAxis() const;
		MATH_USAGE float GetAngle() const;

		MATH_USAGE Vector3 RotatePoint(const Vector3& point) const;
		MATH_USAGE Matrix3x3 RotateMatrix(const Matrix3x3& matrix) const;

		MATH_USAGE Matrix3x3 GetRotationMatrix3x3() const;
		MATH_USAGE Matrix4x4 GetRotationMatrix4x4() const;
		MATH_USAGE void SetRotationMatrix(const Matrix3x3& matrix);
		MATH_USAGE void SetRotationMatrix(const Matrix4x4& matrix);

		MATH_USAGE static Quaternion QuaternionMultiply(const Quaternion& q1, const Quaternion& q2)
		{
			Quaternion result;
			result.x = (q2.w * q1.x) + (q2.x * q1.w) + (q2.y * q1.z) - (q2.z * q1.y);
			result.y = (q2.w * q1.y) - (q2.x * q1.z) + (q2.y * q1.w) + (q2.z * q1.x);
			result.z = (q2.w * q1.z) + (q2.x * q1.y) - (q2.y * q1.x) + (q2.z * q1.w);
			result.w = (q2.w * q1.w) - (q2.x * q1.x) - (q2.y * q1.y) - (q2.z * q1.z);

			return result;
		}

		MATH_USAGE Quaternion& operator=(const Quaternion& rhs);

		MATH_USAGE Quaternion& operator*=(float rhs);
		MATH_USAGE Quaternion& operator+=(const Quaternion& rhs);
		MATH_USAGE Quaternion& operator+=(const Vector3& rhs);
		MATH_USAGE Quaternion& operator-=(const Quaternion& rhs);
		MATH_USAGE Quaternion& operator*=(const Quaternion& rhs);



		MATH_USAGE bool operator==(const Quaternion& rhs) const;
		MATH_USAGE bool operator!=(const Quaternion& rhs) const;

		union
		{
			float x;
			float i;
		};

		union
		{
			float y;
			float j;
		};

		union
		{
			float z;
			float k;
		};

		union
		{
			float w;
		};
	};

	MATH_USAGE float Dot(const Quaternion& a, const Quaternion& b);
	MATH_USAGE Quaternion Normalize(const Quaternion& q);
	MATH_USAGE Quaternion Inverse(const Quaternion& q);
}

MATH_USAGE Math::Quaternion operator+(const Math::Quaternion& q1, const Math::Quaternion& q2);
MATH_USAGE Math::Quaternion operator-(const Math::Quaternion& q1, const Math::Quaternion& q2);
MATH_USAGE Math::Quaternion operator*(const Math::Quaternion& q1, const Math::Quaternion& q2);
MATH_USAGE Math::Quaternion operator*(const Math::Quaternion& q1, float scale);
MATH_USAGE Math::Quaternion operator*(float scale, const Math::Quaternion& q1);
MATH_USAGE Math::Quaternion operator-(const Math::Quaternion& lhs);
MATH_USAGE Math::Vector3 operator*(const Math::Quaternion& q, const Math::Vector3& v);
MATH_USAGE Math::Vector3 operator*(const Math::Vector3& v, const Math::Quaternion& q);

static_assert((sizeof(float) * 4) == sizeof(Math::Quaternion));
 