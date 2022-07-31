#include "Volumes/OrientedBoundingBox/OrientedBoundingBox2D.h"

using namespace Math;

OrientedBoundingBox2D::OrientedBoundingBox2D()
{
}

const Vector2& OrientedBoundingBox2D::GetCenter() const
{
	return m_center;
}

