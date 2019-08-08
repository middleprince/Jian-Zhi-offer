// 题目10.4 矩形覆盖
// 有一矩形，她是由两个小正方形相接而成 。
// 现在有 有 八个这样的矩形拼接而成的大矩形，用小矩形去覆盖大的矩形，
// 有两种覆盖方法，一种横向覆盖一种是纵向覆盖；用8块小矩形覆盖大矩形，
// 问一共有多少种覆盖方式？
// 
//      []    [][][][][][][][]
//      []    [][][][][][][][]

// 分析：小矩形覆盖时，有两种方式；令F(n) 表示为n 矩形组成的大矩形的覆盖方式。
//  (1) 当小矩形竖放时， 剩下7个矩形有 F(7) 中方式；
//  (2) 当小矩形横放时， 必须放两个，剩下有 6 个矩形 F(6);
//  F(8) = F(7) + F(6) = F(6) + F(5) + F(5) + F(4) = ... 
//  这就是Fibonacci数列
//

#include <cstdio>
long long fibonacci(int n) {
    int num[2] = {0, 1};
    if (n < 2)
        return num[n];
    long long finbMinusOne = 1;
    long long finbMinusTwo = 0; 
    long long result = 0; 
    for (int i = 2; i <= n; ++i) {
        result = finbMinusOne + finbMinusTwo; 
        finbMinusTwo = finbMinusOne;
        finbMinusOne = result;
    }
    return result;
}

long long fibonacciRecursive(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return  fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}


//==============================================================================
//      Test 
//==============================================================================

void Test(int n, int expected) {
    printf("== test for fibonacci ==\n");
    if (fibonacci(n) == expected) 
        printf("PASS\n");
    else 
        printf("FAILED");
    
    printf("== test for fibonacciRecursive ==\n");
    if (fibonacci(n) == expected) 
        printf("PASS\n");
    else 
        printf("FAILED");

}

int main() {
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);

    return 0;
}
