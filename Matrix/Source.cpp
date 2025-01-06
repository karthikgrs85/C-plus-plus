// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"
#include <vector>

int main()
{
  //  std::cout << "Hello World!\n";

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
		cout << "\n Enter an option - add <matrix1> <matrix2>, subtract <matrix1> <matrix2> exit to quit :\n";
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

			Matrix* m = new Matrix((*(it + m1 - 1)) + (*(it + m2 - 1)));
			cout << "\n The result = \n" << *m;
			delete m;
		}
		else if (!strcmp(operation.c_str(), "subtract"))
		{
			vector<Matrix>::iterator it = vecMatrix.begin();
			if (m1 > vecMatrix.size() || m2 > vecMatrix.size() || m1<1 || m2<1)
			{
				cout << "\n Invalid matrix indices !";
				continue;
			}

			Matrix* m = new Matrix((*(it + m1 - 1)) - (*(it + m2 - 1)));
			cout << "\n The result = \n" << *m;
			delete m;
		}
	} while (strcmp(operation.c_str(), "exit"));
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
