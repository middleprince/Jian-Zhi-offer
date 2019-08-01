
// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。


#include <cstdio>

int countInRange(const int* a, int length, int start, int end) {
    if (a == nullptr)
        return 0;
    int count = 0;
    for (int i = 0; i < length; ++i)
        if (a[i] >= start && a[i] <= end)
            ++count;
    return count;
}

int isDuplictedArray(const int *intA, int length) {
    if (intA == nullptr || length <= 0)
            return -1;
    int start = 1;
    int end = length - 1;
    
    while (start <= end) {
        // using bit moving opreator to improve efficient
        int middle = ((end-start) >> 1) + start;
        
        int range_count = countInRange(intA, length, start, middle);
        if (end == start) {
            if (range_count > 1) 
                return start;
            else 
                break;
        }
        
        if (range_count > (middle - start + 1))
            end = middle;
        else 
            start = middle + 1;
    } 
    return -1;

}

//==============================================================================
//      Test functions
//==============================================================================

void testForErrorAndNone() {
    int errorA[] = {0};
    int non[] = {1, 2, 3};
    int* errorB = nullptr;
    printf("## expected print: -1\n");
    printf("Results is: %d\n", isDuplictedArray(errorA, 0));
    printf("## expected print: -1\n");
    printf("Results is: %d\n", isDuplictedArray(errorB, 10));
    printf("## expected print: -1\n");
    printf("Results is: %d\n", isDuplictedArray(non, sizeof(non) / sizeof(int)));
}

void testForOnes() {
    int A[] = {1, 2, 3, 4, 5, 3};
    int B[] = {1, 2, 3, 2, 4, 5, 4, 6};
    printf("## expected print: 3\n");
    printf("Results is: %d\n", isDuplictedArray(A, sizeof(A) / sizeof(int)));
    printf("## expected print: 4\n");
    printf("Results is: %d\n", isDuplictedArray(B, sizeof(B) / sizeof(int)));
}

int main() {
    testForErrorAndNone();
    testForOnes();
    return 0;
}

