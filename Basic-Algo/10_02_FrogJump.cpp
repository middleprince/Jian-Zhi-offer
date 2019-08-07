// 题目10.2 青蛙跳台阶问题
// 一直青蛙一次可以跳上1级台阶，也可以跳上两级台阶。
// 求青蛙跳上一个 n 级台阶一共有多少种跳法。

//分析： 如果令 F(n) 表示 n 级台阶的跳法，当青蛙第一次跳1了一阶，
// 剩下的n-1 阶有 F(n-1)种跳法；如果第一次跳两阶则剩下的 n-2 阶
// 一共有F(n-2)中跳法。
// F(n) = F(n-2) + F(n-1)
// 这就是Fibonacci数列

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
