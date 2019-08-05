// using the physical constructure of vector to design Tree
#ifndef Tree_h
#define Tree_h


#include <vector>
struct TreeNode {
    int value;
    std::vector<TreeNode *> pChild;
};

TreeNode* createTreeNode(int);
void connectTreeNode(TreeNode*, TreeNode*);
void printTreeNode(const TreeNode*);
void printTree(const TreeNode*);
void destroyTree(TreeNode*);
#endif
