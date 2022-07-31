#include "Quaternion/DualQuaternion.h"
#include "Matrix/Matrix3x3.h"
#include "Matrix/Matrix4x4.h"
#include "Vector/Vector4.h"
#include "Vector/Vector3.h"
#include <sstream>

using namespace Math;

DualQuaternion::DualQuaternion()
	: m_real(0.0f, 0.0f, 0.0f, 1.0f)
	, m_dual(0.0f, 0.0f, 0.0f, 0.0f)
{
}

DualQuaternion::DualQuaternion(const Quaternion& real, const Quaternion& dual)
	: m_real(real)
	, m_dual(dual)
{
}

DualQuaternion::~DualQuaternion()
{
}

void DualQuaternion::Normalize()
{
	float magnitude = m_real.Magnitude();

	if (magnitude != 0.0f)
	{
		float inverseMagnitude = 1.0f / magnitude;
		m_real *= inverseMagnitude;
		m_dual *= inverseMagnitude;
	}
}

DualQuaternion& DualQuaternion::operator=(const DualQuaternion& rhs)
{
	m_real = rhs.m_real;
	m_dual = rhs.m_dual;

	return (*this);
}

DualQuaternion& DualQuaternion::operator*=(float rhs)
{
	m_real *= rhs;
	m_dual *= rhs;

	return (*this);
}

DualQuaternion& DualQuaternion::operator+=(const DualQuaternion& rhs)
{
	m_real += rhs.m_real;
	m_dual += rhs.m_dual;

	return (*this);
}

DualQuaternion& DualQuaternion::operator-=(const DualQuaternion& rhs)
{
	m_real -= rhs.m_real;
	m_dual -= rhs.m_dual;

	return (*this);
}

DualQuaternion& DualQuaternion::operator*=(const DualQuaternion& rhs)
{
	DualQuaternion result(m_real * rhs.m_real, m_real * rhs.m_dual + m_dual * rhs.m_real);

	(*this) = result;

	return (*this);
}

bool DualQuaternion::operator==(const DualQuaternion& rhs) const
{
	return ((m_real == rhs.m_real) && (m_dual == rhs.m_dual));
}

bool DualQuaternion::operator!=(const DualQuaternion& rhs) const
{
	return(!operator==(rhs));
}

DualQuaternion Math::Normalize(const DualQuaternion& q)
{
	DualQuaternion result = q;
	result.Normalize();

	return result;
}

float Math::Magnitude(const Vector3& v)
{
	return v.Magnitude();
}

float Math::MagnitudeSquared(const Vector3& v)
{
	return v.MagnitudeSquared();
}
