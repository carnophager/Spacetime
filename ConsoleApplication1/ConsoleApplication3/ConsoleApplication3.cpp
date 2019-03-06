// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

// Рекурсия - линейна, разклонена, опашкова; recursive backtracking
// Проблеми - извикването на функция е overhead, заема място
// Може да променим колко стек ни трябва само compile time
// Стека е разделен на page-ове от 64 килобайта и те се заделят on demand, обикновен макса е 1MB
// Във Visual C, максималния брой рекурсии е 40
// Kernelspace, userspace
// Може да кашеш на някоя памет никога да не бъде swap-вана ( оптимизиация ? )
// факториел от 5 = 5 * 4 * 3 * 2 * 1; 
// Мемоизация - частен случай на кеширане

// Линейна рекурсия
int fact(int n)
{
	if (n == 1) return 1;
	return n * fact(n - 1);
}

// Опашкова рекурсия
int fact2(int n, int current = 1)
{
	if (n == 1)
	{
		return current;
	}

	return fact2(n - 1, current * n);
}

// Разклонена рекурсия n^2 сложност
int fib(int n)
{
	if (n == 0)
		return 0;

	if (n == 1)
		return 1;

	return fib(n - 1) + fib(n - 2);
}

// Recursive backtracking 
// e = exit
char arr[5][6] = {
	".....",
	".###.",
	"..#..",
	"..#..",
	"..#e."
};



//Incomplete
bool findPath(char arr[5][6], int x, int y)
{
	if (x < 0 || x > 4 )
		return false;

	if ( y < 0 || y > 5 )
		return false;

	if (arr[x][y] == 'e')
	{
		return true;
	}

	if (findPath(arr, x + 1, y))
		return true;
	if (findPath(arr, x -1, y))
		return true;
	if (findPath(arr, x, y - 1))
		return true;
	if (findPath(arr, x, y + 1))
		return true;

	return false;
}




enum Flag
{
	HAS_RED = 1,
	HAS_BLUE = 1 << 1,
	HAS_GREEN = 1 << 2,
};

bool checkFlag(int value, Flag f)
{
	return ( value & f) != 0;
}

// Bit Masking
bool checkFlags(int value, int testFlag)
{
	return (value & testFlag) == testFlag;
}

void setFlag(int & value, Flag f)
{
	value = value | f;
}

void clearFlag(int & value, Flag f)
{
	value = value & (~f); 
}

int main()
{
    std::cout << "Hello World!\n"; 

	checkFlags(123, Flag::HAS_RED | Flag::HAS_BLUE);

	//   10101
	// ~ 11110 
	//   10100 
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
