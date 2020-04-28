/*
#面试刷题# 第0048期
#Leetcode# Q1300 最接近目标的突变数组之和
难度：中
给定一个整数数组arr和一个目标值target，返回整数值，
以便当我们将大于给定数组中的value的所有整数更改为等于value时，
该数组的总和尽可能接近（绝对差）） 达到目标。
如果是平局，则返回最小的整数。
请注意，答案并非必须来自arr的数字。
约束条件：
(a) 1 <= arr.length <= 10^4
(b) 1 <= arr[i], target <= 10^5

例1:
Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.

例2:
Input: arr = [2,3,5], target = 10
Output: 5

例3:
Input: arr = [60864,25176,27249,21296,20204], target = 56803
Output: 11361
*/
#include "leetcode.h"

namespace q1300{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        vector<int> arr {4,9,3};
        int target = 10, ret = 3;
        if (ret != slt.findBestValue(arr, target)) {return false;}
    }

    {
        vector<int> arr {2,3,5};
        int target = 10, ret = 5;
        if (ret != slt.findBestValue(arr, target)) {return false;}
    }

    {
        vector<int> arr {60864,25176,27249,21296,20204};
        int target = 56803, ret = 11361;
        if (ret != slt.findBestValue(arr, target)) {return false;}
    }

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 20 ms, faster than 84.02%
    // Memory Usage: 9.4 MB, less than 100.00%
    int findBestValue(vector<int>& arr, int target) {
        // sort ascending
        sort(arr.begin(), arr.end());
        // find the best value
        int len = arr.size(), low = 0, high = 0;
        for (int i = 0, s = len; i<len ; ++i, --s) {
            // find a special element
            if (arr[i] * s > target) {
                low = target / s;
                high = low + 1;
                // to process gt and lt target situation
                return abs(target-low*s) <= abs(target-high*s) ? low : high;
            }
            target -= arr[i];
        }
        // return the last elements
        return arr[len-1];
    }
};
TEST(Q1300, Solution) {EXPECT_EQ(q1300::run_testcases<q1300::Solution>(), true);}
};
