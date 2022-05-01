/*
#剑指Offer# Q11 数值的整数次方
实现一个函数，计算base的exponent次方。不能使用库函数。

*/
#include "leetcode.h"

namespace sword_q11
{

template<typename T>
bool run_testcases() {
    T slt;

    CHECK_RET(slt.equal(1.0/16, slt.myPower(2, -4)));
    CHECK_RET(slt.equal(1.0/16, slt.myPower(16, -1)));
    CHECK_RET(slt.equal(27.0, slt.myPower(3.0, 3)));

    return true;
}

class Solution {
private:

    double _pos_power(double base, uint32_t exponent) {
        double ret = 1.0;
        for (int i = 1; i <= exponent; ++i) {ret *= base;}
        return ret;
    }
public:
    bool equal(double v1, double v2) {
        return (v1 - v2 > -0.00001) && (v1 - v2  < 0.00001);
    }

    double myPower(double base, int exponent) {
        // 异常情况处理
        if (equal(base, 0.0) && exponent < 0) {return 0.0;}
        uint32_t abs_exp = (uint32_t)exponent;
        // 处理负值指数
        if (exponent < 0) {abs_exp = (uint32_t)(-exponent);}
        double ret = _pos_power(base, abs_exp);
        // 负值指数情况下取倒数
        if (exponent < 0) {ret = 1.0 / ret;}
        return ret;
    }
};
TEST(SwordQ11, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q11