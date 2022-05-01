
/*
#剑指Offer# Q45 圆圈中最后剩下的数字
0，1,...,n-1这n个数组排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字。
求这个圆圈剩下的随后的数字。

*/
#include "leetcode.h"

namespace sword_q45
{

template<typename T>
bool run_testcases() {
    T slt;

    CHECK_RET(3 == slt.lastRemain(5,3));

    return true;
}

/*
解决思路1:使用环形链表模拟求解。

解决思路2: 
当n=1时，f(n, m) = 0
当n>1时, f(n, m) = [f(n-1, m) + m] % n
*/

class Solution {
public:
    int lastRemain(uint32_t n, uint32_t m) {
        if (n < 1 || m < 1) {return -1;}
        int last = 0;
        for (int i = 2; i <= n; ++i) {
            last = (last + m) % i;
        }
        return last;
    }
};
TEST(SwordQ45, Solution){EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q45
