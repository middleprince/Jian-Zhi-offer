// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

 #include <cstdio>

bool duplicate(int numbers[], int len, int *duplication) {
    if (numbers == nullptr || len <= 0)
        return false;
    
    for (int i = 0; i < len; ++i)
        if (numbers[i] < 0 || numbers[i] > len-1)
            return false;
    
    for (int i = 0; i < len; ++i) {
        while (numbers[i] != i) {
            if (numbers[i] == numbers[numbers[i]] ){
                *duplication = numbers[i]; 
                return true;
            }  
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}

// test code 

bool contains(int array[], int length, int number) {
    for (int i = 0; i < length; ++i) {
        if (array[i] == number)
            return true;
    }
    return false;
}

void test(const char *test_name, int numbers[], int length, int expected[], 
        int expected_count, bool validArgument) {
    printf("%s begins\n", test_name);
   
    int duplicatoin;
    bool result = duplicate(numbers, length, &duplicatoin);
    if (result == validArgument) {
        if (validArgument) {
            if (contains(expected, expected_count, duplicatoin)) 
                printf("PASS \n");
            else 
                printf("FAILED \n");
        } else
            printf("PASS \n");
    } else
        printf("FAILED \n");
}


void testOneDup() {
    int numbers[] = {1, 4, 5, 3, 6, 7, 0, 3};
    int dupArray[] = {3};
    test("Test for one duplication", numbers, sizeof(numbers) / sizeof(int),
            dupArray, sizeof(dupArray) / sizeof(int), true); 
}

// test for more than one duplacated numbers
void testMoreDup() {
    int numbers[] = {1, 4, 5, 3, 6, 7, 0, 3, 4};
    int dupArray[] = {3, 4};
    test("Test for more than one duplication", numbers, sizeof(numbers) / sizeof(int),
            dupArray, sizeof(dupArray) / sizeof(int), true); 
}

// test for no duplication
void testNoDup() {
    int numbers[] = {1, 4, 5, 3, 6, 7, 0, 13, 14};
    int dupArray[] = {-1};
    test("Test for no duplication", numbers, sizeof(numbers) / sizeof(int),
            dupArray, sizeof(dupArray) / sizeof(int), false); 
}

// test for erro input 
void testError() {
    int numbers[] = {-1};
    int dupArray[] = {-1};
    test("Test for item contain error one", numbers, sizeof(numbers) / sizeof(int),
            dupArray, sizeof(dupArray) / sizeof(int), false); 

    int *numbers_void = nullptr;
    test("Test for void array ", numbers_void, sizeof(numbers_void) / sizeof(int),
            dupArray, sizeof(dupArray) / sizeof(int), false); 

}

int main() {
    testError(); 
    testOneDup();
    testMoreDup();
    testNoDup();
    return 0;
}
