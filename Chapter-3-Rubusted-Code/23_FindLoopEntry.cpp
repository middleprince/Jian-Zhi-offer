// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。


//思路：利用快慢指针来找循环。
// 1. 找到相遇的节点 node_meet，这就一定表示有循环。
// 2. 通过 node_meet 开始找出循环链条的长度 n_loop。
// 3. 同样双指针，fast 先走n_loop，slow开始， 直到fast 与 slow相遇。
//
// 注意：
//  1. 循环链 < 总长的链条。
//  2. 入口在头结点的情况。
//  3. 没有循环的链条。
//  4. 空链。

#include <cstdio>
#include "../Utilities/List.h"

ListNode *findMeetingNode(ListNode *);
ListNode *findLoopEntry(ListNode *head) {
    
    if (head == nullptr)
        return nullptr;
    
    // list no loop 
    ListNode *node_meet = findMeetingNode(head);
    if (node_meet == nullptr)
        return nullptr;

    // calculate loop length
    int n = 1;
    ListNode *node_meet_cp = node_meet;
    node_meet = node_meet->pNext;
    while (node_meet != node_meet_cp) {
        node_meet = node_meet->pNext;
        ++n;
    }

    // find the entry
    ListNode *fast = head;
    ListNode *slow = head;
    
    while (n--) 
        fast = fast->pNext;
    
    while(fast != slow) {
        fast = fast->pNext; 
        slow = slow->pNext;
    }
        
    return slow;
 
}

ListNode *findMeetingNode(ListNode *head) {
    if (head == nullptr)
        return nullptr;
    
    // only one node exist
    ListNode *slow = head->pNext;
    if (slow == nullptr)
        return nullptr; 
    
    ListNode *fast = slow->pNext;
    while (fast != nullptr && slow != nullptr) {
        if (fast == slow) 
            return fast;
        slow = slow->pNext;
        fast = fast->pNext;
        // for there is no loop in list 
        if (fast != nullptr)
            fast = fast->pNext;
        //else break;
    } 
    
    return nullptr;
}

//=============================================================================
//      Test
//=============================================================================


void testInfo(const char* testName, ListNode* pHead, ListNode* entryNode)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(findLoopEntry(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = createListNode(1);

    testInfo("Test1", pNode1, nullptr);

    destroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = createListNode(1);
    connectListNode(pNode1, pNode1);

    testInfo("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test3()
{
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNode(pNode1, pNode2);
    connectListNode(pNode2, pNode3);
    connectListNode(pNode3, pNode4);
    connectListNode(pNode4, pNode5);
    connectListNode(pNode5, pNode3);

    testInfo("Test3", pNode1, pNode3);

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
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNode(pNode1, pNode2);
    connectListNode(pNode2, pNode3);
    connectListNode(pNode3, pNode4);
    connectListNode(pNode4, pNode5);
    connectListNode(pNode5, pNode1);

    testInfo("Test4", pNode1, pNode1);

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
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNode(pNode1, pNode2);
    connectListNode(pNode2, pNode3);
    connectListNode(pNode3, pNode4);
    connectListNode(pNode4, pNode5);
    connectListNode(pNode5, pNode5);

    testInfo("Test5", pNode1, pNode5);

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
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNode(pNode1, pNode2);
    connectListNode(pNode2, pNode3);
    connectListNode(pNode3, pNode4);
    connectListNode(pNode4, pNode5);

    testInfo("Test6", pNode1, nullptr);

    destroyList(pNode1);
}

// Empty list
void Test7()
{
    testInfo("Test7", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
