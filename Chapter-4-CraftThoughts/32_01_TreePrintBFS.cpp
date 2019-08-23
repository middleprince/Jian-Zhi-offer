// 面试题32（一）：不分行从上往下打印二叉树
// 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。

// 思路： 层次打印一颗树，也就是按照广度优先来打印树。

#include "../Utilities/BinaryTree.h"
#include <cstdio>
#include <deque>

void printTreeBFS(BinaryTreeNode *head) {
    if(head == nullptr)
        return;

    std::deque<BinaryTreeNode *> queue_nodes{};
    BinaryTreeNode *curr = nullptr;
    queue_nodes.push_back(head);
    while(!queue_nodes.empty()) {
        curr = queue_nodes.front(); 
        queue_nodes.pop_front();
        printf("%d ",curr->value);
        
        if (curr->leftChild)
            queue_nodes.push_back(curr->leftChild);
        if (curr->rightChild)
            queue_nodes.push_back(curr->rightChild);
    }
}

//==============================================================================
//              Test
//==============================================================================

void Test(const char* testName, BinaryTreeNode* pRoot)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    printBinaryTree(pRoot);

    printf("The nodes from top to bottom, from left to right are: \n");
    printTreeBFS(pRoot);

    printf("\n\n");
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

    destroyBinaryTree(pNode10);
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

    destroyBinaryTree(pNode5);
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

    destroyBinaryTree(pNode1);
}

// 树中只有1个结点
void Test4()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    Test("Test4", pNode1);

    destroyBinaryTree(pNode1);
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
