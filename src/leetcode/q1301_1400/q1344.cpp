/*
#面试刷题# 第0027期
#Leetcode# Q1344 钟针之间的角度
难度：中
给定两个数字，小时和分钟。返回时针和分针之间形成的较小角度（以60进制单位）。
约束条件：
(a) 1 <= hour <= 12
(b) 0 <= minutes <= 59
(c) 实际值的10 ^ -5以内的答案将被认为是正确的。

例1:
Input: hour = 12, minutes = 30
Output: 165

例2:
Input: hour = 3, minutes = 30
Output: 75

例3:
Input: hour = 3, minutes = 15
Output: 7.5

例4:
Input: hour = 4, minutes = 50
Output: 155

例5:
Input: hour = 12, minutes = 0
Output: 0
*/
#include "leetcode.h"

namespace q1344{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    CHECK_RET(std::abs(165 - slt.angleClock(12, 30)) < 1e-5);
    CHECK_RET(std::abs(75 - slt.angleClock(3, 30)) < 1e-5);
    CHECK_RET(std::abs(7.5 - slt.angleClock(3, 15)) < 1e-5);
    CHECK_RET(std::abs(155 - slt.angleClock(4, 50)) < 1e-5);
    CHECK_RET(std::abs(0 - slt.angleClock(12, 0)) < 1e-5);

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 0 ms, faster than 100.00%
    // Memory Usage: 8.4 MB, less than 100.00%
    double angleClock(int hour, int minutes) {
        double ang_h = minutes * 30 / 60.0 + hour * 30;
        int ang_m = minutes * 6;
        double diff = abs(ang_h - ang_m);
        return diff > 180 ? 360 - diff : diff;
    }
};
TEST(Q1344, Solution) {EXPECT_EQ(q1344::run_testcases<q1344::Solution>(), true);}
};
