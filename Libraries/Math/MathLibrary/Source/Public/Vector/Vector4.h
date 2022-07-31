#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"
#include <string>

namespace Math
{
	class Matrix4x4;

	class Vector2;
	class Vector3;

	class Vector4
	{
	public:
		MATH_USAGE constexpr Vector4()
			: x(0.0f)
			, y(0.0f)
			, z(0.0f)
			, w(1.0f)
		{
		}

		MATH_USAGE constexpr Vector4(float newX, float newY, float newZ, float newW)
			: x(newX)
			, y(newY)
			, z(newZ)
			, w(newW)
		{
		}

		MATH_USAGE constexpr Vector4(float newX, float newY, float newZ)
			: x(newX)
			, y(newY)
			, z(newZ)
			, w(1.0f)
		{
		}

		MATH_USAGE constexpr Vector4(float newValue)
			: x(newValue)
			, y(newValue)
			, z(newValue)
			, w(newValue)
		{
		}


		MATH_USAGE constexpr Vector4(const Vector3& newValue, float newW)
			: x(newValue.x)
			, y(newValue.y)
			, z(newValue.z)
			, w(newW)
		{
		}

		MATH_USAGE constexpr Vector4(const Vector2& newValueXY, const Vector2& newValueZW)
			: x(newValueXY.x)
			, y(newValueXY.y)
			, z(newValueZW.x)
			, w(newValueZW.y)
		{
		}

		MATH_USAGE void SetXYZW(float newX, float newY, float newZ, float newW);
		MATH_USAGE void SetXYZ(float newX, float newY, float newZ);

		MATH_USAGE const Vector3& GetXYZ() const;

		MATH_USAGE float Magnitude() const;
		MATH_USAGE float MagnitudeSquared() const;
		MATH_USAGE void Normalize();

		MATH_USAGE float Dot(const Vector4& rhs) const;
		MATH_USAGE Vector4 Cross(const Vector4& rhs) const;

		MATH_USAGE std::string ToString() const;

		MATH_USAGE static Vector4 Zero();
		MATH_USAGE static Vector4 One();

		MATH_USAGE bool operator==(const Vector4& rhs) const;
		MATH_USAGE bool operator!=(const Vector4& rhs) const;

		MATH_USAGE Vector4& operator=(const Vector2& rhs);
		MATH_USAGE Vector4& operator=(const Vector3& rhs);
		MATH_USAGE Vector4& operator=(const Vector4& rhs);

		MATH_USAGE Vector4& operator+=(const Vector4& rhs);
		MATH_USAGE Vector4& operator-=(const Vector4& rhs);
		MATH_USAGE Vector4& operator*=(const Vector4& rhs);
		MATH_USAGE Vector4& operator/=(const Vector4& rhs);
		MATH_USAGE Vector4& operator*=(float scale);
		MATH_USAGE Vector4& operator/=(float scale);

		MATH_USAGE void ApplyTransformation(const Matrix4x4& transformation);

		union
		{
			struct
			{
				union
				{
					Vector3 m_xyz;

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

						union
						{
							float z;
							float b;
							float k;
						};
					};
				};

				union
				{
					float w;
					float a;
				};
			};

			float m_data[4];
		};
	};

	MATH_USAGE float Dot(const Vector4& a, const Vector4& b);
	MATH_USAGE Vector4 Cross(const Vector4& a, const Vector4& b);
	MATH_USAGE Vector4 Normalize(const Vector4& v);
	MATH_USAGE float Magnitude(const Vector4& v);
	MATH_USAGE float MagnitudeSquared(const Vector4& v);
}

MATH_USAGE Math::Vector4 operator+(const Math::Vector4& lhs, const Math::Vector4& rhs);
MATH_USAGE Math::Vector4 operator-(const Math::Vector4& lhs, const Math::Vector4& rhs);
MATH_USAGE Math::Vector4 operator*(const Math::Vector4& lhs, const Math::Vector4& rhs);
MATH_USAGE Math::Vector4 operator*(const Math::Vector4& lhs, float scale);
MATH_USAGE Math::Vector4 operator*(float scale, const Math::Vector4& lhs);
MATH_USAGE Math::Vector4 operator/(const Math::Vector4& lhs, const Math::Vector4& rhs);
MATH_USAGE Math::Vector4 operator/(const Math::Vector4& lhs, float scale);
MATH_USAGE Math::Vector4 operator-(const Math::Vector4& lhs);

static_assert((sizeof(float) * 4) == sizeof(Math::Vector4));