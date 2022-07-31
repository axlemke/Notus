#include "Range/Range.h"

#include "Operations/MinMax.h"

using namespace Math;

Range::Range()
	: m_min(0.0f)
	, m_max(0.0f)
{
}

Range::Range(float min, float max)
	: m_min(Math::Min(min, max))
	, m_max(Math::Max(min, max))
{
}

float Range::GetMin() const
{
	return m_min;
}

float Range::GetMax() const
{
	return m_max;
}

float Range::GetRange() const
{
	return (m_max - m_min);
}

bool Range::IsWithinRange(float value) const
{
	return ((value >= m_min) && (value <= m_max));
}

bool Math::operator<(const Range& a, const Range& b)
{
	return a.GetMin() < b.GetMin();
}
