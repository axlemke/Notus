#pragma once

namespace Math
{
	namespace Curves
	{
		template<typename DataType>
		DataType GetCubicHermitePoint(
			const DataType& start,
			const DataType& slopeStart,
			const DataType& end,
			const DataType& slopeEnd,
			float t)
		{
			return start * ((1.0f + 2.0f * t) * ((1.0f - t) * (1.0f - t)))
				+ slopeStart * (t * ((1.0f - t) * (1.0f - t)))
				+ end * ((t * t) * (3.0f - 2.0f * t))
				+ slopeEnd * ((t * t) * (t - 1.0f));
		}
	}
}
