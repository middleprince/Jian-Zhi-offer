// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
// 不能创建任何新的结点，只能调整树中结点指针的指向。
//

// 思路： 通过排序二叉树知道，排序二叉树中序遍历就是有序的序列。
//        链表的建立就是通过中序的递归来建立。

#include "../Utilities/BinaryTree.h"
#include <cstdio>

void convertToList(BinaryTreeNode *p_root, BinaryTreeNode **p_last_node);

BinaryTreeNode* transferIntoList(BinaryTreeNode *p_head) {
    if (p_head == nullptr)
        return nullptr;
    BinaryTreeNode *p_last_node = nullptr;
    convertToList(p_head, &p_last_node);
    
    
    BinaryTreeNode *converted_head = p_last_node;
    
    while (converted_head != nullptr && converted_head->leftChild != nullptr)
        converted_head = converted_head->leftChild;

    return converted_head;
}

void convertToList(BinaryTreeNode *p_root, BinaryTreeNode **p_last_node) {
    if (p_root == nullptr)
        return;

    BinaryTreeNode *p_current = p_root;
    if (p_current->leftChild != nullptr)
        convertToList(p_current->leftChild, p_last_node);
    
    p_current->leftChild = *p_last_node;
    
    if (*p_last_node != nullptr)
        (*p_last_node)->rightChild = p_current;

    *p_last_node = p_current; 
    
    if (p_current->rightChild)
        convertToList(p_current->rightChild, p_last_node);
}


//==============================================================================
//              Test
//==============================================================================


void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;

    printf("The nodes from left to right are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->value);

        if(pNode->rightChild == nullptr)
            break;
        pNode = pNode->rightChild;
    }

    printf("\nThe nodes from right to left are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->value);

        if(pNode->leftChild == nullptr)
            break;
        pNode = pNode->leftChild;
    }

    printf("\n");
}

void DestroyList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;
    while(pNode != nullptr)
    {
        BinaryTreeNode* pNext = pNode->rightChild;

        delete pNode;
        pNode = pNext;
    }
}

void Test(const char* testName, BinaryTreeNode* pRootOfTree)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printBinaryTree(pRootOfTree);

    BinaryTreeNode* pHeadOfList = transferIntoList(pRootOfTree);

    PrintDoubleLinkedList(pHeadOfList);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = createBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = createBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = createBinaryTreeNode(16);

    connectBinaryTreeNode(pNode10, pNode6, pNode14);
    connectBinaryTreeNode(pNode6, pNode4, pNode8);
    connectBinaryTreeNode(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    DestroyList(pNode4);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);

    connectBinaryTreeNode(pNode5, pNode4, nullptr);
    connectBinaryTreeNode(pNode4, pNode3, nullptr);
    connectBinaryTreeNode(pNode3, pNode2, nullptr);
    connectBinaryTreeNode(pNode2, pNode1, nullptr);

    Test("Test2", pNode5);

    DestroyList(pNode1);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);

    connectBinaryTreeNode(pNode1, nullptr, pNode2);
    connectBinaryTreeNode(pNode2, nullptr, pNode3);
    connectBinaryTreeNode(pNode3, nullptr, pNode4);
    connectBinaryTreeNode(pNode4, nullptr, pNode5);

    Test("Test3", pNode1);

    DestroyList(pNode1);
}

// 树中只有1个结点
void Test4()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyList(pNode1);
}

// 树中没有结点
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
