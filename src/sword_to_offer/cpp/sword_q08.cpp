/*
#剑指Offer# Q08 旋转数组的最小数字
把一个数组的最开始的若干元素搬到数组的末尾所形成的新数组就是旋转数组。
输入一个原始数组为递增数组的旋转数组，要求查找其中最小的元素。
*/
#include "leetcode.h"

namespace sword_q08
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> arr {3,4,5,1,2};
        CHECK_RET(1 == slt.findMinVal(arr));
    }

    return true;
}

class Solution{
public:
    int findMinVal(vector<int> & arr) {
        if (arr.size() == 0) {return -1;}
        int start = 0, end = arr.size() - 1, mid = start;
        while (arr[start] >= arr[end]) {
            // 当end与start相邻，则end处的更小
            if (end - start == 1) {
                mid = end;
                break;
            }
            // 二分法
            mid = (start + end) / 2;
            // 放弃左边
            if (arr[mid] >= arr[start]) {start = mid;}
            // 放弃右边
            else if (arr[mid] <= arr[end]) {end = mid;}
        }
        return arr[mid];
    }
};
TEST(SwordQ08, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q08