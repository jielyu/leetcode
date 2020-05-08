/*
#面试刷题# 第0115期
#Leetcode# Q1438 绝对差小于或等于极限值的最长连续子阵列
难度：中
给出一个整数数组nums和一个整数极限，返回最长的连续子数组的大小，使任何两个元素之间的绝对差值小于或等于极限。
如果没有满足给定条件的子数组，则返回0。
约束条件：
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9

示例1:
Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

示例2:
Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

示例3:
Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
*/
#include "leetcode.h"

namespace q1438
{
template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> nums {8,2,4,7}; 
        CHECK_RET(2 == slt.longestSubarray(nums, 4));
    }

    {
        vector<int> nums {10,1,2,4,7,2}; 
        CHECK_RET(4 == slt.longestSubarray(nums, 5));
    }

    {
        vector<int> nums {4,2,2,2,4,4,2,2}; 
        CHECK_RET(3 == slt.longestSubarray(nums, 0));
    }
    return true;
}

// Runtime: 156 ms, faster than 69.97% 
// Memory Usage: 46.6 MB, less than 100.00%
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int start = 0, end = 1, min_v = nums[0], max_v = nums[0];
        int len = nums.size(), ret = 1;
        bool valid_min = true, valid_max = true;
        for (int i = 1; i < len; ++i) {
            valid_min = abs(nums[i] - min_v) <= limit;
            valid_max = abs(nums[i] - max_v) <= limit;
            // meet valid element and expand ending index
            if (valid_min && valid_max) {
                end = i + 1;
                if (min_v > nums[i]) {min_v = nums[i];}
                if (max_v < nums[i]) {max_v = nums[i];}
            } else {
                // adjust subarray
                min_v = nums[end], max_v = nums[end];
                int j = i;
                for (; j >= start; --j) {
                    if (abs(nums[i] - nums[j]) > limit) {break;}
                    if (min_v > nums[j]) {min_v = nums[j];}
                    if (max_v < nums[j]) {max_v = nums[j];}
                }
                // adjust starting and ending indexes
                start = j + 1;
                end = i + 1;
            }
            // cout << i << "," << start << "," << end << endl;
            // record result
            if (end - start > ret) {ret = end - start;}
        }
        return ret;
    }
};
TEST(Q1438, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace q1438
