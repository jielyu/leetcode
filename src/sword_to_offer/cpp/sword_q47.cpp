
/*
#剑指Offer# Q47 不用加减乘除做加法
写一个函数求两个整数之和，要求不能使用加减乘除。


*/
#include "leetcode.h"

namespace sword_q47
{

template<typename T>
bool run_testcases() {
    T slt;

    CHECK_RET(10 == slt.add(4, 6));

    return true;
}

class Solution {
public:
    int add(int n1, int n2) {
        int sum = 0, inc = 0;
        do {
            sum = n1 ^ n2;
            inc = (n1 & n2) << 1;
            n1 = sum;
            n2 = inc;
        } while(n2 != 0);
        return n1;
    }
};
TEST(SwordQ47, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q47
