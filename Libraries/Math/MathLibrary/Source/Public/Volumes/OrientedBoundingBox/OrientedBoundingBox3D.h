#pragma once

#include "MathCommon.h"
#include "Vector/Vector3.h"

namespace Math
{
	class OrientedBoundingBox3D
	{
	public:
		MATH_USAGE OrientedBoundingBox3D();

		MATH_USAGE const Vector3& GetCenter() const;

		Vector3 m_center;
		Vector3 m_localXAxis;
		Vector3 m_localYAxis;
		Vector3 m_localZAxis;
		Vector3 m_halfWithExtents;
	};
	using OOB3D = OrientedBoundingBox3D;
};

static_assert((sizeof(float) * 15) == sizeof(Math::OrientedBoundingBox3D));
