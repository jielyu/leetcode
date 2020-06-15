/*
#面试刷题# 第124期
#LeetCode# Q1447 简化分式
难度：中
给定一个整数n，返回一个在0到1之间的所有简化分母小于等于或等于n的分母的列表。
约束条件：
1 <= n <= 100

示例1:
Input: n = 2
Output: ["1/2"]
Explanation: "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.

示例2:
Input: n = 3
Output: ["1/2","1/3","2/3"]

示例3:
Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]
Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".

示例4:
Input: n = 1
Output: []
*/
#include "leetcode.h"

namespace q1447
{
template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<string> ret {"1/2"};
        CHECK_RET(comp_vector(ret, slt.simplifiedFractions(2)));
    }

    {
        vector<string> ret {"1/2","1/3","2/3"};
        vector<string> ans = slt.simplifiedFractions(3);
        sort(ret.begin(), ret.end());
        sort(ans.begin(), ans.end());
        CHECK_RET(comp_vector(ret, ans));
    }

    {
        vector<string> ret {"1/2","1/3","1/4","2/3","3/4"};
        vector<string> ans = slt.simplifiedFractions(4);
        sort(ret.begin(), ret.end());
        sort(ans.begin(), ans.end());
        CHECK_RET(comp_vector(ret, ans));
    }

    {
        vector<string> ret;
        CHECK_RET(comp_vector(ret, slt.simplifiedFractions(1)));
    }

    return true;
}


// Runtime: 192 ms, faster than 54.92% 
// Memory Usage: 22.1 MB, less than 100.00%
class Solution {
private:
    int _max_factor(int i, int j) {
        if (i % j == 0) {return j;}
        int k = min(i, j);
        while (k > 1) {
            if ((i % k == 0) && (j % k) == 0) {return k;}
            --k;
        }
        return 1;
    }
    
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ret;
        if (1 == n) {return ret;}
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                // 不是最简形式的分式不需要收录
                if (_max_factor(i, j) == 1) {
                    ret.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        return ret;
    }
};    
TEST(Q1447, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace q1447
