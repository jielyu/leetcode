/*
#面试刷题# 第0089期
#Leetcode# Q1405 最长的快乐字符串
难度：中
如果字符串不包含任何字符串“ aaa”，“ bbb”或“ ccc”作为子字符串，则称为“快乐”。
给定三个整数a，b和c，返回满足以下条件的任何字符串s：
s是幸福的，也是最长的。
s最多包含一个字母“ a”的出现，最多b个出现的字母“ b”和最多c个出现的字母“ c”。
s仅包含“ a”，“ b”和“ c”字母。
如果没有这样的字符串，则返回空字符串“”。
约束条件：
0 <= a, b, c <= 100
a + b + c > 0

示例1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

示例2:
Input: a = 2, b = 2, c = 1
Output: "aabbc"

示例3:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It's the only correct answer in this case.
*/
#include "leetcode.h"

namespace q1405 {

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below
    slt.longestDiverseString(1,1,7);
    slt.longestDiverseString(2,2,1);
    slt.longestDiverseString(7,1,0);

    // succ
    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 100.00%
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // maintain a big top heap
        priority_queue<pair<int, char>> pqueue;
        if(a > 0) pqueue.push({a, 'a'});
        if(b > 0) pqueue.push({b, 'b'});
        if(c > 0) pqueue.push({c, 'c'});
        
        string ret = "";
        while (pqueue.size() > 1) {
            // get two pairs <int, char>
            auto  p1 = pqueue.top();
            pqueue.pop();
            auto  p2 = pqueue.top();
            pqueue.pop();
            // follow the rules
            if (p1.first >= 2) {
                ret += p1.second;
                ret += p1.second;
                p1.first -= 2;
            } else {
                ret += p1.second;
                p1.first -= 1;
            }
            if (p2.first >= 2 && p2.first > p1.first) {
                ret += p2.second;
                ret += p2.second;
                p2.first -= 2;
            } else {
                ret += p2.second;
                p2.first -= 1;
            }
            // check number
            if (p1.first > 0) {
                pqueue.push(p1);
            }
            if (p2.first > 0) {
                pqueue.push(p2);
            }
        }
        // process the remainders
        if (pqueue.size() > 0) {
            auto & p = pqueue.top();
            if (p.first >= 2) {
                ret += p.second;
                ret += p.second;
            } else {
                ret += p.second;
            }
        }
        return ret;
    }
};
TEST(Q1405, Solution) {EXPECT_EQ(q1405::run_testcases<q1405::Solution>(), true);}

};