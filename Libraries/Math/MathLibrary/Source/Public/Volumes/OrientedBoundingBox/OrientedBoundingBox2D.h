#pragma once

#include "MathCommon.h"
#include "Vector/Vector2.h"

namespace Math
{
	class OrientedBoundingBox2D
	{
	public:
		MATH_USAGE OrientedBoundingBox2D();

		MATH_USAGE const Vector2& GetCenter() const;

		Vector2 m_center;
		Vector2 m_localXAxis;
		Vector2 m_localYAxis;
		Vector2 m_halfWithExtents;
	};
	using OOB2D = OrientedBoundingBox2D;
};

static_assert((sizeof(float) * 8) == sizeof(Math::OrientedBoundingBox2D));
