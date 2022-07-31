#pragma once

#include "MathCommon.h"
#include <string>

namespace Math
{
	class Vector2
	{
	public:
		MATH_USAGE constexpr Vector2()
			: x(0.0f)
			, y(0.0f)
		{
		}

		MATH_USAGE constexpr Vector2(float newX, float newY)
			: x(newX)
			, y(newY)
		{
		}

		MATH_USAGE constexpr Vector2(float value)
			: x(value)
			, y(value)
		{
		}

		MATH_USAGE constexpr Vector2(double newX, double newY)
			: x(static_cast<float>(newX))
			, y(static_cast<float>(newY))
		{
		}

		MATH_USAGE void SetXY(float newX, float newY);

		MATH_USAGE static Vector2 Zero();
		MATH_USAGE static Vector2 One();

		MATH_USAGE float GetValueByIndex(unsigned index) const;

		MATH_USAGE float Magnitude() const;
		MATH_USAGE float MagnitudeSquared() const;
		MATH_USAGE void Normalize();

		MATH_USAGE std::string ToString() const;

		MATH_USAGE Vector2& operator=(const Vector2& rhs);
		MATH_USAGE bool operator==(const Vector2& rhs) const;
		MATH_USAGE bool operator!=(const Vector2& rhs) const;

		MATH_USAGE Vector2& operator+=(const Vector2& rhs);
		MATH_USAGE Vector2& operator-=(const Vector2& rhs);
		MATH_USAGE Vector2& operator*=(const Vector2& rhs);
		MATH_USAGE Vector2& operator/=(const Vector2& rhs);
		MATH_USAGE Vector2& operator*=(float scale);
		MATH_USAGE Vector2& operator/=(float scale);

		MATH_USAGE float& operator[](const unsigned int spot);
		MATH_USAGE float operator[](const unsigned int spot) const;

		union
		{
			struct
			{
				float x;
				float y;
			};

			float m_data[2];
		};
	};

	MATH_USAGE float Dot(const Vector2& a, const Vector2& b);
	MATH_USAGE Vector2 Project(const Vector2& a, const Vector2& b);
	MATH_USAGE Vector2 UnitProject(const Vector2& lhs, const Vector2& b);
	MATH_USAGE Vector2 Reflection(const Vector2& d, const Vector2& n);
	MATH_USAGE Vector2 Normalize(const Vector2& v);
	MATH_USAGE float Magnitude(const Vector2& v);
	MATH_USAGE float MagnitudeSquared(const Vector2& v);

	MATH_USAGE Vector2 RotateAroundZAxis(const Vector2& v, float angle);
};

MATH_USAGE Math::Vector2 operator+(const Math::Vector2& lhs, const Math::Vector2& rhs);
MATH_USAGE Math::Vector2 operator-(const Math::Vector2& lhs, const Math::Vector2& rhs);
MATH_USAGE Math::Vector2 operator*(const Math::Vector2& lhs, const Math::Vector2& rhs);
MATH_USAGE Math::Vector2 operator*(const Math::Vector2& lhs, float scale);
MATH_USAGE Math::Vector2 operator*(float scale, const Math::Vector2& lhs);
MATH_USAGE Math::Vector2 operator/(const Math::Vector2& lhs, const Math::Vector2& rhs);
MATH_USAGE Math::Vector2 operator/(const Math::Vector2& lhs, float scale);
MATH_USAGE Math::Vector2 operator-(const Math::Vector2& lhs);

static_assert((sizeof(float) * 2) == sizeof(Math::Vector2));