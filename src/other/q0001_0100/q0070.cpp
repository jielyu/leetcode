
/*
#LeetCode# Q0070 攀爬楼梯
难度：低
你在爬楼梯的情况下。它需要N个台阶才能到达顶部。

每一次，你可以爬1或2个台阶。你可以用多少种不同的方式爬到顶上？

注：鉴于n将是一个正整数。

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/
#include "leetcode.h"

namespace q0070
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 39.04%
class Solution {
public:
    int climbStairs(int n) {
        if (0 == n) {return 1;}
        if (1 == n) {return 1;}
        int n_1 = 1, n_2 = 1, ret = 0;
        for (int i = 2; i <= n; ++i) {
            ret = n_1 + n_2;
            n_2 = n_1;
            n_1 = ret;
        }
        return ret;
    }
};

} // namespace q0070
