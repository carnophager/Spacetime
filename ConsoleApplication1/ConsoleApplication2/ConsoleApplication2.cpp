// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

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
	case myEnum::a: printf("neshto si\n"); break;
	case myEnum::b: printf("drugo\n");
	};
}

int main()
{
	myEnum en = myEnum::b;
	f(en);

	// a + ( b + c ) != ( a + b ) + c - no associativity
	// floating point fixing error algorithm ( kahan? )
	float arr[100] = { 0.f, };
	float sum = 0;
	float t = 0.f; // по дефолт е double, затова трябва ".f"
	float e = 0.f;
	float y = 0.f;
	for (int i = 0; i < 100; i++)
	{
		y = arr[i] - e;
		t = sum + arr[i];
		e = (t -  sum) - y;
		sum = t;
	}
}
