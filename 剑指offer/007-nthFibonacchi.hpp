typedef unsigned long long ulong;
class Solution {
public:
    ulong Fibonacci(int n) {
        if (n < 0)
        {
            return -1;
        }
        
        if (n < 2)
        {
            return n;
        }

        ulong a = 0, b = 1;
        for (ulong i = 2; i <= n; i++)
        {
            if (a < b)
            {
                a = a + b;
            }
            else
            {
                b = a + b;
            }
        }

        return a < b ? b : a;
    }
};