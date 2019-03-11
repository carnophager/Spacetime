//#include <QCoreApplication>
#include "pch.h"
#include <iostream>
#include <string.h>
#include <iostream>
#include <climits>
#include <bitset>
#include <math.h>

using namespace std;

template <typename T>
void printb(T const & whole_number)
{
	std::bitset<sizeof(whole_number) * 8> bits(whole_number);
	std::cout << "printb number: " << whole_number << "\nbits: " << bits << std::endl;
}

struct T
{
	char s;
	char ss;
	//int i : 1;
	//int ss : 1;
};

struct TS
{
	T t;
	int s;
};

// Represents a float number with 48 bits
struct LargeFloat
{
	unsigned short mantissa_1 : 16;
	unsigned short mantissa_2 : 16;
	unsigned short mantissa_3 : 8;
	unsigned short exponent : 7;
	bool sign : 1;

public:
	LargeFloat(double initial_value)
	{
		std::cout << "INITIAL VALUE: " << initial_value << std::endl;
		
		double initv = 26; //0 10000000011 1010000000000000000000000000000000000000000000000000 //26
		double * d = &initv;

		unsigned char *c = reinterpret_cast<unsigned char *>(&initv);
		exponent = *reinterpret_cast<unsigned short*>(&initv);
		mantissa_1 = static_cast<unsigned short>(initial_value);
		mantissa_3 = static_cast<unsigned short>(initial_value);
		c+=6;
		exponent += 6;
		std::bitset<7>   bits(exponent);
		//std::cout << "size " << sizeof(exponent) << std::endl;
		std::cout << "bits " << bits << std::endl;
		/*
		std::cout << "c address: " << *(c+3) << " " << &c << " " << &initv << " " << d << " " << &d << " " << &*d << " " << *d << std::endl;
		c++;
		std::cout << "c address: " << c << std::endl;
		PrintBits(*c);
		std::cout << "prev m" << std::endl;
		PrintBits(mantissa_1);
		std::cout << "prev mantissa 1, next mantissa 3 " << std::endl;
		PrintBits(mantissa_2);
		std::cout << std::endl;
		*/
		//initial_value >> 8;

		/*
		union
		{
			double     input;   // assumes sizeof(double) == sizeof(uint64_t) or 8 bytes
			uint64_t   output;
		}    data;

		data.input = initial_value;
		//data.output = 123123123;
		std::cout << "Convert to binary initial ";
		const unsigned int double_length_in_bits = sizeof(double) * 8;
		bool initial_value_binary[double_length_in_bits] = { 0 };
		//initial_value_binary[1] = false;
		std::cout << initial_value_binary[1] << " next ";

		//ConvertIntToBinary(data.output, initial_value_binary, double_length_in_bits);
		std::cout << std::endl;

		sign = initial_value_binary[0];
		int index = 1;
		*/

		/*
		exponent = ConvertBitsToShort(initial_value_binary, 7, index);
		index += 12;
		mantissa_1 = ConvertBitsToShort(initial_value_binary, 16, index);
		index += 16;
		mantissa_2 = ConvertBitsToShort(initial_value_binary, 16, index);
		index += 16;
		mantissa_3 = ConvertBitsToShort(initial_value_binary, 8, index);
		*/
		

		/*

		std::cout << " final :";
		for (int i = 0; i < double_length_in_bits; ++i)
		{
			//std::cout << initial_value_binary[i];
		}
		std::cout << " print bits: " << std::endl;
		PrintBits(exponent);
		std::cout << std::endl;
		*/
	}

	friend LargeFloat operator+(const LargeFloat &a, const LargeFloat &b)
	{
		uint64_t combined_mantissa_a = a.getCombinedMantissa();
		uint64_t combined_mantissa_b = b.getCombinedMantissa();
		uint64_t combined = combined_mantissa_a + combined_mantissa_b;

		std::cout << "mants a " << a.mantissa_1 << " " << a.mantissa_2 << "" << a.mantissa_3 << std::endl;
		std::cout << "mants b " << b.mantissa_1 << " " << b.mantissa_2 << "" << b.mantissa_3 << std::endl;
		std::cout << "combined mantissa a " << combined_mantissa_a << std::endl;
		std::cout << "combined mantissa b " << combined_mantissa_b << std::endl;
		std::cout << "combined " << combined << std::endl;
		uint64_t offset = (uint64_t)1 << 40;
		//fset<<= 40;
		if (combined & offset)
		{
			std::cout << "overflow !!!";
		}

		printb(a.mantissa_1);
		printb(a.mantissa_2);
		printb(a.mantissa_3);
		printb(combined_mantissa_a);
		printb(combined_mantissa_b);
		printb(combined);
		printb(offset);

		return LargeFloat(combined_mantissa_a);
	}

	//0000000000000000000000000001111111111111111111111111111111111111
	//0000000000000000000000000001110100000000000000000000000000000000
	//0000000000000000000000000011101000000000000000000000000000000000

private:

