/*
#面试刷题# 第0043期
#Leetcode# Q1309 将字符串从字母解密为整数映射
难度：低
给定由数字（'0'-'9'）和'＃'组成的字符串s。我们想将s映射为英文小写字符，如下所示：
(1) 字符（'a'至'i'）分别由（'1'至'9'）表示。
(2) 字符（'j'至'z'）分别由（'10＃'至'26＃'）表示。
返回映射后形成的字符串。
确保唯一的映射将始终存在。
约束条件：
(1) 1 <= s.length <= 1000
(2) s[i] 只包含数字字符 ('0'-'9') 和 '#' 字符.
(3) s是有效字符串，因此始终可以进行映射

例1:
Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

例2:
Input: s = "1326#"
Output: "acz"

例3:
Input: s = "25#"
Output: "y"

例4:
Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"
*/
#include "leetcode.h"

namespace q1309{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 4 ms, faster than 64.27%
    // Memory Usage: 8.5 MB, less than 100.00%
    string freqAlphabets(string s) {
        string ret;
        int len = s.size(), idx = 0;
        while (idx < len) {
            if (idx+2<len && s[idx+2]=='#') {
                ret += 'a' + (s[idx] - '0')*10 + s[idx+1] - '0' - 1;
                idx += 3;
            } else {
                ret += 'a' + s[idx] - '0' - 1;
                ++idx;
            }
        }
        return ret;
    }
};

};