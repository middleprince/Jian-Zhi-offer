// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。
//

// 分析：这是一个典型的数组遍历的问题，可以使用「双指针」加快效率是
//  时间复杂度O(1), 空间复杂度O(1);
//  头指针与尾指指针，遍历比较，根据结果来交换元素。
//
//  这样的数组特定重排的操作可以 抽象出公共的框架，通过传入不同的比较算法
//  实现不同的重排要求。
//

#include <cstdio>

bool isEven(int);

int rearrangeArray(int *nums, unsigned int length, bool (*func)(int)) {
    if (nums == nullptr || length <= 0)
        return -1;

    unsigned int front = 0;
    unsigned int back = length-1;

    while (front < back) {
        // 从前往后定位
        while (front < back && !func(nums[front]))  
           ++front; 

        // 从后往前定位
        while (front < back && func(nums[back]))
            --back;
            
        if (front < back ) {
            nums[front] ^= nums[back];
            nums[back] ^= nums[front];
            nums[front] ^= nums[back];
        }
            
    }

    return 0;
}

bool isEven(int n) {
    return n % 2 == 0;
}


//========================================================================
//          Test  
//========================================================================

void PrintArray(const int numbers[], int length)
{
    if(length < 0)
        return;

    for(int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void testInfo(const char* testName, const int numbers[], int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
    {
        copy[i] = numbers[i];
    }

    printf("#Array before rearrange: \n");
    PrintArray(copy, length);
    rearrangeArray(copy, (unsigned int)length, isEven);
    PrintArray(copy, length);

    delete[] copy;
}

void Test1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    testInfo("Test1", numbers, sizeof(numbers)/sizeof(int));
}

void Test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    testInfo("Test2", numbers, sizeof(numbers)/sizeof(int));
}

void Test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    testInfo("Test3", numbers, sizeof(numbers)/sizeof(int));
}

void Test4()
{
    int numbers[] = {1};
    testInfo("Test4", numbers, sizeof(numbers)/sizeof(int));
}

void Test5()
{
    int numbers[] = {2};
    testInfo("Test5", numbers, sizeof(numbers)/sizeof(int));
}

void Test6()
{
    testInfo("Test6", nullptr, 0);
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
