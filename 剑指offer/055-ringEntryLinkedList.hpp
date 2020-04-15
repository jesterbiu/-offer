#include <map>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (nullptr == pHead)
        {
            return nullptr;
        }
        else
        {
            exploredNodes[pHead]++;
            if (exploredNodes[pHead] > 1)
            {
                return pHead;
            }
            else
            {
                EntryNodeOfLoop(pHead->next);
            }            
        }
    }
private:
    std::map<ListNode*, int> exploredNodes;
};