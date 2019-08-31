//
// 题目38.4 八皇后问题
// 在8 * 8 的棋盘上，放上八个棋子，横竖，斜线不会成一条线为符合的条件。
// 扩展为求解 n 皇后的问题。
//

// 思路：典型的利用回溯法来求解的问题，根据规则来判断回溯条件；直接排列回溯
// 算法的时间效率比较低。
//  在算法实现的一开始就限制号那些情况可行，具体来说就是同行同列不能有棋子，
//  这就将问题转化为 n列上的行排列问题； 使用hashtable来实现排列。

#include <cstdio>
#include <cstdlib>

const int max = 20;

int board[max], solution , n_queen;
bool queen_hash[max] = {false};
 
void nQeuen(int index) { // 第index 列的排列
    if (n_queen <= 0)
        return ;
        
    // 边界条件，当前的排列完 n 列
    if (index == n_queen+1) {
        ++solution;  // 合法，找到一种排列方式
        return ;
    }

    // 从x 行开始排列回溯
    for (int x = 1; x <= n_queen; ++x) {
        if (!queen_hash[x]) {
            bool flag = true; 
        // 判断index 列之前的皇后是否违规
            for (int pre = 1; pre < index; ++pre) {
                if (abs(index - pre) == abs(x - board[pre])) {
                    flag = false; // 是否符合规则 
                    break;
                } 
            }
            if (flag) {
                board[index] = x; // index 列x行放下皇后合法. 
                queen_hash[x] = true;
                nQeuen(index+1);
                queen_hash[x] = false;
            }
        }
    }
}

//==============================================================================
//          Test
//==============================================================================

void Test(int n) {
    printf("== test for %d queen begins ==\n", n);
    solution = 0;
    n_queen = n;
    nQeuen(1);
    printf("the number of %d queen solution is: %d\n\n",n_queen, solution);
}

int main() {
    Test(1);
    Test(2);
    Test(3);
    Test(5);
    Test(6);
    Test(8);
    Test(10);
    
    return 0;
}
