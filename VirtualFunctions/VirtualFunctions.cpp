// VirtualFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
class Person
{


protected:
	string name;
	int age;

public:

	virtual void getdata() = 0;
	virtual void putdata() = 0;
};

class Professor : public Person
{

private:

	int publications, cur_id;


public:

	static int id;

	Professor() : Person()
	{
		cur_id = ++id;
	}

	virtual void getdata()
	{
		cin >> name >> age >> publications;
	}
	virtual void putdata()
	{
		cout << name << " " << age << " " << publications << " " << cur_id << "\n";
	}

};

class Student : public Person
{
private:

	int marks[6], cur_id;


public:
	static int id;

	Student() :Person()
	{
		cur_id = ++id;
	}

	virtual void getdata()
	{
		cin >> name >> age;
		for (int i = 0; i<6; ++i)
		{
			cin >> marks[i];
		}
	}

	virtual void putdata()
	{
		cout << name << " " << age << " " << marks[0] + marks[1] + marks[2] + marks[3] + marks[4] + marks[5] << " " << cur_id << "\n";
	}

};

int Professor::id = 0;
int Student::id = 0;

int main()
{
	int n, val;
	cin >> n; //The number of objects that is going to be created.
	Person *per[n];

	for (int i = 0; i < n; i++) {

		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			per[i] = new Professor;

		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.

	}

	for (int i = 0; i<n; i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;
}

