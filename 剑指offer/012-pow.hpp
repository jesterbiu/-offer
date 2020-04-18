#include <vector>
#include <cmath>
#include <limits>
#include <stdexcept>
class Solution {

    // to determine if 2 float points are equal
    bool equaldouble(double a, double b)
    {
        if (fabs(a - b) < std::numeric_limits<double>::epsilon())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    // calculate power recursively
    double calculateUnsignedPower(double base, unsigned int exp)
    {
        // does not deal with 0 base
        // ...

        // special input
        if (0 == exp)
        {
            return 1;
        }
        if (1 == exp)
        {
            return base;
        }

        // calculate
        //   a^n (a > 0, n >=2 & n is an integer)
        // = a^(n/2) * a^(n/2) when n is a even number
        // = a^(n/2) * a^(n/2) * a when n is an odd number
        double result = calculateUnsignedPower(base, exp >> 1);
        result *= result;
        if (exp & 1)
        {
            result *= base;
        }

        return result;
    }

public:
    double Power(double base, int exp) 
    {
        // invalid input
        try {
            if (equaldouble(base, 0.0))
            {
                throw std::invalid_argument("base is 0!");
            } 
        }
        catch (const std::invalid_argument& expt)
        {
            return 0;
        }

        // calculate
        bool positive_exp = exp >= 0? true : false;       
        unsigned int expAbs = positive_exp ? exp : -exp;
        double result = calculateUnsignedPower(base, expAbs);

        // result
        if (!positive_exp)
        {
            result = 1.0 / result;
        }

        return result;
    }

    
};

std::vector<double> testpow()
{
    std::vector<double> r;
    Solution pow;
    // base = 0
    r.push_back(pow.Power(0, 10));
    // exp = 0
    r.push_back(pow.Power(10, 0));
    // base is negative
    r.push_back(pow.Power(-10, 4));
    // power is negative
    r.push_back(pow.Power(10, -2));

    return std::move(r);
    
}