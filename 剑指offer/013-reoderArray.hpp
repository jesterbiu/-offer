#include <iostream>
#include <vector>
using std::vector;
using std::cout; 
using std::endl;

inline bool isOdd(int n)
{
	return (n % 2 == 1);
}

inline bool isEven(int n)
{
	return (n % 2 == 0);
}

void reOrderArray_unstable(vector<int>& array) {
	if (array.empty())
		return;

	size_t ptr1 = 0, ptr2 = array.size() - 1;
	while (true)
	{
		// while ptr1 is odd, move forward
		while (isOdd(array[ptr1]) && ptr1 < ptr2)
		{
			ptr1++;
		}

		// while ptr2 is even, move forward
		while (isEven(array[ptr2]) && ptr1 < ptr2)
		{
			ptr2--;
		}

		// if ptr1 != ptr2, switch
		if (ptr1 < ptr2)
		{
			std::swap(array[ptr1], array[ptr2]);
		}
		// else ptr1 and ptr2 have already travesed the array
		else
		{
			break;
		}
	}
}

void reOrderArray(vector<int>& array) // stable version
{
	if (array.empty())
	{
		return;
	}

	for (size_t i = 1; i < array.size(); i++)
	{
		if (isOdd(array[i]))
		{
			
			size_t j = i;
			while (j > 0 && isEven(array[j - 1]))
			{
				std::swap(array[j - 1], array[j]);
				j--;
			}
		}
	}
}

void test_reOrderArray()
{
	vector<int> testv1 = { 1,2,3,4,5,6,7,8 };
	vector<int> testv2 = { 10,12,36,48,5,61,73,87 };
	vector<int> testv3 = { 11,21,31,41,54,64,74,84 };
	vector<int> testv4 = { 1 };

	vector<vector<int>> tests = { testv1, testv2, testv3, testv4 };

	auto printArray = [](const vector<int>& v)
	{
		for (int i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	};

	for (int i = 0; i < tests.size(); i++)
	{
		reOrderArray(tests[i]);
		printArray(tests[i]);
	}

}