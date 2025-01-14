// OperatorOverloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

class Matrix
{
private:

	int m_rows, m_cols;
	int** val;

public:

	
	Matrix() = delete;
	Matrix(const int& rows, const int& cols) 
	{ 
		m_rows = rows;
		m_cols = cols;
		val = new int*[rows];
		for (int i = 0; i < rows; ++i)
		{
			*(val+i) = new int[cols];
		}
	}
	Matrix(const Matrix& m)
	{
		int i, j;
		m_rows = m.m_rows;
		m_cols = m.m_cols;
		int *rowptr;
		val = new int*[m.m_rows];
		for (i = 0; i < m.m_rows; ++i)
		{
			
			val[i] = new int[m.m_cols];
			for (j = 0; j < m.m_cols; ++j)
			{
				*(val[i] + j) = (*(m.val[i] + j));
			}
		}
	}
	~Matrix()
	{
		for (int i = 0; i < m_rows; ++i)
		{
			delete[] val[i];
		}
		delete[] val;
	}

	friend bool isAdditionCompatible(const Matrix&, const Matrix&);
	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator-(const Matrix&, const Matrix&);
	friend istream& operator>>(istream&, Matrix&);
	friend ostream& operator<<(ostream&, const Matrix&);
};

bool isAdditionCompatible(const Matrix& x, const Matrix& y)
{
	if (x.m_rows == y.m_rows && x.m_cols == y.m_cols)
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
			*(result.val[i]+j) = *(x.val[i] +j) + *(y.val[i]+j);
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
	for (i = 0; i< m.m_rows; ++i)
	{
		rowptr = m.val[i];
		for (j = 0; j < m.m_cols; ++j)
		{
			cout << "\n Enter element " << i+1 << " , " << j+1 << " :";
			in >> val;
			*(rowptr + j) = val;

		}
	}
	return in;
}

ostream& operator<<(ostream& out, const Matrix& m)
{
	int *rowptr;
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


int main() {
	int numMatrices, k;
	stringstream ss;
	string inp, operation;
	int rows, cols, m1, m2;
	vector<Matrix> vecMatrix;
	cout << "\n Enter no. of matrices to input: ";
	cin >> numMatrices;
	for (k = 0; k < numMatrices; k++)
	{
		cout << "\n Enter no. of rows and columns";
		cin >> rows >> cols;
		Matrix m(rows, cols);
		cin >> m;
		vecMatrix.push_back(m);
	}
	cout << "\n The list of matrices :";
	k = 1;
	vector<Matrix>::iterator it = vecMatrix.begin();
	for (; it != vecMatrix.end(); ++it)
	{
		cout << "\n Matrix " << k++ << " :\n";
		cout << *it;
	}
	
	cin.ignore();
	do
	{
		cout << "\n Enter an option - add <matrix1> <matrix2>, subtract <matrix1> <matrix2> 0 to quit :\n";
		getline(cin, inp);
		ss = stringstream(inp);
		ss >> operation >> m1 >> m2;
		if (!strcmp(operation.c_str(), "add"))
		{
			vector<Matrix>::iterator it = vecMatrix.begin();
			if (m1 > vecMatrix.size() || m2 > vecMatrix.size())
			{
				cout << "\n Invalid matrix indices !";
				continue;
			}

			Matrix *m = new Matrix((*(it+m1-1)) + (*(it+m2-1)));
			cout << "\n The result = \n" << *m;
			delete m;
		}
		else if (!strcmp(operation.c_str(), "subtract"))
		{
			vector<Matrix>::iterator it = vecMatrix.begin();
			if (m1 > vecMatrix.size() || m2 > vecMatrix.size())
			{
				cout << "\n Invalid matrix indices !";
				continue;
			}

			Matrix* m = new Matrix((*(it + m1 - 1)) - (*(it + m2 - 1)));
			cout << "\n The result = \n" << *m;
			delete m;
		}
	} while (strcmp(operation.c_str(), "0"));
	return 0;
}

