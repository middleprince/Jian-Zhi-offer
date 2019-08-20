// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。
//

// 思路：在遍历是分别交换左右子树，直到根节点。
//
//

#include <cstdio>
#include "../Utilities/BinaryTree.h"
#include <stack>

void transferToMirror(BinaryTreeNode *head) {
    if (head == nullptr || 
        (head->leftChild == nullptr && head->rightChild == nullptr)) {
        return ;
    }

    BinaryTreeNode *temp_node = head->leftChild;
    head->leftChild = head->rightChild;
    head->rightChild = temp_node;
    
    if (head->leftChild)
        transferToMirror(head->leftChild); 
    if (head->rightChild)
        transferToMirror(head->rightChild); 
}

// transfer into mirror tree iteraterly
void transferToMirrorIterly(BinaryTreeNode *head) {
    if (head == nullptr)
        return;
    std::stack<BinaryTreeNode *> tree_nodes_stack;
    tree_nodes_stack.push(head);
    
    while (tree_nodes_stack.size()) {
        BinaryTreeNode *p_node = tree_nodes_stack.top(); 
        tree_nodes_stack.pop();

        //if (p_node != nullptr && 
        //    (p_node->leftChild || p_node->rightChild)) {

        BinaryTreeNode *node_temp = p_node->leftChild;
        p_node->leftChild = p_node->rightChild;
        p_node->rightChild = node_temp;   
        //}
        
        if (p_node->leftChild) 
            tree_nodes_stack.push(p_node->leftChild);
        if (p_node->rightChild) 
            tree_nodes_stack.push(p_node->rightChild);
    }
}


//==============================================================================
//          Test
//==============================================================================

// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void Test1()
{
    printf("=====Test1 starts:=====\n");
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = createBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = createBinaryTreeNode(11);

    connectBinaryTreeNode(pNode8, pNode6, pNode10);
    connectBinaryTreeNode(pNode6, pNode5, pNode7);
    connectBinaryTreeNode(pNode10, pNode9, pNode11);

    printBinaryTree(pNode8);

    printf("=====Test1: Mirror Tree=====\n");
    transferToMirror(pNode8);
    printBinaryTree(pNode8);

    printf("=====Test1: Original Tree=====\n");
    transferToMirrorIterly(pNode8);
    printBinaryTree(pNode8);

    destroyBinaryTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
//            8
//          7   
//        6 
//      5
//    4
void Test2()
{
    printf("=====Test2 starts:=====\n");
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);

    connectBinaryTreeNode(pNode8, pNode7, nullptr);
    connectBinaryTreeNode(pNode7, pNode6, nullptr);
    connectBinaryTreeNode(pNode6, pNode5, nullptr);
    connectBinaryTreeNode(pNode5, pNode4, nullptr);

    printBinaryTree(pNode8);

    printf("=====Test2: Mirror Tree=====\n");
    transferToMirror(pNode8);
    printBinaryTree(pNode8);

    printf("=====Test2: Original Tree=====\n");
    transferToMirrorIterly(pNode8);
    printBinaryTree(pNode8);

    destroyBinaryTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
//            8
//             7   
//              6 
//               5
//                4
void Test3()
{
    printf("=====Test3 starts:=====\n");
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);

    connectBinaryTreeNode(pNode8, nullptr, pNode7);
    connectBinaryTreeNode(pNode7, nullptr, pNode6);
    connectBinaryTreeNode(pNode6, nullptr, pNode5);
    connectBinaryTreeNode(pNode5, nullptr, pNode4);

    printBinaryTree(pNode8);

    printf("=====Test3: Mirror Tree=====\n");
    transferToMirror(pNode8);
    printBinaryTree(pNode8);

    printf("=====Test3: Original Tree=====\n");
    transferToMirrorIterly(pNode8);
    printBinaryTree(pNode8);

    destroyBinaryTree(pNode8);
}

// 测试空二叉树：根结点为空指针
void Test4()
{
    printf("=====Test4 starts:=====\n");
    BinaryTreeNode* pNode = nullptr;

    printBinaryTree(pNode);

    printf("=====Test4: Mirror Tree=====\n");
    transferToMirror(pNode);
    printBinaryTree(pNode);

    printf("=====Test4: Original Tree=====\n");
    transferToMirrorIterly(pNode);
    printBinaryTree(pNode);
}

// 测试只有一个结点的二叉树
void Test5()
{
    printf("=====Test5 starts:=====\n");
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);

    printBinaryTree(pNode8);

    printf("=====Test4: Mirror Tree=====\n");
    transferToMirror(pNode8);
    printBinaryTree(pNode8);

    printf("=====Test4: Original Tree=====\n");
    transferToMirrorIterly(pNode8);
    printBinaryTree(pNode8);
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
