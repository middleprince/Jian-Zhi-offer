// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。
//

// 思路： 双指针扫描两链表，比较链接。
//        使用递归的设计来实现比较。
// 1. 存在空链表。

#include <cstdio>
#include "../Utilities/List.h"

ListNode *combineListV1(ListNode *list1_head, ListNode *list2_head) {
    ListNode *p1 = list1_head ;
    ListNode *p2 = list2_head;
    ListNode *new_head = nullptr; 
    ListNode *temp = nullptr; 
    ListNode *p1_pre = nullptr; 
    ListNode *p2_pre = nullptr; 
    bool first = true;

    if (p1 != nullptr && p2 == nullptr)
        return p2;
    if (p1 == nullptr && p2 != nullptr)
        return p1;
    if (p1 == nullptr && p2 == nullptr)
        return nullptr;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->value < p2->value ) {
            if (first)
                new_head = p1;

            if (p1->pNext != nullptr && p1->pNext->value < p2->value) {
                p1 = p1->pNext;
                continue;
            }
            // TOFIX: bug can't connect list corecctly
            temp = p1->pNext;
            p1->pNext = p2;
            
            p1_pre = p2;
            p2 = p2->pNext;

            p1_pre->pNext = temp; 
            p1 = temp;
        }
        else {
            if (first)
                new_head = p1;

            if (p1->value >= p2->value) {
                p2 = p2->pNext; 
                continue;
            } 
            temp = p2->pNext;
            p2->pNext = p1;
            p2_pre = p1;
            p2 = temp;
            p1 = p1->pNext;
            p2_pre->pNext = p2;

        }
            
    }

    if (p1 == nullptr && p2!= nullptr)
        p1_pre->pNext = p2;
    if (p1 != nullptr && p2== nullptr)
        p2_pre->pNext = p1;
    
    return new_head;
}


ListNode *combineListV2(ListNode *list1_head, ListNode *list2_head) {
    if (list1_head == nullptr)     
        return list2_head;
    if (list2_head == nullptr)     
        return list2_head;

    ListNode *new_head = nullptr;

    if (list1_head->value < list2_head->value) {
        new_head = list1_head; 
        new_head->pNext = combineListV2(list1_head->pNext, list2_head);
    }
    else {
        new_head = list2_head; 
        new_head->pNext = combineListV2(list1_head, list2_head->pNext);
    }
    return new_head;
} 



//=============================================================================
//          Test 
//=============================================================================
//

ListNode* testInfo(const char* testName, ListNode* pHead1, ListNode* pHead2)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    printList(pHead1);

    printf("The second list is:\n");
    printList(pHead2);

    printf("The merged list is:\n");
    ListNode* pMergedHead = combineListV1(pHead1, pHead2);
    printList(pMergedHead);
    
    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode5 = createListNode(5);

    connectListNode(pNode1, pNode3);
    connectListNode(pNode3, pNode5);

    ListNode* pNode2 = createListNode(2);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode6 = createListNode(6);

    connectListNode(pNode2, pNode4);
    connectListNode(pNode4, pNode6);

    ListNode* pMergedHead = testInfo("Test1", pNode1, pNode2);

    destroyList(pMergedHead);
}

// 两个链表中有重复的数字
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode5 = createListNode(5);

    connectListNode(pNode1, pNode3);
    connectListNode(pNode3, pNode5);

    ListNode* pNode2 = createListNode(1);
    ListNode* pNode4 = createListNode(3);
    ListNode* pNode6 = createListNode(5);

    connectListNode(pNode2, pNode4);
    connectListNode(pNode4, pNode6);

    ListNode* pMergedHead = testInfo("Test2", pNode1, pNode2);

    destroyList(pMergedHead);
}

// 两个链表都只有一个数字
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);

    ListNode* pMergedHead = testInfo("Test3", pNode1, pNode2);

    destroyList(pMergedHead);
}

// 一个链表为空链表
// list1: 1->3->5
// list2: 空链表
void Test4()
{
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode5 = createListNode(5);

    connectListNode(pNode1, pNode3);
    connectListNode(pNode3, pNode5);

    ListNode* pMergedHead = testInfo("Test4", pNode1, nullptr);

    destroyList(pMergedHead);
}

// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void Test5()
{
    ListNode* pMergedHead = testInfo("Test5", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
