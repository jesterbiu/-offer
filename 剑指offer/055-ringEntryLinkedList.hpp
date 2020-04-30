#include "list.hpp"

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	// validate input
	if (pHead == nullptr)
	{
		return nullptr;
	}

	// determine if the list has a loop
	// using a fast poniter and a slow one
	// a loop exists if the fast pointer catches up with the slow one
	ListNode* pSlow = pHead, * pFast = pHead->m_pNext;
	while (pFast != nullptr && pSlow != pFast)
	{
		// pFast move two steps at a time
		for (int i = 0; i < 2 && pFast != nullptr; i++)
		{
			pFast = pFast->m_pNext;
		}	
		// pSlow move one step at the time
		pSlow = pSlow->m_pNext;
	}
	
    // there is no loop if the list ends
    // return null
    if (pFast == nullptr)
    {
        return nullptr;
    }

	// if the fast catches up with the slow one
	// they must be at a node in the loop
	// travese the loop again to determine how many steps pointers have taken
	unsigned loopCounts = 0;
	do
	{
		pSlow = pSlow->m_pNext;
		loopCounts++;
	} while (pSlow != pFast);
	
	// start from pHead
	// pFast takes loopCounts steps first
	// then pSlow and pFast move at the same speed
	// pFast will meet pSlow at the entry of the loop (pFast just finish the loop
	pSlow = pHead;
	pFast = pHead;
	for (int i = 0; i < loopCounts; i++)
	{
		pFast = pFast->m_pNext;
	}
	while (pSlow != pFast)
	{
		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
	}
	return pSlow;
}

void Test(const char* testName, ListNode* pHead, ListNode* entryNode)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);

    Test("Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test3()
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
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test4()
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
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test5()
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
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop 
void Test6()
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

    Test("Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", nullptr, nullptr);
}
