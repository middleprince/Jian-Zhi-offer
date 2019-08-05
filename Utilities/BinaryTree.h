#ifndef BinaryTree_h
#define BinaryTree_h

struct BinaryTreeNode{
   int value;
   BinaryTreeNode *leftChild;
   BinaryTreeNode *rightChild;
};

BinaryTreeNode* createBinaryTreeNode(int); 
void connectBinaryTreeNode(BinaryTreeNode *,BinaryTreeNode *, BinaryTreeNode *);
void printBinaryTreeNode(const BinaryTreeNode *);
void printBinaryTree(const BinaryTreeNode *);
void destroyBinaryTree(BinaryTreeNode *);
#endif
