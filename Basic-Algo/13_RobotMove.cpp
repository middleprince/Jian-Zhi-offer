// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
//

#include <cstdio>
#include <new>

int sumDigits(int n);
int moveBlockCoreFunc(int row, int col, int rows, int cols, 
        int threshold, bool *visited);
bool checkMove(int row, int col, int rows, int cols, 
        int threshold, bool *visit);

int moveBlockN(int rows, int cols, int threshold) {
    if (rows <= 0 || cols <= 0 || threshold < 0)
        return -1;
    
    bool *visited = new bool[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
        visited[i] = false; 
    }

    int move_count = moveBlockCoreFunc(0, 0, rows, cols, threshold, visited);
    
    delete[] visited; 
    
    return move_count;
}

int sumDigits(int n) {
    int ret = 0;
    while ( n > 0) {
        ret +=n % 10;
        n /= 10;
    }
    return ret;
}

int moveBlockCoreFunc(int row, int col, int rows, int cols, 
        int threshold, bool *visited) {

    int result = 0;

    if (checkMove(row, col, rows, cols , threshold, visited)) {

        visited[row*cols + col] = true; 
        result = 1 + moveBlockCoreFunc(row, col - 1, rows, cols , threshold, visited)    
                   + moveBlockCoreFunc(row - 1, col, rows, cols ,threshold, visited)
                   + moveBlockCoreFunc(row, col + 1, rows, cols ,threshold, visited)
                   + moveBlockCoreFunc(row + 1, col, rows, cols ,threshold, visited);
    }

    return result;
}

bool checkMove(int row, int col, int rows, int cols ,int threshold, bool *visited) {
    if (row >= 0 && row < rows && col >= 0 && col < cols 
            && sumDigits(row)+sumDigits(col) <= threshold 
            && !visited[row*cols + col]) {

        return true;
    }

    return false;
}

//=============================================================================
//          Test 
//=============================================================================

// 1. test for regular input. 
// 2. test for error input.
// 3. test for boundry conditions.
// 4. test for one line
//

void testInfo(const char *msg, int rows, int cols, int threshold, int expected) {
    printf("== Test for %s begins\n", msg);
    if (moveBlockN(rows, cols, threshold) == expected)
        printf("PASS\n");
    else 
        printf("FAILED\n");
}

void test1() {
    testInfo("1. normal input", 10, 10, 5, 21);
}

void test2() {
    testInfo("2. normal input", 20, 20, 15, 359);
}

void test3() {
    testInfo("3. one line matrix", 1, 100, 10, 29);
}

void test4() {
    testInfo("4. one line matrix", 1, 10, 10, 10);
}

void test5() {
    testInfo("5. one line matrix", 100, 1, 15, 79);
}

void test6() {
    testInfo("6. one line matrix", 10, 1, 15, 79);
}

void test7() {
    testInfo("7. one item matrix", 1, 1, 15, 1);
}

void test8() {
    testInfo("8. one item matrix", 1, 1, 0, 1);
}

void test9() {
    testInfo("9. error input matrix", 0, 1, 0, -1);
}

void test10() {
    testInfo("10. error input threshold", 1, 1, -2, -1);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}
