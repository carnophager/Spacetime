// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

void printPermutation(int current[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << current[i];
	}

	std::cout << std::endl;
}

void getPermutations(int M[], int n, int current[], int position)
{
	if (position == n)
	{
		printPermutation(current, n);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		current[position] = M[i];
		getPermutations(M, n, current, position + 1);
	}
}

// N-k
void getVariations(int M[], int n, int current[], int position, int k)
{
	if (position == k)
	{
		printPermutation(current, k);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		current[position] = M[i];
		getVariations(M, n, current, position + 1, k);
	}
}

void generateAllPermutations()
{
	int M[] = { 1, 2, 3 };
	const int N = sizeof(M) / sizeof(int); //get count of elements in M
	int arr[N];
	for (int i = 0; i < N; ++i)
	{
		for ( int j = 0; j < N; ++j )
		{
			std::cout << "j" << j << std::endl;
			std::cout << M[i] << M[j] << std::endl;
		}
	}
}

int main()
{
	int M[] = { 1, 2, 3 };
	const int N = sizeof(M) / sizeof(int);
	int arr[N];
	//generateAllPermutations();
	getPermutations(M, N, arr, 0);
	getVariations(M, N, arr, 0, 2);

	double d = 2.5;
	long long L = *((long long*)&d);
	std::cout << L << std::endl;

	// Задачата за раницата и търсене на най-кратък път от точка до точка ( Dijkstra ) 

	// Комбинаторика
	// Множество - съвкупност от разнородни елементи
	// M = { a, b, c } // 3 елемента
	// B = { 0, 1 }  // булевото множество
	// операции с множества - събиране, изваждане, умножение, степенуване, сечение
	// B x B = { {1, 0}, {1, 1}, { 0, 1}, {0, 0}, { } } - декартово произведение
	// |M|| = m, |N| = n, 
	// Вариации без повторение - |M+M| = Pn = n! ( 3*2*1) factoriel може да избера за първа позиция от 3 елемента, за втора позиция 2, за трета позиция от 1, затова общият брой е 3*2*1;
	// Част от вариации без повторение - V n ^ k = n!/(n - k)! ( Където n e общият брой елементи, а k е новият брой ) 
	// Вариации с повторение - NVn^k = n^k
	// (Cn)^k = n!/k!(n-k)!
	// (NCn)^k = n^k/
	// P = permutations, V = variations, 
}
