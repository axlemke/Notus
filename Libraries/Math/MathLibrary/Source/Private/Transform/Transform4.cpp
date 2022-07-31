#include "Transform/Transform4.h"

using namespace Math;

Transform4::Transform4()
{
}

Transform4::Transform4(
	float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44)
{
	n[0][0] = m11;
	n[0][1] = m12;
	n[0][2] = m13;
	n[0][3] = m14;

	n[1][0] = m21;
	n[1][1] = m22;
	n[1][2] = m23;
	n[1][3] = m24;

	n[2][0] = m31;
	n[2][1] = m32;
	n[2][2] = m33;
	n[2][3] = m34;

	n[3][0] = m41;
	n[3][1] = m42;
	n[3][2] = m43;
	n[3][3] = m44;
}

Transform4::Transform4(
	float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34)
	: Matrix4x4(
		m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		0.0f, 0.0f, 0.0f, 1.0f)
{
}

const Vector3& Transform4::GetTranslation() const
{
	return row[3].m_xyz;
}

void Transform4::SetTranslation(const Vector3& translation)
{
	row[3].m_xyz = translation;
}