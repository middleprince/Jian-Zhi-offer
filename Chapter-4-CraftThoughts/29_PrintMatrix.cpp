// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
//

// 思路：分析顺时针打印时以「圈层」来划分,从左上角开始化分成圈。
// 1. 观察后得到，每圈的开始点从 (0, 0) 到 (1, 1) 到 (2, 2) ... ; 
//    目标找到开始点的边界值，令起点为(startX, startY), 满足「扩张」
//    条件的是 columns > startX * 2 && rows > startY * 2
// 2. 分布拆出四个遍历的步骤，① 从左往右； ② 从上往下； ③ 从右往左； 
//    ④ 从下往上。
//    分别分析出每种走法所需要满足的条件，然后进行遍历。
//    

#include <cstdio>

void printCircle(int **, int , int , int);
void printMatrix(int **nums, int rows, int cols) {
    if (nums == nullptr || rows <= 0 || cols <= 0)
        return;
    
    int start_point = 0;
    while (cols > 2*start_point && rows > 2*start_point) {
        printCircle(nums, rows, cols, start_point);
        ++start_point;
        printf("\n");
    }
}

void printCircle(int **nums, int rows, int cols, int start_point) {
    
    //计算圈长度与宽度
    int startx_end = cols - start_point - 1;
    int starty_end = rows - start_point - 1;

    int number = 0;
    //从左往右打印，长度大于等于1就可以.
    for (int i = start_point; i <= startx_end ; ++i) {
        number = nums[start_point][i]; 
        printf("%d ", number);
    }
    printf("\n");
    
    // 从上往下打印，宽度大于等于2
    if (start_point < starty_end) {
        for (int i = start_point+1; i <= starty_end; ++i) {
            number = nums[i][startx_end]; 
            printf("%d ", number);
        }
    }
    printf("\n");

    // 从右往左打印, 长度大于2 宽度也大于2，
    if (start_point < starty_end && start_point < startx_end) {
        for (int i = startx_end-1; i >= start_point; --i) {
            number = nums[starty_end][i]; 
            printf("%d ", number);
        }
    }
    printf("\n");
    
    // 从下往上打印, 长度大于2 宽度也大于2，
    if (start_point < starty_end-1 && start_point < startx_end) {
        for (int i = starty_end-1; i > start_point; --i) {
            number = nums[i][start_point]; 
            printf("%d ", number);
        }
    }
    printf("\n");
}


//==============================================================================
//          Test
//==============================================================================
//

void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    printMatrix(numbers, rows, columns);
    printf("\n");

    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}

int main(int argc, char* argv[])
{
    /*
    1    
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}
