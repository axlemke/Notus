#pragma once

#include "Operations/Interpolation.h"

namespace Math
{
	namespace Curves
	{
		template<typename DataType>
		DataType GetQuadraticBezierPointDeCastelaju(
			const DataType& start,
			const DataType& controlPoint,
			const DataType& end,
			float t)
		{
			DataType p0 = Lerp(start, controlPoint, t);
			DataType p1 = Lerp(controlPoint, end, t);
			return Lerp(p0, p1, t);
		}
	}
}
