// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
// 不能创建任何新的结点，只能调整树中结点指针的指向。
//

// 思路： 通过排序二叉树知道，排序二叉树中序遍历就是有序的序列。
//        链表的建立就是通过中序的递归来建立。

#include "../Utilities/BinaryTree.h"
#include <cstdio>

BinaryTreeNode* convertToList(BinaryTreeNode *p_root, BinaryTreeNode **p_last_node);
BinaryTreeNode* treanferIntoList(BinaryTreeNode *p_head) {
    if (p_head == nullptr)
        return nullptr;

    
}
