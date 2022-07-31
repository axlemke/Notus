#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"

namespace Math
{
	class Vector2;;
	class Triangle2D;
	class Triangle3D;

	constexpr Vector3 k_centroidBarycentricCoords(1.0f / 3.0f);

	constexpr Vector3 k_edgeMidpoint0BarycentricCoords(0.5f, 0.5f, 0.0f);
	constexpr Vector3 k_edgeMidpoint1BarycentricCoords(0.0f, 0.5f, 0.5f);
	constexpr Vector3 k_edgeMidpoint2BarycentricCoords(0.5f, 0.0f, 0.5f);



	MATH_USAGE Vector3 GetBarycentricCoords(const Vector2& pointA, const Vector2& pointB, const Vector2& pointC, const Vector2& pointP);
	MATH_USAGE Vector3 GetBarycentricCoords(const Triangle2D& triangle, const Vector2& pointP);

	MATH_USAGE Vector3 GetBarycentricCoords(const Vector3& pointA, const Vector3& pointB, const Vector3& pointC, const Vector3& pointP);
	MATH_USAGE Vector3 GetBarycentricCoords(const Triangle3D& triangle, const Vector3& pointP);
};
