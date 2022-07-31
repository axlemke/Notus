#include "Operations/Distance.h"

#include "Lines/Line2D.h"
#include "Lines/Line3D.h"
#include "Operations/MinMax.h"
#include "Operations/Saturate.h"
#include "Surfaces/Plane/Plane.h"
#include "Surfaces/Triangles/Triangle2D.h"
#include "Surfaces/Triangles/Triangle3D.h"
#include "Vector/Vector2.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"
#include "Volumes/AxisAlignedBoundingBox/AxisAlignedBoundingBox2D.h"
#include "Volumes/AxisAlignedBoundingBox/AxisAlignedBoundingBox3D.h"
#include "Volumes/Sphere/Sphere2D.h"
#include "Volumes/Sphere/Sphere3D.h"

using namespace Math;

float Math::Distance(float rhs, float lhs)
{
	return abs(rhs - lhs);
}

float Math::Distance(const Vector2& pointA, const Vector2& pointB)
{
	Vector2 difference = pointB - pointA;
	return difference.Magnitude();
}

float Math::Distance(const Vector3& pointA, const Vector3& pointB)
{
	Vector3 difference = pointB - pointA;
	return difference.Magnitude();
}

float Math::DistanceSquared(const Vector2& pointA, const Vector2& pointB)
{
	Vector2 difference = pointB - pointA;
	return difference.MagnitudeSquared();
}

float Math::DistanceSquared(const Vector3& pointA, const Vector3& pointB)
{
	Vector3 difference = pointB - pointA;
	return difference.MagnitudeSquared();
}

bool Math::IsWithinBounds(float value, float minValue, float maxValue)
{
	if ((maxValue <= value) || (minValue >= value))
	{
		return false;
	}
	return true;
}

bool Math::IsWithinBounds(const Vector2& value, const Vector2& minValue, const Vector2& maxValue)
{
	if (IsWithinBounds(value.x, minValue.x, maxValue.x) && IsWithinBounds(value.y, minValue.y, maxValue.y))
	{
		return true;
	}
	return false;
}

bool Math::IsWithinBounds(const Vector3& value, const Vector3& minValue, const Vector3& maxValue)
{
	if (IsWithinBounds(value.m_xy, minValue.m_xy, maxValue.m_xy)
		&& IsWithinBounds(value.z, minValue.z, maxValue.z))
	{
		return true;
	}
	return false;
}

bool Math::IsWithinBounds(const Vector4& value, const Vector4& minValue, const Vector4& maxValue)
{
	if (IsWithinBounds(value.m_xyz, minValue.m_xyz, maxValue.m_xyz)
		&& IsWithinBounds(value.w, minValue.w, maxValue.w))
	{
		return true;
	}
	return false;
}

bool Math::DoBoundsOverlap(float lhsMinValue, float lhsMaxValue, float rhsMinValue, float rhsMaxValue)
{
	if ((lhsMaxValue <= rhsMinValue) || (lhsMinValue >= rhsMaxValue))
	{
		return false;
	}
	return true;
}

bool Math::DoBoundsOverlap(const Vector2& lhsMinValues, const Vector2& lhsMaxValues, const Vector2& rhsMinValues, const Vector2& rhsMaxValues)
{
	if (DoBoundsOverlap(lhsMinValues.x, lhsMaxValues.x, rhsMinValues.x, rhsMaxValues.x)
		&& DoBoundsOverlap(lhsMinValues.y, lhsMaxValues.y, rhsMinValues.y, rhsMaxValues.y))
	{
		return true;
	}
	return false;
}

bool Math::DoBoundsOverlap(const Vector3& lhsMinValues, const Vector3& lhsMaxValues, const Vector3& rhsMinValues, const Vector3& rhsMaxValues)
{
	if (DoBoundsOverlap(lhsMinValues.m_xy, lhsMaxValues.m_xy, rhsMinValues.x, rhsMaxValues.m_xy)
		&& DoBoundsOverlap(lhsMinValues.z, lhsMaxValues.z, rhsMinValues.z, rhsMaxValues.z))
	{
		return true;
	}
	return false;
}

float Math::DistanceOutsideOfBounds(float value, float minValue, float maxValue)
{
	float distanceSquared = 0.0f;

	if (value < minValue)
	{
		float difference = minValue - value;
		distanceSquared += difference * difference;
	}
	
	if (value > maxValue)
	{
		float difference = value - maxValue;
		distanceSquared += difference * difference;
	}

	return distanceSquared;
}

