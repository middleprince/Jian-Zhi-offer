// 题目10.3 青蛙跳台阶，它一次可以跳上1个台阶，也可以跳上2个台阶，
// 3个台阶，..., n个台阶。
// 问 跳n阶台阶有多少种方法？
//

// 分析：
// 同样 设F(n) 为跳上 n 台阶有的方式。
// 当第一次跳上 1 台阶是，剩下的 n-1 台阶有 F(n-1) 种跳法；如果第一次跳2阶，
// 则剩下的 n-2 阶有 F(n-2) 种跳法；... ;类推第一次跳 n 阶有 1 种跳法。
//
//  F(n) = F(n-1) + F(n-2) + ... + F(1)              (1)
//  F(n-1) = F(n-2) + F(n-3) + ... + F(1)            (2)
//  (1) - (2) : F(n) = 2 * F(n-1)
//  递推: F(n) = 2 * 2 * F(n-2) ...
//        F(n) = 2 ^ (n-1) * F(1) => F(n) = 2 ^ (n-1)
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

long double frogJumpNsteps(int n) {
    if (n <= 0)
        throw std::runtime_error("invalid input");
    return powl(2, n-1);
}

void test(int n, long double expected) {
    try {
        if (frogJumpNsteps(n) == expected)
            printf("PASS\n");
        else 
            printf("FAILED\n");
    } catch(std::runtime_error err) {
        printf("ERROR: %s", err.what());
    }
}

int main() {
    test(1, 1); 
    test(2, 2); 
    test(3, 4); 
    test(0, 4); 
    return 0;
}
