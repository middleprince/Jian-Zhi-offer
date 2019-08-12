//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题15.2：判断一个整数是不是2 的整数次方
//

#include <cstdio>

bool isDividByTwo(int num) {
    if (num == 0)
        return false;
    unsigned abs_num = 0;
    if (num < 0)
        abs_num = (unsigned int)-num; 
    else 
        abs_num = (unsigned int)num;

    if (abs_num & (abs_num-1)) 
        return false;
    return true;

}
// ========================================
//      Test
// ========================================
//
void Test(const char *msg, int number, bool expected)
{
    printf("== test %s begins ==\n", msg);
    bool actual = isDividByTwo(number);
    if (actual == expected)
        printf("PASS.\n");
    else
        printf("FAILED.\n");

        printf("\n");
}

int main()
{
    Test("1. num is 0", 0, false);

    Test("2. num -8", -8, true);

    Test("3. num is 1024", 1024, true);

    return 0;
}
