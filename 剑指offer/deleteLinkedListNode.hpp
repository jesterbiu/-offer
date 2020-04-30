#include "ListNode.hpp"

void deleteTail(ListNode* pHead)
{
	auto pNewTail = pHead, pTail = pHead->next;
	while (pTail->next != nullptr)
	{
		pNewTail = pTail;
		pTail = pTail->next;
	}
	pNewTail->next = nullptr;
	delete pTail;
}

void deleteLinkedListNode(ListNode** pHead, ListNode* pToDel)
{
	// validate input
	if (nullptr == *pHead || nullptr == pToDel)
	{
		return;
	}

	// 
	// pToDel is not tail
	if (nullptr != pToDel->next)
	{
		auto ptrDel = pToDel->next;
		pToDel->val = ptrDel->val;
		pToDel->next = ptrDel->next;
		delete ptrDel;
	}
	// pToDel is tail but not head
	else if (pToDel != *pHead && nullptr == pToDel->next)
	{
		deleteTail(*pHead);
	}
	// pToDel is tail and head
	else if (pToDel == *pHead && nullptr == pToDel->next)
	{
		delete pToDel;
		*pHead = nullptr;
	}
	else
	{
		// nothing
	}

	return;
}



void test_deleteLinkedListNode()
{
	std::vector<int> arr1 = { 1 };
	auto pHead1 = generateList(arr1);
	printList(pHead1);
	deleteLinkedListNode(&pHead1, pHead1);
	printList(pHead1);
	deleteList(pHead1);

}