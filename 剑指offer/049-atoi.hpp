
#pragma once
#include <stack>
#include <string>
#include <limits>
#include <stdexcept>
class Solution {
public:
    
    int StrToInt(const std::string& str) {
        // return 0 if illegal?
        // validate input
        try
        {
            if (str.empty())
            {
                throw std::invalid_argument("empty string!");                
            }
        }
        catch (std::invalid_argument& invalid_arg)
        {
            return 0;
        }
         

        // skip space
        size_t pos = str.find_first_not_of(' ');
        // if fail to convert
        try
        {
            if (str.npos == pos)
            {
                throw std::invalid_argument("string has only spaces!");
                
            }
        }
        catch (std::invalid_argument& invalid_arg)
        {
            return 0;
        }
        
       
        // determine sign       
        bool positive;
        char start_ch = str[pos];
        auto is_digit = 
            [](char ch)
            {
                if ('0' <= ch && ch <= '9') return true;
                else return false; 
            };

        try
        {
            if ('+' == start_ch || is_digit(start_ch))
            {
                positive = true;
                if ('+' == start_ch)
                {
                    pos++;
                }
            }
            else if ('-' == start_ch)
            {
                positive = false;
                pos++;
            }
            else
            {
                // fail to convert if detects other characters
                throw std::invalid_argument("string is not digit!");            
            }
        }
        catch (std::invalid_argument& invalid_arg)
        {
            return 0;
        }
        

        // store every digits
        std::stack<char> digits;
        while (pos < str.size())
        {
            if (!is_digit(str[pos]))
            {
                return 0;
            }

            digits.push(str[pos]);
            pos++;
        }

        // transform
        unsigned int base = 1, result = 0, 
            int_max = INT_MAX, int_min = -INT_MIN;       
        while (!digits.empty())
        {
            int digit = digits.top() - '0';           
            result += digit * base;

            // check overflow / underflow
            try
            {
                if (positive && result > int_max)
                {
                    throw std::overflow_error("overflow!");
                    
                }
                if (!positive && result > int_min)
                {
                    throw std::overflow_error("overflow!");

                }
            }
            catch (std::overflow_error& overflow_err)
            {
                return 0;
            }

            digits.pop();
            base *= 10;
        }

        // check sign
        int _result = result;
        if (!positive)
        {
            _result = -_result;
        }
        return _result;
    }
};
