/*
#面试刷题# 第0041期
#Leetcode# Q779 语法的第K个符号
在第一行上，我们写为0。现在，在每个随后的行中，我们查看前一行，
并用01替换每个出现的0，并用10替换每个出现的1。
给定第N行和索引K，返回第N行的第K个索引符号。（K的值为1索引。）（1个索引）。
约束条件：
N 是 [1, 30]范围的整数.
K 是 [1, 2^(N-1)] 范围的整数.

例1:
Input: N = 1, K = 1
Output: 0

例2:
Input: N = 2, K = 1
Output: 0

例3:
Input: N = 2, K = 2
Output: 1

例4：
Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
*/
#include "leetcode.h"

namespace q0779{
template<typename T>
bool run_testcases() {
    T slt;
    // example 01
    if (slt.kthGrammar(1,1) != 0) return false;
    // example 02
    if (slt.kthGrammar(2,1) != 0) return false;
    // example 03
    if(slt.kthGrammar(2,2) != 1) return false;
    // example 04
    if(slt.kthGrammar(4,5) != 1) return false;
    return true;
}

class Solution {
public:
    int get_kth_bit(const int & low, const int & high, const int & value, const int & K) {
        if (low == high) {
            return value;
        }
        int mid = (low + high) / 2;
        int cur_val = value;
        if (K > mid) {
            cur_val = (value == 0 ? 1 : 0);
            return get_kth_bit(mid + 1, high, cur_val, K);
        }
        return get_kth_bit(low, mid, cur_val, K);
    }
    
    // Runtime: 4 ms, faster than 55.34%
    // Memory Usage: 8.4 MB, less than 41.67%
    int kthGrammar(int N, int K) {
        return get_kth_bit(1, 1<<(N-1), 0, K);
    }
};
TEST(Q0779, Solution) {EXPECT_EQ(q0779::run_testcases<q0779::Solution>(), true);}

};