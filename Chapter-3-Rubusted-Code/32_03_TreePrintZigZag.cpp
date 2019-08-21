// 面试题32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
// 序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
// 其他行以此类推。

// 思路： 同样是层次打印一颗树，不过需要两个stack 来辅助实现之字形打印。

#include "../Utilities/BinaryTree.h"
#include <cstdio>
#include <stack>

void printTreeZigZag(BinaryTreeNode *head) {
    if(head == nullptr)
        return;

    std::stack<BinaryTreeNode *> stacks[2];
    int current_layer = 0, next_layer = 1;

    BinaryTreeNode *curr = head;

    stacks[current_layer].push(curr);
    
    while(!stacks[0].empty() || !stacks[1].empty()) {
        curr = stacks[current_layer].top();
        stacks[current_layer].pop();
        printf("%d ",curr->value);
        
        
        // 交替入栈的顺序, 从一层开始奇数层从左往右入栈; 从2层开始偶数层
        //  从右往左入栈
        //  使用 current_layer, next_layer 记录这样的顺序并且打印。
        if (current_layer == 0) {
            if (curr->leftChild)
                stacks[next_layer].push(curr->leftChild);
            if (curr->rightChild)
                stacks[next_layer].push(curr->rightChild);
        }
        else {
            if (curr->rightChild) 
                stacks[next_layer].push(curr->rightChild);
            if (curr->leftChild)
                stacks[next_layer].push(curr->leftChild);
        }

        if (stacks[current_layer].empty()) {
            printf("\n"); 
            current_layer = 1 - current_layer;
            next_layer = 1 - next_layer;
        }
    }
}

//==============================================================================
//              Test
//==============================================================================

//            8
//        6      10
//       5 7    9  11
void Test1()
{
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

    printf("====Test1 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("10 6 \n");
    printf("5 7 9 11 \n\n");

    printf("Actual Result is: \n");
    printTreeZigZag(pNode8);
    printf("\n");

    destroyBinaryTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test2()
{
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);

    connectBinaryTreeNode(pNode5, pNode4, nullptr);
    connectBinaryTreeNode(pNode4, pNode3, nullptr);
    connectBinaryTreeNode(pNode3, pNode2, nullptr);

    printf("====Test2 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    printTreeZigZag(pNode5);
    printf("\n");

    destroyBinaryTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test3()
{
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);

    connectBinaryTreeNode(pNode5, nullptr, pNode4);
    connectBinaryTreeNode(pNode4, nullptr, pNode3);
    connectBinaryTreeNode(pNode3, nullptr, pNode2);

    printf("====Test3 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    printTreeZigZag(pNode5);
    printf("\n");

    destroyBinaryTree(pNode5);
}

void Test4()
{
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);

    printf("====Test4 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n\n");

    printf("Actual Result is: \n");
    printTreeZigZag(pNode5);
    printf("\n");

    destroyBinaryTree(pNode5);
}

void Test5()
{
    printf("====Test5 Begins: ====\n");
    printf("Expected Result is:\n");

    printf("Actual Result is: \n");
    printTreeZigZag(nullptr);
    printf("\n");
}

//        100
//        /
//       50   
//         \
//         150
void Test6()
{
    BinaryTreeNode* pNode100 = createBinaryTreeNode(100);
    BinaryTreeNode* pNode50 = createBinaryTreeNode(50);
    BinaryTreeNode* pNode150 = createBinaryTreeNode(150);

    connectBinaryTreeNode(pNode100, pNode50, nullptr);
    connectBinaryTreeNode(pNode50, nullptr, pNode150);

    printf("====Test6 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("100 \n");
    printf("50 \n");
    printf("150 \n\n");

    printf("Actual Result is: \n");
    printTreeZigZag(pNode100);
    printf("\n");
}

//                8
//        4              12
//     2     6       10      14
//   1  3  5  7     9 11   13  15
void Test7()
{
    BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode12 = createBinaryTreeNode(12);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
    BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
    BinaryTreeNode* pNode14 = createBinaryTreeNode(14);
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = createBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = createBinaryTreeNode(11);
    BinaryTreeNode* pNode13 = createBinaryTreeNode(13);
    BinaryTreeNode* pNode15 = createBinaryTreeNode(15);

    connectBinaryTreeNode(pNode8, pNode4, pNode12);
    connectBinaryTreeNode(pNode4, pNode2, pNode6);
    connectBinaryTreeNode(pNode12, pNode10, pNode14);
    connectBinaryTreeNode(pNode2, pNode1, pNode3);
    connectBinaryTreeNode(pNode6, pNode5, pNode7);
    connectBinaryTreeNode(pNode10, pNode9, pNode11);
    connectBinaryTreeNode(pNode14, pNode13, pNode15);

    printf("====Test7 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("12 4 \n");
    printf("2 6 10 14 \n");
    printf("15 13 11 9 7 5 3 1 \n\n");

    printf("Actual Result is: \n");
    printTreeZigZag(pNode8);
    printf("\n");

    destroyBinaryTree(pNode8);
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

    return 0;
}
