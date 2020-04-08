/*
#面试刷题# 第0013期
#Leetcode# Q1262 能被3整除的最大和
难度：中
给定一个整数数组nums，我们需要从中找出可能的最大的能被3整除的和。
约束条件：
(a) 1 <= nums.length <= 4 * 10^4
(b) 1 <= nums[i] <= 10^4
例1:
Input: nums = [3,6,5,1,8]
Output: 18
例2:
Input: nums = [4]
Output: 0
例3:
Input: nums = [1,2,3,4,4]
Output: 12
*/
#include "leetcode.h"

namespace q1262{

template<typename T>
bool run_testcases() {
    T slt;
    vector<int> example01{3,6,5,1,8};
    if (slt.maxSumDivThree(example01) != 18) {return false;}
    vector<int> example02{4};
    if (slt.maxSumDivThree(example02) != 0) {return false;}
    vector<int> example03{1,2,3,4,4};
    if (slt.maxSumDivThree(example03) != 12) {return false;}
    return true;
}

class Solution {
public:
    // 48ms, faster than 92.89%
    int maxSumDivThree(vector<int>& nums) {
        // record states for remaider = 0,1,2 situations
        vector<int> remainds{int(-4e8), int(-4e8), int(-4e8)};
        int mid = 0;
        for (auto & v : nums) {
            if (v % 3 == 0) { 
                remainds[0] = max(remainds[0] + v, v);
                remainds[1] = remainds[1] > 0 ? remainds[1] + v : remainds[1];
                remainds[2] = remainds[2] > 0 ? remainds[2] + v : remainds[2];
            } else if (v % 3 == 1) { 
                mid = remainds[0];
                remainds[0] = remainds[2] > 0 ? max(remainds[0], remainds[2] + v) : remainds[0];
                remainds[2] = remainds[1] > 0 ? max(remainds[2], remainds[1] + v) : remainds[2];
                remainds[1] = max(remainds[1], max(mid + v, v));
            } else { 
                mid = remainds[0];
                remainds[0] = remainds[1] > 0 ? max(remainds[0], remainds[1] + v) : remainds[0];
                remainds[1] = remainds[2] > 0 ? max(remainds[1], remainds[2] + v) : remainds[1];
                remainds[2] = max(remainds[2], max(mid + v, v));  
            }
            //std::cout << v << "," << remainds[0] << "," 
            //          << remainds[1] << "," << remainds[2] <<std::endl;
        }
        return max(0, remainds[0]);
    }
};
TEST(Q1262, Solution) {EXPECT_EQ(q1262::run_testcases<Solution>(), true);}

};