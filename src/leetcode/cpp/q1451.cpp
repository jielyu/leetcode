/*
#面试刷题# 第127期
#LeetCode# Q1451 重排句子中的词语
难度：中
给出一个句子文本（句子是一串空格分隔的单词），格式如下：
(1) 第一个字母为大写。
(2) 文本中的每个字都用一个空格隔开。
你的任务是将文本中的单词重新排列，使所有的单词按长度递增的顺序重新排列。
如果两个词的长度相同，则按原顺序排列。按照上文所示的格式返回新文本。
约束条件：
text以大写字母开头，然后包含小写字母，字与字之间的空格。
1 <= text.length <= 10^5

示例1:
Input: text = "Leetcode is cool"
Output: "Is cool leetcode"
Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
Output is ordered by length and the new first word starts with capital letter.

示例2:
Input: text = "Keep calm and code on"
Output: "On and keep calm code"
Explanation: Output is ordered as follows:
"On" 2 letters.
"and" 3 letters.
"keep" 4 letters in case of tie order by position in original text.
"calm" 4 letters.
"code" 4 letters.

示例3:
Input: text = "To be or not to be"
Output: "To be or to be not"
*/
#include "leetcode.h"

namespace q1451
{

template<typename T>
bool run_testcases() {
    T slt;
    CHECK_RET("Is cool leetcode" == slt.arrangeWords("Leetcode is cool"));
    CHECK_RET("On and keep calm code" == slt.arrangeWords("Keep calm and code on"));
    CHECK_RET("To be or to be not" == slt.arrangeWords("To be or not to be"));
    return true;
}

// Runtime: 220 ms, faster than 37.56% 
// Memory Usage: 17.9 MB, less than 100.00%
class Solution {
public:
    string arrangeWords(string text) {
        text[0] -= ('A' - 'a'); // to lower case
        vector<pair<string, int>> words;
        int idx = 0, n = 0, len = text.size();
        for (int i = 0; i < len; ++i) {
            if (text[i] == ' ') {
                words.push_back({text.substr(idx, n), idx});
                idx = i + 1; 
                n = 0;
            } else {++n;}
        }
        // record the last word
        words.push_back({text.substr(idx, n), idx});
        sort(words.begin(), words.end(), [](pair<string, int> & i, pair<string, int> & j) {
            if (i.first.size() < j.first.size()) {return true;}
            if ((i.first.size() == j.first.size()) && (i.second < j.second)) {return true;}
            return false;
        });
        // arrange result
        string ret;
        for (auto iter = words.begin(); iter != words.end(); ++iter) {
            ret += (iter->first);
            ret.push_back(' ');
        }
        ret[0] -= ('a' - 'A');
        ret.resize(len);
        return ret;
    }
};    
TEST(Q1451, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace q1451
