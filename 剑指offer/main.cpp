#include <vector>
#include <iostream>
#include <stack>
#include "007-nthFibonacchi.hpp"
int main()
{		
	Solution fib;
	for (int i = 0; i <= 100; i++)
		std::cout << fib.Fibonacci(i) << "\n";
	return 0;
}