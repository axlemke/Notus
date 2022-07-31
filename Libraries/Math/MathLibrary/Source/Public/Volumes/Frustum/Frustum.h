#pragma once

#include "Libraries/Math/MathLibrary/Source/Public/MathCommon.h"
#include "Libraries/Math/MathLibrary/Source/Public/Quaternion/Quaternion.h"
#include "Libraries/Math/MathLibrary/Source/Public/Vector/Vector3.h"

namespace Math
{
	class Matrix4x4;

	class Frustum
	{
	public:
		MATH_USAGE Frustum();

		MATH_USAGE Frustum(
			const Vector3& origin,
			const Quaternion& orientation,
			float rightSlope,
			float leftSlope,
			float topSlope,
			float bottomSlope,
			float near,
			float far);

		MATH_USAGE Frustum(const Math::Matrix4x4& projection);

		MATH_USAGE ~Frustum();

		Vector3 m_origin;
		Quaternion m_orientation;

		float m_rightSlope;
		float m_leftSlope;

		float m_topSlope;
		float m_bottomSlope;

		float m_near;
		float m_far;
	};
};
