
// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
//

#include <cstdio>
#include <cstdlib>

//==============================================================================
//      BinaryTree which contain pointer to it's parent
//      essential function to consturct BiTree and use it  
//==============================================================================
struct BinaryTreeNode {
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode *parent;
};

BinaryTreeNode* createBinaryTreeNode(int vaule) {
    BinaryTreeNode *pNode = new BinaryTreeNode;
    pNode->value = vaule;
    pNode->left = nullptr;
    pNode->right = nullptr;
    pNode->parent = nullptr;
    return pNode;
}

void connectTreeNode(BinaryTreeNode *parent, BinaryTreeNode *left, BinaryTreeNode *right) {
    if (parent != nullptr) {
        parent->left = left; 
        parent->right = right; 

        if (left != nullptr)
            left->parent = parent;
        if (right != nullptr) 
            right->parent = parent;
        
    }
}

void printBinaryTreeNode(const BinaryTreeNode *pNode) {
    if (pNode != nullptr) {
        printf("Parent node value is: %d\n", pNode->value); 
        if (pNode->left != nullptr)
            printf("Left child node value is: %d\n", pNode->left->value); 
        else printf("Left child is void\n");
        
        if (pNode->right != nullptr)
            printf("Right child node value is: %d\n", pNode->right->value); 
        else printf("Right child is void\n");

    } else {
        printf("Parent node is void\n"); 
    } 
    printf("\n");
}

// print tree by preorder
void printBinaryTree(const BinaryTreeNode *pRoot) {
    printBinaryTreeNode(pRoot);
    if (pRoot != nullptr) {
        if (pRoot->left != nullptr) 
            printBinaryTree(pRoot->left); 
        
        if (pRoot->right != nullptr) 
            printBinaryTree(pRoot->right); 
    }
}

// destory BinaryTreeNode by preoder
void destroyBinaryTree(BinaryTreeNode *pRoot) {
    if (pRoot != nullptr) {
        BinaryTreeNode *leftNode = pRoot->left;
        BinaryTreeNode *rightNode = pRoot->right;

        delete pRoot;
        pRoot = nullptr;
        destroyBinaryTree(leftNode);
        destroyBinaryTree(rightNode);
    }

}

//==============================================================================
//      Functio to fund next node
//=============================================================================

BinaryTreeNode* findNextNode(BinaryTreeNode *pNode) {
    if (pNode == nullptr) {
        printf("illegal input\n");
        exit(1);
    }
    BinaryTreeNode *pCurrent = nullptr; 
    if (pNode->right != nullptr) {
        pCurrent = pNode->right;
        while (pCurrent->left != nullptr) { 
            pCurrent = pCurrent->left; 
        } 
        return pCurrent;
    }
    // Fixed: parent is nullptr
    else if (pNode->parent != nullptr) {
        pCurrent = pNode;
        while (pCurrent->parent != nullptr && pCurrent->parent->left != pCurrent) { 
            pCurrent = pCurrent->parent;
        }
        pCurrent =  pCurrent->parent;
    }
    
    return pCurrent; 
}

//==============================================================================
//      Test function
//=============================================================================

void Test(const char* testName, BinaryTreeNode* pNode, BinaryTreeNode* expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    BinaryTreeNode* pNext = findNextNode(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = createBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = createBinaryTreeNode(11);

    connectTreeNode(pNode8, pNode6, pNode10);
    connectTreeNode(pNode6, pNode5, pNode7);
    connectTreeNode(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, nullptr);

    destroyBinaryTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test8_11()
{
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);

    connectTreeNode(pNode5, pNode4, nullptr);
    connectTreeNode(pNode4, pNode3, nullptr);
    connectTreeNode(pNode3, pNode2, nullptr);

    Test("Test8", pNode5, nullptr);
    Test("Test9", pNode4, pNode5);
    Test("Test10", pNode3, pNode4);
    Test("Test11", pNode2, pNode3);

    destroyBinaryTree(pNode5);
}

//        2
//         3
//          4
//           5
void Test12_15()
{
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);

    connectTreeNode(pNode2, nullptr, pNode3);
    connectTreeNode(pNode3, nullptr, pNode4);
    connectTreeNode(pNode4, nullptr, pNode5);

    Test("Test12", pNode5, nullptr);
    Test("Test13", pNode4, pNode5);
    Test("Test14", pNode3, pNode4);
    Test("Test15", pNode2, pNode3);
}

void Test16()
{
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);

    Test("Test16", pNode5, nullptr);

    destroyBinaryTree(pNode5);
}

int main(int argc, char* argv[])
{
    Test1_7();
    Test8_11();
    Test12_15();
    Test16();
}
