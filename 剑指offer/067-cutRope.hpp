#include <queue>
class Solution {
public:
    int cutRope(int number) 
    {
        // validate input
        if (number <= 1)
        {
            return number;
        }

        // notice that cutting makes greater product ONLY when the length of rope > 4; 
        // however the it requires the rope to te cut at least once,
        // thus cut when the length = original length.
        // to sum it up:
        // cut only when (length == original length) or (length > 4)
        // cutting until ropes lengths are under 5
        std::queue<int> cuts;
        cuts.push(number);
        int product = 1;
        while (!cuts.empty())
        {
            // dequeue
            int temp_cut = cuts.front();
            cuts.pop();

            if (temp_cut == number || temp_cut > 4)
            {               
                //cut
                int part0 = temp_cut / 2;
                int part1 = temp_cut - part0;
                cuts.push(part0);
                cuts.push(part1);               
            }
            else //temp_cut == number
            {
                product *= temp_cut;
            }
        }

        return product;
    }
};