float Math::DistanceSquaredOutsideOfBounds(const Vector2& value, const Vector2& minValue, const Vector2& maxValue)
{
	Vector2 distanceSquared(0.0f);

	distanceSquared.x = DistanceOutsideOfBounds(value.x, minValue.x, maxValue.x);
	distanceSquared.y = DistanceOutsideOfBounds(value.y, minValue.y, maxValue.y);

	return distanceSquared.MagnitudeSquared();
}

float Math::DistanceSquaredOutsideOfBounds(const Vector3& value, const Vector3& minValue, const Vector3& maxValue)
{
	Vector3 distanceSquared(0.0f);

	distanceSquared.x = DistanceOutsideOfBounds(value.x, minValue.x, maxValue.x);
	distanceSquared.y = DistanceOutsideOfBounds(value.y, minValue.y, maxValue.y);
	distanceSquared.z = DistanceOutsideOfBounds(value.z, minValue.z, maxValue.z);

	return distanceSquared.MagnitudeSquared();
}

float Math::DistanceSquaredOutsideOfBounds(const Vector4& value, const Vector4& minValue, const Vector4& maxValue)
{
	Vector4 distanceSquared(0.0f);

	distanceSquared.x = DistanceOutsideOfBounds(value.x, minValue.x, maxValue.x);
	distanceSquared.y = DistanceOutsideOfBounds(value.y, minValue.y, maxValue.y);
	distanceSquared.z = DistanceOutsideOfBounds(value.z, minValue.z, maxValue.z);
	distanceSquared.w = DistanceOutsideOfBounds(value.w, minValue.w, maxValue.w);

	return distanceSquared.MagnitudeSquared();
}

float Math::DistanceOutsideOfBounds(const Vector2& value, const Vector2& minValue, const Vector2& maxValue)
{
	float distanceSquared = DistanceSquaredOutsideOfBounds(value, minValue, maxValue);
	return sqrtf(distanceSquared);
}

float Math::DistanceOutsideOfBounds(const Vector3& value, const Vector3& minValue, const Vector3& maxValue)
{
	float distanceSquared = DistanceSquaredOutsideOfBounds(value, minValue, maxValue);
	return sqrtf(distanceSquared);
}

float Math::DistanceOutsideOfBounds(const Vector4& value, const Vector4& minValue, const Vector4& maxValue)
{
	float distanceSquared = DistanceSquaredOutsideOfBounds(value, minValue, maxValue);
	return sqrtf(distanceSquared);
}

float Math::Distance(const Plane& plane, const Vector3& point)
{
	return Math::Dot(point, plane.GetNormal()) - plane.GetDistanceFromOrigin();
}

float Math::Distance(const Plane& plane, const Sphere3D& sphere)
{
	float distanceToSphereCenter = Math::Dot(sphere.GetCenter(), plane.GetNormal()) - plane.GetDistanceFromOrigin();
	return Math::Max(distanceToSphereCenter - sphere.GetRadius(), 0.0f);
}

float Math::DistanceSquared(const Sphere2D& lhs, const Sphere2D& rhs)
{
	Vector2 difference = lhs.GetCenter() - rhs.GetCenter();
	float distanceSquared = difference.MagnitudeSquared();
	float radiiSum = (lhs.GetRadius() + rhs.GetRadius());
	return Math::Max(distanceSquared - (radiiSum * radiiSum), 0.0f);
}

float Math::DistanceSquared(const Sphere3D& lhs, const Sphere3D& rhs)
{
	Vector3 difference = lhs.GetCenter() - rhs.GetCenter();
	float distanceSquared = difference.MagnitudeSquared();
	float radiiSum = (lhs.GetRadius() + rhs.GetRadius());
	return Math::Max(distanceSquared - (radiiSum * radiiSum), 0.0f);
}

float Math::DistanceSquared(const Sphere2D& sphere, const Vector2& point)
{
	Vector2 difference = sphere.GetCenter() - point;
	float distanceSquared = difference.MagnitudeSquared();
	return Math::Max(distanceSquared - (sphere.GetRadius() * sphere.GetRadius()), 0.0f);
}

float Math::DistanceSquared(const Sphere3D& sphere, const Vector3& point)
{
	Vector3 difference = sphere.GetCenter() - point;
	float distanceSquared = difference.MagnitudeSquared();
	return Math::Max(distanceSquared - (sphere.GetRadius() * sphere.GetRadius()), 0.0f);
}

