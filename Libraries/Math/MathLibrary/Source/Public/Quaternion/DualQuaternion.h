#pragma once

#include "MathCommon.h"
#include "Quaternion/Quaternion.h"

namespace Math
{
	//Forward Declarations
	class Matrix3x3;
	class Matrix4x4;
	class Vector4;
	class Vector3;

	class DualQuaternion
	{
	public:
		MATH_USAGE DualQuaternion();
		MATH_USAGE DualQuaternion(const Quaternion& real, const Quaternion& dual);
		MATH_USAGE ~DualQuaternion();
		
		MATH_USAGE void Normalize();

		MATH_USAGE DualQuaternion& operator=(const DualQuaternion& rhs);

		MATH_USAGE DualQuaternion& operator*=(float rhs);
		MATH_USAGE DualQuaternion& operator+=(const DualQuaternion& rhs);
		MATH_USAGE DualQuaternion& operator-=(const DualQuaternion& rhs);
		MATH_USAGE DualQuaternion& operator*=(const DualQuaternion& rhs);

		MATH_USAGE bool operator==(const DualQuaternion& rhs) const;
		MATH_USAGE bool operator!=(const DualQuaternion& rhs) const;


		union
		{
			struct
			{
				Quaternion m_real;
				Quaternion m_dual;
			};

			float m_data[8];
		};
	};

	MATH_USAGE DualQuaternion Normalize(const DualQuaternion& q);
}

static_assert((sizeof(float) * 8) == sizeof(Math::DualQuaternion));