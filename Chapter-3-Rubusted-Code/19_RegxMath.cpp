// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

// 思路：迭代得来匹配子串。
// (1). 当前模式串中 ch_match 与匹配字符串中 ch 匹配，则继续向后匹配。
// (2). 当前模式串中 ch_match 为 . , 则与匹配字符串中任何字符匹配，继续向后匹配。
// (3). 当前模式串中 ch_match+1 为 * , 有两中选择：
//      (3).1 ch_match 与 ch 不匹配，抛弃 * 之前的 ch_match, 向后移动两个位置，继续匹配。
//      (3).2 ch_match 与 ch 匹配，因为 * 之前任何字符可以出现任意次， 则可以有两种状态选择:
//          (3.2).1 math_ch 出现一次，向后2位置，继续匹配。
//          (3.2).2 math_ch 出现多于一次， match_ch 保持在当前位子。
//  考虑嵌套的情况
//

#include <cstdio>

bool regMatch(const char *, const char *);
bool regMatchCore(const char *, const char *);

bool regMatch(const char *strs, const char *pattern) {
    if (strs == nullptr || pattern == nullptr)
        return false; 
    return regMatchCore(strs, pattern);
}

bool regMatchCore(const char *strs, const char *pattern) {
    if (*strs == '\0' && *pattern == '\0')
        return true;
    
    if (*strs != '\0' && *pattern == '\0') 
        return false;

    if (*(pattern+1) == '*') {
        // when * following *
        if (*pattern == *strs || (*pattern == '.' && *strs != '\0')) {
            return regMatchCore(strs+1, pattern+2) // state 1: pattern occurs once 
                || regMatchCore(strs+1, pattern)  // state 2: pattern occurs more than once.
                || regMatchCore(strs, pattern+2); // state 3: pattern occurs none
        } 
        else {
            return regMatchCore(strs, pattern+2); 
        }
    }

    if ((*pattern == *strs) || (*pattern == '.' && *strs != '\0'))
        return regMatchCore(strs+1, pattern+1);

    return false;
}


//=======================================================================================
//      Test 
//=======================================================================================

void testInfo(const char* testName, const char* string, const char* pattern, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(regMatch(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    testInfo("Test01", "", "", true);
    testInfo("Test02", "", ".*", true);
    testInfo("Test03", "", ".", false);
    testInfo("Test04", "", "c*", true);
    testInfo("Test05", "a", ".*", true);
    testInfo("Test06", "a", "a.", false);
    testInfo("Test07", "a", "", false);
    testInfo("Test08", "a", ".", true);
    testInfo("Test09", "a", "ab*", true);
    testInfo("Test10", "a", "ab*a", false);
    testInfo("Test11", "aa", "aa", true);
    testInfo("Test12", "aa", "a*", true);
    testInfo("Test13", "aa", ".*", true);
    testInfo("Test14", "aa", ".", false);
    testInfo("Test15", "ab", ".*", true);
    testInfo("Test16", "ab", ".*", true);
    testInfo("Test17", "aaa", "aa*", true);
    testInfo("Test18", "aaa", "aa.a", false);
    testInfo("Test19", "aaa", "a.a", true);
    testInfo("Test20", "aaa", ".a", false);
    testInfo("Test21", "aaa", "a*a", true);
    testInfo("Test22", "aaa", "ab*a", false);
    testInfo("Test23", "aaa", "ab*ac*a", true);
    testInfo("Test24", "aaa", "ab*a*c*a", true);
    testInfo("Test25", "aaa", ".*", true);
    testInfo("Test26", "aab", "c*a*b", true);
    testInfo("Test27", "aaca", "ab*a*c*a", true);
    testInfo("Test28", "aaba", "ab*a*c*a", false);
    testInfo("Test29", "bbbba", ".*a*a", true);
    testInfo("Test30", "bcbbabab", ".*a*a", false);

    return 0;
}
