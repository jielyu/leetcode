/*
#经典算法问题# 动态规划

用于收录动态规划相关的问题和解决方案
*/
#include "leetcode.h"

// 换零钱问题，对于n元前，有 1，2，5，10这些零钱可供兑换
namespace small_change
{

class Solution {
private:
    vector<int> _sc {1,2,5,10};
public:
    int change(int n, int m=4) {
        if (0 == n) {return 1;}
        if (n < 0 || 0 == m) {return 0;}
        return change(n, m-1) + change(n - _sc[m-1], m);
    }
};

class Solution02 {
private:
    vector<int> _sc {1,2,5,10};
public:
    int change(int n, int m=4) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = _sc[i]; j <= n; ++j) {
                dp[j] += dp[j - _sc[i]];
            }
        }
        return dp[n];
    }
};
TEST(DP_SmallChange, Solution) {
    Solution slt;
    Solution02 slt2;
    EXPECT_TRUE(slt.change(100) == slt2.change(100));
}
    
} // namespace small_change
