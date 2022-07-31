#pragma once

#include "MathCommon.h"
#include <string>

namespace Math
{
	class Matrix
	{
	public:
		MATH_USAGE Matrix();
		MATH_USAGE Matrix(unsigned numberOfRows, unsigned numberOfColumns);
		MATH_USAGE Matrix(const Matrix& rhs);
		MATH_USAGE ~Matrix();

		MATH_USAGE unsigned GetRowCount() const;
		MATH_USAGE unsigned GetColumnCount() const;
		MATH_USAGE unsigned GetTotalElementCount() const;

		MATH_USAGE float GetElement(unsigned index) const;
		MATH_USAGE float GetElement(unsigned row, unsigned column) const;
		MATH_USAGE void SetElement(unsigned row, unsigned column, float value);

		MATH_USAGE bool CanMultiply(const Matrix& rhs) const;
		MATH_USAGE Matrix Multiply(const Matrix& rhs) const;

		MATH_USAGE void Setup(unsigned numberOfRows, unsigned numberOfColumns);
		MATH_USAGE void Clear();

		MATH_USAGE Matrix& operator=(const Matrix& rhs);

	private:
		unsigned GetElementIndex(unsigned row, unsigned column) const;
		void ZeroOut();

		unsigned m_rowCount;
		unsigned m_columnCount;
		float* m_data;
	};
}
