// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

// 分析：
//  能够看处旋转数组可以将其分为两个子数组，都是递增的数组；其中前半部分的
//  数组A 整体大于后半部分的数组 B。
//  算法设计： 它们都是有序的关系，直接进行遍历不够高效，可以用二分法来实现
//  查找。 分别设置 start，end指针； middle = (start + end) / 2.
//      比较*start， *middle， *end, 来细分定位具体的区间：
//      (1) *start <= *middle && *middle >= *end, start = middle 
//      (2) *start <= *middle && *middle <= *end, end = millde
//      直到 satrt+1 < end, 找到最小元素 *(middle + 1)
//
//      a {3, 4, 5, 1, 2}
//  注意：特例的情况。
//      
//      b.1 (0, 1, 1, 1, 1) -> (1, 0, 1, 1, 1) 
//      b.2 (0, 1, 1, 1, 1) -> (1, 1, 1, 0, 1) 
//      中间index 与 middle end 相同则无法比较， 这是必须用遍历
//      c. (1, 2, 3, 4, 5) -> (1, 2, 3, 4, 5) 也算是旋转数组
//

#include <cstdio>
#include <cstdlib>

int miniRotateScan(int[], int, int);

int miniRotateArray(int nums[], int length) {
    if (nums == nullptr || length <= 0)
        return -1;
    
    int  start = 0, end = length - 1;
    int middle = (start+length) / 2;
    if (nums[start] < nums[middle] && nums[middle] < nums[end])
        return nums[start];
    
    while (nums[middle] <= nums[middle+1]) {
        if (nums[start] == nums[middle] && nums[middle] == nums[end]) 
            return miniRotateScan(nums, start, end);
        else if (nums[start] <= nums[middle] && nums[middle] >= nums[end])
            start = middle;
        else if (nums[start] >= nums[middle] && nums[middle] <= nums[end])
            end = middle;
        else 
            ;
        
        middle = (start + end) / 2;
    }

    return nums[middle+1];
     
}

int miniRotateScan(int nums[], int start, int end) {
    int result = nums[0];
    while (start <= end) {
        if (nums[start] < result)
            result = nums[start];
        ++start;
    }
    return result;
}

//=============================================================================
//      Test 
//=============================================================================

// test for cases a, b, c, and error input

void Test(const char *msg, int nums[], int length, int expected) {
    printf("== test for %s begins\n", msg);
    if (msg == nullptr || length <= 0) {
        if (miniRotateArray(nums, length) == expected) 
            printf("PASS\n");
        else 
            printf("FAILED\n");
        return;
    }
    
    if (miniRotateArray(nums, length) == expected) 
        printf("PASS\n");
    else 
        printf("FAILED\n");

}

void testError() {
    int *nums = nullptr;
    int num2[] = {1, 2, 3};
    Test("nulptr num error", nums, 1, -1);
    Test("length eror", num2, 0, -1);
}

void testB() {
    int nums1[] = {1, 0, 1, 1, 1};
    int nums2[] = {1, 1, 1, 0, 1};
    Test("case b.1", nums1, 5, 0);
    Test("case b.2", nums2, 5, 0);
}

void testC() {
    int nums1[] = {3, 4, 8, 9, 10};
    int nums2[] = {1, 2, 3, 4, 5};
    Test("case c.1", nums1, 5, 3);
    Test("case c.2", nums2, 5, 1);
}

void testA() {
    int nums1[] = {3, 4, 5, 1, 2};
    int nums2[] = {7, 8, 9, 0, 1};
    int nums3[] = {7, 8, 9, 10, 12, 3, 4};
    Test("case a.1", nums1, 5, 1);
    Test("case a.2", nums2, 5, 0);
    Test("case a.3", nums3, 7, 3);
}

int main() {
    testError();
    testA();
    testB();
    testC();

    return 0;
}
