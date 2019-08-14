
// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点。
//

#include <cstdio>
#include "../Utilities/List.h"

int deleteNode(ListNode **head, ListNode *to_delete) {
    if (head == nullptr || to_delete == nullptr)
        return -1;
    
    // Fixed: bug for address out of bundry, there is only one node exist
    //        in list, the onde to be deleted. this should be adress 
    //
    if (*head == to_delete && to_delete->pNext == nullptr) {
        //printf("##debug in delete head\n");
        //printf("before delete head is: %d\n", (*head)->value);
        *head = (*head)->pNext;
        delete to_delete; 
        to_delete = nullptr;
        //printf("after delete head is %d \n", (*head)->value);
    }
    
    ListNode *curr = *head;
    if (to_delete->pNext == nullptr)  {
        while(curr->pNext != to_delete) 
            curr = curr->pNext;
        curr->pNext = nullptr;
        delete to_delete;
        to_delete = nullptr;
    }
    else {
        to_delete->value = to_delete->pNext->value;
        curr = to_delete->pNext;
        to_delete->pNext = to_delete->pNext->pNext;
        delete curr;
        curr = nullptr;
    }

    return 0;
}

//=========================================================================
//      Test 
//=========================================================================

void Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    printList(pListHead);

    printf("The node to be deleted is: \n");
    printListNode(pNode);

    deleteNode(&pListHead, pNode);
    
    printf("The result list is: \n");
    printList(pListHead);
}

// 链表中有多个结点，删除中间的结点
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

    Test(pNode1, pNode3);

    destroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
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

    Test(pNode1, pNode5);

    destroyList(pNode1);
}

// 链表中有多个结点，删除头结点
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

    Test(pNode1, pNode1);

    destroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
    ListNode* pNode1 = createListNode(1);

    Test(pNode1, pNode1);
}

// 链表为空
void Test5()
{
    Test(nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    //Test4();
    Test5();

    return 0;
}