float Math::DistanceSquared(const Vector2& point, const Sphere2D& sphere)
{
	return DistanceSquared(sphere, point);
}

float Math::DistanceSquared(const Vector3& point, const Sphere3D& sphere)
{
	return DistanceSquared(sphere, point);
}

void Math::GetClosestPointOnLineToPoint(const Line2D& line, const Vector2& point, Vector2& closestPoint, float& t)
{
	const Vector2& start = line.GetStart();
	Vector2 lineDirecton = line.GetLineDirection();

	//Math::Project(point, line);
	t = Math::Dot(point - start, lineDirecton) / Math::Dot(lineDirecton, lineDirecton);

	//t = Math::Clamp(t, 0.0f, 1.0f);
	t = Math::Saturate(t);

	closestPoint = start + t * lineDirecton;
}

void Math::GetClosestPointOnLineToPoint(const Line3D& line, const Vector3& point, Vector3& closestPoint, float& t)
{
	const Vector3& start = line.GetStart();
	Vector3 lineDirecton = line.GetLineDirection();

	//Math::Project(point, line);
	t = Math::Dot(point - start, lineDirecton) / Math::Dot(lineDirecton, lineDirecton);

	//t = Math::Clamp(t, 0.0f, 1.0f);
	t = Math::Saturate(t);

	closestPoint = start + t * lineDirecton;
}

Vector3 Math::GetClosestPointOnTriangleToPoint(const Triangle3D& triangle, const Vector3& point)
{
	const Vector3& pointA = triangle.GetPointA();
	const Vector3& pointB = triangle.GetPointB();
	const Vector3& pointC = triangle.GetPointC();

	Vector3 ab = pointB - pointA;
	Vector3 ac = pointC - pointA;
	Vector3 bc = pointC - pointB;

	Vector3 n = Math::Cross(ab, ac);

	float sNom = Math::Dot(point - pointA, ab);
	float sDenom = Math::Dot(point - pointB, pointA - pointB); // Any reason why we can't use -ab here?

	float tNom = Math::Dot(point - pointA, ac);
	float tDenom = Math::Dot(point - pointC, pointA - pointC);

	if ((sNom <= 0.0f) && (tNom <= 0.0f))
	{
		return pointA;
	}

	float uNom = Math::Dot(point - pointB, bc);
	float uDenom = Math::Dot(point - pointC, pointB - pointC);

	if ((sDenom <= 0.0f) && (uNom <= 0.0f))
	{
		return pointB;
	}

	if ((tDenom <= 0.0f) && (uDenom <= 0.0f))
	{
		return pointC;
	}

	// If outside or on AB
	float vc = Math::Dot(n, Math::Cross(pointA - point, pointB - point));

	if ((vc <= 0.0f) && (sNom >= 0.0f) && (sDenom >= 0.0f))
	{
		return pointA + sNom / (sNom + sDenom) * ab;
	}

	// If outside or on BC
	float va = Math::Dot(n, Math::Cross(pointB - point, pointC - point));

	if ((va <= 0.0f) && (uNom >= 0.0f) && (uDenom >= 0.0f))
	{
		return pointB + uNom / (uNom + uDenom) * bc;
	}


	// If outside or on CA
	float vb = Math::Dot(n, Math::Cross(pointC - point, pointA - point));

	if ((vb <= 0.0f) && (tNom >= 0.0f) && (tDenom >= 0.0f))
	{
		return pointA + tNom / (tNom + tDenom) * bc;
	}

	// Inside the triangle, use barycentric coordinates
	float u = va / (va + vb + vc);
	float v = vb / (va + vb + vc);
	float w = 1.0f - u - v;

	return u * pointA + v * pointB + w * pointC;
}

float Math::DistanceSquared(const AxisAlignedBoundingBox2D& box, const Vector2& point)
{
	return Math::DistanceSquaredOutsideOfBounds(point, box.GetMinBound(), box.GetMaxBound());
}

float Math::DistanceSquared(const AxisAlignedBoundingBox3D& box, const Vector3& point)
{
	return Math::DistanceSquaredOutsideOfBounds(point, box.GetMinBound(), box.GetMaxBound());
}

