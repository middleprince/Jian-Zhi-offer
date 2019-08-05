#include "Tree.h"
#include <cstdio>
#include <cstdlib>
// using the pysical storing structure of vector to design Tree

TreeNode* createTreeNode(int value) {
    TreeNode *pNode = new TreeNode;
    pNode->value = value;
    return pNode;
}

void connectTreeNode(TreeNode *pParent, TreeNode *pChild) {
    if (pParent != nullptr)
        pParent->pChild.push_back(pChild);
}

// print vaules of there node and is't children'.
void printTreeNode(const TreeNode *pNode) {
    if (pNode != nullptr) {
        printf("the value of node is: \t %d \n", pNode->value); 
        printf("the value of it's direct children are showing below:\n");
        
        auto iter =pNode->pChild.cbegin();
        while (iter != pNode->pChild.cend()) {
        // To FIX: print the parent's node corecctly
            if (*iter != nullptr) {
                printf("%d\t", (*iter)->value);
                ++iter;
            }
        }
    } 
    else {
        printf("this node is nullptr.\n");
    } 
    
    printf("\n");
}

// BFS  to print tree
void printTree(const TreeNode *pRoot) {
    printTreeNode(pRoot);
    if (pRoot != nullptr) {
        auto iter = pRoot->pChild.cbegin(); 
        while (iter != pRoot->pChild.cend()) {
            printTreeNode(*iter); 
            ++iter;
        }
    }
}

// destroy Tree by DFS
void destroyTree(TreeNode *pRoot) {
    if (pRoot != nullptr) {
        auto iter = pRoot->pChild.begin(); 
        while (iter != pRoot->pChild.end()) {
            destroyTree(*iter);
            ++iter;
        }
        delete pRoot;
        
    }
}
