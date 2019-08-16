// 题目22.2 
// 在一个链表中找到它的中间节点。 如果总的节点数目是奇数则返回中间节点；
// 如果数目是偶数则返回中间两节点的任意一个。
//
// 思路：使用快慢指针来，快指针fast 每次两步，慢指针每次一步，
// 快指针遍历到链表末尾，慢指针到中间节点。
// 
// 1.正常的情况
// 2.只有一个节点
// 3.头指针nullptr
//

#include <cstdio>
#include "../Utilities/List.h"

ListNode *findMiddleNode(ListNode *head) {
    if (head == nullptr)
        return nullptr;
    
    if (head->pNext == nullptr)
        return head;

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast->pNext != nullptr) {
        fast = fast->pNext; 
        if (fast->pNext != nullptr)
            fast = fast->pNext;
        slow = slow->pNext;
    }
    return slow;
}

//=============================================================================
//          Test 
//=============================================================================

void testInfo(const char *msg, ListNode *head, ListNode *expcted) {
    printf("==Test for %s ==\n", msg);
    ListNode *middle = findMiddleNode(head);
    if (middle == expcted)
        printf("PASS\n");
    else if (middle->value == expcted->value) 
        printf("PASS\n");
    else
        printf("FAILED\n");
}

// 正常的奇数节点
void Test1()
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
    
    ListNode *middle = createListNode(3);
    testInfo("Test1() normal list has 5 nodes", pNode1, middle); 
    
    destroyList(middle);
    destroyList(pNode1);
}

// 测试正常的偶数节点
void Test2()
{
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);

    connectListNode(pNode1, pNode2);
    connectListNode(pNode2, pNode3);
    connectListNode(pNode3, pNode4);

    
    ListNode *middle = createListNode(3);
    testInfo("Test()2 normal list 4 nodes", pNode1, middle); 
    
    destroyList(middle);
    destroyList(pNode1);
}

// 测试只有一个头结点
void Test3()
{
    ListNode* pNode1 = createListNode(1);

    ListNode *middle = createListNode(1);
    
    testInfo("Test()3 normal list has 1 nodes", pNode1, middle); 
    destroyList(middle);
    destroyList(pNode1);
}

// 测试空链表
void Test4()
{
    testInfo("Test()4 void list", nullptr, nullptr); 
}



int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
