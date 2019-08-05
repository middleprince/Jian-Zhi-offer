//题5.2 相关题目
// 现在两排序数组A、B；A数组中有足够的空间可以容纳数组B的元素，现在实现将
// B 中的所有的元素插入到A 数组中，使得插入后的元素有序。
//

#include <cstdio>

int catArray(int a[], int a_length, int b[], int b_length) {
    if (a == nullptr || b == nullptr)
        return -1;

    // idex for end of array a
    int new_end_a = 0;
    // index of array b
    int end_b = b_length-1;
    
    while (a[new_end_a] != 9999)
        ++new_end_a;
    int old_end_a = new_end_a;
    new_end_a += b_length; 

    if (new_end_a > a_length) {
        printf("# debug a length is short\n");
        return -1;
    }
    
    // scan from back of a and b to insert item into a  reversely
    while (old_end_a >= 0 && end_b >= 0) {
        if (a[old_end_a] > b[end_b])
            a[new_end_a--] = a[old_end_a--];
        else
            a[new_end_a--] = b[end_b--];
    }
    while (old_end_a >= 0)
        a[new_end_a--] = a[old_end_a--];
    
    while (end_b >= 0)
        a[new_end_a--] = a[end_b--];
    
    return 0;
}

//=============================================================================
//      Test function
//=============================================================================
//

bool equalArray(int a[], int a_length, int b[], int b_length) {
    for (int i = 0; i < a_length && i < b_length ; ++i) {
        if (a[i] == b[i]) 
            continue;
        else
            return false;
    }
    return true; 
}

void testInfo(const char *testName, int A[], int lengthA, int B[], 
        int lengthB, int expected[], int lengthE)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    catArray(A, lengthA, B, lengthB);

    if(expected == nullptr && A == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && A != nullptr)
        printf("failed.\n");
    else if(equalArray(A, lengthA, expected, lengthE))
        printf("passed.\n");
    else
        printf("failed.\n");
}

void testError() {
    int *a = nullptr;
    int b[] = {1, 2, 3};
    int *c = nullptr;

    testInfo("test for array pointer pointed nullpttr", a, 0, b, 3, c, 0);
}

void testequal() {
    int a[30] = {1, 2, 3, 9999};
    int b[] = {1, 2, 3};
    int c[] = {1, 1, 2, 2, 3, 3};

    testInfo("test for two equal array", a, sizeof(a) / sizeof(int), 
            b, sizeof(b) / sizeof(int), c, sizeof(c) / sizeof(int));
}

void testInterset() {
    int a[30] = {1, 2, 5, 8, 9999};
    int b[] = {1, 3, 9};
    int c[] = {1, 1, 2, 3, 5, 8, 9};

    testInfo("test for two  array overlaped", a, sizeof(a) / sizeof(int), 
            b, sizeof(b) / sizeof(int), c, sizeof(c) / sizeof(int));
}

void testNoOverlap() {
    int a[30] = {1, 2, 5, 8, 9999};
    int b[] = {10, 20};
    int c[] = {1,  2,  5, 8, 10 , 20};

    testInfo("test for two  array not  overlaped", a, sizeof(a) / sizeof(int), 
            b, sizeof(b) / sizeof(int), c, sizeof(c) / sizeof(int));
}

int main() {
    testError();
    testequal();
    testInterset();
    testNoOverlap();
    return -1; 
}
