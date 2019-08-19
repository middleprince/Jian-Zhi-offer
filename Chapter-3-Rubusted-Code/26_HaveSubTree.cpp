

// 面试题26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。


#include <cstdio>
#include "../Utilities/BinaryTree.h"

const double epsilon = 1e-8;

bool doesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
bool equal(double num1, double num2);

bool hasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    bool result = false;

    if(pRoot1 != nullptr && pRoot2 != nullptr)
    {
        if(equal(pRoot1->value, pRoot2->value))
            result = doesTree1HaveTree2(pRoot1, pRoot2);
        if(!result)
            result = hasSubtree(pRoot1->leftChild, pRoot2);
        if(!result)
            result = hasSubtree(pRoot1->rightChild, pRoot2);
    }

    return result;
}

bool doesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if(pRoot2 == nullptr)
        return true;

    if(pRoot1 == nullptr)
        return false;

    if(!equal(pRoot1->value, pRoot2->value))
        return false;

    return doesTree1HaveTree2(pRoot1->leftChild, pRoot2->leftChild) &&
           doesTree1HaveTree2(pRoot1->rightChild, pRoot2->rightChild);
}

bool equal(double num1, double num2)
{
    if((num1 - num2 > epsilon) && (num1 - num2 < epsilon))
        return true;
    else
        return false;
}


// ====================================================================================================
//                  Test
// ====================================================================================================
void Test(const char* testName, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected)
{
    if(hasSubtree(pRoot1, pRoot2) == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s failed.\n", testName);
}

// 树中结点含有分叉，树B是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
void Test1()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = createBinaryTreeNode(2);
    BinaryTreeNode* pNodeA6 = createBinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = createBinaryTreeNode(7);

    connectBinaryTreeNode(pNodeA1, pNodeA2, pNodeA3);
    connectBinaryTreeNode(pNodeA2, pNodeA4, pNodeA5);
    connectBinaryTreeNode(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(2);

    connectBinaryTreeNode(pNodeB1, pNodeB2, pNodeB3);

    Test("Test1", pNodeA1, pNodeB1, true);

    destroyBinaryTree(pNodeA1);
    destroyBinaryTree(pNodeB1);
}

// 树中结点含有分叉，树B不是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
void Test2()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = createBinaryTreeNode(3);
    BinaryTreeNode* pNodeA6 = createBinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = createBinaryTreeNode(7);

    connectBinaryTreeNode(pNodeA1, pNodeA2, pNodeA3);
    connectBinaryTreeNode(pNodeA2, pNodeA4, pNodeA5);
    connectBinaryTreeNode(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(2);

    connectBinaryTreeNode(pNodeB1, pNodeB2, pNodeB3);

    Test("Test2", pNodeA1, pNodeB1, false);

    destroyBinaryTree(pNodeA1);
    destroyBinaryTree(pNodeB1);
}

// 树中结点只有左子结点，树B是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    2
//         /      
//        2        
//       /
//      5
void Test3()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = createBinaryTreeNode(5);

    connectBinaryTreeNode(pNodeA1, pNodeA2, nullptr);
    connectBinaryTreeNode(pNodeA2, pNodeA3, nullptr);
    connectBinaryTreeNode(pNodeA3, pNodeA4, nullptr);
    connectBinaryTreeNode(pNodeA4, pNodeA5, nullptr);

    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(2);

    connectBinaryTreeNode(pNodeB1, pNodeB2, nullptr);
    connectBinaryTreeNode(pNodeB2, pNodeB3, nullptr);

    Test("Test3", pNodeA1, pNodeB1, true);

    destroyBinaryTree(pNodeA1);
    destroyBinaryTree(pNodeB1);
}

// 树中结点只有左子结点，树B不是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    3
//         /      
//        2        
//       /
//      5
void Test4()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = createBinaryTreeNode(5);

    connectBinaryTreeNode(pNodeA1, pNodeA2, nullptr);
    connectBinaryTreeNode(pNodeA2, pNodeA3, nullptr);
    connectBinaryTreeNode(pNodeA3, pNodeA4, nullptr);
    connectBinaryTreeNode(pNodeA4, pNodeA5, nullptr);

    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(3);

    connectBinaryTreeNode(pNodeB1, pNodeB2, nullptr);
    connectBinaryTreeNode(pNodeB2, pNodeB3, nullptr);

    Test("Test4", pNodeA1, pNodeB1, false);

    destroyBinaryTree(pNodeA1);
    destroyBinaryTree(pNodeB1);
}

// 树中结点只有右子结点，树B是树A的子结构
//       8                   8
//        \                   \
//         8                   9   
//          \                   \
//           9                   2
//             \
//             2        
//              \
//               5
void Test5()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = createBinaryTreeNode(5);

    connectBinaryTreeNode(pNodeA1, nullptr, pNodeA2);
    connectBinaryTreeNode(pNodeA2, nullptr, pNodeA3);
    connectBinaryTreeNode(pNodeA3, nullptr, pNodeA4);
    connectBinaryTreeNode(pNodeA4, nullptr, pNodeA5);

    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(2);

    connectBinaryTreeNode(pNodeB1, nullptr, pNodeB2);
    connectBinaryTreeNode(pNodeB2, nullptr, pNodeB3);

    Test("Test5", pNodeA1, pNodeB1, true);

    destroyBinaryTree(pNodeA1);
    destroyBinaryTree(pNodeB1);
}

// 树A中结点只有右子结点，树B不是树A的子结构
//       8                   8
//        \                   \
//         8                   9   
//          \                 / \
//           9               3   2
//            \
//             2        
//              \
//               5
void Test6()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = createBinaryTreeNode(5);

    connectBinaryTreeNode(pNodeA1, nullptr, pNodeA2);
    connectBinaryTreeNode(pNodeA2, nullptr, pNodeA3);
    connectBinaryTreeNode(pNodeA3, nullptr, pNodeA4);
    connectBinaryTreeNode(pNodeA4, nullptr, pNodeA5);

    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNodeB4 = createBinaryTreeNode(2);

    connectBinaryTreeNode(pNodeB1, nullptr, pNodeB2);
    connectBinaryTreeNode(pNodeB2, pNodeB3, pNodeB4);

    Test("Test6", pNodeA1, pNodeB1, false);

    destroyBinaryTree(pNodeA1);
    destroyBinaryTree(pNodeB1);
}

// 树A为空树
void Test7()
{
    BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNodeB4 = createBinaryTreeNode(2);

    connectBinaryTreeNode(pNodeB1, nullptr, pNodeB2);
    connectBinaryTreeNode(pNodeB2, pNodeB3, pNodeB4);

    Test("Test7", nullptr, pNodeB1, false);

    destroyBinaryTree(pNodeB1);
}

// 树B为空树
void Test8()
{
    BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = createBinaryTreeNode(9);
    BinaryTreeNode* pNodeA3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);

    connectBinaryTreeNode(pNodeA1, nullptr, pNodeA2);
    connectBinaryTreeNode(pNodeA2, pNodeA3, pNodeA4);

    Test("Test8", pNodeA1, nullptr, false);

    destroyBinaryTree(pNodeA1);
}

// 树A和树B都为空
void Test9()
{
    Test("Test9", nullptr, nullptr, false);
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

    return 0;
}
