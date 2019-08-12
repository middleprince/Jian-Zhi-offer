//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。
//

#include <cstdio>

int countOneV1(int num) {
    int count = 0;
    
    unsigned int flag = 1;
    while (flag) {
        if (flag & num)
            ++count;
        flag <<= 1; 
    }
    return count;
}

int countOneV2(int num) {
    int count = 0;
    while (num) {
        ++count;
        num = num & (num-1);
    }
    return count;
}

// ========================================
//      Test
// ========================================
//
void Test(int number, unsigned int expected)
{
    int actual = countOneV1(number);
    if (actual == expected)
        printf("Solution1: Test for %d passed.\n", number);
    else
        printf("Solution1: Test for %d failed.\n", number);

    actual = countOneV2(number);
    if (actual == expected)
        printf("Solution2: Test for %d passed.\n", number);
    else
        printf("Solution2: Test for %d failed.\n", number);

    printf("\n");
}

int main()
{
    // 输入0，期待的输出是0
    Test(0, 0);

    // 输入1，期待的输出是1
    Test(1, 1);

    // 输入10，期待的输出是2
    Test(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(-1, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);

    return 0;
}
