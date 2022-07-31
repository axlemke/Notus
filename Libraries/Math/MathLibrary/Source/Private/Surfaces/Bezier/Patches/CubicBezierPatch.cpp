#include "Surfaces/Bezier/Patches/CubicBezierPatch.h"

#include "Lines/Curves/Bezier/Cubic/CubicBezierUtils.h"
#include <Memory/MemoryLibrary/Source/Public/MemoryCommon.h>
#include <Framework/LibraryShell/Source/Public/CustomAssert.h>

using namespace Math;

CubicBezierPatch::CubicBezierPatch()
	: m_points(nullptr)
	, m_width(0)
	, m_height(0)
{
}

CubicBezierPatch::CubicBezierPatch(unsigned long width, unsigned long height)
{
	ReserveDimensions(width, height);
}

CubicBezierPatch::~CubicBezierPatch()
{
	Clear();
}

void CubicBezierPatch::ReserveDimensions(unsigned long width, unsigned long height)
{
	HB_ASSERT(width > 0);
	HB_ASSERT(height > 0);

	m_width = width;
	m_height = height;

	unsigned long totalCount = width * height;
	HB_ASSERT(m_points == nullptr);
	m_points = HaveBlueNewArray(Vector3, totalCount, "CubicBezierPatch");
}

void CubicBezierPatch::Clear()
{
	m_width = 0;
	m_height = 0;

	if (m_points)
	{
		HaveBlueDeleteArray(m_points);
		m_points = nullptr;
	}
}

Vector3& CubicBezierPatch::GetPoint(unsigned long index)
{
	HB_ASSERT(index < (m_width * m_height));
	HB_ASSERT(m_points);

	return m_points[index];
}

const Vector3& CubicBezierPatch::GetPoint(unsigned long index) const
{
	HB_ASSERT(index < (m_width * m_height));
	HB_ASSERT(m_points);

	return m_points[index];
}

Vector3& CubicBezierPatch::GetPoint(unsigned long x, unsigned long y)
{
	HB_ASSERT(x < m_width);
	HB_ASSERT(y < m_height);

	return GetPoint(y * m_width + x);
}
const Vector3& CubicBezierPatch::GetPoint(unsigned long x, unsigned long y) const
{
	HB_ASSERT(x < m_width);
	HB_ASSERT(y < m_height);

	return GetPoint(y * m_width + x);
}

void CubicBezierPatch::SetPoint(unsigned long index, const Vector3& point)
{
	HB_ASSERT(index < (m_width* m_height));
	HB_ASSERT(m_points);

	m_points[index] = point;
}

void CubicBezierPatch::SetPoint(unsigned long x, unsigned long y, const Vector3& point)
{
	HB_ASSERT(x < m_width);
	HB_ASSERT(y < m_height);

	SetPoint(y * m_width + x, point);
}

unsigned long CubicBezierPatch::GetWidth() const
{
	return m_width;
}

unsigned long CubicBezierPatch::GetHeight() const
{
	return m_height;
}
