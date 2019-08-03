// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include <cstdio>
#include <cstring>

int replaceBlankChar(char string[], int length) {
    
    if (string == nullptr || length <= 0)
        return -1;
    int original_end = 0;
    int space_count = 0;

    while (string[original_end] != '\0') {
        if (string[original_end] == ' ') 
            ++space_count;
        ++original_end;

        continue;
    }
    
    // calculate the length of replaced string
    int new_end = original_end + space_count * 2; // bug fixed
    
    if (new_end >= length)
        return -1;
    string[new_end--] = string[original_end--];
   
    while (new_end != original_end && original_end >= 0) { // original_end must
        // >= 0, for only one char in string
       if (string[original_end] == ' ') {
           string[new_end--]  = '0';
           string[new_end--]  = '2';
           string[new_end--]  = '%';
       } else
           string [new_end--] = string[original_end];
       --original_end;
    }
    return 0;
}

//==============================================================================
//      Test function
//==============================================================================
// 1. test for nullptr
// 2. test for legth is too short
// 3. test for string contians no space
// 4. test for correct input 

void Test(char* testName, char str[], int length, char expected[])
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    replaceBlankChar(str, length);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}

