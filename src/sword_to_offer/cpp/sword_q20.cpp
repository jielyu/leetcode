
/*
#剑指Offer# Q20 顺时针打印矩阵
输入一个矩阵，按照 从外向里以顺时针的次序依次打印每一个元素。


*/
#include "leetcode.h"

namespace sword_q20
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<vector<int>> arr{{1,2,3,4}, {5,6,7,8}};
        vector<int> ret {1,2,3,4,8,7,6,5};
        CHECK_RET(comp_vector(ret, slt.printInCircle(arr)));
    }

    return true;
}

class Solution {
public:
    vector<int> printInCircle(vector<vector<int>> arr) {
        vector<int> ret;
        int m = arr.size(), n = arr[0].size();
        int left = 0, up = 0, right = n - 1, down = m - 1;
        while (left <= right && up <= down) {
            // 打印以(left, up)-> (right, down)的举行边框
            if (left == right) {
                for (int k = up; k <= down; ++k) {ret.push_back(arr[k][left]);}
                break;
            }
            if (up == down) {
                for (int k = left; k < right; ++k) {ret.push_back(arr[up][k]);}
                break;
            }
            // 上边
            for (int k = left; k < right; ++k) {ret.push_back(arr[up][k]);}
            // 右边
            for (int k = up; k < down; ++k) {ret.push_back(arr[k][right]);}
            // 底边
            for (int k = right; k > left; --k) {ret.push_back(arr[down][k]);}
            // 左边
            for (int k = down; k > up; --k) {ret.push_back(arr[k][left]);}
            // 收缩矩形框
            ++left; --right; ++up; --down;
        }
        return ret;
    }
};
TEST(SwordQ20, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q20
