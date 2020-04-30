#include <iostream>
#include <string>

// skip 0s
void printDigit(const std::string& digit)
{
	size_t start = digit.find_first_not_of('0');
	for (size_t pos = start; pos < digit.size(); pos++)
	{
		std::cout << digit[pos];
	}
	std::cout << std::endl;
}

void digitPerm(std::string& digit, size_t pos)
{
	if (pos == digit.size())
	{
		printDigit(digit);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		digit[pos] = '0' + i;
		digitPerm(digit, pos + 1);
	}
}

void print1ToMaxOfNDigits(int n)
{
	// validate input
	if (n <= 0)
	{
		std::cout << "invalid input!" << std::endl;
		return;
	}

	// construct str
	std::string digit((size_t)n, '0');

	for (int i = 0; i < 10; i++)
	{	
		digit[0] = '0' + i;
		digitPerm(digit, 1);
	}
}

void test_print1ToMaxOfNDigits()
{
	for (int i = -1; i < 5; i++)
		print1ToMaxOfNDigits(i);
}