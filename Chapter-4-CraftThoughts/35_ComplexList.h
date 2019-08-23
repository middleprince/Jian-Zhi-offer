// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。
//

#ifndef _35_COMPLEXLIST_H
#define _35_COMPLEXLIST_H

struct ComplexListNode {
    int value;
    ComplexListNode *p_next;
    ComplexListNode *p_sibling;
    
};

ComplexListNode* createNode(int value);
void connectNode(ComplexListNode *p_node, ComplexListNode *p_next,
        ComplexListNode *p_sibling);
void printList(ComplexListNode *p_head);


#endif
