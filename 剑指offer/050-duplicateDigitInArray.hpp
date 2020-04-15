#include <algorithm>
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        // validate input array
        if (nullptr == numbers || length <= 0)
        {
            return false;
        }

        for (int i = 0; i < length; i++)
        {
            // check if numbers[i] is within the range of [0, length - 1]
            if (0 >= numbers[i] || numbers[i] >= length)
            {
                return false;
            }

            // while disordered
            while (numbers[i] != i)
            {
                int key = numbers[i];
                if (numbers[key] == numbers[i])
                {
                    *duplication = key;
                    return true;
                }
                std::swap(numbers[key], numbers[i]);
            }           
        }
        return false;
    }
};