/*
#剑指Offer# Q10 二进制中1的个数
编写一个函数，对输入的正数计数其二进制表示中的1的个数。

*/
#include "leetcode.h"

namespace sword_q10
{

template<typename T>
bool run_testcases() {
    T slt;

    CHECK_RET(2 == slt.numberOfOne(9));
    CHECK_RET(0 == slt.numberOfOne(0));
    CHECK_RET(1 == slt.numberOfOne(1));
    CHECK_RET(31 == slt.numberOfOne(0x7fffffff));
    CHECK_RET(32 == slt.numberOfOne(0xffffffff));
    return true;
}

class Solution{
public:
    int numberOfOne(int n) {
        int count = 0;
        uint32_t flag = 1;
        while (flag) {
            if (n & flag) {++count;}
            flag = flag << 1;
        }
        return count;
    }
};
TEST(SwordQ10, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

class Solution02{
public:
    int numberOfOne(int n) {
        int count = 0;
        while (n) {
            ++count;
            n = (n-1) & n;
        }
        return count;
    }
};
TEST(SwordQ10, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}
} // namespace sword_q10