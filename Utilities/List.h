#ifdef LIBRARY_EXPORTS
#    define LIBRARY_API __declspec(dllexport)
#else
#    define LIBRARY_API __declspec(dllimport)
#endif

#ifndef List_h
#define List_h

#define LIBRARY_EXPORTS
struct ListNode {
    int value;
    ListNode *pNext;
};

ListNode *creatListNode(int value);
void addToTail(ListNode **head, int value);
void addToHead(ListNode **head, int value);
void removeNode(ListNode **head, int value);
void connectListNode(ListNode *pCurrent, ListNode *pNext);
void printListNode(ListNode *pNode);
void printList(ListNode **head); 
void destroyList(ListNode **head);

#endif


