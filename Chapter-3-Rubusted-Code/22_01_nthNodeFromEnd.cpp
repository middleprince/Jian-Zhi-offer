// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。
//

// 分析：双指针遍历问题
// 比较典型链表定位，利用长度关系配合双指针在 o(n) 时间内找到节点。
// 注意事项：空链表
//           链表长度小于k
//          
// prt p1, p2; 保持 k-1 距离同步运动，知道back遍历到尾节点。

#include <cstdio>
#include "../Utilities/List.h"

ListNode *findNodeFromEnd(ListNode *head, int k) {
    if (head == nullptr || k <= 0)
        return nullptr;

    ListNode *p1 = head;
    ListNode *p2 = nullptr;
    
    for (int i = 0; i < k-1; ++i) {
        // k 大于链表的长度
        if (p1->pNext != nullptr)
            p1 = p1->pNext;
        else
            return nullptr;
    }
    
    {
        p2 = head; 
        while (p1->pNext != nullptr) {
            p2 = p2->pNext;
            p1 = p1->pNext;
        } 
    }
    return p2;    
}

//==============================================================================
//          Test
//==============================================================================


void Test1()
{
    printf("=====Test1 starts:=====\n");
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNode(pNode1, pNode2);
    connectListNode(pNode2, pNode3);
    connectListNode(pNode3, pNode4);
    connectListNode(pNode4, pNode5);

    printf("expected result: 4.\n");
    ListNode* pNode = findNodeFromEnd(pNode1, 2);
    printListNode(pNode);

    destroyList(pNode1);
}

// 测试要找的结点是链表的尾结点
void Test2()
{
    printf("=====Test2 starts:=====\n");
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNode(pNode1, pNode2);
    connectListNode(pNode2, pNode3);
    connectListNode(pNode3, pNode4);
    connectListNode(pNode4, pNode5);

    printf("expected result: 5.\n");
    ListNode* pNode = findNodeFromEnd(pNode1, 1);
    printListNode(pNode);

    destroyList(pNode1);
}

// 测试要找的结点是链表的头结点
void Test3()
{
    printf("=====Test3 starts:=====\n");
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNode(pNode1, pNode2);
    connectListNode(pNode2, pNode3);
    connectListNode(pNode3, pNode4);
    connectListNode(pNode4, pNode5);

    printf("expected result: 1.\n");
    ListNode* pNode = findNodeFromEnd(pNode1, 5);
    printListNode(pNode);

    destroyList(pNode1);
}

// 测试空链表
void Test4()
{
    printf("=====Test4 starts:=====\n");
    printf("expected result: nullptr.\n");
    ListNode* pNode = findNodeFromEnd(nullptr, 100);
    printListNode(pNode);
}

// 测试输入的第二个参数大于链表的结点总数
void Test5()
{
    printf("=====Test5 starts:=====\n");
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNode(pNode1, pNode2);
    connectListNode(pNode2, pNode3);
    connectListNode(pNode3, pNode4);
    connectListNode(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode* pNode = findNodeFromEnd(pNode1, 6);
    printListNode(pNode);

    destroyList(pNode1);
}

// 测试输入的第二个参数为0
void Test6()
{
    printf("=====Test6 starts:=====\n");
    ListNode* pNode1 = createListNode(1);
    ListNode* pNode2 = createListNode(2);
    ListNode* pNode3 = createListNode(3);
    ListNode* pNode4 = createListNode(4);
    ListNode* pNode5 = createListNode(5);

    connectListNode(pNode1, pNode2);
    connectListNode(pNode2, pNode3);
    connectListNode(pNode3, pNode4);
    connectListNode(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode* pNode = findNodeFromEnd(pNode1, 0);
    printListNode(pNode);

    destroyList(pNode1);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
