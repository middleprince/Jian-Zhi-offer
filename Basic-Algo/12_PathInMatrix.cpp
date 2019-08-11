// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H


// 分析： 使用回溯法来进行路径寻找，使用一个数组来记录当前的路径是否访问过来
//   以此来避免回路存在。
//   
#include <cstdio>
#include <stdexcept>
#include <exception>
#include <cstring>

bool hasPathCoreFunc(const char*, int, int, int, int,
        const char*, int &, bool *);

bool pathInArray(const char *map , int rows, int cols, const char *target) {
    if (map == nullptr || rows <= 0 || cols <= 0 
        || target == nullptr) {
        // FIXED: error in link
        throw std::runtime_error("invalid arguments");
        //return false;
    }

    //bool visited[rows*cols] = {0};
    bool *visited = new bool[rows*cols]();
    memset(visited, 0, size_t(rows*cols));
    int path_length = 0;
    
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (hasPathCoreFunc(map, rows, cols, row, col, 
                    target, path_length, visited)) {
                delete[] visited;
                return true;
            } 
        }
    }
    delete[] visited;
    return false;
}

bool hasPathCoreFunc(const char *map, int rows, int cols, int row, int col,
    const char *target, int &path_length, bool *visited) {
    
    // FIXED: fix bug which i wrote map[path_length] OMG 
    if (target[path_length] == '\0' && path_length <= rows * cols) {
        return true;
    }

    bool path_exist = false;
    if (row >= 0 && row <rows && col >= 0 && col < cols 
            && map[row*cols+col] == target[path_length] 
            && !visited[row*cols+col]) {

        visited[row*cols+col] = true;
        ++path_length; 

        //printf("## Debug: the row = %d, col = %d, path_length = %d, target[%d] = %c\n", row, col, path_length, path_length, target[path_length]);
        //printf("## debug: path_length = %d\n", path_length);

        path_exist = hasPathCoreFunc(map, rows, cols, row, col-1, 
            target, path_length, visited)  
                || hasPathCoreFunc(map, rows, cols, row-1, col, 
            target, path_length, visited)
                || hasPathCoreFunc(map, rows, cols, row, col+1, 
            target, path_length, visited)
                || hasPathCoreFunc(map, rows, cols, row+1, col, 
            target, path_length, visited);

        //  当前路径下没找到，回溯
        if (!path_exist) {
            --path_length;
            visited[row*cols + col] = false; 
        }
    }
    
   return path_exist; 
}


//==============================================================================
//          Test
//==============================================================================

void Test(const char* testName, const char* matrix, int rows, int cols, 
    const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    
    //Fixed: error in link the exception operation
    try {
        if(pathInArray(matrix, rows, cols, str) == expected)
            printf("Passed.\n");
        else
            printf("FAILED.\n");
    } catch(std::runtime_error &e) {
        printf("Erro : %s\n", e.what()); 
    }
    //if(pathInArray(matrix, rows, cols, str) == expected)
    //    printf("Passed.\n");
    //else
    //    printf("FAILED.\n");

}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";

    Test("Test1", (const char*) matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
    const char* matrix = "ABCESFCSADEE";
    const char* str = "SEE";

    Test("Test2",  matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "ABFB";

    Test("Test3", (const char*) matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (const char*) matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (const char*) matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";

    Test("Test8", (const char*) matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAAA";

    Test("Test9", (const char*) matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
    const char* matrix = "A";
    const char* str = "A";

    Test("Test10", (const char*) matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
    const char* matrix = "A";
    const char* str = "B";

    Test("Test11", (const char*) matrix, 1, 1, str, false);
}

void Test12()
{
    Test("Test12", nullptr, 0, 0, nullptr, false);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}
