#include <cstring>
class Solution {

	// a replacement for the space
	const char *replaceStr = "%20";

	// after replacement,  pos past the last inserted char
	void reversedReplace(char** pos)
	{
		int replacementLength = std::strlen(replaceStr);
		char* tempPos = *pos;
		for (int i = replacementLength - 1; i >= 0; i--, tempPos--)
		{
			*tempPos = replaceStr[i];
		}
		*pos = tempPos;
	}

public:
	void replaceSpace(char* str, int length) {
		// validate input
		if (nullptr == str || length <= 1)
		{
			return;
		}
		
		// count the number of spaces and chars
		int spaceCount = 0, originalLength = 0;
		for (int i = 0; i < length; i++)
		{
			if ('\0' == str[i])
			{
				originalLength = i;
				break;
			}
			else if (' ' == str[i])
			{
				spaceCount++;
			}
			else
			{
			}
		}
		if (spaceCount == 0)
		{
			return;
		}

		// create new length and check string boundary
		int replacementLength = std::strlen(replaceStr);
		int newLength = originalLength + (replacementLength - 1) * spaceCount;
		if (newLength >= length)
		{
			return;
		}
		
		// replace
		char * pstr1 = str + originalLength, 
			* pstr2 = str + newLength;
		while (pstr1 >= str && pstr1 != pstr2)
		{
			if (*pstr1 != ' ')
			{
				*pstr2 = *pstr1;
				pstr1--; 
				pstr2--;
			}
			else
			{
				reversedReplace(&pstr2);
				pstr1--;
			}
		}
		 
	}
};