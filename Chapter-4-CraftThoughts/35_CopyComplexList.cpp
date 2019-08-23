// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。
//
//


#include "35_ComplexList.h" 
#include <cstdio>

void makeListCopy(ComplexListNode *p_head);
void connectSibling(ComplexListNode *p_head);
ComplexListNode* splitList(ComplexListNode *p_head);

ComplexListNode* cloneList(ComplexListNode *p_head) {

    if (p_head == nullptr)
        return nullptr;
    makeListCopy(p_head);
    connectSibling(p_head);
    ComplexListNode *p_node_copy_head = splitList(p_head);
    
    return p_node_copy_head;
    
    
}
void makeListCopy(ComplexListNode *p_head) {
    if (p_head == nullptr) 
        return;
    ComplexListNode *p_node_copy = nullptr;
    ComplexListNode *p_node = p_head;
    while (p_node) {
        p_node_copy = createNode(p_node->value); 
        p_node_copy->p_next = p_node->p_next;
        p_node->p_next = p_node_copy;

        p_node = p_node_copy->p_next;
    } 
}

void connectSibling(ComplexListNode *p_head) {
    if (p_head == nullptr) 
        return;
    ComplexListNode *p_node = p_head;
    ComplexListNode *p_node_copy = p_node->p_next;

    while (p_node != nullptr) {
        if (p_node->p_sibling) 
            p_node_copy->p_sibling = p_node->p_sibling->p_next;
        p_node = p_node_copy->p_next;
        p_node_copy = p_node->p_next;
    }
}

ComplexListNode* splitList(ComplexListNode *p_head) {
    if (p_head == nullptr) 
        return nullptr;
    ComplexListNode *p_node = p_head;
    ComplexListNode *p_node_copy_head = p_node->p_next;
    ComplexListNode *p_node_copy = p_node->p_next;

    while (p_node) {
        p_node->p_next = p_node_copy->p_next; 
        p_node = p_node->p_next;
        p_node_copy->p_next = p_node->p_next; 

    }
    
    return p_node_copy_head;
}


//==============================================================================
//          Test
//==============================================================================

void Test(const char* testName, ComplexListNode* pHead)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    printList(pHead);

    //debug 
    makeListCopy(pHead);
    connectSibling(pHead);
    printf("### DEBUG  The cloned list is: \n");
    printList(pHead);

    ComplexListNode* p_node_copy_head = cloneList(pHead);

    printf("The cloned list is:\n");
    printList(p_node_copy_head);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode* pNode1 = createNode(1);
    ComplexListNode* pNode2 = createNode(2);
    ComplexListNode* pNode3 = createNode(3);
    ComplexListNode* pNode4 = createNode(4);
    ComplexListNode* pNode5 = createNode(5);

    connectNode(pNode1, pNode2, pNode3);
    connectNode(pNode2, pNode3, pNode5);
    connectNode(pNode3, pNode4, nullptr);
    connectNode(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode* pNode1 = createNode(1);
    ComplexListNode* pNode2 = createNode(2);
    ComplexListNode* pNode3 = createNode(3);
    ComplexListNode* pNode4 = createNode(4);
    ComplexListNode* pNode5 = createNode(5);

    connectNode(pNode1, pNode2, nullptr);
    connectNode(pNode2, pNode3, pNode5);
    connectNode(pNode3, pNode4, pNode3);
    connectNode(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|

void Test3()
{
    ComplexListNode* pNode1 = createNode(1);
    ComplexListNode* pNode2 = createNode(2);
    ComplexListNode* pNode3 = createNode(3);
    ComplexListNode* pNode4 = createNode(4);
    ComplexListNode* pNode5 = createNode(5);

    connectNode(pNode1, pNode2, nullptr);
    connectNode(pNode2, pNode3, pNode4);
    connectNode(pNode3, pNode4, nullptr);
    connectNode(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
    ComplexListNode* pNode1 = createNode(1);
    connectNode(pNode1, nullptr, pNode1);

    Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5()
{
    Test("Test5", nullptr);
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