float Math::DistanceSquared(const Vector2& lineStart, const Vector2& lineEnd, const Vector2& point)
{
	Vector2 ab = lineEnd - lineStart;
	Vector2 ac = point - lineStart;
	Vector2 bc = point - lineEnd;

	float e = Math::Dot(ac, ab);

	// If e is less than 0 then we know it's away from the line, 
	// so we just return the distance squared between the the line start and the point
	if (e <= 0.0f)
	{
		return Math::Dot(ac, ac);
	}

	float f = Math::Dot(ab, ab);

	if (e >= f)
	{
		return Math::Dot(bc, bc);
	}

	// Cases where point projects onto the line
	return Math::Dot(ac, ac) - e * e / f;
}

float Math::DistanceSquared(const Vector3& lineStart, const Vector3& lineEnd, const Vector3& point)
{
	Vector3 ab = lineEnd - lineStart;
	Vector3 ac = point - lineStart;
	Vector3 bc = point - lineEnd;

	float e = Math::Dot(ac, ab);
	
	// If e is less than 0 then we know it's away from the line, 
	// so we just return the distance squared between the the line start and the point
	if (e <= 0.0f)
	{
		return Math::Dot(ac, ac);
	}

	float f = Math::Dot(ab, ab);

	if (e >= f)
	{
		return Math::Dot(bc, bc);
	}

	// Cases where point projects onto the line
	return Math::Dot(ac, ac) - e * e / f;
}

float Math::DistanceSquared(const Line2D& line, const Vector2& point)
{
	return Math::DistanceSquared(line.GetStart(), line.GetEnd(), point);
}

float Math::DistanceSquared(const Line3D& line, const Vector3& point)
{
	return Math::DistanceSquared(line.GetStart(), line.GetEnd(), point);
}

Vector2 Math::GetClosestPointOnLineToPoint(const Vector2& lineStart, const Vector2& lineEnd, const Vector2& point)
{
	// Not as optimal but useful for reference!
	Vector2 lineDirection = lineEnd - lineStart;
	Vector2 lineDirectionNormalized = Normalize(lineDirection);

	Vector2 pointToLineStart = point - lineStart;

	// First get the dot product between pointToLineStart and the line 
	// to see if they're facing the same direction
	float dotResult = Math::Dot(pointToLineStart, lineDirectionNormalized);
	if (dotResult < 0.0f)
	{
		// They aren't not going in the same direction so the closest point should be the start 
		return lineStart;
	}

	// Next project pointToLineStart onto the line
	Vector2 projectedPointOnLine = dotResult * lineDirectionNormalized;

	// Now get a t value, could probably use magnitude squared here
	float t = projectedPointOnLine.Magnitude() / lineDirection.Magnitude();

	// If t is greater than one then we know the line end must be closest
	if (t > 1.0f)
	{
		return lineEnd;
	}

	// Otherwise calculate the closest point
	return lineStart + lineDirectionNormalized * t;
}

Vector3 Math::GetClosestPointOnLineToPoint(const Vector3& lineStart, const Vector3& lineEnd, const Vector3& point)
{
	// Not as optimal but useful for reference!
	Vector3 lineDirection = lineEnd - lineStart;
	Vector3 lineDirectionNormalized = Normalize(lineDirection);

	Vector3 pointToLineStart = point - lineStart;

	// First get the dot product between pointToLineStart and the line 
	// to see if they're facing the same direction
	float dotResult = Math::Dot(pointToLineStart, lineDirectionNormalized);
	if (dotResult < 0.0f)
	{
		// They aren't not going in the same direction so the closest point should be the start 
		return lineStart;
	}

	// Next project pointToLineStart onto the line
	Vector3 projectedPointOnLine = dotResult * lineDirectionNormalized;

	// Now get a t value, could probably use magnitude squared here
	float t = projectedPointOnLine.Magnitude() / lineDirection.Magnitude();

	// If t is greater than one then we know the line end must be closest
	if (t > 1.0f)
	{
		return lineEnd;
	}

	// Otherwise calculate the closest point
	return lineStart + lineDirectionNormalized * t;
}

Vector2 Math::GetClosestPointOnLineToPoint(const Line2D& line, const Vector2& point)
{
	return Math::GetClosestPointOnLineToPoint(line.GetStart(), line.GetEnd(), point);
}

Vector3 Math::GetClosestPointOnLineToPoint(const Line3D& line, const Vector3& point)
{
	return Math::GetClosestPointOnLineToPoint(line.GetStart(), line.GetEnd(), point);
}
