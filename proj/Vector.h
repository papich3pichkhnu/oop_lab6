#pragma once
#include <iostream>
using namespace std;
template<class T, size_t L>
class Vector
{
public:
	T* myarray;
	Vector()
	{
		myarray = new T[L];
	}
	T& operator[](int a)
	{
		if (a >= L)throw runtime_error("Array index out of bounds");
		else return myarray[a];
	}
	void print()	
	{
		for (size_t i = 0; i < L; i++)
		{
			cout << i + 1 << " ";
			if (myarray[i] == nullptr)cout << "null";
			else cout << *(myarray[i]);
			cout << endl;
		}
	}
	void clear()
	{
		for (size_t i = 0; i < L; i++)
		{
			myarray[i] = nullptr;
		}
	}
	static void swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}
	void reverse()
	{
		for (size_t i = 0; i < (L+1)/2; i++)
		{
			swap(myarray[i], myarray[L - i - 1]);
		}
	}
};

