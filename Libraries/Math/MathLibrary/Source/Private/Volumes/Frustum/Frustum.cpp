#include "Volumes/Frustum/Frustum.h"

#include "Matrix/Matrix4x4.h"

using namespace Math;

Frustum::Frustum()
	: m_rightSlope(1.0f)
	, m_leftSlope(-1.0f)
	, m_topSlope(1.0f)
	, m_bottomSlope(-1.0f)
	, m_near(0.0f)
	, m_far(1.0f)
{
}

Frustum::Frustum(
	const Vector3& origin,
	const Quaternion& orientation,
	float rightSlope,
	float leftSlope,
	float topSlope,
	float bottomSlope,
	float near,
	float far)
	: m_origin(origin)
	, m_orientation(orientation)
	, m_rightSlope(rightSlope)
	, m_leftSlope(leftSlope)
	, m_topSlope(topSlope)
	, m_bottomSlope(bottomSlope)
	, m_near(near)
	, m_far(far)
{
}

Frustum::Frustum(const Math::Matrix4x4& projection)
{
	//// Corners of the projection frustum in homogenous space.
	//static XMVECTORF32 HomogenousPoints[6] =
	//{
	//	{ { {  1.0f,  0.0f, 1.0f, 1.0f } } },   // right (at far plane)
	//	{ { { -1.0f,  0.0f, 1.0f, 1.0f } } },   // left
	//	{ { {  0.0f,  1.0f, 1.0f, 1.0f } } },   // top
	//	{ { {  0.0f, -1.0f, 1.0f, 1.0f } } },   // bottom

	//	{ { { 0.0f, 0.0f, 0.0f, 1.0f } } },     // near
	//	{ { { 0.0f, 0.0f, 1.0f, 1.0f } } }      // far
	//};

	static Math::Vector4 s_homogenousPoints[6] =
	{
		Math::Vector4(1.0f, 0.0f, 1.0f, 1.0f), // right
		Math::Vector4(-1.0f, 0.0f, 1.0f, 1.0f), // left
		Math::Vector4(0.0f, 1.0f, 1.0f, 1.0f), // top
		Math::Vector4(0.0f, -1.0f, 1.0f, 1.0f), // bottom

		Math::Vector4(0.0f, 0.0f, 0.0f, 1.0f), // near
		Math::Vector4(0.0f, 0.0f, 1.0f, 1.0f), // far
	};


	float determinant = projection.Determinant();
	Math::Matrix4x4 inverseProjection = projection.Inverse();

	//XMVECTOR Determinant;
	//XMMATRIX matInverse = XMMatrixInverse(&Determinant, Projection);

	//// Compute the frustum corners in world space.
	//XMVECTOR Points[6];
	Math::Vector4 points[6];

	for (unsigned int i = 0; i < 6; ++i)
	{
		points[i] = s_homogenousPoints[i];

		//	// Transform point.
		//	Points[i] = XMVector4Transform(HomogenousPoints[i], matInverse);
		points[i].ApplyTransformation(inverseProjection);
	}

	m_origin = Math::Vector3::Zero();
	m_orientation = Math::Quaternion(0.0f, 0.0f, 0.0f, 1.0f);

	//Out.Origin = XMFLOAT3(0.0f, 0.0f, 0.0f);
	//Out.Orientation = XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);



	// Compute the slopes.
	//Points[0] = XMVectorMultiply(Points[0], XMVectorReciprocal(XMVectorSplatZ(Points[0])));
	//Points[1] = XMVectorMultiply(Points[1], XMVectorReciprocal(XMVectorSplatZ(Points[1])));
	//Points[2] = XMVectorMultiply(Points[2], XMVectorReciprocal(XMVectorSplatZ(Points[2])));
	//Points[3] = XMVectorMultiply(Points[3], XMVectorReciprocal(XMVectorSplatZ(Points[3])));

	points[0] *= (1.0f / points[0].z);
	points[1] *= (1.0f / points[1].z);
	points[2] *= (1.0f / points[2].z);
	points[3] *= (1.0f / points[3].z);

	//Out.RightSlope = XMVectorGetX(Points[0]);
	//Out.LeftSlope = XMVectorGetX(Points[1]);
	//Out.TopSlope = XMVectorGetY(Points[2]);
	//Out.BottomSlope = XMVectorGetY(Points[3]);

	m_rightSlope = points[0].x;
	m_leftSlope = points[1].x;
	m_topSlope = points[2].y;
	m_bottomSlope = points[3].y;

	//// Compute near and far.
	//Points[4] = XMVectorMultiply(Points[4], XMVectorReciprocal(XMVectorSplatW(Points[4])));
	//Points[5] = XMVectorMultiply(Points[5], XMVectorReciprocal(XMVectorSplatW(Points[5])));

	points[4] *= (1.0f / points[4].w);
	points[5] *= (1.0f / points[5].w);

	//Out.Near = XMVectorGetZ(Points[4]);
	//Out.Far = XMVectorGetZ(Points[5]);

	m_near = points[4].z;
	m_far = points[5].z;
}

Frustum::~Frustum()
{
}
