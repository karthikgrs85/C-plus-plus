#include "Matrix.h"


Matrix::Matrix(const int& rows, const int& cols)
{
	m_rows = rows;
	m_cols = cols;
	val = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		*(val + i) = new int[cols];
	}
}
Matrix::Matrix(const Matrix& m)
{
	int i, j;
	m_rows = m.m_rows;
	m_cols = m.m_cols;
	int* rowptr;
	val = new int* [m.m_rows];
	for (i = 0; i < m.m_rows; ++i)
	{

		val[i] = new int[m.m_cols];
		for (j = 0; j < m.m_cols; ++j)
		{
			*(val[i] + j) = (*(m.val[i] + j));
		}
	}
}
Matrix::~Matrix()
{
	for (int i = 0; i < m_rows; ++i)
	{
		delete[] val[i];
	}
	delete[] val;
}

bool isAdditionCompatible(const Matrix& x, const Matrix& y)
{
	if (x.m_rows == y.m_rows && x.m_cols == y.m_cols)
		return true;
	return false;
}

bool isMultiplicationCompatible(const Matrix& x, const Matrix& y)
{
	if (x.m_cols == y.m_rows)
		return true;
	return false;
}


Matrix operator+(const Matrix& x, const Matrix& y)
{
	Matrix result(x.m_rows, x.m_cols);
	if (!isAdditionCompatible(x, y))
	{
		cout << "\n Add operation not supported! ...";
		return result;
	}

	for (int i = 0; i < x.m_rows; ++i)
	{
		for (int j = 0; j < x.m_cols; ++j)
		{
			*(result.val[i] + j) = *(x.val[i] + j) + *(y.val[i] + j);
		}
	}

	return result;
}

Matrix operator-(const Matrix& x, const Matrix& y)
{
	Matrix result(x.m_rows, x.m_cols);
	if (!isAdditionCompatible(x, y))
	{
		cout << "\n Add operation not supported! ...";
		return result;
	}

	for (int i = 0; i < x.m_rows; ++i)
	{
		for (int j = 0; j < x.m_cols; ++j)
		{
			*(result.val[i] + j) = *(x.val[i] + j) - *(y.val[i] + j);
		}
	}

	return result;
}

istream& operator>> (istream& in, Matrix& m)
{
	int val, i, j;
	int* rowptr;
	for (i = 0; i < m.m_rows; ++i)
	{
		rowptr = m.val[i];
		for (j = 0; j < m.m_cols; ++j)
		{
			cout << "\n Enter element " << i + 1 << " , " << j + 1 << " :";
			in >> val;
			*(rowptr + j) = val;

		}
	}
	return in;
}

ostream& operator<<(ostream& out, const Matrix& m)
{
	int* rowptr;
	int i, j;
	out << "\n Elements of matrix: ";
	for (i = 0; i < m.m_rows; ++i)
	{
		rowptr = m.val[i];
		out << "\n [";
		for (j = 0; j < m.m_cols; ++j)
		{
			out << *(rowptr + j) << ",";
		}
		out << "]";
	}
	return out;
}