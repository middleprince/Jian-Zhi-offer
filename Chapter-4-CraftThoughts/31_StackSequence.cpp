//面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。
//

// 思路： 通过入栈出栈的可还原来判断。
//        将入栈序列 一边入栈一边和出栈序列进行比较：
//        1. 入栈序列直到和出栈序列当前的值相等，停止入栈；弹出当前相等的数字
//           并且将 出栈序列向后移动。
//        2. 入栈序列完毕就和出栈序列比较，栈顶与出栈序列首元素相等：出栈
//           且入栈序列后移。
//        知道入栈序列为空后，就可以判断出栈序列与入栈序列匹配；否则不匹配。 

#include <cstdio>
#include <stack>

bool isStackSeqsMatch(const int *in_nums, const int *out_nums, int length) {
    bool result = false;
    if (in_nums != nullptr && out_nums != nullptr && length > 0) {
        const int *in_next = in_nums; 
        const int *out_next = out_nums; 

        std::stack<int> in_stack{};

        while (out_next - out_nums < length) {
            while (in_stack.empty() || in_stack.top() != *out_next) { 
                if (in_next - in_nums == length)
                    break;
                in_stack.push(*in_next);
                ++in_next;
            }
            
            if (in_stack.top() != *out_next)
                break;
            
            in_stack.pop();
            ++out_next;
        }

        if (in_stack.empty() && out_next - out_nums == length)
            result = true;
    }
    return result;
}


//==============================================================================
//      Test 
//==============================================================================
//

void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isStackSeqsMatch(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};
    
    Test("Test1", push, pop, nLength, true);
}

void Test2()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};
    
    Test("Test2", push, pop, nLength, true);
}

void Test3()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};
    
    Test("Test3", push, pop, nLength, false);
}

void Test4()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};
    
    Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test("Test6", push, pop, nLength, true);
}

void Test7()
{
    Test("Test7", nullptr, nullptr, 0, false);
}
 
int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
