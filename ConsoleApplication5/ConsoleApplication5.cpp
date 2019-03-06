// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
	1. Greedy algorithm - този, който се оптива да оптимизира стейта в момента/ моментното състояние, без оглед на цялото
	Cost(state)->[0,1] връща стойност от 0 до 1 спрямо това колко е добър намереният резултат
	Queue or heap
	bfs ( breadth-first search), best first search both take a lot of memory, until they get next element in queue
	beam search is actually optimization of bfs and best first search
	alpha go algorithm is actually a beam search navigated by a neural network
	hill climbing algorithm, basis for ml algorithm - gradient descent

	2. Genetic algorithm - 4 parameters - how much to mutate each generation, what percentatate of the generation to mutate, initial memory/count population size, mutation frequency 
	Suitable for traversal problem - shortest path to go through each city in a node structure
	Suitable in artificial intelligence - using genetic algorithms for picking topology for neural networks, 
	Monte Carlo
	Las Vegas
	Atlantic City
*/
#include "pch.h"
#include <iostream>
#include <iostream>
#include <bitset>

int main()
{
	union
	{
		float input;   // assumes sizeof(float) == sizeof(int)
		int   output;
	}   data;

	data.input = 2.25125;
	std::bitset<sizeof(float) * CHAR_BIT> bits(data.output);
	std::cout << bits << std::endl;
	std::cout << "BIT 4: " << bits[3] << std::endl;

    std::cout << "Hello World!\n"; 
}
