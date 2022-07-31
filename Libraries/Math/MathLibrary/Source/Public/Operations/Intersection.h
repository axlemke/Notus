#pragma once

#include "MathCommon.h"

namespace Math
{
	class AxisAlignedBoundingBox2D;
	class AxisAlignedBoundingBox3D;
	class Capsule2D;
	class Capsule3D;
	class OrientedBoundingBox3D;
	class Line2D;
	class Line3D;
	class Plane;
	class Range;
	class Ray2D;
	class Ray3D;
	class Sphere2D;
	class Sphere3D;
	class Triangle2D;
	class Triangle3D;
	class Vector2;
	class Vector3;
	class Vector4;

	MATH_USAGE bool Intersects(const Plane& planeA, const Plane& planeB);
	MATH_USAGE bool Intersects(const Plane& planeA, const Plane& planeB, Ray3D& intersectionRay);
	MATH_USAGE bool Intersects(const Plane& planeA, const Plane& planeB, const Plane& planeC);

	MATH_USAGE bool Intersects(const Plane& plane, const Vector3& point);
	MATH_USAGE bool Intersects(const Plane& plane, const Ray3D& ray);
	MATH_USAGE bool Intersects(const Plane& plane, const Ray3D& ray, float& t);

	MATH_USAGE bool IsPointInsidePlane(const Plane& plane, const Vector3& point);

	MATH_USAGE bool Intersects(const Plane& plane, const Sphere3D& sphere);
	MATH_USAGE bool IsSphereFullyInsidePlane(const Plane& plane, const Sphere3D& sphere);
	MATH_USAGE bool DoesSphereIntersectsNegativeHalfspace(const Plane& plane, const Sphere3D& sphere);

	MATH_USAGE bool Intersects(const Sphere2D& sphereA, const Sphere2D& sphereB);
	MATH_USAGE bool Intersects(const Sphere3D& sphereA, const Sphere3D& sphereB);

	MATH_USAGE bool Intersects(
		const Sphere3D& sphereA,
		const Sphere3D& sphereB,
		const Math::Vector3& velocitySphereA,
		const Math::Vector3& velocitySphereB,
		float& t);

	MATH_USAGE bool Intersects(
		const Sphere3D& sphereA, 
		const Sphere3D& sphereB,
		const Math::Vector3& velocitySphereA,
		const Math::Vector3& velocitySphereB,
		float deltaTime,
		Math::Vector3& pointOfImpactOnSphereA,
		Math::Vector3& pointOfImpactOnSphereB,
		float& timeOfImpact);

	MATH_USAGE bool Intersects(const Sphere2D& sphere, const Vector2& point);
	MATH_USAGE bool Intersects(const Sphere3D& sphere, const Vector3& point);

	MATH_USAGE bool Intersects(const Sphere2D& sphere, const Ray2D& ray);
	MATH_USAGE bool Intersects(const Sphere3D& sphere, const Ray3D& ray);
	MATH_USAGE bool Intersects(const Sphere2D& sphere, const Ray2D& ray, float& t);
	MATH_USAGE bool Intersects(const Sphere3D& sphere, const Ray3D& ray, float& t);
	MATH_USAGE bool Intersects(const Sphere3D& sphere, const Ray3D& ray, float& t0, float& t1);

	MATH_USAGE bool GetIntersectionPosition(const Sphere2D& sphere, const Ray2D& ray, Vector2& intersectionPosition);
	MATH_USAGE bool GetIntersectionPosition(const Sphere3D& sphere, const Ray3D& ray, Vector3& intersectionPosition);

	MATH_USAGE bool Intersects(const Triangle2D& triangle, const Vector2& point);
	MATH_USAGE bool Intersects(const Triangle3D& triangle, const Vector3& point);

	MATH_USAGE bool Intersects(const AxisAlignedBoundingBox2D& boxA, const AxisAlignedBoundingBox2D& boxB);
	MATH_USAGE bool Intersects(const AxisAlignedBoundingBox2D& box, const Vector2& point);

	MATH_USAGE bool Intersects(const AxisAlignedBoundingBox3D& boxA, const AxisAlignedBoundingBox3D& boxB);
	MATH_USAGE bool Intersects(const AxisAlignedBoundingBox3D& box, const Vector3& point);

	MATH_USAGE bool Intersects(const AxisAlignedBoundingBox3D& box, const Sphere3D& sphere);

	MATH_USAGE bool Intersects(const Capsule2D& capsule, const Sphere2D& sphere);
	MATH_USAGE bool Intersects(const Capsule3D& capsule, const Sphere3D& sphere);

	MATH_USAGE bool Intersects(const Capsule2D& capsule, const Line2D& line);
	MATH_USAGE bool Intersects(const Capsule3D& capsule, const Line3D& line);

	MATH_USAGE bool Intersects(const Capsule2D& capsuleA, const Capsule2D& capsuleB);
	MATH_USAGE bool Intersects(const Capsule3D& capsuleA, const Capsule3D& capsuleB);

	MATH_USAGE bool Intersects(const OrientedBoundingBox3D& boxA, const OrientedBoundingBox3D& boxB);

	MATH_USAGE bool Intersects(const Range& rangeA, const Range& rangeB);
};
