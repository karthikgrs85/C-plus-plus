#include "ComplexNumbers.h"

// ComplexNumbers.cpp : Defines the entry point for the console application.
//




Complex& Complex::operator+=(const Complex& a)
{
	re += a.re;
	im += a.im;
	return *this;
}

bool Complex::operator==(const Complex& a)
{
	return ((re == a.re) && (im == a.im));

}

Complex operator+(const Complex& a, const Complex& b)
{
	return(Complex(a.re + b.re, a.im + b.im));
}

Complex operator-(const Complex& a, const Complex& b)
{
	return(Complex(a.re - b.re, a.im - b.im));
}

Complex operator*(const Complex& a, const Complex& b)
{
	return Complex((a.re*b.re - a.im*b.im), (a.im*b.re + a.re*b.im));
}

Complex operator/(const Complex& a, const Complex& b)
{
	return Complex(((a.re*b.re + a.im*b.im) / (b.re*b.re + b.im*b.im)), ((a.im*b.re - a.re*b.im) / (b.re*b.re + b.im*b.im)));
}

ostream& operator<<(ostream& out, const Complex& a)
{
	out << a.re;

	if (a.im > 0)
	{
		if (a.im == 1)
			out << " + i";
		else
			out << " + " << a.im << "i";
	}
	else if (a.im < 0)
	{
		if (a.im == -1)
			out << " - i";
		else
			out << " - " << abs(a.im) << "i";
	}
	return out;
}

istream& operator>>(istream& in, Complex& a)
{
	string str, realStr, imagStr;
	float realF = 0, imagF = 0;
	string::size_type len = 0;
	int i = 0;
	in >> str;
	bool hasRealPart =false, hasImagPart = false, parsingImagPart = false;
	hasImagPart = (str[str.size() - 1] == 'i') ? true : false;
	
	for(i = (str.size() - 1); i >= 0; --i)
	{
		if (hasImagPart)
		{
			if (str[i] == 'i')
			{
				parsingImagPart = true;
				continue;
			}
			else if ((str[i] == '-' || str[i] == '+') && parsingImagPart == true)
			{
				if (str[i+1] == 'i')
				{
					imagStr = (str[i] == '-') ? ("-1") : ("1");
			    }
				else if (str[i] == '-')
					imagStr = str.substr(i, len + 1);
				else
					imagStr = str.substr(i+1, len);

				len = 0;
				parsingImagPart = false;
			}
		}
		if (i == 0)
		{
			if (!parsingImagPart)
			{
				realStr = str.substr(i, len+1);
			}
			else
			{
				imagStr = str.substr(i, len+1);
			}
		}
		else 
		{
			len++;
		}

		
	}
	stringstream s = stringstream(realStr);
	s >> realF;

	s = stringstream(imagStr);
	s >> imagF;

	a = Complex(realF, imagF);

	return in;
}