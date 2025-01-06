#include <iostream>
#include <conio.h>


void lambda_value_capture() {
	int value = 1;
	auto copy_value = [value] {
		return value;
	};
	value = 100;
	auto stored_value = copy_value();
	std::cout << "stored_value = " << stored_value << std::endl;
	// At this moment, stored_value == 1, and value == 100.
	// Because copy_value has copied when its was created.
}

void lambda_reference_capture() {
	int value = 1;
	auto copy_value = [&value] {
		return value;
	};
	value = 100;
	auto stored_value = copy_value();
	std::cout << "stored_value = " << stored_value << std::endl;
	// At this moment, stored_value == 100, value == 100.
	// Because copy_value stores reference
}

void main()
{
	//lambda_value_capture();
	//lambda_reference_capture();
	int val = 0, incr = 0;
	auto increment_1 = [val](int incr){ val + incr; };
	auto increment_2 = [&val](int incr) { (val += incr); };
	std::cout << "\n Enter any integer :";
	std::cin >> val;
	std::cout << "\n Enter the increment value :";
	std::cin >> incr;
	increment_1(incr);
	std::cout << "\n The changed value after using increment_1 lambda is :" << val;
	increment_2(incr);
	std::cout << "\n The changed value using increment_2 lambda is :" << val;


	//_getch();

}