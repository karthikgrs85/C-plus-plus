// Hackerrank_Deque.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <deque>
#include <conio.h>
using namespace std;

int getMax(deque<int> dq)
{
	int max = *dq.begin();
	deque<int>::iterator it = dq.begin() + 1;

	while (it != dq.end())
	{
		if (max<*it)
			max = *it;
		it++;
	}
	return max;
}

void printKMax(int arr[], int n, int k) {
	//Write your code here.
	
	int i = 0, j = 0, x = 0;
	cout << " n = " << n << " k = " << k<<endl;
	for (i = 0, j = k - 1; j <= n - 1; i++, j++)
	{
		cout << "\n Deque " << i + 1<<" :\n";
		deque<int> dq;
		for (x = i; x <= j; x++)
		{
			cout << " x = " << x << endl;
			dq.push_back(arr[x]);
			cout <<arr[x] << " "<<endl;
		}
		cout <<"max = "<< getMax(dq) << " ";
	}
	cout << endl;
}

int main() {

	int t;
	cin >> t;
	while (t>0) {
		int n, k;
		cin >> n >> k;
		int i;
		int arr[100];
		for (i = 0; i<n; i++)
			cin >> arr[i];
		printKMax(arr, n, k);
		t--;
	}
	_getch();
	return 0;
}