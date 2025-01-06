#include <vector>
#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


void bubbleSort(vector<int>& vec, bool func(const int& a , const int& b) )
{
	//sort(vec.begin(), vec.end(), [](int a, int b) {return (a < b); });
	vector<int>::iterator iter = vec.begin(), iter1;
	for (;iter != vec.end() - 1;iter++)
	{
		for (iter1 = iter + 1; iter1 != vec.end(); iter1++)
		{
			if (!func(*iter, *iter1))
				swap(*iter, *iter1);
		}
	}

}

int partition(vector<int>& vec, const int& low, const int& high, bool func(const int& a, const int& b))
{
	//Assuming pivot is end
	int pivot = high, startpointer = low;
	int secondpivot = low-1;
	while (startpointer <= high - 1)
	{
		if (func(*(vec.begin()+startpointer), *(vec.begin()+pivot)))
		{
			secondpivot++;
			swap(*(vec.begin()+startpointer), *(vec.begin()+secondpivot));
		}
		startpointer++;
	}
	swap(*(vec.begin()+pivot), *(vec.begin()+(secondpivot+1)));
	return secondpivot + 1;
}

void quicksort(vector<int> &vec, const int &low, const int &high, bool func(const int& a, const int& b))
{
	int pivot;
	if (low < high)
	{
		pivot = partition(vec, low, high, func);
		quicksort(vec, low, pivot-1, func);
		quicksort(vec,pivot + 1, high, func);

	}
}


void printVector(const vector<int> &vec)
{
	if (vec.size() == 0)
	{
		cout << "\n Vector empty!";
	}
	else
	{
		cout << "\n Elements of vector :\n";
		vector<int>::const_iterator iter = vec.begin();
		for (; iter != vec.end()-1; ++iter)
		{
			cout << *iter << ", ";
		}
		cout << *iter;
	}
}

int main()
{
	vector<int> vec1;
	int num;
	cout << "\n Enter some elements (0 to stop)";
	do
	{
		cin >> num;
		if (!num)
			break;
		vec1.push_back(num);
	} while (1);

	cout << "\n Before sort :";
	printVector(vec1);
	auto asc = [](const int& a, const int& b) {return (a < b); };
	auto desc = [](const int& a, const int& b) { return (a > b);  };
	vector<int>::iterator start = vec1.begin(), end = vec1.end() - 1;
	//bubbleSort(vec1, asc);
	quicksort(vec1,0,vec1.size()-1, asc);
	cout << " \n After ascending quick sort :";
	printVector(vec1);

	quicksort(vec1, 0, vec1.size() - 1, desc);
	cout << " \n After descending quick sort :";
	printVector(vec1);


	//bubbleSort(vec1, desc);

	//cout << " \n After descending sort :";
	//printVector(vec1);
}