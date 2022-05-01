/*
#剑指Offer# Q03 二维数组中的查找
在一个二维数组中，每一行都是按照从左到右递增的顺序排序，每一列都是按照从上到下的递增的顺序排列。
编写一个函数，实现在这样的二维数组中查找指定数字是否存在。
*/
#include "leetcode.h"

namespace sword_q03
{

template<typename T>
bool run_testcases(){
    T slt;

    {
        vector<vector<int>> arr{{1,2,8,9}, {2,4,9,12}, {4,7,10,13}, {6,8,11,15}};
        CHECK_RET(true == slt.findNumber(arr, 7));
        CHECK_RET(false == slt.findNumber(arr, 5));
    }

    return true;
}

class Solution {
public:
    bool findNumber(vector<vector<int>> & arr, int target) {
        bool ret = false;
        int m = arr.size(), n = arr[0].size(), i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (arr[i][j] == target) {
                ret = true;
                break;
            }else {
                // 大于target就向左，小于target就向下
                arr[i][j] > target ? --j : ++i;
            }
        }
        return ret;
    }
};
TEST(SwordQ03, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

} // namespace sword_q03
