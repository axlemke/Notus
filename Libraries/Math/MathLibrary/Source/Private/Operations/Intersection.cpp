#include "Operations/Intersection.h"

#include "Lines/Line2D.h"
#include "Lines/Line3D.h"
#include "MathConstants.h"
#include "Operations/Barycentric.h"
#include "Operations/Distance.h"
#include "Operations/Quadratic.h"
#include "Range/Range.h"
#include "Ray/Ray2D.h"
#include "Ray/Ray3D.h"
#include "Surfaces/Plane/Plane.h"
#include "Surfaces/Triangles/Triangle2D.h"
#include "Surfaces/Triangles/Triangle3D.h"
#include "Vector/Vector2.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"
#include "Volumes/AxisAlignedBoundingBox/AxisAlignedBoundingBox2D.h"
#include "Volumes/AxisAlignedBoundingBox/AxisAlignedBoundingBox3D.h"
#include "Volumes/Capsule/Capsule2D.h"
#include "Volumes/Capsule/Capsule3D.h"
#include "Volumes/Sphere/Sphere2D.h"
#include "Volumes/Sphere/Sphere3D.h"

using namespace Math;

bool Math::Intersects(const Plane& planeA, const Plane& planeB)
{
	// if the dot of the two plane normals are 1 that means they're parallel
	return (abs(Dot(planeB.GetNormal(), planeA.GetNormal())) != 1.0f);
}

bool Math::Intersects(const Plane& planeA, const Plane& planeB, Ray3D& intersectionRay)
{
	// Compute direction of intersection line/ray
	intersectionRay.m_direction = Cross(planeA.GetNormal(), planeB.GetNormal());

	// If direction is zero then planes are parallel (and separated) or coincident, so they aren't considered intersecting  
	if (Math::Dot(intersectionRay.m_direction, intersectionRay.m_direction) < k_epsilon)
	{
		return false;
	}

	float d11 = Math::Dot(planeA.GetNormal(), planeA.GetNormal());
	float d12 = Math::Dot(planeA.GetNormal(), planeB.GetNormal());
	float d22 = Math::Dot(planeB.GetNormal(), planeB.GetNormal());

	float denom = d11 * d22 - d12 * d12;  
	float k1 = (planeA.GetDistanceFromOrigin() * d22 - planeB.GetDistanceFromOrigin() * d12) / denom;
	float k2 = (planeB.GetDistanceFromOrigin() * d11 - planeA.GetDistanceFromOrigin() * d12) / denom;

	intersectionRay.m_origin = k1 * planeA.GetNormal() + k2 * planeB.GetNormal();
	
	return true; 
}

bool Math::Intersects(const Plane& planeA, const Plane& planeB, const Plane& planeC)
{
	return false;
}

bool Math::Intersects(const Plane& plane, const Vector3& point)
{
	return (Math::Dot(point, plane.GetNormal()) == plane.GetDistanceFromOrigin());
}

bool Math::IsPointInsidePlane(const Plane& plane, const Vector3& point)
{
	float distance = Math::Distance(plane, point);
	return (distance < 0.0f);
}

bool Math::Intersects(const Plane& plane, const Sphere3D& sphere)
{
	return (abs(Math::Distance(plane, sphere.GetCenter())) <= sphere.GetRadius());
}

bool Math::IsSphereFullyInsidePlane(const Plane& plane, const Sphere3D& sphere)
{
	float distance = Math::Distance(plane, sphere.GetCenter());
	return (distance < -sphere.GetRadius());
}

bool Math::DoesSphereIntersectsNegativeHalfspace(const Plane& plane, const Sphere3D& sphere)
{
	float distance = Math::Distance(plane, sphere.GetCenter());
	return (distance <= sphere.GetRadius());
}

bool Math::Intersects(const Sphere2D& sphereA, const Sphere2D& sphereB)
{
	Vector2 difference = sphereA.GetCenter() - sphereB.GetCenter();
	float distanceSquared = difference.MagnitudeSquared();
	float radiiSum = (sphereA.GetRadius() + sphereB.GetRadius());
	return (distanceSquared <= (radiiSum * radiiSum));
}

bool Math::Intersects(const Sphere3D& sphereA, const Sphere3D& sphereB)
{
	Vector3 difference = sphereA.GetCenter() - sphereB.GetCenter();
	float distanceSquared = difference.MagnitudeSquared();
	float radiiSum = (sphereA.GetRadius() + sphereB.GetRadius());
	return (distanceSquared <= (radiiSum * radiiSum));
}

bool Math::Intersects(
	const Sphere3D& sphereA,
	const Sphere3D& sphereB,
	const Math::Vector3& velocitySphereA,
	const Math::Vector3& velocitySphereB,
	float& t)
{
	float combinedRadius = sphereA.GetRadius() + sphereB.GetRadius();
	Math::Vector3 realitiveVelocity = velocitySphereA - velocitySphereB;

	float velocityMagnitude = realitiveVelocity.Magnitude();

	Ray3D testRay(sphereA.GetCenter(), Normalize(realitiveVelocity));
	Sphere3D testSphere(sphereB.GetCenter(), combinedRadius);

	if (Intersects(testSphere, testRay, t))
	{
		return (t < velocityMagnitude);
	}
	return false;
}

