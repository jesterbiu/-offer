#pragma once
#include "ListNode.hpp"

class Solution {
public:
    // delete duplication string of nodes in [firstDup, next)
    // assign nextNonDup to lastNonDup->next
    void deleteDupString(ListNode* lastNonDup, ListNode* firstDup, ListNode* nextNonDup)
    {
        // validate input
        if (nullptr == firstDup
            || firstDup == nextNonDup)
        {
            return;
        }

        // assign nextNonDup to lastNonDup->next
        // if the duplication string does not start from head node
        if (nullptr != lastNonDup)
        {
            lastNonDup->next = nextNonDup;
        }

        // delete duplication string
        while (firstDup != nullptr
            && firstDup != nextNonDup)
        {
            auto pToDel = firstDup;
            firstDup = firstDup->next;
            delete pToDel;
        }

        return;
    }

    ListNode* deleteDuplication(ListNode* pHead)
    {
        // validate input
        if (nullptr == pHead || nullptr == pHead->next)
        {
            return pHead;
        }

        ListNode* updatedHead = pHead,  // update this ptr if the pHead deleted
            *pLastNotDup = nullptr,     // pointer to the last known non-duplication node
            *pFirstDup = pHead,         // pointer to traverse 
            *pNextNonDup = nullptr;           // pointer to the next non-duplication node

        // traverse the list
        while (pFirstDup != nullptr && pFirstDup->next != nullptr)
        {
            // move to the next if next node is not a duplication              
            if (pFirstDup->val != pFirstDup->next->val)
            {
                pLastNotDup = pFirstDup;
                pFirstDup = pFirstDup->next;                
            }
            // find the next non-duplication node
            else
            {
                pNextNonDup = pFirstDup->next;
                while (pNextNonDup != nullptr && pFirstDup->val == pNextNonDup->val)
                {
                    pNextNonDup = pNextNonDup->next;
                }            
                // if the head node is the start of duplication string
                // update head node
                if (pFirstDup == updatedHead)
                {
                    updatedHead = pNextNonDup;
                }
                deleteDupString(pLastNotDup, pFirstDup, pNextNonDup);
                pFirstDup = pNextNonDup;
            }
        }

        return updatedHead;
    }
    
    void test_deleteDuplication()
    {
        std::vector<std::vector<int> > arrs;
        std::vector<int> arr0 = { 5,5,5 };
        std::vector<int> arr1 = { 1, 2, 3, 3, 4, 4, 5 };
        std::vector<int> arr2 = { 1, 1, 1, 3, 4 };
        std::vector<int> arr3 = { 3,3,5,5,5 };
        arrs.push_back(arr0);
        arrs.push_back(arr1);
        arrs.push_back(arr2);
        arrs.push_back(arr3);
        for (auto arr : arrs)
        {
            auto phead = generateList(arr);
            std::cout << "before delete:\t";
            printList(phead);
            phead = deleteDuplication(phead);
            std::cout << "after delete:\t";
            printList(phead);
            deleteList(phead);
        }
    }
};