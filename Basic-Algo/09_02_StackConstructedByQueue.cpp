// 面试题 09 相关题目：
//  使用两个queue 实现一个stack
//  并且含有方法pushToTail与 popFromTail
//

#include <exception>
#include <queue>
#include <cstdio>

template <typename T>
class Stack {
public: 
    void pushToTail(const T&);
    T popFromTail();
private:
    std::queue<T> q1;
    std::queue<T> q2;
};

template <typename T>
void Stack<T>::pushToTail(const T &item) {
    if (q1.empty() && !q2.empty() ) {
        while (!q2.empty()) {
            T temp = q2.front();
            q2.pop();
            q2.push(temp);
        }
    }
    
    q1.push(item);
}

template <typename T>
T Stack<T>::popFromTail() {
    T ret;
    if (q1.empty() && q2.empty()) {
        throw std::runtime_error("Illegal opertation, trying to pop value\
from empty queue");
    }
    else if (!q1.empty()) {
        while (q1.size() > 1) {
            ret = q1.front();
            q2.push(ret);
            q1.pop();
        }
        ret = q1.front();
        q1.pop();
    } else {
         while (q2.size() > 1) {
            ret = q2.front();
            q1.push(ret);
            q2.pop();
        }
        ret = q2.front();
        q2.pop();
    }
    return ret;
}

//=============================================================================
//      Test for Queue
//=============================================================================

void testInfo(const char *info, int actuall, int expected) {
    printf("test for %s bigins:\n", info);
    if (actuall == expected) 
        printf("PASSED\n"); 
    else
    printf("FAILED\n"); 
         
}

int main() {
    Stack<int> stack;
    
    // add and remove item into or from empty stack.
    stack.pushToTail(100);
    testInfo("add and remove item from empty stack", stack.popFromTail(), 100);
    try {
        testInfo("remove item from empty stack", stack.popFromTail(), 100);
    } catch(std::runtime_error err) {
        printf("ERROR: %s\n", err.what());
    }

    // add and remove items from non-empty stack
    stack.pushToTail(12); 
    stack.pushToTail(99); 
    stack.pushToTail(88); 
    testInfo("remove item from non-stack", stack.popFromTail(), 88);
    testInfo("remove item from non-stack", stack.popFromTail(), 99);
    stack.pushToTail(2019);
    testInfo("remove item from non-stack", stack.popFromTail(), 2019);

    return 0;
}
