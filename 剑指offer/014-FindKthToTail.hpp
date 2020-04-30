#include "ListNode.hpp"

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	// validate input
	if (pListHead == nullptr || k < 1)
	{
		return nullptr;
	}

	ListNode *pKth = pListHead, *pTail = pListHead;
	
	// pTaol advance k-1 steps
	unsigned i = 1;
	while (pTail->next != nullptr && i < k)
	{
		pTail = pTail->next;
		i++;
	}

	// if there is less than k nodes in the list
	if (i < k)
	{
		return nullptr;
	}

	// advance pKth and pTail to the tail of the list
	while (pTail->next != nullptr)
	{
		pKth = pKth->next;
		pTail = pTail->next;
	}

	return pKth;

}