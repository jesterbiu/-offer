#include "list.hpp"

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	// invalid input
	if (pHead1 == nullptr)
	{
		return pHead2;
	}
	if (pHead2 == nullptr)
	{
		return pHead1;
	}

	// merge
	// the head node of the merge list
	ListNode* mergedHead = nullptr;
	if (pHead1->m_nValue > pHead2->m_nValue)
	{
		mergedHead = pHead2;
		pHead2 = pHead2->m_pNext;// remember to step forward
	}
	else
	{
		mergedHead = pHead1;
		pHead1 = pHead1->m_pNext;// remember to step forward
	}
	ListNode* mergedPtr = mergedHead;
	// merge
	while (pHead1 != nullptr && pHead2 != nullptr)
	{
		if (pHead1->m_nValue > pHead2->m_nValue)
		{
			mergedPtr->m_pNext = pHead2;			
			pHead2 = pHead2->m_pNext;
		}
		else
		{
			mergedPtr->m_pNext = pHead1;
			pHead1 = pHead1->m_pNext;
		}
		mergedPtr = mergedPtr->m_pNext;
	}

	// connect the rest
	if (pHead1 != nullptr)
	{
		mergedPtr->m_pNext = pHead1;
	}
	if (pHead2 != nullptr)
	{
		mergedPtr->m_pNext = pHead2;
	}
	
	return mergedHead;
}

ListNode* Test(const char* testName, ListNode* pHead1, ListNode* pHead2)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintList(pHead1);

    printf("The second list is:\n");
    PrintList(pHead2);

    printf("The merged list is:\n");
    ListNode* pMergedHead = Merge(pHead1, pHead2);
    PrintList(pMergedHead);

    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// �������������ظ�������
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(5);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// ��������ֻ��һ������
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// һ������Ϊ������
// list1: 1->3->5
// list2: ������
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pMergedHead = Test("Test4", pNode1, nullptr);

    DestroyList(pMergedHead);
}

// ��������Ϊ������
// list1: ������
// list2: ������
void Test5()
{
    ListNode* pMergedHead = Test("Test5", nullptr, nullptr);
}
