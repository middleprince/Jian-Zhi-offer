// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。
//

// 思路：使用多个指针记录前后的信息，遍历修改链接，直到遍历完整个链表。
//
// 注意：1. 空链表
//       2. 防止链表断裂
//       3. 只有一个节点的链表。
//       

#include <cstdio>
#include "../Utilities/List.h"

ListNode *reverseList(ListNode *head) {
    ListNode *reverse_head = nullptr; 
    ListNode *pre = nullptr;
    ListNode *curr = head;

    while (curr != nullptr) {
        ListNode *next = curr->pNext; 
        
        if (next == nullptr)
            reverse_head = curr;
        curr->pNext = pre;
        
        pre = curr;
        curr = next;
    }
    return reverse_head;
}

// TODO 
// reverse list recursingly
//ListNode *reverseListV2(ListNode *head) {
//    
//}

//=============================================================================
//          Test
//=============================================================================

ListNode* Test(ListNode* pHead)
{
    printf("=== The original list is: \n");
    printList(pHead);

    ListNode* pReversedHead = reverseList(pHead);

    printf("=== The reversed list is: \n");
    printList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
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

    ListNode* pReversedHead = Test(pNode1);

    destroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
    ListNode* pNode1 = createListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    destroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
