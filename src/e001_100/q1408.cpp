/*
#面试刷题# 第0095期
#Leetcode# Q1408 数组中的字符串匹配
难度：低
给定一个字符串words数组。 以任意顺序返回words中所有字符串，
这些字符串是另一个单词的子字符串。
字符串words[i]是words[j]的子字符串，如果可以获取的话，
可以去除words[j]左侧和/或右侧的一些字符。
约束条件：
1 <= words.length <= 100
1 <= words[i] .length <= 30
words[i]仅包含小写英文字母。
可以保证单词[i]是唯一的。

示例1:
Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.

示例2:
Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".

示例3:
Input: words = ["blue","green","bu"]
Output: []
*/
#include "leetcode.h"

namespace q1408 {
    
template<typename T>
bool run_testcases() {
    T slt;
    // example 01
    {
        vector<string> words{"mass","as","hero","superhero"};
        vector<string> ret{"as","hero"};
        if (!comp_vector(slt.stringMatching(words), ret)) {return false;}
    }

    // example 02
    {
        vector<string> words{"leetcode","et","code"};
        vector<string> ret{"et","code"};
        if (!comp_vector(slt.stringMatching(words), ret)) {return false;}
    }

    // example 03
    {
        vector<string> words{"blue","green","bu"};
        vector<string> ret;
        if (!comp_vector(slt.stringMatching(words), ret)) {return false;}
    }

    return true;
}

// Runtime: 8 ms, faster than 83.73%
// Memory Usage: 8.7 MB, less than 100.00%
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // sort ascending in length
        sort(words.begin(), words.end(), [](string & i, string & j){
            return i.size() < j.size();
        });
        // find all results
        int len = words.size();
        vector<string> ret;
        for (int i = 0; i < len - 1; ++i) {
            for (int j = i+1; j < len; ++j) {
                // check if i is a substring of j
                if (words[j].find(words[i]) != string::npos) {
                    ret.push_back(words[i]);
                    break;
                }
            }
        }
        return ret;
    }
};
TEST(Q1408, Solution) {EXPECT_EQ(q1408::run_testcases<q1408::Solution>(), true);}

}; // namespace q1408


