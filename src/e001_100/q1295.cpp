/*
#面试刷题# 第0052期
#Leetcode# Q1295 查找具有偶数位数的数字
难度：低
给定一个由整数组成的数组，返回其中有偶数个数字的整数。
约束条件：
1 <= nums.length <= 500
1 <= nums[i] <= 10^5

例1:
Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.

例2:
Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
*/
#include "leetcode.h"

namespace q1295{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 12 ms, faster than 22.93%
    // Memory Usage: 9.1 MB, less than 100.00% 
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        string s;
        for (auto n : nums) {
            s = to_string(n);
            if (s.size() % 2 == 0) {
                ++ret;
            }
        }
        return ret;
    }
};

class Solution02 {
public:
    // Runtime: 8 ms, faster than 75.12%
    // Memory Usage: 9.1 MB, less than 100.00%
    int findNumbers(vector<int>& nums) {
        int ret = 0, nd = 0;
        for (auto & n : nums) {
            nd = (int)log10(n) + 1;
            if ((nd & 0x01) == 0) {
                ++ret;
            }
        }
        return ret;
    }
};

class Solution03 {
public:
    // Runtime: 0 ms, faster than 100.00%
    // Memory Usage: 9.2 MB, less than 100.00%
    int findNumbers(vector<int>& nums) {
        int ret = 0, nd = 0;
        for (auto & n : nums) {
            nd = (int)log10(n) + 1;
            ret += (int)((nd & 0x01) == 0);
        }
        return ret;
    }
};

};
