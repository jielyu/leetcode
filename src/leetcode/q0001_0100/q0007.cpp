
/*
#LeetCode# Q0007 翻转整数
难度：低
给定一个32位有符号的整数，反之为整数的倒数。

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21

假设我们所处理的环境只能存储32位有符号整数范围内的整数。[−2^31, 2^31 − 1]. 在这个问题中，假设你的函数在反向整数溢出时返回0。

*/
#include "leetcode.h"

namespace q0007
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

/*
思路：关键在于对溢出情况的处理
*/

// Runtime: 0 ms, faster than 100.00%
// Runtime: 0 ms, faster than 100.00%
class Solution {
public:
    int reverse(int x) {
        bool isPos = (x>=0);
        long xx = x;
        if (!isPos) {xx = -xx;}
        long val = 0;
        while(xx){
            int t = xx % 10;
            xx /= 10;
            if ((0x7fffffff - t) > val * 10) {val = 10 * val + t;}
            else {val = 0; break;}
        }
        if (!isPos) {val = -val;}
        return (int)val;
    }
};

} // namespace q0007
