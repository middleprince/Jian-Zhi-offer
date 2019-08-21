// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。
//

// 思路：类似于后续遍历重构二叉树的思想，从序列的最后一个节点向前递归地构建
//       搜索二叉树。
//       1. 搜索二叉树的做子树小于右子树。

#include <cstdio>

bool isBST(int *, int);
bool isSequenceOfBST(int *seqs, int length) {
    if (seqs == nullptr || length < 0)
        return false;
    
    int back_index = length - 1; 
    int left_index = 0;
    
    // 找到左子树序列
    for (; left_index < back_index; ++left_index) {
        if (seqs[left_index] > seqs[back_index]) 
            break;
    }
    //printf("##debug after find left part\n");
    
    //  验证右子树序列是否合法
    int right_index = left_index;
    for ( ; right_index < back_index; ++right_index) { 
        // 非法的搜索树的情况
        if (seqs[right_index] < seqs[back_index]) 
            return false;
    }

    
    bool is_left = true;
    if (left_index > 0)
        is_left = isSequenceOfBST(seqs, left_index);
    
    bool is_right = true;
    if (right_index < back_index)
        is_right = isSequenceOfBST(seqs + left_index, length - left_index - 1);
    
    return is_left && is_right;
}


//==============================================================================
//          Test
//==============================================================================


void Test(const char* testName, int sequence[], int length, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isSequenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    int data[] = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data)/sizeof(int), true);
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
void Test3()
{
    int data[] = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data)/sizeof(int), true);
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
void Test4()
{
    int data[] = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// 树中只有1个结点
void Test5()
{
    int data[] = {5};
    Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6()
{
    int data[] = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7()
{
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8()
{
    Test("Test8", nullptr, 0, false);
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

    return 0;
}












































































