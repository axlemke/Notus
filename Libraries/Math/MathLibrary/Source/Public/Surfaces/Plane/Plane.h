#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"

namespace Math
{
	class Triangle3D;

	class Plane
	{
	public:
		MATH_USAGE Plane();
		MATH_USAGE Plane(const Vector3& normal, float distanceFromOrigin);
		MATH_USAGE Plane(const Vector4& plane);
		MATH_USAGE Plane(float a, float b, float c, float distanceFromOrigin);
		MATH_USAGE Plane(const Vector3& pointA, const Vector3& pointB, const Vector3& pointC);
		MATH_USAGE Plane(const Triangle3D& triangle);

		MATH_USAGE const Vector3& GetNormal() const;
		MATH_USAGE float GetDistanceFromOrigin() const;
		MATH_USAGE float D() const;
		MATH_USAGE float DistanceToPoint(const Vector3& point) const;
		
		MATH_USAGE Vector3 ClosestPointOnPlaneToPoint(const Vector3& point) const;

		MATH_USAGE bool Intersects(const Plane& plane) const;
		MATH_USAGE bool Intersects(const Vector3& point) const;

		union
		{
			Vector4 m_planeEquation;

			struct
			{
				union
				{
					Vector3 m_normal;

					struct
					{
						float a;
						float b;
						float c;
					};
				};
				float m_d;
			};
		};
	};

	MATH_USAGE Plane CreatePlane(const Vector3& pointA, const Vector3& pointB, const Vector3& pointC);
	MATH_USAGE Plane CreatePlane(const Triangle3D& triangle);
};

static_assert((sizeof(float) * 4) == sizeof(Math::Plane));