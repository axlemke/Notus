#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"
#include <string>

namespace Math
{
	class Matrix3x3;
	class Matrix4x4;
	class Viewport;
	class Vector4;

	class Vector3
	{
	public:
		MATH_USAGE constexpr Vector3()
			: x(0.0f)
			, y(0.0f)
			, z(0.0f)
		{
		}

		MATH_USAGE constexpr Vector3(float newX, float newY, float newZ)
			: x(newX)
			, y(newY)
			, z(newZ)
		{
		}

		MATH_USAGE constexpr Vector3(float newValue)
			: x(newValue)
			, y(newValue)
			, z(newValue)
		{
		}

		MATH_USAGE constexpr Vector3(const Vector2& newValue, float newZ)
			: x(newValue.x)
			, y(newValue.y)
			, z(newZ)
		{
		}

		MATH_USAGE void SetXYZ(float newX, float newY, float newZ);

		MATH_USAGE float Magnitude() const;
		MATH_USAGE float MagnitudeSquared() const;
		MATH_USAGE void Normalize();

		MATH_USAGE const float* GetDataPointer() const;
		MATH_USAGE float* GetDataPointer();

		MATH_USAGE void ApplyTransformation(const Matrix4x4& transformation);
		MATH_USAGE void ApplyTransformation(const Matrix3x3& transformation);
		MATH_USAGE void ApplyTransformationAndNormalize(const Matrix4x4& transformation);
		MATH_USAGE void ApplyTransformationAndNormalize(const Matrix3x3& transformation);

		MATH_USAGE void RotateAroundAxis(const Vector3& axis, float angle);

		MATH_USAGE std::string ToString() const;
		

		MATH_USAGE static Vector3 Zero();
		MATH_USAGE static Vector3 One();
		MATH_USAGE static Vector3 Forward();
		MATH_USAGE static Vector3 Right();
		MATH_USAGE static Vector3 Up();
		MATH_USAGE static Vector3 Backward();
		MATH_USAGE static Vector3 Left();
		MATH_USAGE static Vector3 Down();

		MATH_USAGE Vector3& operator=(const Vector2& rhs);
		MATH_USAGE Vector3& operator=(const Vector3& rhs);
		MATH_USAGE Vector3& operator=(const Vector4& rhs);

		MATH_USAGE bool operator==(const Vector3& rhs) const;
		MATH_USAGE bool operator!=(const Vector3& rhs) const;
		MATH_USAGE Vector3& operator+=(const Vector3& rhs);
		MATH_USAGE Vector3& operator-=(const Vector3& rhs);
		MATH_USAGE Vector3& operator*=(const Vector3& rhs);
		MATH_USAGE Vector3& operator/=(const Vector3& rhs);
		MATH_USAGE Vector3& operator*=(float scale);
		MATH_USAGE Vector3& operator/=(float scale);

		MATH_USAGE Vector3& operator*=(const Matrix3x3& m);

		MATH_USAGE float& operator[](const unsigned int spot);
		MATH_USAGE float operator[](const unsigned int spot) const;
		
		union
		{
			struct
			{
				union
				{
					Vector2 m_xy;

					struct
					{
						union
						{
							float x;
							float r;
							float i;
						};

						union
						{
							float y;
							float g;
							float j;
						};
					};
				};

				union
				{
					float z;
					float b;
					float k;
				};
			};

			float m_data[3];
		};
	};

	MATH_USAGE float Dot(const Vector3& a, const Vector3& b);
	MATH_USAGE Vector3 Cross(const Vector3& a, const Vector3& b);
	MATH_USAGE float ScalarTriple(const Vector3& a, const Vector3& b, const Vector3& c);
	MATH_USAGE Vector3 Project(const Vector3& a, const Vector3& b);
	MATH_USAGE Vector3 UnitProject(const Vector3& a, const Vector3& b);
	MATH_USAGE Vector3 Reject(const Vector3& a, const Vector3& b);
	MATH_USAGE Vector3 Reflection(const Vector3& d, const Vector3& n);
	MATH_USAGE Vector3 Normalize(const Vector3& v);
	MATH_USAGE float Magnitude(const Vector3& v);
	MATH_USAGE float MagnitudeSquared(const Vector3& v);

	MATH_USAGE Vector3 RotateAroundAxis(const Vector3& v, const Vector3& axis, float angle);
}

MATH_USAGE Math::Vector3 operator+(const Math::Vector3& lhs, const Math::Vector3& rhs);
MATH_USAGE Math::Vector3 operator-(const Math::Vector3& lhs, const Math::Vector3& rhs);
MATH_USAGE Math::Vector3 operator*(const Math::Vector3& lhs, const Math::Vector3& rhs);
MATH_USAGE Math::Vector3 operator*(const Math::Vector3& lhs, float scale);
MATH_USAGE Math::Vector3 operator*(float scale, const Math::Vector3& rhs);
MATH_USAGE Math::Vector3 operator*(const Math::Vector3& lhs, float scale);
MATH_USAGE Math::Vector3 operator/(const Math::Vector3& lhs, float scale);
MATH_USAGE Math::Vector3 operator-(const Math::Vector3& lhs);
MATH_USAGE Math::Vector3 operator*(const Math::Vector3& v, const Math::Matrix3x3& m);

static_assert((sizeof(float) * 3) == sizeof(Math::Vector3));