bool Math::Intersects(
	const Sphere3D& sphereA,
	const Sphere3D& sphereB,
	const Math::Vector3& velocitySphereA,
	const Math::Vector3& velocitySphereB,
	float deltaTime,
	Math::Vector3& pointOfImpactOnSphereA,
	Math::Vector3& pointOfImpactOnSphereB,
	float& timeOfImpact)
{
	Math::Vector3 relativeVelocy = velocitySphereA - velocitySphereB;

	const Math::Vector3& startA = sphereA.GetCenter();
	Math::Vector3 endA = startA + relativeVelocy * deltaTime;
	Math::Vector3 rayDirection = endA - startA;

	float t0 = 0.0f;
	float t1 = 0.0f;

	const float k_esplion = 0.001f;
	const float k_esplionSquared = k_esplion * k_esplion;

	if (rayDirection.MagnitudeSquared() < k_esplionSquared)
	{
		Math::Vector3 ab = sphereB.GetCenter() - sphereA.GetCenter();
		float radius = sphereA.GetRadius() + sphereB.GetRadius() + k_esplion;

		if (ab.MagnitudeSquared() > (radius * radius))
		{
			return false;
		}

	}
	else
	{
		Ray3D ray3d(startA, rayDirection);
		Sphere3D combinedSphere(sphereB.GetCenter(), sphereA.GetRadius() + sphereB.GetRadius());
		if (Math::Intersects(combinedSphere, ray3d, t0) == false)
		{
			return false;
		}
	}

	t0 *= deltaTime;
	t1 *= deltaTime;

	timeOfImpact = t0;

	Math::Vector3 newPositionA = sphereA.GetCenter() + velocitySphereA + timeOfImpact;
	Math::Vector3 newPositionB = sphereB.GetCenter() + velocitySphereB + timeOfImpact;
	Math::Vector3 ab = newPositionB - newPositionA;
	ab.Normalize();

	pointOfImpactOnSphereA = newPositionA + ab * sphereA.GetRadius();
	pointOfImpactOnSphereB = newPositionB - ab * sphereB.GetRadius();

	return true;
}

bool Math::Intersects(const Sphere2D& sphere, const Vector2& point)
{
	Vector2 difference = sphere.GetCenter() - point;
	float distanceSquared = difference.MagnitudeSquared();
	float radius = sphere.GetRadius();
	return distanceSquared <= (radius * radius);
}

bool Math::Intersects(const Sphere3D& sphere, const Vector3& point)
{
	Vector3 difference = sphere.GetCenter() - point;
	float distanceSquared = difference.MagnitudeSquared();
	float radius = sphere.GetRadius();
	return distanceSquared <= (radius * radius);
}

bool Math::Intersects(const Plane& plane, const Ray3D& ray)
{
	float t = 0;
	return Intersects(plane, ray, t);
}

bool Math::Intersects(const Plane& plane, const Ray3D& ray, float& t)
{
	float rayDirectionDotPlaneNormal = Math::Dot(ray.m_direction, plane.GetNormal());

	if (rayDirectionDotPlaneNormal != 0.0f)
	{
		// We're basically getting the distance from the ray's origin to the plane with the following
		// Math::Dot(ray.m_origin, plane.m_normal) + plane.GetDistanceFromOrigin()
		//
		// We then scale that dot product between the plane's normal and the ray's direction to get the actual t value
		t = -(Math::Dot(ray.m_origin, plane.m_normal) + plane.GetDistanceFromOrigin()) / rayDirectionDotPlaneNormal;

		// If that t value is greater than 0 we know the intersection is the position direction of the ray
		return (t >= 0.0f);
	}
	return false;
}

bool Math::Intersects(const Sphere2D& sphere, const Ray2D& ray)
{
	float t = 0;
	return Intersects(sphere, ray, t);
}

bool Math::Intersects(const Sphere3D& sphere, const Ray3D& ray)
{
	float t = 0;
	return Intersects(sphere, ray, t);
}

bool Math::Intersects(const Sphere2D& sphere, const Ray2D& ray, float& t)
{
	Vector2 difference = ray.Origin() - sphere.GetCenter();
	float a = Math::Dot(ray.Direction(), ray.Direction());
	float b = 2.0f * Math::Dot(difference, ray.Direction());

	float radius = sphere.GetRadius();
	float c = Math::Dot(difference, difference) - (radius * radius);

	float discriminant = Math::GetDiscriminant(a, b, c);

	if (discriminant < 0.0f)
	{
		t = -1.0f;

		return false;
	}

	t = (-b - sqrtf(discriminant)) / (2.0 * a);

	return true;
}

