/*
#面试刷题# 第0035期
#Leetcode# Q1317 将整数转换为两个零值之和
难度：低
给定整数n。无零整数是一个正整数，其十进制表示形式不包含任何0。
返回两个整数[A，B]的列表，其中：
(1) A和B是非零整数。
(2) A + B = n
保证至少有一个有效的解决方案。如果有许多有效的解决方案，您可以返回其中任何一个。
约束条件：
(a) 2 <= n <= 10^4

例1:
Input: n = 2
Output: [1,1]
Explanation: A = 1, B = 1. A + B = n and both A and B don't contain any 0 in their decimal representation.

例2:
Input: n = 11
Output: [2,9]

例3:
Input: n = 10000
Output: [1,9999]

例4:
Input: n = 69
Output: [1,68]

例5:
Input: n = 1010
Output: [11,999]
*/
#include "leetcode.h"

namespace q1317{

bool check_ret(const vector<int> & ret, int n) {
    if (ret.size() != 2) {return false;}
    if (ret[0] + ret[1] != n) {return false;}
    for (int i : ret) {
        while (i) {
            if (i % 10 == 0) {return false;}
            i /= 10;
        }
    }
    return true;
}

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below
    if (!check_ret(slt.getNoZeroIntegers(2), 2)) {return false;}
    if (!check_ret(slt.getNoZeroIntegers(11), 11)) {return false;}
    if (!check_ret(slt.getNoZeroIntegers(10000), 10000)) {return false;}
    if (!check_ret(slt.getNoZeroIntegers(69), 69)) {return false;}
    if (!check_ret(slt.getNoZeroIntegers(1010), 1010)) {return false;}
    // succ
    return true;
}

class Solution {
public:
    // Runtime: 4 ms, faster than 60.03%
    // Memory Usage: 8.5 MB, less than 100.00%
    vector<int> getNoZeroIntegers(int n) {
        int len = n / 2 + 1;
        string buff;
        for (int i = 0; i < len; ++i) {
            buff = to_string(i);
            if (buff.find('0') != string::npos) {
                continue;
            }
            buff = to_string(n-i);
            if (buff.find('0') != string::npos) {
                continue;
            } 
            return {i, n-i};
        }
        return vector<int>();
    }
};
TEST(Q1317, Solution) {EXPECT_EQ(q1317::run_testcases<q1317::Solution>(), true);}
};
