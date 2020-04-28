/*
#面试刷题# 第0032期
#Leetcode# Q1323 最大的69数字
难度：低
给定一个仅由数字6和9组成的正整数num。
返回最多更改一位可获得的最大数字（6变为9，而9变为6）。
约束条件：
(a) 1 <= num <= 10^4
(b) num的各位数字为6或者9

例1:
Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666. 
The maximum number is 9969.

例2:
Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.

例3:
Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
*/
#include "leetcode.h"

namespace q1323{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    if (9969 != slt.maximum69Number(9669)) {return false;}
    if (9999 != slt.maximum69Number(9996)) {return false;}
    if (9999 != slt.maximum69Number(9999)) {return false;}

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 0 ms, faster than 100.00%
    // Memory Usage: 8.4 MB, less than 100.00%
    int maximum69Number (int num) {
        auto s = to_string(num);
        for (auto & c : s) {
            if ('6' == c) {
                c = '9';
                break;
            }
        }
        return stoi(s);
    }
};
TEST(Q1323, Solution) {EXPECT_EQ(q1323::run_testcases<q1323::Solution>(), true);}
};