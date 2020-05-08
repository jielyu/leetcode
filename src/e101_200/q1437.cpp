/*
#面试刷题# 第0114期
#Leetcode# Q1437 检查是否所有的1都是至少长度为K的地方的距离
难度：中
给出一个0和1s的数组nums和一个整数k，如果所有的1都至少相距k位，则返回True，否则返回False。
约束条件：
1 <= nums.length <= 10^5
0 <= k <= nums.length
nums[i] 是 0 或者 1

示例1:
Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.

示例2:
Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.

示例3:
Input: nums = [1,1,1,1,1], k = 0
Output: true

示例4:
Input: nums = [0,1,0,1], k = 1
Output: true
*/
#include "leetcode.h"

namespace q1437
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> nums {1,0,0,0,1,0,0,1};
        CHECK_RET(true == slt.kLengthApart(nums, 2));
    }

    {
        vector<int> nums {1,0,0,1,0,1};
        CHECK_RET(false == slt.kLengthApart(nums, 2));
    }

    {
        vector<int> nums {1,1,1,1,1};
        CHECK_RET(true == slt.kLengthApart(nums, 0));
    }

    {
        vector<int> nums {0,1,0,1};
        CHECK_RET(true == slt.kLengthApart(nums, 1));
    }
    return true;
}

// Runtime: 164 ms, faster than 62.33%
// Memory Usage: 57.5 MB, less than 100.00%
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_idx = -1, len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nums[i] == 1) {
                if (-1 == last_idx) {
                    last_idx = i;
                } else {
                    if (i - 1 - last_idx < k) {return false;}
                    last_idx = i;
                }
            }
        }
        return true;
    }
};
TEST(Q1437, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace q1437
