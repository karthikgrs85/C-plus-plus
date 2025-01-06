#include "ComplexNumbers.h"

int main()
{
	Complex a, b;
	string str;
	cout << " Enter 2 complex numbers: ";
	cin >> a >> b;
	cout << "\n a = " << a;
	cout << "\n b = " << b;
	str = (a == b ? ("\n They are same") : ("\n They are different "));
	cout << str;
	cout << "\n The sum is " << a + b;
	cout << "\n The difference is " << a - b;
	cout << "\n The product is " << a * b;
	cout << "\n The quotient is " << a / b;
	//_getch();
	return 0;
}
