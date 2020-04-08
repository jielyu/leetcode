/*
#面试刷题# 第0088期
#Leetcode# Q1404 将二进制表示形式的数量减少为1的步骤数
难度：中
给定其二进制表示形式中的数字。 根据以下规则返回将其减少为1的步骤数：
如果当前数字为偶数，则必须将其除以2。
如果当前数字为奇数，则必须对其加1。
保证您始终可以在所有测试用例中达到一个。
约束条件：
1 <= s.length <= 500
s 由字符 '0' 或者 '1'组成
s[0] == '1'

示例1:
Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1. 

示例2:
Input: s = "10"
Output: 1
Explanation: "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  

示例3:
Input: s = "1"
Output: 0
*/
#include "leetcode.h"

namespace q1404{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

// Runtime: 0 ms, faster than 100.00% 
// Memory Usage: 6.3 MB, less than 100.00%
class Solution {
public:
    int numSteps(string s) {
        int ret = 0, len = s.size();
        bool increase = false;
        for (int i = len - 1; i >= 0; --i) {
            if (i==0 && !increase) {break;}
            if ((!increase) && (s[i] == '1')) {
                increase = true;
                ret += 2;
            } else if (increase && (s[i] == '1')) {
                ++ret;
                increase = true;
            } else if ((!increase) && (s[i] == '0')) {
                ++ret;
                increase = false;
            } else {
                ret += 2;
                increase = true;
            }
            //cout << increase << "," << s[i] << "," << ret << endl;
        }
        return ret;
    }
};

};
