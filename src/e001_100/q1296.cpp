/*
#面试刷题# 第0051期
#Leetcode# Q1296 将数组划分为K个连续数的集合
难度：中
给定整数nums和正整数k的数组，请确定是否有可能将此数组划分为k个连续数字的集合
如果可能返回True，否则返回False。
约束条件：
(a) 1 <= nums.length <= 10^5
(b) 1 <= nums[i] <= 10^9
(c) 1 <= k <= nums.length

例1:
Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].

例2:
Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].

例3:
Input: nums = [3,3,2,2,1,1], k = 3
Output: true

例4:
Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.
*/
#include "leetcode.h"

namespace q1296{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 76 ms, faster than 99.28%
    // Memory Usage: 15 MB, less than 100.00%
    bool isPossibleDivide(vector<int>& nums, int k) {
        int len = nums.size();
        if (len % k != 0) {
            return false;
        }
        // sum of each sequence b+1 + b+2 +...+ b+k
        long s = (long)k*(k+1)/2;
        int n = len / k;
        // sum of all numbers
        long sum = 0;
        for (auto & v : nums) {
            sum += v;
        }
        sum -= s*n;
        return sum % k == 0;
    }
};

};
