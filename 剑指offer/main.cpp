#include <vector>
#include <iostream>
#include <stack>
//#include "006-rotatedArray.hpp"
//#include "100-priorityQueue.hpp"
#include "065-findPathInMatrix.hpp"
int main()
{		
	int n = 1;
	Solution haspath;
	const char* matrix = "abcesfcsadee";//"ABCESFCSADEE"; ;
	const char* str = "bcced";//"ABCB";
	int rows = 3, cols = 4;
	bool has1 = haspath.hasPath(matrix, rows, cols, str);
	const char ch[] = "A";
	rows = cols = 1;
	bool has0 = haspath.hasPath(ch, rows, cols, ch);
	
	return 0;
}