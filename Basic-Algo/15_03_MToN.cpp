//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题15.3.
// 输入两个整数 m, n, 计算需要改变m 中的多少二进制位才能够得到n
//

#include <cstdio>

int mTon(int m, int n) {
    int diferrence = m ^ n; 

    int n_bit = 0;
    while (diferrence) {
        ++n_bit;
        diferrence = diferrence & (diferrence - 1);
    }

    return n_bit;

}
// ========================================
//      Test
// ========================================
//
void Test(const char *msg, int m, int n, int expected)
{
    printf("== test %s begins ==\n", msg);
    int actual = mTon(m, n);
    if (actual == expected)
        printf("PASS.\n");
    else
        printf("FAILED.\n");

        printf("\n");
}

int main()
{
    Test("1. m = 1, n = 0", 1, 0, 1);

    Test("2. m = 2, n = 0", 2, 0, 1);
    
    Test("3. m = 0, n = 0", 0, 0, 0);
    
    Test("4. m = 32, n = 1", 32, 1, 2);

    return 0;
}
