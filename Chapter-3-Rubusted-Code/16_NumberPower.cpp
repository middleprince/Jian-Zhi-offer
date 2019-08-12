// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。
//

// 分析：
// 1. 指数的为负数的问题。
// 2. 底数为负数的问题。
// 3. 小数的的近似比较的问题。

#include <cstdio>

extern bool valid_input;
bool valid_input = false;
const double boundry = 1e-8;

bool equalDouble(double a1, double a2) {
    if ((a1 - a2 < boundry) && (a2 - a1 > -boundry))
        return true;
    return false;
}

double PowerV1Core(double base, unsigned int exponent) {
    double result = 1.0;
    for (double i = 0; i <= exponent; ++i) {
        result *= base; 
    }
    return result;
}

double PowerV1(double base, int exponent) {
    valid_input = false;

    if (exponent == 0)
        return 1;
    
    if (equalDouble(base, 0.0) && exponent < 0) {
        valid_input = true; 
        return 0.0;
    }
    
    unsigned int abs_exponent = (unsigned int)exponent; 
    if (exponent < 0) 
        abs_exponent = (unsigned int)-exponent; 
    double result = PowerV1Core(base, abs_exponent);    
    
    result = (exponent > 0 ? result : 1 / result); 
    
    return result;
}

// compute by recursive

double PowerV2Core(double base, unsigned int exponent) {
    if (exponent == 0)
        return 1.0; 
    if (exponent == 1)
        return base;
    
    double result = PowerV1Core(base, exponent >> 1);
    result *= result;
    if ((exponent&1) == 1)
        result *= base;
    return result;
}

double PowerV2(double base, int exponent) {
    valid_input = false;

    if (exponent == 0)
        return 1;
    
    if (equalDouble(base, 0.0) && exponent < 0) {
        valid_input = true; 
        return 0.0;
    }
    
    unsigned int abs_exponent = (unsigned int)exponent; 
    if (exponent < 0) 
        abs_exponent = (unsigned int)-exponent; 
    double result = PowerV1Core(base, abs_exponent);    
    
    result = (exponent > 0 ? result : 1 / result); 
    
    return result;
}
//==============================================================================
//      Test 
//==============================================================================

void testInfo(const char *msg, double base, int exponent, double expected, bool expected_flag) {
    printf("== test for %s begins \n", msg);
    printf("## test for v1\n");
    if (equalDouble(expected, PowerV1(base, exponent)) && valid_input == expected_flag)
        printf("PASS\n");
    else
        printf("FAILED\n");
    
    printf("## test for v2\n");
    if (equalDouble(expected, PowerV2(base, exponent)) && valid_input == expected_flag)
        printf("PASS\n");
    else
        printf("FAILED\n");
    
    printf("\n");
}


int main(int argc, char* argv[])
{
    // 底数、指数都为正数
    testInfo("1. base > 0, exponent > 0", 2, 3, 8, false);

    // 底数为负数、指数为正数
    testInfo("2. base < 0, exponent > 0", -2, 3, -8, false);

    // 指数为负数
    testInfo("3. base < 0, exponent < 0", 2, -3, 0.125, false);

    // 指数为0
    testInfo("4. base != 0, exponent = 0", 2, 0, 1, false);

    // 底数、指数都为0
    testInfo("5. base = 0, exponent = 0 ", 0, 0, 1, false);

    // 底数为0、指数为正数
    testInfo("6. base 0, exponet > 0", 0, 4, 0, false);

    // 底数为0、指数为负数
    testInfo("7. base 0, exponent < 0", 0, -4, 0, true);

    return 0;
}
