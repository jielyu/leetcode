/*
#面试刷题# 第0028期
#Leetcode# Q1346 检查N及其2倍的值是否存在
难度：低
给定整数数组arr，请检查是否存在两个整数N和M，以使N为M的两倍（即N = 2 * M）。
更正式地检查是否存在两个索引i和j，使得：
(1) i != j
(2) 0 <= i, j < arr.length
(3) arr[i] == 2 * arr[j]
约束条件：
(a) 2 <= arr.length <= 500
(b) -10^3 <= arr[i] <= 10^3

例1:
Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.

例2:
Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.

例3:
Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.
*/
#include "leetcode.h"

namespace q1346{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        vector<int> arr{10,2,5,3};
        CHECK_RET(true == slt.checkIfExist(arr));
    }

    {
        vector<int> arr{7,1,14,11};
        CHECK_RET(true == slt.checkIfExist(arr));
    }

    {
        vector<int> arr{3,1,7,11};
        CHECK_RET(false == slt.checkIfExist(arr));
    }

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 8 ms, faster than 79.28%
    // Memory Usage: 9.2 MB, less than 100.00%
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> buff;
        for (auto & v : arr) {
            if (buff.count(2*v) || (0==v%2 && buff.count(v/2))) {
                return true;
            }
            buff.insert(v);
        }
        return false;
    }
};
TEST(Q1346, Solution) {EXPECT_EQ(q1346::run_testcases<q1346::Solution>(), true);}
};