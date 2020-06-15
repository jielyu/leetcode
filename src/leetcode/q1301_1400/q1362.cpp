/*
#面试刷题# 第0090期
#Leetcode# Q1362 最近的除数
难度：中
给定一个整数num，找到绝对差值中最接近的两个整数，其乘积等于num + 1或num + 2。
以任何顺序返回两个整数。
约束条件：
1 <= num <= 10^9

示例1:
Input: num = 8
Output: [3,3]
Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.

示例2:
Input: num = 123
Output: [5,25]

示例3:
Input: num = 999
Output: [40,25]
*/
#include "leetcode.h"

namespace q1362
{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below
    // example 01
    {
        int num = 8;
        vector<int> ret{3,3};
        if (!comp_vector(slt.closestDivisors(num), ret)) {return false;}
    }
    // example 02
    {
        int num = 123;
        vector<int> ret{5,25};
        if (!comp_vector(slt.closestDivisors(num), ret)) {return false;}
    }
    // example 03
    {
        int num = 999;
        vector<int> ret{25,40};
        if (!comp_vector(slt.closestDivisors(num), ret)) {return false;}
    }

    // succ
    return true;
}

class Solution {
private:
    // Runtime: 8 ms, faster than 84.94%
    // Memory Usage: 6 MB, less than 100.00%
    vector<int> _find_closest_factors(int n) {
        int d1 = 1, d2 = n, diff = n -1, min_diff = n - 1;
        int max_len = (int)sqrt(n), mid = 0;
        for (int i = 2; i <= max_len; ++i) {
            if (n % i == 0) {
                mid = n / i;
                diff = abs(mid - i);
                if (diff < min_diff) {
                    min_diff = diff;
                    d1 = i; d2 = mid;
                }
            }
        }
        return {d1, d2};
    }
    
public:
    vector<int> closestDivisors(int num) {
        auto ret1 = _find_closest_factors(num + 1);
        auto ret2 = _find_closest_factors(num + 2);
        return abs(ret1[1]-ret1[0]) < abs(ret2[1]-ret2[0]) ? ret1 : ret2;
    }
};    
TEST(Q1362, Solution) {EXPECT_EQ(q1362::run_testcases<q1362::Solution>(), true);}
    
}; // namespace q1362
