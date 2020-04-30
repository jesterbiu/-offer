#pragma once
#include <iostream>
#include <vector>
// define unsigned int as u, signed int as s.
// a numeric is 
// s[.u][e|Es]
// or .u[e|Es]

constexpr static const char legalChar[] = "+-.0123456789Ee";

bool matchUnsignedInteger(char** string)
{
	char* str = *string;
	auto isDigit = [](const char& ch) { return '0' <= ch && ch <= '9'; };
	while (*str != '\0' && isDigit(*str))
	{
		str++;
	}

	bool hasUnsignedInt = str > * string ? true : false;
	*string = str;
	return hasUnsignedInt;
}

bool matchInteger(char** string)
{
	char* str = *string;

	// validate input
	if (*str == '\0')
	{
		return false;
	}

	// signed
	if (*str == '+' || *str == '-')
	{
		str++;
	}
	
	*string = str;

	return matchUnsignedInteger(string);
}

bool isLegal (const char& ch)
{
	for (int i = 0; i < 15; i++)
	{
		if (legalChar[i] == ch)
			return true;
	}
	return false;
};

bool isNumeric(char* string)
{
	// validate input
	if (nullptr == string)
	{
		return 0;
	}

	// find illegal character

	for (int i = 0; string[i] != '\0'; i++)
	{
		char ch = string[i];
		if (!isLegal(ch))
		{
			return false;
		}
	}

	bool isNumeric = false;

	// match integer
	isNumeric = matchInteger(&string);

	// match fraction
	if (*string == '.')
	{
		string++;
		// 应尽可能地多识别numerics，因此要先检测小数部分
		isNumeric = matchUnsignedInteger(&string) || isNumeric ;
	}

	// match exponent
	if (*string == 'E' || *string == 'e')
	{
		string++;
		isNumeric = isNumeric && matchInteger(&string);		
	}

	if (*string != '\0')
		return false;

	return isNumeric;
}

void test_isNumberic()
{
	char str1[] = "123.45e+6";
	char str2[] = "3.1416";
	char str3[] = "000";
	char str4[] = "600.";
	char str5[] = "-.123";
	char str6[] = "-1E-16";
	char str7[] = "1a3.14";
	char str8[] = ".";
	char str9[] = "+.";
	char str10[] = ".e1";
	char str11[] = "+-5";
	
	std::vector<char*> strs = { 
		str1, str2, str3, 
		str4, str5, str6, str7, 
		str8, str9, str10, str11 };
	
	auto numericTestOutput = [](char* str)
	{
		std::cout << str << "\t";
		if (isNumeric(str))
		{
			std::cout << "is a numberic" << std::endl;
		}
		else
		{
			std::cout << "is not a numberic" << std::endl;
		}
	};

	for (auto str : strs)
	{
		numericTestOutput(str);
	}
	
	
}