// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

// 大数的存储打印问题，使用数组的存储。

#include <cstdio>
#include <memory>
#include <cstring>

void printNumber(const char *);
bool incement(char *);
void incementByPermutation(char *, int, char);

int printFromOneToN(int n) {
    if (n <= 0)
        return -1;     
    char *number = new char[n+1];
    memset(number, '0', (size_t)n);
    number[n] = '\0';
    
    while (!incement(number)) {
        printNumber(number); 
    }

    delete[] number;
    return 0;
}

bool incement(char *number) {
    bool overflow = false;
    int length = (int)strlen(number);
    //printf("##debug length is: %d", length);
    char n_sum_up = 0;

    for (int i = length - 1; i >= 0; --i)  {
        char sum = number[i] - '0' + n_sum_up; 
        if (i == length - 1)
            ++sum;
        
        if (sum >= 10) {
            if (i == 0) 
                overflow = true;
            else{
                sum -= 10; 
                n_sum_up = 1;
                number[i] = '0' + sum;
            }
        } 
        else {
            number[i] = '0' + sum;
            break;
        }
    }
    return overflow;
}

void printNumber(const char *number) {
    bool is_beg_zero = true;
    int length = (int)strlen(number);
    
    for (int i = 0; i < length ; ++i) {
        if (is_beg_zero && number[i] != '0')
            is_beg_zero = false;
        if (!is_beg_zero)
            printf("%c", number[i]);
    }

    printf("\t");
}



// using permutation to print it recuersively

int printFromOneToNRecursively(int n) {
    if (n <= 0)
        return -1;
    
    char *number = new char[n+1]; 
    number[n] = '\0'; 

    // set the highest bit from 1 to 9
    for (char i= 0; i < 10; ++i) {
        number[0] = '0' + i; 
        incementByPermutation(number, n, 0);
    }
    delete[] number;
    return 0;
}

// permutation for n-1 digits
void incementByPermutation(char *number, int length, char index) {
    // when reach the last digit, print it.
    if (index == length-1) {
        printNumber(number); 
        return ;
    }
    
    // permutaion core sectoin
    for (char i = 0; i < 10; ++i) {
        // incrememt for digit from 0 to 9 combine each digit
        number[index + 1] = i + '0';
        incementByPermutation(number, length, index+1);
    }
}

//=============================================================================
//          Test 
//=============================================================================

int main() {
    printFromOneToN(2);
    printf("\n");
    printf("\n");

    printFromOneToNRecursively(3);
    printf("\n");

    return 0;


}

