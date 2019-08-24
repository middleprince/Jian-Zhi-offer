// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。

#include "35_ComplexList.h"
#include <cstdio>

ComplexListNode* createNode(int value) {
    ComplexListNode* p_node = new ComplexListNode();
    p_node->value = value;
    p_node->p_next = nullptr;
    p_node->p_sibling = nullptr;
    return p_node;
}

void connectNode(ComplexListNode *p_node, ComplexListNode *p_next,
        ComplexListNode *p_sibling) {
    if (p_node == nullptr)
        return ;
    p_node->p_next = p_next;
    p_node->p_sibling = p_sibling;
}

void printList(ComplexListNode *p_head) {
    if (p_head ==nullptr)
        return ;
    ComplexListNode *p_node = p_head;
    while (p_node) {
        printf("Value of the node is: %d\n", p_node->value);
        if (p_node->p_sibling)
            printf("node's sibling is %d\n", p_node->p_sibling->value);
        else
            printf("the node does not have sibling\n");
        printf("\n");
        
        p_node = p_node->p_next;
    }
}