bool Math::Intersects(const Sphere3D& sphere, const Ray3D& ray, float& t)
{
	Vector3 difference = ray.Origin() - sphere.GetCenter();
	float a = Math::Dot(ray.Direction(), ray.Direction());
	float b = 2.0f * Math::Dot(difference, ray.Direction());

	float radius = sphere.GetRadius();
	float c = Math::Dot(difference, difference) - (radius * radius);

	float discriminant = Math::GetDiscriminant(a, b, c);

	if (discriminant < 0.0f)
	{
		t = -1.0f;

		return false;
	}

	t = (-b - sqrtf(discriminant)) / (2.0 * a);

	return true;
}

bool Math::Intersects(const Sphere3D& sphere, const Ray3D& ray, float& t0, float& t1)
{
	return true;
}

bool Math::GetIntersectionPosition(const Sphere2D& sphere, const Ray2D& ray, Vector2& intersectionPosition)
{
	float t = 0;

	if (Intersects(sphere, ray, t))
	{
		intersectionPosition = ray.GetPositionAlongRay(t);

		return true;
	}
	return false;
}

bool Math::GetIntersectionPosition(const Sphere3D& sphere, const Ray3D& ray, Vector3& intersectionPosition)
{
	float t = 0;

	if (Intersects(sphere, ray, t))
	{
		intersectionPosition = ray.GetPositionAlongRay(t);

		return true;
	}
	return false;
}

bool Math::Intersects(const Triangle2D& triangle, const Vector2& point)
{
	Vector3 barycentric = Math::GetBarycentricCoords(triangle, point);
	return (barycentric.i >= 0.0f) && (barycentric.k >= 0.0f) && ((barycentric.i + barycentric.k) <= 1.0f);
}

bool Math::Intersects(const Triangle3D& triangle, const Vector3& point)
{
	Vector3 barycentric = Math::GetBarycentricCoords(triangle, point);
	return (barycentric.i >= 0.0f) && (barycentric.k >= 0.0f) && ((barycentric.i + barycentric.k) <= 1.0f);
}

bool Math::Intersects(const AxisAlignedBoundingBox2D& boxA, const AxisAlignedBoundingBox2D& boxB)
{
	return Math::DoBoundsOverlap(boxA.GetMinBound(), boxA.GetMaxBound(), boxB.GetMinBound(), boxB.GetMaxBound());
}

bool Math::Intersects(const AxisAlignedBoundingBox2D& box, const Vector2& point)
{
	return Math::IsWithinBounds(point, box.GetMinBound(), box.GetMaxBound());
}

bool Math::Intersects(const AxisAlignedBoundingBox3D& boxA, const AxisAlignedBoundingBox3D& boxB)
{
	return Math::DoBoundsOverlap(boxA.GetMinBound(), boxA.GetMaxBound(), boxB.GetMinBound(), boxB.GetMaxBound());
}

bool Math::Intersects(const AxisAlignedBoundingBox3D& box, const Vector3& point)
{
	return Math::IsWithinBounds(point, box.GetMinBound(), box.GetMaxBound());
}

bool Math::Intersects(const AxisAlignedBoundingBox3D& box, const Sphere3D& sphere)
{
	// Compute squared distance between sphere center and AABB
	float squaredDistance = Math::DistanceSquared(box, sphere.GetCenter());  
	
	// Sphere and AABB intersect if the (squared) distance between them is less than the (squared) sphere radius  
	return squaredDistance <= (sphere.GetRadius() * sphere.GetRadius());
}

bool Math::Intersects(const Capsule2D& capsule, const Sphere2D& sphere)
{
	Vector2 sphereCenter = sphere.GetCenter();
	Vector2 closestPointOnCapsule = Math::GetClosestPointOnLineToPoint(capsule.GetStart(), capsule.GetEnd(), sphereCenter);
	float distanceSquared = DistanceSquared(closestPointOnCapsule, sphereCenter);
	float combinedRadius = capsule.GetRadius() + sphere.GetRadius();

	return distanceSquared <= combinedRadius;
}

bool Math::Intersects(const Capsule3D& capsule, const Sphere3D& sphere)
{
	Vector3 closestPointOnCapsule = Math::GetClosestPointOnLineToPoint(capsule.GetStart(), capsule.GetEnd(), sphere.GetCenter());
	float distanceSquared = DistanceSquared(closestPointOnCapsule, sphere);
	float combinedRadius = capsule.GetRadius() + sphere.GetRadius();

	return distanceSquared <= combinedRadius;
}

// TODO:!

bool Math::Intersects(const Capsule2D& capsule, const Line2D& line)
{
	return false;
}

bool Math::Intersects(const Capsule3D& capsule, const Line3D& line)
{
	return false;
}

bool Math::Intersects(const Capsule2D& capsuleA, const Capsule2D& capsuleB)
{
	return false;
}

bool Math::Intersects(const Capsule3D& capsuleA, const Capsule3D& capsuleB)
{
	return false;
}

bool Math::Intersects(const OrientedBoundingBox3D& boxA, const OrientedBoundingBox3D& boxB)
{
	return false;
}

bool Math::Intersects(const Range& rangeA, const Range& rangeB)
{
	return DoBoundsOverlap(rangeA.GetMin(), rangeA.GetMax(), rangeB.GetMin(), rangeB.GetMax());
}
