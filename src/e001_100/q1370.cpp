/*
#面试刷题# 第71期
#Leetcode# Q1370 递增递减字符串
难度：低
给定一个字符串s。您应该使用以下算法对字符串重新排序：
(1) 从s中选择最小的字符，并将其附加到结果中。
(2) 从s中选择一个大于最后一个追加字符的最小字符，并将其追加。
(3) 重复步骤2，直到您不能选择更多的字符。
(4) 从s中选择最大的字符，并将其附加到结果中。
(5) 从s中选择比最后添加的字符小的最大字符，然后将其添加。
(6) 重复步骤5，直到您无法选择更多字符。
(7) 重复步骤1到6，直到从中选择所有字符。
在每个步骤中，如果最小或最大字符出现多次，则可以选择任何出现的字符并将其附加到结果中。
使用此算法对s排序后返回结果字符串。
约束条件：
(a) 1 <= s.length <= 500
(b) s仅包含小写英文字母

例1:
Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"

例2:
Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.

例3:
Input: s = "leetcode"
Output: "cdelotee"

例4：
Input: s = "ggggggg"
Output: "ggggggg"

例5:
Input: s = "spo"
Output: "ops"
*/
#include "leetcode.h"

namespace q1370{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 0 ms, faster than 100.00%
    // Memory Usage: 7.6 MB, less than 100.00%
    string sortString(string s) {
        vector<int> hist(26, 0);
        // create histogram
        int max_cnt = 0;
        for (auto c : s) {
            c -= 'a';
            ++hist[c];
        }
        // get the max count 
        for (auto & i : hist) {
            if (max_cnt < i) {
                max_cnt = i;
            }
        }
        
        // generate result
        string ret;
        int direction = 1, jj = 0;
        for (int i = 0; i < max_cnt; ++i) {
            for (int j = 0; j < 26; ++j) {
                jj = direction ? j : 25 - j;
                if (!hist[jj]) {
                    continue;
                }
                ret.push_back((char)(jj+'a'));
                --hist[jj];
            }
            // change direction
            direction = 1 - direction;
        }
        return ret;
    }
};
};
