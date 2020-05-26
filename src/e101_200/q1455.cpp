/*
#面试刷题# 第129期
#LeetCode# Q1455 检查一个单词是否作为句子中任何单词的前缀出现在句子中
给出一个由一些单词组成的句子，用一个空格隔开的单词和一个searchWord。
你必须检查 searchWord 是否是句子中任何一个词的前缀。
返回句子中 searchWord 是这个词的前缀的词的索引（1-indexed）。
如果 searchWord 是一个以上单词的前缀，返回第一个单词的索引（最小索引）。
如果没有这个词，则返回-1。
一个字符串S的前缀是S的任何前导连续子串。
约束条件：
1 <= sentence.length <= 100
1 <= searchWord.length <= 10
句子由小写英文字母和空格组成。
searchWord由小写英文字母和空格组成。

示例1:
Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.

示例2:
Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.

示例3:
Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.

示例4:
Input: sentence = "i use triple pillow", searchWord = "pill"
Output: 4

示例5:
Input: sentence = "hello from the other side", searchWord = "they"
Output: -1
*/
#include "leetcode.h"

namespace q1455
{

template<typename T>
bool run_testcases() {
    T slt;
    CHECK_RET(4 == slt.isPrefixOfWord("i love eating burger", "burg"));
    CHECK_RET(2 == slt.isPrefixOfWord("this problem is an easy problem", "pro"));
    CHECK_RET(-1 == slt.isPrefixOfWord("i am tired", "you"));
    CHECK_RET(4 == slt.isPrefixOfWord("i use triple pillow", "pill"));
    CHECK_RET(4 == slt.isPrefixOfWord("i use triplepill pillow", "pill"));
    CHECK_RET(-1 == slt.isPrefixOfWord("hello from the other side", "they"));
    return true;
}

class Solution {
private:
    vector<string> _split_words(const string & s) {
        vector<string> ret;
        int len = s.size(), idx = 0, n = 0;
        for (int i = 0; i < len; ++i) {
            if (' ' == s[i] && n > 0) {
                ret.push_back(s.substr(idx, n));
                idx = i + 1;
                n = 0;
            } else {
                ++n;
            }
        }
        if (idx < len - 1) {
            ret.push_back(s.substr(idx, n));
        }
        return ret;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int len = sentence.size(), start = 0, idx = 0, ret = -1;
        while (start < len) {
            idx = sentence.find(searchWord, start);
            // cout << start << "," << idx << endl;
            // 不存在指定单词的情况
            if (string::npos == idx ) {break;}
            // 结果为第一个单词的情况
            if (0 == idx) {return 1;}
            // 判断查找到的位置是否为单词的起点位置
            if (sentence[idx-1] != ' ') {
                // 当前结果不是单词首位置，从下一个词继续查找
                for(start = idx; start < len && sentence[start] != ' '; ++start){}
            } else {
                // 返回结果
                for (ret = 0; idx >= 0; --idx) {
                    if (' ' == sentence[idx]){++ret;}
                }
                return ret + 1;
            }
        }
        return -1;
    }
};    
TEST(Q1455, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace q1455
