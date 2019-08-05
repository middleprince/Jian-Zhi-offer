// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。


#include "../Utilities/List.h"
#include <stack>

void printListReversingly(ListNode *head) {
    std::stack<ListNode *> nodeStack;
    ListNode *pNode = head;
    while (pNode != nullptr) {
        nodeStack.push(pNode);
        pNode = pNode->pNext;
    }

    while (!nodeStack.empty()) {
        pNode = nodeStack.top(); 
        printListNode(pNode);
        nodeStack.pop();
    }
}

void printListRecursively(ListNode *head) {
    if(head != nullptr) { 
        if (head->pNext != nullptr)
            printListRecursively(head->pNext);
        printf("node's value is: \t %d \n", head->value); 
    }
}

//=============================================================================
//      Test function code
//=============================================================================

void Test(ListNode *head) {
   printList(head);
   printf("\n print list reversively by stack\n");
   printListRecursively(head);
   printf("\n print list reversively by recursive\n");
   printListReversingly(head);
   printf("\n");
}

// test for 5 node list
void testForFiveNodes() {
    int i = 100;
    ListNode *node1 = nullptr; 
    while (i != 600) {
        addToTail(&node1, i); 
        i += 100;
    }
   
    printf("Test for five nodes\n");
    Test(node1); 
    destroyList(node1);
}

// Test for 1 node
void testForOneNode() {
    ListNode *head = createListNode(678);
    printf("Test for one node"); 
    Test(head); 
    destroyList(head);
}

void testForVoidList() {
    printf("test for empty list");
    ListNode *headVoid = nullptr;    
    Test(headVoid); 
}

int main() {
    testForOneNode();
    testForFiveNodes();
    testForVoidList();
    return 0;
}
    
