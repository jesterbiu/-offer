
#pragma once
#include <stack>
#include <string>
#include <limits>
#include <stdexcept>
class Solution {
public:
    
    // return the pos of the first not-space character
    inline size_t SkipSpace(const std::string& str)
    {
        return  str.find_first_not_of(' ');
    }

    inline bool is_digit(char ch)
    {
        return ('0' <= ch && ch <= '9');
    }

    // check sign of the string starts at str[pos] and move the pos past the sign
    // return true if positive
    // throw invalid_argument if the str[pos] is not any of digit, '-' or '+'
    bool GetSign(const std::string& str, size_t& pos)
    {
        bool positive = true;
        char start_ch = str[pos];
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
            throw std::invalid_argument("string is not digit!");
        }
        return positive;
    }

    // get as many as possible digits starts from str[pos]
    // store them in digits
    void GetDigits(const std::string& str, size_t pos, std::stack<char>& digits)
    {
        while (pos < str.size())
        {
            if (!is_digit(str[pos]))
            {
                break;
            }

            digits.push(str[pos]);
            pos++;
        }
    }

    // transform a string of characters stores in digits to an unsigned
    // return the transformed unsigned
    int TransformStrToInt(std::stack<char>& digits, bool positive)
    {
        unsigned int base = 1, result = 0,
            int_max = INT_MAX, int_min_abs = -INT_MIN;

        while (!digits.empty())
        {
            int digit = digits.top() - '0';
            result += digit * base;

            // check overflow           
            if (positive && result > int_max)
            {
                throw std::overflow_error("overflow!");

            }
            if (!positive && result > int_min_abs)
            {
                throw std::overflow_error("overflow!");
            }           
           
            digits.pop();
            base *= 10;
        }

        // check sign
        int signed_result = result;
        if (!positive)
        {
            signed_result = -signed_result;
        }

        return result;
    }
       
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
        size_t pos = SkipSpace(str);
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
        try
        {
            positive = GetSign (str, pos);
        }
        catch (std::invalid_argument& invalid_arg)
        {
            return 0;
        }
        

        // store every digits
        std::stack<char> digits;
        GetDigits(str, pos, digits);

        // transform
        unsigned result = 0;
        try
        {
            result = TransformStrToInt(digits, positive);
        }
        catch (std::overflow_error& oferr)
        {
            return 0;
        }
        
        return result;
    }
};
