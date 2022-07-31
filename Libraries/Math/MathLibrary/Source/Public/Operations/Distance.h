#pragma once

#include "MathCommon.h"

namespace Math
{
	class AxisAlignedBoundingBox2D;
	class AxisAlignedBoundingBox3D;
	class Capsule2D;
	class Capsule3D;
	class Line2D;
	class Line3D;
	class Plane;
	class Sphere2D;
	class Sphere3D;
	class Triangle2D;
	class Triangle3D;
	class Vector2;
	class Vector3;
	class Vector4;

	MATH_USAGE float Distance(float rhs, float lhs);

	MATH_USAGE float Distance(const Vector2& pointA, const Vector2& pointB);
	MATH_USAGE float Distance(const Vector3& pointA, const Vector3& pointB);
	MATH_USAGE float DistanceSquared(const Vector2& pointA, const Vector2& pointB);
	MATH_USAGE float DistanceSquared(const Vector3& pointA, const Vector3& pointB);

	MATH_USAGE bool IsWithinBounds(float value, float minValue, float maxValue);
	MATH_USAGE bool IsWithinBounds(const Vector2& value, const Vector2& minValue, const Vector2& maxValue);
	MATH_USAGE bool IsWithinBounds(const Vector3& value, const Vector3& minValue, const Vector3& maxValue);
	MATH_USAGE bool IsWithinBounds(const Vector4& value, const Vector4& minValue, const Vector4& maxValue);

	MATH_USAGE bool DoBoundsOverlap(float lhsMinValue, float lhsMaxValue, float rhsMinValue, float rhsMaxValue);
	MATH_USAGE bool DoBoundsOverlap(const Vector2& lhsMinValues, const Vector2& lhsMaxValues, const Vector2& rhsMinValues, const Vector2& rhsMaxValues);
	MATH_USAGE bool DoBoundsOverlap(const Vector3& lhsMinValues, const Vector3& lhsMaxValues, const Vector3& rhsMinValues, const Vector3& rhsMaxValues);

	MATH_USAGE float DistanceOutsideOfBounds(float value, float minValue, float maxValue);
	MATH_USAGE float DistanceSquaredOutsideOfBounds(const Vector2& value, const Vector2& minValue, const Vector2& maxValue);
	MATH_USAGE float DistanceSquaredOutsideOfBounds(const Vector3& value, const Vector3& minValue, const Vector3& maxValue);
	MATH_USAGE float DistanceSquaredOutsideOfBounds(const Vector4& value, const Vector4& minValue, const Vector4& maxValue);

	MATH_USAGE float DistanceOutsideOfBounds(float value, float minValue, float maxValue);
	MATH_USAGE float DistanceOutsideOfBounds(const Vector2& value, const Vector2& minValue, const Vector2& maxValue);
	MATH_USAGE float DistanceOutsideOfBounds(const Vector3& value, const Vector3& minValue, const Vector3& maxValue);
	MATH_USAGE float DistanceOutsideOfBounds(const Vector4& value, const Vector4& minValue, const Vector4& maxValue);

	MATH_USAGE float Distance(const Plane& plane, const Vector3& point);
	MATH_USAGE float Distance(const Plane& plane, const Sphere3D& sphere);

	MATH_USAGE float DistanceSquared(const Sphere2D& lhs, const Sphere2D& rhs);
	MATH_USAGE float DistanceSquared(const Sphere3D& lhs, const Sphere3D& rhs);

	MATH_USAGE float DistanceSquared(const Sphere2D& sphere, const Vector2& point);
	MATH_USAGE float DistanceSquared(const Sphere3D& sphere, const Vector3& point);
	MATH_USAGE	float DistanceSquared(const Vector2& point, const Sphere2D& sphere);
	MATH_USAGE	float DistanceSquared(const Vector3& point, const Sphere3D& sphere);

	MATH_USAGE void GetClosestPointOnLineToPoint(const Line2D& line, const Vector2& point, Vector2& closestPoint, float& t);
	MATH_USAGE void GetClosestPointOnLineToPoint(const Line3D& line, const Vector3& point, Vector3& closestPoint, float& t);

	MATH_USAGE Vector3 GetClosestPointOnTriangleToPoint(const Triangle3D& triangle, const Vector3& point);

	MATH_USAGE float DistanceSquared(const AxisAlignedBoundingBox2D& box, const Vector2& point);
	MATH_USAGE float DistanceSquared(const AxisAlignedBoundingBox3D& box, const Vector3& point);

	MATH_USAGE float DistanceSquared(const Vector2& lineStart, const Vector2& lineEnd, const Vector2& point);
	MATH_USAGE float DistanceSquared(const Vector3& lineStart, const Vector3& lineEnd, const Vector3& point);
	MATH_USAGE float DistanceSquared(const Line2D& line, const Vector2& point);
	MATH_USAGE float DistanceSquared(const Line3D& line, const Vector3& point);

	MATH_USAGE Vector2 GetClosestPointOnLineToPoint(const Vector2& lineStart, const Vector2& lineEnd, const Vector2& point);
	MATH_USAGE Vector3 GetClosestPointOnLineToPoint(const Vector3& lineStart, const Vector3& lineEnd, const Vector3& point);
	MATH_USAGE Vector2 GetClosestPointOnLineToPoint(const Line2D& line, const Vector2& point);
	MATH_USAGE Vector3 GetClosestPointOnLineToPoint(const Line3D& line, const Vector3& point);
};
