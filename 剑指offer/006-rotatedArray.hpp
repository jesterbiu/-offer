#include <vector>
#include <limits>
class Solution {
public:
    int minNumberInRotateArray(const std::vector<int>& rotatedArray) {
        if (rotatedArray.empty())
        {
            return std::numeric_limits<int>::lowest();
        }
        if (rotatedArray.size() == 1)
        {
            return *(rotatedArray.begin());
        }
        if (rotatedArray.size() == 2)
        {
            return rotatedArray[0] <= rotatedArray[1] ? rotatedArray[0] : rotatedArray[1];
        }
               

        int left = 0, right = rotatedArray.size() - 1;
        if (rotatedArray[left] < rotatedArray[right])
        {
            return rotatedArray[left];
        }
        while (left + 1 != right)
        {
            int mid = left + (right - left) / 2;
            // mid is within the rotated part
            // min is right to mid
            if (rotatedArray[mid] >= rotatedArray[left])
            {
                left = mid;
                continue;
            }
            // mid is within the not-rotated part
            // min is left to mid
            if (rotatedArray[mid] <= rotatedArray[right])
            {
                right = mid;
                continue;
            }
        }
        return rotatedArray[right];
        
    }
};