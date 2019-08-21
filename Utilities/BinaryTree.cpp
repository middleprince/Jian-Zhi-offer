#include "BinaryTree.h"
#include <cstdio>
#include <cstdlib>

BinaryTreeNode* createBinaryTreeNode(int vaule) {
    BinaryTreeNode *pNode = new BinaryTreeNode;
    pNode->value = vaule;
    pNode->leftChild = nullptr;
    pNode->rightChild = nullptr;
    return pNode;
}

void connectBinaryTreeNode(BinaryTreeNode *parent, BinaryTreeNode *left, BinaryTreeNode *right) {
    if (parent != nullptr) {
        parent->leftChild = left; 
        parent->rightChild = right; 
    }
}

void printBinaryTreeNode(const BinaryTreeNode *pNode) {
    if (pNode != nullptr) {
        printf("Parent node value is: %d\n", pNode->value); 
        if (pNode->leftChild != nullptr)
            printf("Left child node value is: %d\n", pNode->leftChild->value); 
        else printf("Left child is void\n");
        
        if (pNode->rightChild != nullptr)
            printf("Right child node value is: %d\n", pNode->rightChild->value); 
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
        if (pRoot->leftChild != nullptr) 
            printBinaryTree(pRoot->leftChild); 
        
        if (pRoot->rightChild != nullptr) 
            printBinaryTree(pRoot->rightChild); 
    }
}

// destory BinaryTreeNode by preoder
void destroyBinaryTree(BinaryTreeNode *pRoot) {
    if (pRoot != nullptr) {
        BinaryTreeNode *leftNode = pRoot->leftChild;
        BinaryTreeNode *rightNode = pRoot->rightChild;

        delete pRoot;
        pRoot = nullptr;
        destroyBinaryTree(leftNode);
        destroyBinaryTree(rightNode);
    }

}
