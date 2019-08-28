// 面试题38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
// 则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。


// 思路： 实质是实现排列，通过枚举法来实现全排列


#include <cstdio>

void permutationCore(char *, char *);
void strsPermutation(char *strs) {
    if (strs == nullptr)
        return ;
    permutationCore(strs, strs);
}

void permutationCore(char *strs, char *sub_strs) {
    if (*sub_strs == '\0') 
        printf("%s\t", strs);
    else {
        for (char *p_curr = sub_strs; *p_curr != '\0'; ++p_curr) {
            char temp = *p_curr; 
            *p_curr = *sub_strs; 
            *sub_strs = temp;
        
            permutationCore(strs, sub_strs+1);
            
            temp = *sub_strs;
            *sub_strs = *p_curr;
            *p_curr = temp;
        } 
        
    }
}

//==============================================================================
//              Test
//==============================================================================
//

 void Test(char* pStr)
{
    if(pStr == nullptr)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    strsPermutation(pStr);

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

    return 0;
}
