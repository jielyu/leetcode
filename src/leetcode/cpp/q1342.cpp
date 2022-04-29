/*
#面试刷题# 第0025期
#Leetcode# Q1342 将数字减少为零的步骤数
难度：低
给定一个非负整数num，返回将其减少为零的步骤数。
如果当前数字为偶数，则必须将其除以2，否则，必须从中减去1。
约束条件：
(a) 0 <= num <= 10^6

例1:
Input: num = 14
Output: 6
Explanation: 
Step 1) 14 is even; divide by 2 and obtain 7. 
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3. 
Step 4) 3 is odd; subtract 1 and obtain 2. 
Step 5) 2 is even; divide by 2 and obtain 1. 
Step 6) 1 is odd; subtract 1 and obtain 0.

例2:
Input: num = 8
Output: 4
Explanation: 
Step 1) 8 is even; divide by 2 and obtain 4. 
Step 2) 4 is even; divide by 2 and obtain 2. 
Step 3) 2 is even; divide by 2 and obtain 1. 
Step 4) 1 is odd; subtract 1 and obtain 0.

例3:
Input: num = 123
Output: 12
*/
#include "leetcode.h"

namespace q1342{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    if (6 != slt.numberOfSteps(14)) {return false;}
    if (4 != slt.numberOfSteps(8)) {return false;}
    if (12 != slt.numberOfSteps(123)) {return false;}

    // succ
    return true;
}

class Solution {
public:
    int numberOfSteps(int num) {
        int ret = 0;
        while (num > 0) {
            ++ret;
            if (num % 2 == 1) {
                num -= 1;
            } else {
                num /=2;
            }
        }
        return ret;
    }
};
TEST(Q1342, Solution) {EXPECT_EQ(q1342::run_testcases<q1342::Solution>(), true);}

class Solution02 {
public:
    // Runtime: 0 ms, faster than 100.00%
    // Memory Usage: 8.4 MB, less than 100.00%
    int numberOfSteps(int num) {
        if (!num) {
            return 0;
        }
        // number of bits + number of ones in binary
        return log2(num) + bitset<32>(num).count();
    }
};
TEST(Q1342, Solution02) {EXPECT_EQ(q1342::run_testcases<q1342::Solution02>(), true);}
};