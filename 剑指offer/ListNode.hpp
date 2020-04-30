#pragma once
#include <vector>
#include <iostream>
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

ListNode* generateList(const std::vector<int>& arr)
{
	if (arr.empty())
	{
		return nullptr;
	}

	auto iterArr = arr.begin();
	ListNode* pHead = new ListNode(*iterArr);
	ListNode* pNode = pHead;
	while (++iterArr != arr.end())
	{
		pNode->next = new ListNode(*iterArr);
		pNode = pNode->next;
	}

	return pHead;
}

void deleteList(ListNode* pHead)
{
	if (nullptr == pHead)
	{
		return;
	}

	auto pDel = pHead, pNext = pHead->next;
	while (true)
	{
		delete pDel;
		if (pNext == nullptr)
		{
			break;
		}
		pDel = pNext;
		pNext = pNext->next;
	}
}

void printList(ListNode* pHead)
{
	while (pHead != nullptr)
	{
		std::cout << pHead->val << " ";
		pHead = pHead->next;
	}
	std::cout << std::endl;
}