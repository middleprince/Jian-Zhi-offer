// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18
//

#include <cstdio>
#include <cmath>

int maxDynamic(int rope_length) {
    if (rope_length < 2)
        return -1;
    if (rope_length == 2)
        return 1;
    if (rope_length == 3)
        return 2;
    
    int *result = new int[rope_length+1]{0};
    
    result[0] = 0; 
    result[1] = 1;
    result[2] = 2;
    result[3] = 3;
    
    // from bottom to up to cut rope which the rop from short to length 
    for (int i = 4; i <= rope_length; ++i) {
        int max = 0;
        // search for the best cut point
        for (int j = 1; j <= i/2; ++j) {
            if (max < j * result[i-j]) 
                max = j * result[i-j];
        } 
        result[i] = max;
    }


    return result[rope_length];
}

// cuting the rope to a smallest part which is 3; wherease  when rope's legth 
// is 4 cut it into 2 by 2.
int maxGreedy(int rope_length) {
    if (rope_length < 2)
        return -1;
    if (rope_length == 2)
        return 1;
    if (rope_length == 3)
        return 2;
   
    int counts_of_three = rope_length / 3;
    int counts_of_two = 0;
    // the tength of last one is 4
    if (rope_length - counts_of_three * 3 == 1) { 
        counts_of_three -= 1; 
    }
    counts_of_two = (rope_length - counts_of_three * 3) / 2;
        
   
    int result = (int)pow(3, counts_of_three) * (int)pow(2, counts_of_two);
    //printf("## debug: result is : %d\n" ,result);
    return result;
}

//=============================================================================
//          Test 
//=============================================================================

// 1. test for regular input. 
// 2. test for error input.
// 3. test for boundry conditions.
//

void testInfo(const char *msg, int length, int expected) {
    printf("== Test for %s begins\n", msg);
    printf("# test for Dynamic\n");
    if (maxDynamic(length) == expected)
        printf("PASS\n");
    else 
        printf("FAILED\n");
    
    printf("# test for Greedy\n");
    if (maxGreedy(length) == expected)
        printf("PASS\n");
    else 
        printf("FAILED\n");
}

void test1() {
    testInfo("1. regular input", 7, 12);
}

void test2() {
    testInfo("2. regular input", 9, 27);
}

void test3() {
    testInfo("3. regular input", 50, 86093442);
}

void test4() {
    testInfo("4. Boundry input", 2, 1);
}

void test5() {
    testInfo("5. Boundry input", 3, 2);
}

void test6() {
    testInfo("6. Error input", 1, -1);
}


int main() {

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    
    return 0;
}