	uint64_t getCombinedMantissa() const
	{
		uint64_t combined_mantissa = 0;
		combined_mantissa |= mantissa_1;
		combined_mantissa <<= 16;
		combined_mantissa |= mantissa_2;
		combined_mantissa <<= 8;
		combined_mantissa |= mantissa_3;
		return combined_mantissa;
	}

	/*!
		Gets number of bits from array
	*/
	unsigned short ConvertBitsToShort(bool bits[], int num_of_bits_to_copy, int &starting_index)
	{
		unsigned short number = 0;
		for (int i = starting_index + num_of_bits_to_copy; i > starting_index; --i)
		{
			//printf("for: %d %d %d %d %d\n", num_of_bits_to_copy + starting_index - i, i - 1, starting_index, bits[i - 1], bits[num_of_bits_to_copy - i]);
			if (bits[i - 1])
			{
				number += std::pow(2, num_of_bits_to_copy + starting_index - i);
				printf("number: %d %d\n", num_of_bits_to_copy, number);
			}
		}

		return number;
	}

	/*!
		Fills an array containing the bits of a given 64 bits unsigned integer
	*/
	void ConvertIntToBinary(uint64_t n, bool bits[], int index)
	{
		if (n / 2 != 0) {
			this->ConvertIntToBinary(n / 2, bits, index - 1);
		}
		//printf("dd%d", index);
		bits[index] = n % 2;
		//asdf(1);
	}

	void PrintBits(unsigned short n)
	{
		if (n / 2 != 0) {
			this->PrintBits(n / 2);
		}
		printf("%d", n % 2);

	}



	//signed short exponent;
};


int printReverse(int num)
{
	if (num < 10)
	{
		cout << num;
		return 0;
	}
	cout << num % 10;
	return printReverse(num / 10);
}

bool determinePalindrome(string str)
{
	if (tolower(str.at(0)) != tolower(str.back()))
		return false;

	if (str.length() < 3)
		return true;

	str.erase(0, 1);
	str.pop_back();

	return determinePalindrome(str);
}

int main()
{
	cout << "Core" << std::endl;
	float test = 17.25;


	//LargeFloat arr[11]; Requires a default constructor ( empty constructor or with value in double constructor )

	T t;
	std::cout << sizeof(t) << endl;
	printf("size of t (in bytes): %d \n", sizeof(t));
	int integer = 1;
	float initialfn = -26;
	float initialf = 26;
	std::cout << initialfn;
	printf("size of float in bytes: %d \n", sizeof(initialf));
	double initial = 26;
	double initial1 = 1;
	printf("size of double in bytes: %d \n", sizeof(initial));
	LargeFloat large_float(initial);
	LargeFloat large_float1(initial1);
	LargeFloat large_float2 = large_float + large_float1;
	std::cout << "sizeof LargeFloat (in bytes): " << sizeof(large_float) << endl;
	printf("size of large_float (in bits): %d \n", sizeof(large_float) * 8);

	unsigned short one = 1;
	uint64_t ui = 0;
	ui |= one;
	ui <<= 16;
	ui |= one;
	//ui <<= 16;
	std::cout << "ui: " << ui;


	std::cout << std::endl;

	union
	{
		double     input;   // assumes sizeof(double) == sizeof(uint64_t) or 8 bytes
		uint64_t   output;
	}    data;

	data.input = 26;// 1.652;
	//1023 exponent offset
	// 0 10000000011 1010000000000000000000000000000000000000000000000000 //26
	// 0 10000000100 1010000000000000000000000000000000000000000000000000 //52
	// 0 01111111111 0011 00110011 00110011 00110011 00110011 00110011 00110011 //1.4
	// 0 01111111111 1010011011101001011110001101010011111101111100111011 // 1.652

	short shor = *((short*)&data.input);

	//char chars = 1;
	unsigned int ints = 1.652 ;
	char chars = static_cast<char>(ints);
	// 00000000 00010010 11001001 01111111
	// 01111111
	// 01100110 01100110
	// 1010011011101001011110001101010011111101111100111011
	// 11011111 00111011
	std::bitset<sizeof(double) * CHAR_BIT>   bits(data.output);
	std::cout << "bits " << bits << std::endl;

	// or

	//std::cout << "BIT 4: " << bits[4] << std::endl;
	//std::cout << "BIT 7: " << bits[7] << std::endl;

	double double_long = 3.14159265358979323846264338327950288419716939937510;
	//1023 bias
	//11 digits exponent
	//rest is significand
	float float_long = double_long;
	std::cout.precision(50);
	std::cout << "double: " << double_long << std::endl;
	std::cout << "float: " << float_long << std::endl;

	int num = 1234;
	printReverse(num);

	cout << endl;

	string palindrome = "abrba";
	cout << palindrome << " is palinrome?: " << determinePalindrome(palindrome) << endl;

	//QCoreApplication a(argc, argv);


	return 0;//a.exec();q
}
