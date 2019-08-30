// 38.2 求解给定的符串的所有组合
// 输入： a, b, c 输出： a, b, c, ab, ac, bc, abc
//

// 思路：同样使用递归的思想来实现，就是从 n 个字符中选择 m 个字符 (1 <= m <= n)
// 1. 在n个字符中选择，第一个字符选中如组合中；在剩下 n-1 个字符中选择 m-1  个字符。
// 2. 在n个字符中选择，第一个字字符不被选中；则在剩下n-1 个字符中选择 m 个字符。

#include <cstdio>
#include <cstdlib>
#include <vector>
using std::vector;

void strsCombinationCore(char *, int, vector<char>&);
void strsCombination(char *strs) {
    if (strs == nullptr)
        return ;
    vector<char> str_vec{};
    int length = static_cast<int>(strlen(strs));
    
    for (int i = 1; i <= length; ++i)
        strsCombinationCore(strs, i, str_vec); 
}

void strsCombinationCore(char *strs, int index, vector<char> &str_vec) {
    if (strs == nullptr)  
        return ;
    
    // 列举组合完毕
    if (index == 0) {
        for (auto iter = str_vec.cbegin(); iter != str_vec.cend(); ++iter)
            printf("%c", *iter);
        printf("\n");
        return ;
    }

    if (*strs == '\0')
        return ;

    str_vec.push_back(*strs);

    strsCombinationCore(strs+1, index-1, str_vec);
    str_vec.pop_back();
    strsCombinationCore(strs+1, index, str_vec);
}

// 使用binary bits 来选择组合。
// n 个字符可以组成 2^n -1 种组合，使用二进制位来选择组合

void strsCombinationBinary(char *strs) {
    if (strs == nullptr)
        return ;
    
    int length = static_cast<int>(strlen(strs));
    // 2^n - 1 种情况
    for (int curr = 1; curr < (1 << length) ; ++curr) {
        for (int j = 0; j < length; ++j) {
            if (curr & (1 << j))  // curr 位组合在strs中index的位置
                printf("%c", *(strs+j));
        } 
        printf("\n");
    }
}

//==============================================================================
//              Test
//==============================================================================

 void Test(char* pStr)
{
    if(pStr == nullptr)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    printf("\n====strs combination recursively ==\n");
    strsCombination(pStr);
    printf("\n");

    printf("\n====strs combination by binary bits==\n");
    strsCombinationBinary(pStr);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(nullptr);

    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "ab";
    Test(string3);

    char string4[] = "abc";
    Test(string4);
    
    char string5[] = "abcde";
    Test(string5);

    return 0;
}

