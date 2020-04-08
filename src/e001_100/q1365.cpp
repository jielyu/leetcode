/*
#面试刷题# 第0083期
#Leetcode# Q1365 多少个数字小于当前数字
难度：低
给定数组nums，对于每个nums [i]找出数组中比其小的数字。 
也就是说，对于每个nums [i]，您都必须计算有效j的数量，
以使j！= i，并且nums [j] <nums [i]。
以数组形式返回答案。
约束条件：
(a) 2 <= nums.length <= 500
(b) 0 <= nums[i] <= 100

示例1:
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).

示例2:
Input: nums = [6,5,4,8]
Output: [2,1,0,3]

示例3:
Input: nums = [7,7,7,7]
Output: [0,0,0,0]
*/
#include "leetcode.h"

namespace q1365{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

// Runtime: 12 ms, faster than 93.68% 
// Runtime: 12 ms, faster than 93.68% 
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size(), MAX_NUM = 101;
        // construct dict from number to frequency
        vector<int> stat(MAX_NUM, 0);
        for (auto & v : nums) {
            ++stat[v];
        }
        // accumulate only for valid position
        int sum = 0, tmp = 0;
        for (int i = 0; i < MAX_NUM; ++i) {
            if (0 == stat[i]) {continue;}
            sum += tmp;
            tmp = stat[i];
            stat[i] = sum;
        }
        // output results
        vector<int> ret(n, 0);
        for (int i = 0; i < n; ++i) {
            ret[i] = stat[nums[i]];
        }
        return ret;
    }
};
};
