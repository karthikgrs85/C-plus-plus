#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <iostream>
#include <sstream>
#include <string>


using namespace std;

class Complex
{
private:
	float re, im;

public:
	Complex() :re(0.0), im(0.0) {}
	Complex(const float& a, const float& b) : re(a), im(b) {}

	friend Complex operator+(const Complex& a, const Complex& b);
	friend Complex operator-(const Complex& a, const Complex& b);
	friend Complex operator*(const Complex& a, const Complex& b);
	friend Complex operator/(const Complex& a, const Complex& b);
	friend ostream& operator<<(ostream& out, const Complex& a);
	friend istream& operator>>(istream& in, Complex& a);

	Complex& operator+=(const Complex& a);
	bool operator==(const Complex& a);

};

#endif