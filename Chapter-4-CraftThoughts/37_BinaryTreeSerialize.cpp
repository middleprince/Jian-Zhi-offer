// 面试题37：序列化二叉树
// 题目：请实现两个函数，分别用来序列化和反序列化二叉树。

// 思路：二叉树的序列化反序列化目标就是实现二叉树的重构；使用
// 前序或则后续遍历二叉树就可以实现序列化二叉树还能重构。
// 使用前序来来遍历二叉树，其中将空节点用特殊符号来代替，比如「#」; 这样
// 可以实现根左右子树对，更容易操作。
//

#include "../Utilities/BinaryTree.h"
#include <iostream>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

bool readFromStream(std::istream&, int*);

// tranverse tree by  pre-order
void serializeBT(const BinaryTreeNode *p_head, ostream &os) {
    if (p_head == nullptr) {
        os << "#" << ","; 
        return ;
    }
    
    os << p_head->value << ",";
    serializeBT(p_head->leftChild, os);
    serializeBT(p_head->rightChild, os);
}      


void deserializeToBT(BinaryTreeNode **p_head, istream &is) {
    int number;
    if (readFromStream(is, &number)) {
        *p_head = new BinaryTreeNode();
        (*p_head)->value = number;
        (*p_head)->leftChild = nullptr;
        (*p_head)->rightChild = nullptr;

        deserializeToBT(&((*p_head)->leftChild), is);
        deserializeToBT(&((*p_head)->rightChild), is);
    
    }
}

bool readFromStream(std::istream &is, int *number) {
    if (is.eof())
        return false;
    
    char buf[64]{'\0'};

    char ch;
    is >> ch;
    int i = 0;
    while (!is.eof() && ch != ',') {
        buf[i++] = ch; 
        is >> ch;
    }

    bool is_number = false;
    if (i > 0 && buf[0] != '#') {
        *number = atoi(buf); 
        is_number = true;
    } 
    
    return is_number;
}


//==============================================================================
//              Test
//==============================================================================

bool isSameTree(const BinaryTreeNode* pRoot1, const BinaryTreeNode* pRoot2)
{
    if(pRoot1 == nullptr && pRoot2 == nullptr)
        return true;

    if(pRoot1 == nullptr || pRoot2 == nullptr)
        return false;

    if(pRoot1->value != pRoot2->value)
        return false;

    return isSameTree(pRoot1->leftChild, pRoot2->leftChild) &&
        isSameTree(pRoot1->rightChild, pRoot2->rightChild);
}

void Test(const char* testName, const BinaryTreeNode* pRoot)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    printBinaryTree(pRoot);

    const char* fileName = "test.txt";
    ofstream fileOut;
    fileOut.open(fileName);

    serializeBT(pRoot, fileOut);
    fileOut.close();

    // print the serialized file
    ifstream fileIn1;
    char ch;
    fileIn1.open(fileName);
    while(!fileIn1.eof())
    {
        fileIn1 >> ch;
        cout << ch;
    }
    fileIn1.close();
    cout << endl;

    ifstream fileIn2;
    fileIn2.open(fileName);
    BinaryTreeNode* pNewRoot = nullptr;
    deserializeToBT(&pNewRoot, fileIn2);
    fileIn2.close();

    printBinaryTree(pNewRoot);

    if(isSameTree(pRoot, pNewRoot))
        printf("The deserialized tree is same as the oritinal tree.\n\n");
    else
        printf("The deserialized tree is NOT same as the oritinal tree.\n\n");

    destroyBinaryTree(pNewRoot);
}

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

    Test("Test1", pNode8);

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

    Test("Test2", pNode5);

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

    Test("Test3", pNode5);

    destroyBinaryTree(pNode5);
}

void Test4()
{
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);

    Test("Test4", pNode5);

    destroyBinaryTree(pNode5);
}

void Test5()
{
    Test("Test5", nullptr);
}

//        5
//         5
//          5
//         5
//        5
//       5 5
//      5   5
void Test6()
{
    BinaryTreeNode* pNode1 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode2 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode3 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode61 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode62 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = createBinaryTreeNode(5);
    BinaryTreeNode* pNode72 = createBinaryTreeNode(5);

    connectBinaryTreeNode(pNode1, nullptr, pNode2);
    connectBinaryTreeNode(pNode2, nullptr, pNode3);
    connectBinaryTreeNode(pNode3, pNode4, nullptr);
    connectBinaryTreeNode(pNode4, pNode5, nullptr);
    connectBinaryTreeNode(pNode5, pNode61, pNode62);
    connectBinaryTreeNode(pNode61, pNode71, nullptr);
    connectBinaryTreeNode(pNode62, nullptr, pNode72);

    Test("Test6", pNode1);

    destroyBinaryTree(pNode1);
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

