/*
#面试刷题# 第0103期
#Leetcode# Q1417 重排列字符串
难度：低
给出一个字母数字字符串s（字母数字字符串是由小写英文字母和数字组成的字符串）。
你必须找到一个字符串的排列，其中没有一个字母后面有另一个字母，也没有一个数字后面有另一个数字。
也就是说，没有两个相邻的字符具有相同的类型。
返回重新格式化的字符串，如果无法重新格式化，则返回空字符串。
约束条件：
1 <= s.length <= 500
s仅由小写的英文字母和/或数字组成。

示例1:
Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.

示例2:
Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.

示例3:
Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.

示例4:
Input: s = "covid2019"
Output: "c2o0v1i9d"

示例5:
Input: s = "ab123"
Output: "1a2b3"
*/
#include "leetcode.h"

namespace q1417 {

bool is_valid(const string & s) {
    int n = s.size();
    for (int i=1; i < n; ++i) {
        auto is_digit1 = s[i] >= '0' && s[i] <= '9';
        auto is_digit2 = s[i-1] >= '0' && s[i-1] <= '9'; 
        if (!(is_digit1 ^ is_digit2)) {return false;}
    }
    return true;
}

template<typename T>
bool run_testcases() {
    T slt;

    CHECK_RET(is_valid(slt.reformat("a0b1c2")));
    CHECK_RET(is_valid(slt.reformat("leetcode")));
    CHECK_RET(is_valid(slt.reformat("1229857369")));
    CHECK_RET(is_valid(slt.reformat("covid2019")));
    CHECK_RET(is_valid(slt.reformat("ab123")));

    return true;
}

// Runtime: 16 ms, faster than 81.86%
// Memory Usage: 7.6 MB, less than 100.00%
class Solution {
public:
    string reformat(string s) {
        int n = s.size();
        // divide letters and digits
        string letters, digits;
        for (auto & c : s) {
            if (c >= '0' && c <= '9') {
                digits.push_back(c);
            } else {
                letters.push_back(c);
            }
        }
        //cout << digits << "," << letters << endl;
        int diff = digits.size() - letters.size();
        if (diff > 1 || diff < -1) {return "";}
        // judge the longer
        auto longer = digits.size() > letters.size() ? digits : letters;
        auto shorter = digits.size() <= letters.size() ? digits : letters;
        // create results
        string ret(n, 'x');
        for (int i = 0, j = 0; i < n; i += 2, ++j) {
            ret[i] = longer[j];
        }
        for (int i = 1, j = 0; i < n; i += 2, ++j) {
            ret[i] = shorter[j];
        }
        return ret;
    }
};
TEST(Q1417, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace q1417
