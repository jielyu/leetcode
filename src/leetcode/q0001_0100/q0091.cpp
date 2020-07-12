
/*
#面试刷题# 第129期
#LeetCode# Q0091 解码方式
难度：中
使用以下映射将包含A-Z字母的消息编码为数字：

'A'-> 1
'B'-> 2
...
'Z'-> 26
给定一个仅包含数字的非空字符串，请确定对其进行解码的总数。

范例1：

输入：“ 12”
输出2
说明：可以将其解码为“ AB”（1 2）或“ L”（12）。
范例2：

输入：“ 226”
输出3
说明：可以将其解码为“ BZ”（2 26），“ VF”（22 6）或“ BBF”（2 2 6）。

*/
#include "leetcode.h"

namespace q0091
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 4 ms, faster than 54.79% 
// Memory Usage: 6.4 MB, less than 49.80%
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (0 == len) {return 0;}
        
        vector<int> dp (len + 1, 0);
        // 空字符串的情况
        dp[0] = 1;
        // 长度为1的字符串的情况
        if (s[0] != '0') {dp[1] = 1;}
        // 长度大于等于2的字符串的状态
        for (int i = 2; i <= len; ++i) {
            int n1 = stoi(s.substr(i-1, 1));
            int n2 = stoi(s.substr(i-2, 2));
            if (n1 >= 1 && n1 <= 9) {dp[i] += dp[i-1];}
            if (n2 >= 10 && n2 <= 26) {dp[i] += dp[i-2];}
        }
        return dp[len];
    }
};

} // namespace q0091
