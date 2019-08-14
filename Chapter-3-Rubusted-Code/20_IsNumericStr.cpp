// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是
//
// 思路：分别拆分出数值字符创的模式，来分别判断。
//      模式， A[E|eC][.[B]] 或 .B[e|EC]
//      模式(1). A[E|eB] 科学技术法，以下情况：
//              合格：A 可以是 +/-, 0-9 字符，C 可为 +/-，0-9 字符; B 0-9 字符
//      模式(2): .B[e|EC] 同样可以表示小数，C 可为 +/-， 0-9 字符。

#include <cstdio>

bool isNumericStr(const char *);
bool scanUnsignDigit(const char **);
bool scanSignDigit(const char **);

bool isNumericStr(const char *nums) {
    if (nums == nullptr || *nums == '\0')
        return false;
    bool number = scanSignDigit(&nums);
   
    // pair the float number
    if (*nums == '.') {
        ++nums;     
        // three types: 1.23, .23, 23.
        number =  scanUnsignDigit(&nums) || number;
    }
    
    if (*nums == 'e' || *nums == 'E') {
        ++nums; 
        // exclude e23, 32e
        number =  scanSignDigit(&nums) && number; 
    }
    
    return number && *nums == '\0'; 
}
 
bool scanUnsignDigit(const char **nums) {
    const char *pre = *nums;
    // not including pair e/E and .
    while (**nums != '\0' && **nums >= '0' && **nums <= '9')
        ++(*nums);
    
    return *nums > pre;
}

bool scanSignDigit(const char **nums) {
    if (**nums == '+' || **nums == '-')
        ++(*nums);

    return scanUnsignDigit(nums);
}

//==============================================================================
//          Test 
//==============================================================================

void testInfo(const char* testName, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isNumericStr(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
    testInfo("Test1", "100", true);
    testInfo("Test2", "123.45e+6", true);
    testInfo("Test3", "+500", true);
    testInfo("Test4", "5e2", true);
    testInfo("Test5", "3.1416", true);
    testInfo("Test6", "600.", true);
    testInfo("Test7", "-.123", true);
    testInfo("Test8", "-1E-16", true);
    testInfo("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    testInfo("Test10", "12e", false);
    testInfo("Test11", "1a3.14", false);
    testInfo("Test12", "1+23", false);
    testInfo("Test13", "1.2.3", false);
    testInfo("Test14", "+-5", false);
    testInfo("Test15", "12e+5.4", false);
    testInfo("Test16", ".", false);
    testInfo("Test17", ".e1", false);
    testInfo("Test18", "e1", false);
    testInfo("Test19", "+.", false);
    testInfo("Test20", "", false);
    testInfo("Test21", nullptr, false);

    return 0;
}
