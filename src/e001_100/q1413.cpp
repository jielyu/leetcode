/*
#面试刷题# 第0100期
#Leetcode# Q1413 逐步求和取正值的最小值
难度：低
给定一个整数组nums，从初始正值startValue开始。
在每一次迭代中，计算出startValue加上nums中的元素（从左到右）的逐级求和。
返回startValue的最小正值，使逐级总和永远不小于1。
约束条件：
1 <= nums.length <= 100
-100 <= nums[i] <= 100

示例1:
Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
                step by step sum
                startValue = 4 | startValue = 5 | nums
                  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
                  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
                  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
                  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
                  (4 +2 ) = 6  | (5 +2 ) = 7    |   2

示例2:
Input: nums = [1,2]
Output: 1
Explanation: Minimum start value should be positive. 

示例3:
Input: nums = [1,-2,-3]
Output: 5
*/
#include "leetcode.h"

namespace q1413 {

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> nums{-3,2,-3,4,2};
        int ret = 5;
        if (slt.minStartValue(nums) != ret) {return false;}
    }

    {
        vector<int> nums{1,2};
        int ret = 1;
        if (slt.minStartValue(nums) != ret) {return false;}
    }

    {
        vector<int> nums{1,-2,-3};
        int ret = 5;
        if (slt.minStartValue(nums) != ret) {return false;}
    }

    return true;
}

// Runtime: 4 ms, faster than 46.35%
// Memory Usage: 7.6 MB, less than 100.00%
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ret = 1, sum = 1;
        for (auto & n : nums) {
            sum += n;
            if (sum < 1) {
                // to keep sum >= 1 if add ret
                ret += (1-sum);
                sum = 1;
            }
        }
        return ret;
    }
};
TEST(Q1413, Solution) {EXPECT_EQ(q1413::run_testcases<q1413::Solution>(), true);}
}; // namespace q1413

