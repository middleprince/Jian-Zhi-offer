
// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。
//

// 思路：建立一个辅助 stack 来记录成员stack 中最小的元素。
//       辅助记录stack：对成员stack 的每次入栈进行数据比较记录：
//          a. 入栈元素比当前辅助stack 栈顶元素小，push 入辅助stack
//          b. 入栈元素比当前的辅助stack栈顶的元素大，不做入栈处理。
//       当成员stack 需要出栈时，同样比较给辅助stack 中栈顶元素比较。
//          a. 出栈元素与辅助stack 栈顶元素相等，则辅助stack 也出栈。
//          b. 出栈元素不等于辅助stack 栈顶元素，不对辅助stack 处理。
//      任何时刻，辅助stack 中的栈顶元素是成员stack 中的最小元素。  
//

#ifndef _30_MINISTACK_H
#define _30_MINISTACK_H

#include <cstdio>
#include <stack>
#include <cassert>

template <typename T>
class StackWithMin {
public:
    StackWithMin() = default;
    ~StackWithMin() = default;

    T& top();
    const T& top() const;
    
    void push(const T &value);
    void pop();

    const T& min() const;
    bool empty() const;
    size_t size() const;

private:
    std::stack<T> _data;
    std::stack<T> _min;
};

template <typename T> 
T& StackWithMin<T>::top() {
        return _data.top();

}

template <typename T> 
const T& StackWithMin<T>::top() const {
        return _data.top();
}


template <typename T> 
void StackWithMin<T>::push(const T &value) {
    _data.push(value);
    if (_min.size() == 0 || _min.top() > value)
        _min.push(value);
    else 
        _min.push(_min.top());
}

template <typename T>
void StackWithMin<T>::pop() {
    assert(_data.size() > 0 && _min.size() > 0);
    _data.pop();
    _min.pop();
}

template <typename T>
const T& StackWithMin<T>::min() const {
    assert(_data.size() > 0 && _min.size() > 0);
    return _min.top();
}

template <typename T>
bool StackWithMin<T>::empty() const {
    return _data.empty();
}


template <typename T>
size_t StackWithMin<T>::size() const {
    return _data.size();
}

#endif
