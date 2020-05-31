/*
#剑指Offer# Q09 斐波那契数列
编写一个函数，输入n，返回斐波那契数列的第n项。
f(0)=0, f(1)=1, f(k)=f(k-1)+f(k-2) 其中 k>=2

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55

*/
#include "leetcode.h"

namespace sword_q09
{

template<typename T>
bool run_testcases() {
    T slt;
    CHECK_RET(2 == slt.fibonacci(3));
    CHECK_RET(3 == slt.fibonacci(4));
    CHECK_RET(5 == slt.fibonacci(5));
    CHECK_RET(8 == slt.fibonacci(6));
    CHECK_RET(13 == slt.fibonacci(7));
    CHECK_RET(21 == slt.fibonacci(8));
    CHECK_RET(34 == slt.fibonacci(9));

    return true;
}

class Solution {
public:
    int fibonacci(int n) {
        if (0 == n) return 0;
        if (1 == n) return 1;
        return fibonacci(n-1) + fibonacci(n-2);
    }
};
TEST(SwordQ09, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

class Solution02 {
public:
    int fibonacci(int n) {
        if (0 == n) return 0;
        if (1 == n) return 1;
        int first = 0, second = 1, ret = 0;
        for (int i = 2; i <= n; ++i) {
            ret = first + second;
            first = second;
            second = ret;
        }
        return ret;
    }
};
TEST(SwordQ09, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}
} // namespace sword_q09