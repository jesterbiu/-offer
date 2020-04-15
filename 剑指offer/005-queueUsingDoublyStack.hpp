#include <stack>
#include <stdexcept>
class Solution
{
public:
    void push(int node) {
        in.push(node);
    }

    int pop() 
    {             
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        if (out.empty())
        {
            throw new std::exception("empty queue!");
        }
        int topElement = out.top();
        out.pop();
        return topElement;
    }

private:
    std::stack<int> in;
    std::stack<int> out;
};