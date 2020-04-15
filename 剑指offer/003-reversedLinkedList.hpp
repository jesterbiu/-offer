#include <vector>
#include <stack>
/* a straight forward solution
        std::vector<int> result;
        while (nullptr != head)
        {
            result.insert(result.begin(),head->val);
            head = head->next;
        }
        return result;
*/
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(nullptr) {}
};

class Solution {
public:
    std::vector<int> printListFromTailToHead(ListNode* head)
    {
        // push stack
        std::stack<int> _stack;
        while (nullptr != head)
        {
            _stack.push(head->val);
            head = head->next;
        }

        // pop
        std::vector<int> result;
        while (!_stack.empty())
        {
            result.push_back(_stack.top());
            _stack.pop();
        }
        return std::move(result);
    }
};