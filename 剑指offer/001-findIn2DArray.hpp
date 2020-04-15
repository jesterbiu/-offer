//牛客网有问题
#include <vector>
class Solution {
public:
    bool Find(int target, std::vector<std::vector<int> >& array) {
        //validate array
        if (array.empty())
        {
            return false;
        }

        size_t i = 0, j = array.begin()->size() - 1;
        while (i < array.size() && j >= 0)
        {
            if (target == array[i][j])
            {
                return true;
            }
            else if (target < array[i][j])
            {
                j--;
            }
            else //target > array[i][j])
            {
                i++;
                if (array.begin()->size() < j + 1)
                {
                    return false;
                }
            }
        }

        return false;
    } // end of find
};