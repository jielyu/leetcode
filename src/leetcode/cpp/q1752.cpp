/*
#面试刷题#
#Leetcode# Q1752 Check if Array Is Sorted and Rotated

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
Example 4:

Input: nums = [1,1,1]
Output: true
Explanation: [1,1,1] is the original sorted array.
You can rotate any number of positions to make nums.
Example 5:

Input: nums = [2,1]
Output: true
Explanation: [1,2] is the original sorted array.
You can rotate the array by x = 5 positions to begin on the element of value 2: [2,1].
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

#include "leetcode.h"

namespace q1752{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below
    {
        vector<int> nums {3,4,5,1,2};
        bool ret = true;
        CHECK_RET(ret == slt.check(nums));
    }

    // succ
    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.3 MB, less than 77.43%
class Solution {
public:
    bool check(vector<int>& nums) {
        int len = nums.size();
        // 元素少于3个的情况
        if (len < 3) {return true;}
        
        // 判断左半侧
        int idx = 0, min_val = nums[idx];
        while(idx < len-1 && nums[idx] <= nums[idx+1]) {++idx;}
        if (idx >= len-1) {return true;}
        
        // 判断右半侧
        idx += 1;
        while (nums[idx] <= min_val && idx < len-1 && nums[idx] <= nums[idx+1]) {++idx;}
        return nums[idx] <= min_val && idx >= len-1;
    }
};
TEST(Q1752, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

}