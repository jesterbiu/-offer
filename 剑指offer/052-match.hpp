//´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ´íÔÚÄÄ
//????????

#pragma once
#include <iostream>
#include <vector>

class Solution {
public:  
    bool match(char* str, char* pattern)
    {
        // validate input
        if (nullptr == str || nullptr == pattern)
        {
            return false;
        }

        return coreMatch(str, pattern);

    }

    bool coreMatch(char* str, char* pattern)
    {
        if (*str == '\0' && *pattern == '\0')
        {
            return true;
        }
        if (*str != '\0' && *pattern == '\0')
        {
            return false;
        }

        if (pattern[1] == '*')
        {
            if (*pattern == *str || (*pattern == '.' && *str != '\0'))
            {
                return coreMatch(str + 1, pattern + 2)  // match once
                    || coreMatch(str, pattern + 2)      // ignore *
                    || coreMatch(str + 1, pattern); // repeatedly match 
            }
            else
            {
                return coreMatch(str, pattern + 2);
            }
        }

        if (*pattern == *str || (*pattern == '.' && *str != '\0'))
        {
            return coreMatch(str + 1, pattern + 1);
        }

        return false;
    }

};

void test_match(){
    
    auto matchingResult = [](Solution& s, char* str, char* pattern)
    {
        if (s.match(str, pattern))
            std::cout << str << "\tmatched\t\t" << pattern << std::endl;
        else
            std::cout << str << "\tunmatched\t" << pattern << std::endl;
    };

    char pattern0[] = "a.a";
    char pattern1[] = "a*b";
    char pattern2[] = "b*a.";
    std::vector<char*> patterns;
    patterns.push_back(pattern0);
    patterns.push_back(pattern1);
    patterns.push_back(pattern2);
    
    char str0[] = "aaa";
    char str1[] = "aab";
    char str2[] = "ac";
    char str3[] = "bbba1";
    std::vector<char*> strs;
    strs.push_back(str0);
    strs.push_back(str1);
    strs.push_back(str2);
    strs.push_back(str3);

    Solution s;
    //"",".*"
    char str4[] = ",", pattern3[] = ".*";
    s.match(str4, pattern3);
    for (auto pattern : patterns)
    {
        for (auto str : strs)
        {
            matchingResult(s, str, pattern);
        }
    }


}

/*
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        // validate input
        if (nullptr == str || nullptr == pattern)
        {
            return false;
        }

        // check boundary
        if (*str == '\0' && *pattern != '\0')
        {
            return false;
        }
        if (*str == '\0' && *pattern == '\0')
        {
            return true;
        }
        if (*str != '\0' && *pattern == '\0')
        {
            return false;
        }

        // matching
        // check repeat
        bool repeatition = pattern[1] == '*' ? true : false;
        bool wildcard = pattern[0] == '.' ? true : false;

        // deal with wild card
        if (repeatition)
        {
            if (wildcard || *str == *pattern)
            {
                return match(str + 1, pattern + 2)  // repeat once
                    || match(str, pattern + 2)      // ignore repeatition
                    || match(str + 1, pattern);         // repeat more than once
            }
            else // !wildcard
            {
                return  match(str, pattern + 2);        // ignore repeatition
            }
        }
        else // !repetition
        {
            if (wildcard || *str == *pattern)
            {
                return match(str + 1, pattern + 1);
            }
            else
            {
                return false;
            }
        }
    }
};
*/