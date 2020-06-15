
/*
#LeetCode# Q0050 Pow(x, n)
难度：中
执行pow(x，n)，计算出x升到幂n(x^n)。

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

注：
-100.0 < x < 100.0
n是一个32位有符号的整数，范围为[-231, 231 - 1]。

*/
#include "leetcode.h"

namespace q0050
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 64.28%
class Solution {
double _helper(double x, long n) {
    if (0 == n) {return 1.0;}
    if (n % 2 == 1) {
        return x * _helper(x, n-1);
    }
    double tmp = _helper(x, n / 2);
    return tmp*tmp;
}
public:
    double myPow(double x, int n) {
        if (x > -1e-5 && x < 1e-5 && n < 0) {return 0.0;}
        long abs_exp = n;
        if (n < 0) {abs_exp = - abs_exp;}
        double ret = _helper(x, abs_exp);
        if (n < 0) {ret = 1.0 / ret;}
        return ret;
    }
};

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 38.10% 
class Solution02 {
double _helper(double x, long n) {
    if (0 == n) {return 1.0;}
    double ret = 1.0;
    while (n) {
        if (n & 0x01) {ret *= x;}
        x *= x;
        n >>= 1;
    }
    return ret;
}
public:
    double myPow(double x, int n) {
        if (x > -1e-5 && x < 1e-5 && n < 0) {return 0.0;}
        long abs_exp = n;
        if (n < 0) {abs_exp = - abs_exp;}
        double ret = _helper(x, abs_exp);
        if (n < 0) {ret = 1.0 / ret;}
        return ret;
    }
};

} // namespace q0050
