// 题38.3 
// 输入 8 个点的数组，判断是否可能这八个点分别位于正方体八个顶点上，
// 可以实现两两对面上的点和相等。
//

// 思路： 使用排列来遍历，分别遍历出可能的正方体，并且判断对面点是否满足条件。
// 八个点分别为 a1, a2, a3, a4, a5, a6, a7, a8
// 分别排列计算是否满足， a1 + a2 + a3 + a4 == a5 + a6 + a7 + a8 &&
//                        a1 + a2 + a5 + a6 == a3 + a4 + a7 + a8 &&
//                        a2 + a3 + a6 + a7 == a1 + a4 + a5 + a8

#include <cstdio>
#include <cstdlib>

void isCubePointsCore(int*, int, int, bool*);
bool isCubePointSumEqual(int *points, int length) {
    if (points == nullptr)
        return false;
    bool found = false;

    isCubePointsCore(points, length, 0, &found);
    return found; 
}

void isCubePointsCore(int *points, int length, int sub_index, bool *found) {
    if (*found)
        return ;

    if (sub_index == length-1) {
        int sum1 = points[0] + points[1] + points[2] + points[3];
        int sum2 = points[4] + points[5] + points[6] + points[7];
        int sum3 = points[0] + points[1] + points[4] + points[5];
        int sum4 = points[2] + points[3] + points[6] + points[7];
        int sum5 = points[1] + points[2] + points[5] + points[6];
        int sum6 = points[0] + points[3] + points[4] + points[7];

        //printf("### Debug for int list\n");
        //for (int i = 0; i < length; ++i)
        //    printf(" %d", points[i]);
        //printf("\n");

        if (sum1 == sum2 && sum3 == sum4 && sum5 == sum6) {
            *found = true;
            printf("The accepted case is:\n");
            for (int i = 0; i < length; ++i)
                printf("%d ", points[i]);
            return ;
        }
        
    }
    else {
        for (int index = sub_index; index < length; ++index) {
            //points[index] ^= points[sub_index];  
            //points[sub_index] ^= points[index];  
            //points[index]  ^= points[sub_index];
            
            int temp = points[index];
            points[index] = points[sub_index];
            points[sub_index] = temp;
            

            isCubePointsCore(points, length, sub_index+1, found);
            
            //points[index] ^= points[sub_index];  
            //points[sub_index] ^= points[index];  
            //points[index]  ^= points[sub_index];
            temp = points[index];
            points[index] = points[sub_index];
            points[sub_index] = temp;
        } 
    }
}


//==============================================================================
//                      Test
//==============================================================================

 void Test(int* points, int length){

    if(points  == nullptr || length <= 0)
        printf("Test for nullptr begins:\n");
    else {
        printf("Test for points");
        for (int i = 0; i < length; ++i)
            printf(" %d", points[i]);
    }
    printf("\n");
    
    if (!isCubePointSumEqual(points, length)) 
        printf("cant not found a acceptible case\n");

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(nullptr, 0);

    int points1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test(points1, 8);  
    
    int points2[8] = {1, 2, 4, 8, 1, 2, 4, 8};
    Test(points2, 8);  

    return 0;
}
