// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
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
