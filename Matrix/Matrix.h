#pragma once
#include <iostream>
#include <sstream>

using namespace std;
class Matrix
{
private:

	int m_rows, m_cols;
	int** val;

public:


	Matrix() = delete;
	Matrix(const int&, const int&);
	Matrix(const Matrix& m);
	~Matrix();

	friend bool isAdditionCompatible(const Matrix&, const Matrix&);
	friend bool isMultiplicationCompatible(const Matrix&, const Matrix&);
	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator-(const Matrix&, const Matrix&);
	friend istream& operator>>(istream&, Matrix&);
	friend ostream& operator<<(ostream&, const Matrix&);
};
