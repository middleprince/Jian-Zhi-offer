// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
//

// 思路：回溯法遍历判断，一边遍历一边判断，找到一条路径就打印出来。
//       通过递归来记录当前路径上的节点和。
//

#include "../Utilities/BinaryTree.h"
#include <cstdio>
#include <vector>


void findNextNodeInPath(BinaryTreeNode *, int, int, 
        std::vector<int>&);
void findPath(BinaryTreeNode *head, int sums) {
    if (head == nullptr)
        return;

    int current_sum = 0;
    std::vector<int> path_nodes{};

    findNextNodeInPath(head, sums, current_sum, path_nodes);
}

void findNextNodeInPath(BinaryTreeNode *pnode, int sums, int current_sum,
        std::vector<int> &path_nodes) {

    path_nodes.push_back(pnode->value);
    if (current_sum + pnode->value > sums) {
        path_nodes.pop_back();
        return ;
    }

    if (current_sum + pnode->value == sums && 
            (pnode->leftChild == nullptr && pnode->rightChild == nullptr)) {
        for (const auto &item : path_nodes) 
            printf("%d ", item);

        printf("\n"); 
        path_nodes.pop_back();
        return;
    }
        
    if (current_sum + pnode->value < sums) {
        current_sum += pnode->value;
    }
    
    if (pnode->leftChild)
        findNextNodeInPath(pnode->leftChild, sums, 
                current_sum, path_nodes);
    
    if (pnode->rightChild)
        findNextNodeInPath(pnode->rightChild, sums, 
                current_sum, path_nodes);

    path_nodes.pop_back();
    return ;
}
//==============================================================================
//          Test
//==============================================================================
    
    
void Test(const char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    findPath(pRoot, expectedSum);

    printf("\n");
}

//            10
//         /      \
//        5        12
//       /\
//      4  7     
// 有两条路径上的结点和为22
void Test1()
{
    BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = createBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);

    connectBinaryTreeNode(pNode10, pNode5, pNode12);
    connectBinaryTreeNode(pNode5, pNode4, pNode7);

    printf("Two paths should be found in Test1.\n");
    Test("Test1", pNode10, 22);

    destroyBinaryTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\
//      4  7     
// 没有路径上的结点和为15
void Test2()
{
    BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = createBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = createBinaryTreeNode(7);

    connectBinaryTreeNode(pNode10, pNode5, pNode12);
    connectBinaryTreeNode(pNode5, pNode4, pNode7);

    printf("No paths should be found in Test2.\n");
    Test("Test2", pNode10, 15);

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
// 有一条路径上面的结点和为15
void Test3()
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

    printf("One path should be found in Test3.\n");
    Test("Test3", pNode5, 15);

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
// 没有路径上面的结点和为16
void Test4()
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

    printf("No paths should be found in Test4.\n");
    Test("Test4", pNode1, 16);

    destroyBinaryTree(pNode1);
}

// 树中只有1个结点
void Test5()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(1);

    printf("One path should be found in Test5.\n");
    Test("Test5", pNode1, 1);

    destroyBinaryTree(pNode1);
}

// 树中没有结点
void Test6()
{
    printf("No paths should be found in Test6.\n");
    Test("Test6", nullptr, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

