// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>

void intsInputCompare()
{
	double long largest_int = -DBL_MAX + 1;
	double long second_largest_int = -DBL_MAX;
	double long n;
	while (std::cin >> n)
	{
		if (n > largest_int)
		{
			second_largest_int = largest_int;
			largest_int = n;
			continue;
		} 
		
		if (n > second_largest_int)
		{
			second_largest_int = n;
		}	
	}

	std::cout << "Largets input: " << largest_int << "Second largest input: " << second_largest_int;
}


double long getNThRoot(int root)
{
	int number;
	std::cin >> number;
	return pow(number, 1.f / root);
}


void outputSubsets(int *arr, int position, int size)
{
	static std::vector<int> list;
	if (position == size)
	{
		for (int i = 0; i < list.size(); i++)
		{
			std::cout << list[i];
			if (i != list.size() - 1)
				std::cout << " | ";
			else 
				std::cout << ", ";
		}
		return;
	}
	outputSubsets(arr, position + 1, size);
	list.push_back(arr[position]);
	outputSubsets(arr, position + 1, size);
	list.pop_back();
}

void OutputSubsets()
{
	int * nums = new int[3];
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	outputSubsets(nums, 0, 3);
}

bool checkPalindrome(std::string s, int i)
{
	//std::cout << i << std::endl;
	if (s[i] != s[s.length() - i - 1])
		return false;

	//std::cout << "before check i " << i << " " << (int)(s.length() / 2);
	if (i == (int)(s.length() / 2))
		return true;

	i += 1;
	return checkPalindrome(s, i + 1);
}

int main()
{
	// Exercise 1
	//intsInputCompare();

	// Exercise 2
	//std::cout << getNThRoot(3);

	// Exercise 3
	//OutputSubsets();
	
	// Exercise 4
	//std::cout << "checkPal: " << checkPalindrome("abba", 0);

	/**********************/
	//COURSE
	// 07.02
	/**********************/
	int x = 3;
	int * r = &x;
	*r = 5;
	printf("%d", *r);

	int * p = NULL;
	f(*p);
	f(x);

	int * a[10];
	a[1];
	int * p;
	p = 1[a];

	// dangling reference = undefined behaviour
	// void is a type
	bool a = true;
	void * p = &a;
	*(int*)p = 30000; // undefined ( but really defined by compiler ) behaviour, will write in the neighbour memory slots
}

union UN
{
	//the whole union is 4 bytes ( the bigger of the variables - int. They occupy the same address space
	int a;
	char b;
};

struct myFlags
{
	int a : 3; // Bit-fields, int will occupy only 3 bits
	int b : 7; // Useful in network programming, because you can set packet size types
};

struct Base
{
	int x;
	// If struct is empty and inherited, it doesn't take any memory, but if it's an empty struct and you refer it it takes 1 or 4 bytes
};

struct MyStruct : Base {
	int a;
	int b;
	void f(int x) // accepts one hidden argument CONST this which is a pointer to the object of the struct/class type
	{
		this->a = x;
		this->b = x + 3;
	}
};

class MyClass {
	public: 
		int a;
};

void f(int& i)
{
	i++;
	// не може да се dereference-не, защото тази стойност е по презумция невалидна
	// Дереференцирането на нулев пойнтер е сигурен начин да убеим програмата, defined behaviour
	int *p = NULL; //нулевият адрес в паметта

}

//Не е нормален клас, само те кара да пишеш myEnum::a преди да достъпиш стойността "а", "б" и т.н.
enum class myEnum : char
{
	a, //0
	b, // a + 1 (1)
	c // b + 1 (2)
};

void f(myEnum e)
{
	switch (e)
	{
		case myEnum::a : printf("neshto si"); break;
		case myEnum::b : printf("drugo");
	};
}

void main07()
{
	UN a;
	a.a = 3;
	a.b = 'c';

	
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
