// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

#include <stack>
#include <exception>

template <typename T> 
class Queue{
public:
    void appendTail(const T&);
    T deleteHead();
private:
    std::stack<T> s1;
    std::stack<T> s2;
};

template <typename T>
inline void Queue<T>::appendTail(const T &item) {
    s1.push(item);
}

template <typename T>
inline T Queue<T>::deleteHead() {
    T ret;
    if (s2.empty()) {
        while (!s1.empty()) {
            ret = s1.top(); 
            s1.pop();
            s2.push(ret);
        }
    }

    if (s2.empty())
        throw std::runtime_error("queue is empty");
    ret = s2.top(); 
    s2.pop();
    
    return ret;
}


//==============================================================================
//  Test for Queue
//==============================================================================
//

void testInfo(const char *info, int actuall, int expected) {
    printf("test for %s bigins:\n", info);
    if (actuall == expected) 
        printf("PASSED\n"); 
    else
    printf("FAILED\n"); 
         
}

int main() {
    Queue<int> queue;
    
    // add and remove item into or from empty queue.
    queue.appendTail(100);
    testInfo("add and remove item from empty queue", queue.deleteHead(), 100);
    try {
        testInfo("remove item from empty queue", queue.deleteHead(), 100);
    } catch(std::runtime_error err) {
        printf("ERROR: %s\n", err.what());
    }

    // add and remove items from non-empty queue
    queue.appendTail(12); 
    queue.appendTail(99); 
    queue.appendTail(88); 
    testInfo("remove item from non-queue", queue.deleteHead(), 12);
    testInfo("remove item from non-queue", queue.deleteHead(), 99);
    testInfo("remove item from non-queue", queue.deleteHead(), 88);

    return 0;
}
