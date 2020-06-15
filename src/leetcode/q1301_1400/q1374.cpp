/*
#面试刷题# 第0064期
#Leetcode# Q1374 生成具有奇数字符的字符串
难度：低
给定一个整数n，返回一个包含n个字符的字符串，以使该字符串中的每个字符出现奇数次。
返回的字符串只能包含小写英文字母。如果有多个有效字符串，则返回其中任何一个。
约束条件：
(1) 1 <= n <= 500

例1:
Input: n = 4
Output: "pppz"
Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once. Note that there are many other valid strings such as "ohhh" and "love".

例2:
Input: n = 2
Output: "xy"
Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once. Note that there are many other valid strings such as "ag" and "ur".

例3:
Input: n = 7
Output: "holasss"
*/
#include "leetcode.h"

namespace q1374{

bool check_ret(const string & s) {
    unordered_map<char, int> dict;
    for (const auto & c : s) {
        ++dict[c];
    }
    for (auto & p : dict) {
        if (p.second > 0 && p.second % 2 == 0) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    CHECK_RET(check_ret(slt.generateTheString(4)));
    CHECK_RET(check_ret(slt.generateTheString(2)));
    CHECK_RET(check_ret(slt.generateTheString(7)));

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 0 ms, faster than 100.00% 
    // Memory Usage: 7.7 MB, less than 100.00%
    string generateTheString(int n) {
        string ret(n-1, 'a');
        
        if (n % 2 == 1) {
            ret.push_back('a');
        } else {
            ret.push_back('b');
        }
        return ret;
    }
};
TEST(Q1374, Solution) {EXPECT_TRUE(q1374::run_testcases<q1374::Solution>());}
};
