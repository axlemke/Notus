#include "Volumes/OrientedBoundingBox/OrientedBoundingBox3D.h"

using namespace Math;

OrientedBoundingBox3D::OrientedBoundingBox3D()
{
}

const Vector3& OrientedBoundingBox3D::GetCenter() const
{
	return m_center;
}
