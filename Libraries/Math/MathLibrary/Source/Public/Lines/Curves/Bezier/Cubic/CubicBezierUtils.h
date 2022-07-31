#pragma once

namespace Math
{
	namespace Curves
	{
		template<typename DataType>
		DataType GetCubicBezierPoint(
			const DataType& start, 
			const DataType& controlPoint0, 
			const DataType& controlPoint1, 
			const DataType& end, 
			float t)
		{
			float tSquared = t * t;
			float tCubed = tSquared * t;

			return start * (-tCubed + 3.0f * tSquared - 3.0f * t + 1.0f)
				+ controlPoint0 * (3.0f * tCubed - 6.0f * tSquared + 3.0f * t)
				+ controlPoint1 * (-3.0f * tCubed + 3.0f * tSquared)
				+ end * (tCubed);
		}

		template<typename DataType>
		DataType GetCubicBezierVelocity(
			const DataType& start,
			const DataType& controlPoint0,
			const DataType& controlPoint1,
			const DataType& end,
			float t)
		{
			float tSquared = t * t;

			return start * (-3.0f * tSquared + 6.0f * t - 3.0f)
				+ controlPoint0 * (9.0f * tSquared - 12.0f * t + 3.0f)
				+ controlPoint1 * (-9.0f * tSquared + 6.0f * t)
				+ end * (3.0f * tSquared);
		}
	}
}
