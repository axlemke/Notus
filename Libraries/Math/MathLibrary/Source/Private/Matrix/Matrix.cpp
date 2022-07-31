#include "Matrix/Matrix.h"

#include <Framework/LibraryShell/Source/Public/CustomAssert.h>
#include <Memory/MemoryLibrary/Source/Public/MemoryCommon.h>

using namespace Math;

Matrix::Matrix()
	: m_rowCount(0)
	, m_columnCount(0)
	, m_data(nullptr)
{
}

Matrix::Matrix(unsigned numberOfRows, unsigned numberOfColumns)
	: m_rowCount(numberOfRows)
	, m_columnCount(numberOfColumns)
	, m_data(nullptr)
{
	Setup(numberOfRows, numberOfColumns);

	ZeroOut();
}

Matrix::Matrix(const Matrix& rhs)
{
	Setup(rhs.m_rowCount, rhs.m_columnCount);

	for (unsigned i = 0; i < GetTotalElementCount(); ++i)
	{
		m_data[i] = rhs.GetElement(i);
	}
}

Matrix::~Matrix()
{
	Clear();
}

unsigned Matrix::GetRowCount() const
{
	return m_rowCount;
}

unsigned Matrix::GetColumnCount() const
{
	return m_columnCount;
}

unsigned Matrix::GetTotalElementCount() const
{
	return (m_rowCount * m_columnCount);
}

float Matrix::GetElement(unsigned index) const
{
	HB_ASSERT(index < GetTotalElementCount());

	return m_data[index];
}

float Matrix::GetElement(unsigned row, unsigned column) const
{
	unsigned index = GetElementIndex(row, column);
	return GetElement(index);
}

void Matrix::SetElement(unsigned row, unsigned column, float value)
{
	unsigned index = GetElementIndex(row, column);
	HB_ASSERT(index < GetTotalElementCount());

	m_data[index] = value;
}

bool Matrix::CanMultiply(const Matrix& rhs) const
{
	return (GetColumnCount() == rhs.GetRowCount());
}

Matrix Matrix::Multiply(const Matrix& rhs) const
{
	HB_ASSERT(CanMultiply(rhs));

	Matrix result(GetRowCount(), rhs.GetColumnCount());

	for (unsigned int row = 0; row < GetRowCount(); ++row)
	{
		for (unsigned int column = 0; column < rhs.GetColumnCount(); ++column)
		{
			float value = 0.0f;

			for (unsigned int i = 0; i < GetColumnCount(); ++i)
			{
				value += GetElement(row, i) * rhs.GetElement(i, column);
			}

			result.SetElement(row, column, value);
		}
	}
	return result;	
}

unsigned Matrix::GetElementIndex(unsigned row, unsigned column) const
{
	HB_ASSERT(row < GetRowCount());
	HB_ASSERT(column < GetColumnCount());

	return column * GetRowCount() + row;
}

void Matrix::Setup(unsigned numberOfRows, unsigned numberOfColumns)
{
	Clear();

	m_rowCount = numberOfRows;
	m_columnCount = numberOfColumns;
	HB_ASSERT(GetTotalElementCount() > 0);

	m_data = HaveBlueNewArray(float, GetTotalElementCount(), "Matrix");
	
	ZeroOut();
}

void Matrix::Clear()
{
	if (m_data)
	{
		HaveBlueDeleteArray(m_data);
		m_data = nullptr;
	}

	m_rowCount = 0;
	m_columnCount = 0;
}

Matrix& Matrix::operator=(const Matrix& rhs)
{
	Setup(rhs.m_rowCount, rhs.m_columnCount);

	for (unsigned int i = 0; i < GetTotalElementCount(); ++i)
	{
		m_data[i] = rhs.GetElement(i);
	}

	return (*this);
}

void Matrix::ZeroOut()
{
	for (unsigned int i = 0; i < GetTotalElementCount(); ++i)
	{
		m_data[i] = 0.0f;
	}
}
