#include "List.h"
#include <cstdio>
#include <cstdlib>


ListNode *createListNode(int value) {
    ListNode *pNode = new ListNode;  
    pNode->value  = value; 
    pNode->pNext = nullptr;
    return pNode;
}

void addToTail(ListNode **head, int value) {
    ListNode *pNode = new ListNode;
    pNode->pNext = nullptr;
    pNode->value = value;
    
    if (*head == nullptr) {
        *head = pNode; 
    } else {
        ListNode *currentNode = *head; 
        while (currentNode->pNext != nullptr)
        currentNode = currentNode->pNext;
        currentNode->pNext = pNode;
    }

}

void AddToHead(ListNode **head,int value) {
    ListNode *pNode = new ListNode;
    pNode->value = value;
    pNode->pNext = nullptr; 
    
    if (*head == nullptr)
        *head = pNode;
    else {
        ListNode *currentNode = *head; 
        *head = pNode;
        pNode->pNext = currentNode->pNext;
    }
}

void removeNode(ListNode **head, int value) {
    if (head == nullptr || *head == nullptr) {
        printf("Error to remove node \n"); 
        exit(1);
    }
    
    ListNode *pToDelete = nullptr;
    if ((*head)->value == value) {
        pToDelete = *head; 
        *head = (*head)->pNext;
    } else {
        ListNode *pNode = *head;
        while (pNode->pNext != nullptr && pNode->pNext->value != value)
            pNode = pNode->pNext; 
        if (pNode->pNext != nullptr && pNode->pNext->value == value) {
            pNode->pNext = pNode->pNext->pNext; 
            pToDelete = pNode->pNext; 
        }
    }

    if (pToDelete != nullptr) {
        delete pToDelete; 
        pToDelete = nullptr;
    }
}

void connectListNode(ListNode *pCurrent, ListNode *pNext) {
    if ( pCurrent == nullptr || pNext == nullptr) {
        printf("Error to connect two Listnode\n");
        exit(1);
    }
    pCurrent->pNext = pNext;
}

void printListNode(ListNode *pNode) {
    if ( pNode == nullptr) { 
        printf("Error to print  Listnode\n");
        exit(1);
    }
    printf("Node value:\t %d\n", pNode->value);
}

void printList(ListNode *head) {
    if ( head == nullptr) { 
        printf("Error to print  List\n");
        exit(1);
    }
    ListNode *pNode = head;
    printf("List print begin\n");
    int i = 0;
    while (pNode != nullptr) {
        printf("%d's node's value: \t%d\n", i, pNode->value); 
        ++i;
        pNode = pNode->pNext;
    }
    printf("List print ends\n");
}

void destroyList(ListNode *head) {
    if ( head == nullptr) { 
        printf("Error to destroy  List\n");
        exit(1);
    }

    ListNode *pNode = head;
    while (pNode != nullptr) {
        head = head->pNext; 
        delete pNode;
        pNode = head;
    }
}
    
    
