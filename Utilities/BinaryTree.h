#ifndef BinaryTree_h
#define BinaryTree_h

struct BinaryTree{
    int value;
    BinaryTree *leftChild;
    BinaryTree *rightChild;
};

BinaryTree* createBinaryTreeNode(int); 
void connectBinaryTreeNode(BinaryTree *, BinaryTree *, BinaryTree *);
void printBinaryTreeNode(const BinaryTree *);
void printBinaryTree(const BinaryTree *);
void destroyBinaryTree(BinaryTree *);
#endif
