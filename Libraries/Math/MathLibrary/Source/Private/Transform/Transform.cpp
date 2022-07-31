#include "Transform/Transform.h"

#include <Framework/LibraryShell/Source/Public/CustomAssert.h>
#include "Matrix/Matrix4x4.h"
#include "Operations/Interpolation.h"

using namespace Math;

Transform::Transform()
	: m_scale(1.0f)
	, m_rotation(0.0f, 0.0f, 0.0f, 1.0f)
{
}

Transform::Transform(const Vector3& translation, const Quaternion& rotation, const Vector3& scale)
	: m_translation(translation)
	, m_rotation(rotation)
	, m_scale(scale)
{
}

const Vector3& Transform::GetScale() const
{
	return m_scale;
}

Vector3& Transform::GetScale()
{
	return m_scale;
}

void Transform::SetScale(const Vector3& scale)
{
	m_scale = scale;
}

void Transform::SetScale(float uniformScale)
{
	m_scale.SetXYZ(uniformScale, uniformScale, uniformScale);
}

const Quaternion& Transform::GetRotation() const
{
	return m_rotation;
}

Quaternion& Transform::GetRotation()
{
	return m_rotation;
}

void Transform::SetRotation(const Quaternion& rotation)
{
	m_rotation = rotation;
}

void Transform::SetRotation(const Matrix4x4& matrix)
{
	m_rotation.SetRotationMatrix(matrix);
}

const Vector3& Transform::GetTranslation() const
{
	return m_translation;
}

Vector3& Transform::GetTranslation()
{
	return m_translation;
}

void Transform::SetTranslation(const Vector3& translation)
{
	m_translation = translation;
}

void Transform::SetTranslation(float x, float y, float z)
{
	m_translation.x = x;
	m_translation.y = y;
	m_translation.z = z;
}

Matrix4x4 Transform::GetTransformMatrix4x4() const
{
	//Matrix4x4 result = Matrix4x4::CreateScaling(m_scale);
	//
	////result *= Matrix4x4::CreateTranslation(m_translation);

	//result *= m_rotation.GetRotationMatrix4x4();

	//result *= Matrix4x4::CreateTranslation(m_translation);


	//Matrix4x4 result = Matrix4x4::CreateScaling(m_scale);

	//result *= Matrix4x4::CreateTranslation(m_translation);

	//result *= m_rotation.GetRotationMatrix4x4();

	//Matrix4x4 result = Matrix4x4::CreateTranslation(m_translation);

	//result *= m_rotation.GetRotationMatrix4x4();

	//result *= Matrix4x4::CreateScaling(m_scale);




	Matrix4x4 result = Matrix4x4::CreateScaling(m_scale);

	result *= m_rotation.GetRotationMatrix4x4();

	result *= Matrix4x4::CreateTranslation(m_translation);

	return result;
}

Transform Math::Lerp(const Transform& a, const Transform& b, float t)
{
	Quaternion bRotation = b.GetRotation();

	if (Dot(a.GetRotation(), bRotation) < 0.0f)
	{
		bRotation = -bRotation;
	}

	return Transform(
		Lerp(a.GetTranslation(), b.GetTranslation(), t),
		Lerp(a.GetRotation(), b.GetRotation(), t),
		Lerp(a.GetScale(), b.GetScale(), t));
}

Transform Math::Combine(const Transform& a, const Transform& b)
{
	Transform combined;

	combined.m_scale = a.GetScale() * b.GetScale();
	combined.m_rotation = a.GetRotation() * b.GetRotation();

	combined.m_translation = a.GetRotation() * (a.GetScale() * b.GetTranslation());
	combined.m_translation = a.GetTranslation() + combined.GetTranslation();

	return combined;
}

Transform Math::Inverse(const Transform& transform)
{
	Transform inverse;

	inverse.m_rotation = Inverse(transform.GetRotation());

	HB_ASSERT(transform.m_scale.x != 0.0f);
	inverse.m_scale.x = 1.0f / transform.m_scale.x;
	HB_ASSERT(transform.m_scale.y != 0.0f);
	inverse.m_scale.y = 1.0f / transform.m_scale.y;
	HB_ASSERT(transform.m_scale.z != 0.0f);
	inverse.m_scale.z = 1.0f / transform.m_scale.z;

	Vector3 inverseTranslation = transform.GetTranslation() * -1.0f;
	inverse.m_translation = inverse.GetRotation() * (inverse.GetScale() * inverseTranslation);

	return inverse;
}
