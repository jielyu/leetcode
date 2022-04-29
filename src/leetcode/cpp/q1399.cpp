/*
#面试刷题# 第0084期
#Leetcode# Q1399 计数最大的组
难度：中
给定整数n。 从1到n的每个数字都根据其数字的总和分组。
返回最大的组数。
约束条件：
1 <= n <= 10^4

示例1:
Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.

示例2:
Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.

示例3:
Input: n = 15
Output: 6

示例4：
Input: n = 24
Output: 5
*/
#include "leetcode.h"

namespace q1399{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below
    CHECK_RET(4 == slt.countLargestGroup(13));
    CHECK_RET(2 == slt.countLargestGroup(2));
    CHECK_RET(6 == slt.countLargestGroup(15));
    CHECK_RET(5 == slt.countLargestGroup(24));

    // succ
    return true;
}

// Runtime: 48 ms, faster than 12.50%
// Memory Usage: 8.6 MB, less than 100.00%
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, vector<int>> groups;
        int sum = 0, max_len = 0;
        for (int i=1; i<=n; ++i) {
            auto s = to_string(i);
            sum = 0;
            for (auto & c : s) {
                sum += (int)(c - '0');
            }
            groups[sum].push_back(i);
            if (groups[sum].size() > max_len) {
                max_len = groups[sum].size();
            }
        }
        // accumulate result
        int ret = 0;
        for (auto & g : groups) {
            if (g.second.size() == max_len) {
                ++ret;
            }
        }
        return ret;
    }
};
TEST(Q1399, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

// Runtime: 28 ms, faster than 12.50%
// Memory Usage: 5.9 MB, less than 100.00%
class Solution02 {
public:
    int countLargestGroup(int n) {
        const int MAX_SUM = 36 + 1;
        int groups[MAX_SUM] = {0}, max_len = 0, sum = 0;
        for (int i=1; i<=n; ++i) {
            auto s = to_string(i);
            sum = 0;
            for (auto & c : s) {
                sum += (int)(c - '0');
            }
            ++groups[sum];
            if (groups[sum] > max_len) {
                max_len = groups[sum];
            }
        }
        // accumulate result
        int ret = 0;
        for (int i = 0; i < MAX_SUM; ++i) {
            if (groups[i] == max_len) {
                ++ret;
            }
        }
        return ret;
    }
};
TEST(Q1399, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 100.00% 
class Solution03 {
public:
    int countLargestGroup(int n) {
        const int MAX_SUM = 36 + 1;
        int groups[MAX_SUM] = {0}, max_len = 0, sum = 0;
        for (int i=1, x=1; i<=n; ++i) {
            sum = 0, x = i;
            while(x) {
                sum += x % 10;
                x /= 10;
            }
            ++groups[sum];
            if (groups[sum] > max_len) {
                max_len = groups[sum];
            }
        }
        // accumulate result
        int ret = 0;
        for (int i = 0; i < MAX_SUM; ++i) {
            if (groups[i] == max_len) {
                ++ret;
            }
        }
        return ret;
    }
};
TEST(Q1399, Solution03) {EXPECT_TRUE(run_testcases<Solution03>());}
};
