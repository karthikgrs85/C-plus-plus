#include <iostream>
#include <stdio.h>
#include <memory>

void foo(std::shared_ptr<int> i)
{
	(*i)++;
}

using namespace std;

class A;
class B;

class A
{
	

public:
	weak_ptr<B> mP;
	
	~A()
	{
		cout << " A is destroyed " << endl;
	}
};

class B
{
	

public:
	weak_ptr<A> mP;
	~B()
	{
		cout << " B is destroyed " << endl;
	}
};


class A1;
class B1;



class A1
{
	

public:
	shared_ptr<B1> mP;
	~A1()
	{
		cout << " A1 is destroyed " << endl;
	}
};

class B1
{
	

public:
	shared_ptr<A1> mP;
	~B1()
	{
		cout << " B1 is destroyed " << endl;
	}
};


void main()
{

	auto ptr = make_shared<int>(1);
	foo(ptr);
	auto ptr1 = ptr;
	auto ptr2 = ptr;

	int* p = ptr.get();
	cout << " The reference count of ptr is = " << ptr.use_count() << endl;
	cout << " The reference count of ptr1 is = " << ptr1.use_count() << endl;
	cout << " The reference count of ptr2 is = " << ptr2.use_count() << endl;
	cout << " The pointer value is :" << p << endl;

	ptr1.reset();

	cout << " After ptr1 reset :" << endl;
	cout << " The reference count of ptr is = " << ptr.use_count() << endl;
	cout << " The reference count of ptr1 is = " << ptr1.use_count() << endl;
	cout << " The reference count of ptr2 is = " << ptr2.use_count() << endl;

	ptr2.reset();

	cout << " After ptr2 reset :" << endl;
	cout << " The reference count of ptr is = " << ptr.use_count() << endl;
	cout << " The reference count of ptr1 is = " << ptr1.use_count() << endl;
	cout << " The reference count of ptr2 is = " << ptr2.use_count() << endl;

	unique_ptr<int> uPtr = make_unique<int>(2);
	//auto u2Ptr = uPtr;

	//Since A and B use weak ptr, the destructor will be called
	shared_ptr<A> AVal = make_shared<A>();
	shared_ptr<B> BVal = make_shared<B>();
	AVal->mP = BVal;
	BVal->mP = AVal;


	//Since A1 and B1 do not use weak ptr, the destructor will not be called
	shared_ptr<A1> A1Val = make_shared<A1>();
	shared_ptr<B1> B1Val = make_shared<B1>();
	A1Val->mP = B1Val;
	B1Val->mP = A1Val;

	
}
