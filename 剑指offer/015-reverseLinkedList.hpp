#pragma once
#include "list.hpp"

ListNode* ReverseList(ListNode* pHead) 
{
	// validate input
	if (nullptr == pHead
		|| nullptr == pHead->m_pNext)
	{
		return pHead;
	}

	// prep for reverse
    ListNode* reversed = nullptr,
        * unreversed = pHead;		

	// reverse
	while (nullptr != unreversed)
	{
        ListNode *next = unreversed->m_pNext;
        unreversed->m_pNext = reversed;
        reversed = unreversed;
        unreversed = next;
	}

	return reversed;
}

// ====================测试代码====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
    Test(nullptr);
}

void test()
{
    Test1();
    Test2();
    Test3();

}
