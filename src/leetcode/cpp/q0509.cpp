
/*
#LeetCode# Q0509 斐波那契数
难度：低
斐波那契数通常表示为F（n）形成一个序列，称为斐波那契数列，这样每个数都是从0和1开始的两个前面的数之和。

F（0）= 0，F（1）= 1
对于N> 1.F（N）= F（N-1）+ F（N-2）
给定N，计算F（N）。


范例1：

输入2
输出1
说明：F（2）= F（1）+ F（0）= 1 + 0 = 1。
范例2：

输入3
输出2
说明：F（3）= F（2）+ F（1）= 1 +1 = 2。
范例3：

输入4
输出3
说明：F（4）= F（3）+ F（2）= 2 +1 = 3。


*/
#include "leetcode.h"

namespace q0509
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.8 MB, less than 99.48% 
class Solution {
public:
    int fib(int N) {
        if (0 == N) {return 0;}
        if (1 == N) {return 1;}
        int n = 2, n_1 = 1, n_2 = 0;
        for (int i = 2; i <= N; ++i) {
            n = n_1 + n_2;
            n_2 = n_1;
            n_1 = n; 
        }
        return n;
    }
};

} // namespace q0509
