// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
// 它的镜像一样，那么它是对称的。

// 思路： 使用递归地来判断左右子树是否为对称的.
// 直接通过遍历节点来比较.
// 在同一颗树中通过根左右与 根右左 节点是否相同, 空节点也要加入比较。

#include <cstdio>
#include "../Utilities/BinaryTree.h"

bool isSyemmetricalSubNode(BinaryTreeNode *tree1, BinaryTreeNode *tree2);
bool isSyemmetrical(BinaryTreeNode *head) {
    return isSyemmetricalSubNode(head, head);
}

bool isSyemmetricalSubNode(BinaryTreeNode *tree1, BinaryTreeNode *tree2) {
    if (tree1 == nullptr && tree2 == nullptr)
        return true;
    if (tree1 == nullptr || tree2 == nullptr)
        return false;
    
    if (tree1->value != tree2->value) 
        return false;
    
    return isSyemmetricalSubNode(tree1->leftChild, tree2->rightChild) &&
           isSyemmetricalSubNode(tree1->rightChild, tree2->leftChild); 
    
}


//==============================================================================
//          Test
//==============================================================================
//

void Test(const char* testName, BinaryTreeNode* pRoot, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isSyemmetrical(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      6
//       5 7    7 5
void Test1()
{
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode62 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode51 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode52 = createBinaryTreeNode(5);

    connectBinaryTreeNode(pNode8, pNode61, pNode62);
    connectBinaryTreeNode(pNode61, pNode51, pNode71);
    connectBinaryTreeNode(pNode62, pNode72, pNode52);

    Test("Test1", pNode8, true);

    destroyBinaryTree(pNode8);
}

//            8
//        6      9
//       5 7    7 5
void Test2()
{
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode9 = createBinaryTreeNode(9);
    BinaryTreeNode* pNode51 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode52 = createBinaryTreeNode(5);

    connectBinaryTreeNode(pNode8, pNode61, pNode9);
    connectBinaryTreeNode(pNode61, pNode51, pNode71);
    connectBinaryTreeNode(pNode9, pNode72, pNode52);

    Test("Test2", pNode8, false);

    destroyBinaryTree(pNode8);
}

//            8
//        6      6
//       5 7    7
void Test3()
{
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode62 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode51 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = createBinaryTreeNode(7);

    connectBinaryTreeNode(pNode8, pNode61, pNode62);
    connectBinaryTreeNode(pNode61, pNode51, pNode71);
    connectBinaryTreeNode(pNode62, pNode72, nullptr);

    Test("Test3", pNode8, false);

    destroyBinaryTree(pNode8);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//        /             \
//       1               1
void Test4()
{
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode21 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode22 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode11 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode12 = createBinaryTreeNode(1);

    connectBinaryTreeNode(pNode5, pNode31, pNode32);
    connectBinaryTreeNode(pNode31, pNode41, nullptr);
    connectBinaryTreeNode(pNode32, nullptr, pNode42);
    connectBinaryTreeNode(pNode41, pNode21, nullptr);
    connectBinaryTreeNode(pNode42, nullptr, pNode22);
    connectBinaryTreeNode(pNode21, pNode11, nullptr);
    connectBinaryTreeNode(pNode22, nullptr, pNode12);

    Test("Test4", pNode5, true);

    destroyBinaryTree(pNode5);
}


//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         6           2
//        /             \
//       1               1
void Test5()
{
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode22 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode11 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode12 = createBinaryTreeNode(1);

    connectBinaryTreeNode(pNode5, pNode31, pNode32);
    connectBinaryTreeNode(pNode31, pNode41, nullptr);
    connectBinaryTreeNode(pNode32, nullptr, pNode42);
    connectBinaryTreeNode(pNode41, pNode6, nullptr);
    connectBinaryTreeNode(pNode42, nullptr, pNode22);
    connectBinaryTreeNode(pNode6, pNode11, nullptr);
    connectBinaryTreeNode(pNode22, nullptr, pNode12);

    Test("Test5", pNode5, false);

    destroyBinaryTree(pNode5);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//                      \
//                       1
void Test6()
{
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode21 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode22 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode12 = createBinaryTreeNode(1);

    connectBinaryTreeNode(pNode5, pNode31, pNode32);
    connectBinaryTreeNode(pNode31, pNode41, nullptr);
    connectBinaryTreeNode(pNode32, nullptr, pNode42);
    connectBinaryTreeNode(pNode41, pNode21, nullptr);
    connectBinaryTreeNode(pNode42, nullptr, pNode22);
    connectBinaryTreeNode(pNode21, nullptr, nullptr);
    connectBinaryTreeNode(pNode22, nullptr, pNode12);

    Test("Test6", pNode5, false);

    destroyBinaryTree(pNode5);
}

// 只有一个结点
void Test7()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    Test("Test7", pNode1, true);

    destroyBinaryTree(pNode1);
}

// 没有结点
void Test8()
{
    Test("Test8", nullptr, true);
}

// 所有结点都有相同的值，树对称
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /         \
//         5           5
void Test9()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode21 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode22 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode32 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode41 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode42 = createBinaryTreeNode(5);

    connectBinaryTreeNode(pNode1, pNode21, pNode22);
    connectBinaryTreeNode(pNode21, pNode31, nullptr);
    connectBinaryTreeNode(pNode22, nullptr, pNode32);
    connectBinaryTreeNode(pNode31, pNode41, nullptr);
    connectBinaryTreeNode(pNode32, nullptr, pNode42);
    connectBinaryTreeNode(pNode41, nullptr, nullptr);
    connectBinaryTreeNode(pNode42, nullptr, nullptr);

    Test("Test9", pNode1, true);

    destroyBinaryTree(pNode1);
}

// 所有结点都有相同的值，树不对称
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /       /
//         5       5
void Test10()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode21 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode22 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode32 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode41 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode42 = createBinaryTreeNode(5);

    connectBinaryTreeNode(pNode1, pNode21, pNode22);
    connectBinaryTreeNode(pNode21, pNode31, nullptr);
    connectBinaryTreeNode(pNode22, nullptr, pNode32);
    connectBinaryTreeNode(pNode31, pNode41, nullptr);
    connectBinaryTreeNode(pNode32, pNode42, nullptr);
    connectBinaryTreeNode(pNode41, nullptr, nullptr);
    connectBinaryTreeNode(pNode42, nullptr, nullptr);

    Test("Test10", pNode1, false);

    destroyBinaryTree(pNode1);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    
    return 0;
}
