/*
#面试刷题# 第0097期
#Leetcode# Q410 HTML实体解析器
难度：中
HTML实体解析器是一种将HTML代码作为输入并将特殊字符的所有实体替换为字符本身的解析器。
HTML的特殊字符及其实体为：
(1) &quot; -> "
(2) &apos; -> '
(3) &amp; -> &
(4) &gt; -> >
(5) &lt; -> <
(6) &frasl; -> /
给定HTML解析器的输入text字符串，您必须实现实体解析器。
用特殊字符替换实体后，返回text。
约束条件：
1 <= text.length <= 10 ^ 5
该字符串可以包含所有256个ASCII字符中的任何可能字符。

示例1:
Input: text = "&amp; is an HTML entity but &ambassador; is not."
Output: "& is an HTML entity but &ambassador; is not."
Explanation: The parser will replace the &amp; entity by &

示例2:
Input: text = "and I quote: &quot;...&quot;"
Output: "and I quote: \"...\""

示例3:
Input: text = "Stay home! Practice on Leetcode :)"
Output: "Stay home! Practice on Leetcode :)"

示例4:
Input: text = "x &gt; y &amp;&amp; x &lt; y is always false"
Output: "x > y && x < y is always false"

示例5:
Input: text = "leetcode.com&frasl;problemset&frasl;all"
Output: "leetcode.com/problemset/all"
*/
#include "leetcode.h"

namespace q1410 {

template<typename T>
bool run_testcases() {
    T slt;
    // example 01
    {
        string text = "&amp; is an HTML entity but &ambassador; is not.";
        string ret = "& is an HTML entity but &ambassador; is not.";
        if (slt.entityParser(text) != ret) {return false;}
    }

    // example 02
    {
        string text = "and I quote: &quot;...&quot;";
        string ret = "and I quote: \"...\"";
        if (slt.entityParser(text) != ret) {return false;}
    }

    // example 03
    {
        string text = "Stay home! Practice on Leetcode :)";
        string ret = "Stay home! Practice on Leetcode :)";
        if (slt.entityParser(text) != ret) {return false;}
    }

    // example 04
    {
        string text = "x &gt; y &amp;&amp; x &lt; y is always false";
        string ret = "x > y && x < y is always false";
        if (slt.entityParser(text) != ret) {return false;}
    }

    // example 05
    {
        string text = "leetcode.com&frasl;problemset&frasl;all";
        string ret = "leetcode.com/problemset/all";
        if (slt.entityParser(text) != ret) {return false;}
    }

    return true;
}
    
// Runtime: 1840 ms, faster than 5.07%
// Memory Usage: 97.8 MB, less than 100.00%
class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> dict{
            {"&quot;", "\""}, {"&apos;", "\'"}, {"&amp;", "&"},
            {"&gt;", ">"}, {"&lt;", "<"}, {"&frasl;", "/"}};
        for (auto & p : dict) {
            regex e(p.first);
            text = regex_replace(text, e, p.second);
        }
        return text;
    }
};
TEST(Q1410, Solution) {EXPECT_EQ(q1410::run_testcases<q1410::Solution>(), true);}

// Runtime: 180 ms, faster than 95.89%
// Memory Usage: 16.4 MB, less than 100.00%
class Solution02 {
public:
    string entityParser(string text) {
        unordered_map<string, char> dict{
            {"&quot;", '\"'}, {"&apos;", '\''}, {"&amp;", '&'},
            {"&gt;", '>'}, {"&lt;", '<'}, {"&frasl;", '/'}};
        int start = 0, len = text.size(), size = 0, p = 0;
        for (int i=0; i < len; ++i, ++p) {
            text[p] = text[i];
            if ('&' == text[p]) {
                start = p;
            }
            if (';' == text[p]) {
                // find key word
                size = p - start + 1;
                if (size >= 4 && size <= 7) {
                    auto iter = dict.find(text.substr(start, size));
                    if (dict.end() != iter) {
                        p -= (size - 1);
                        text[p] = iter->second;
                    }
                }
                start = p + 1;
            }
        }
        // change length of text
        text.resize(p);
        return text;
    }
};
TEST(Q1410, Solution02) {EXPECT_EQ(q1410::run_testcases<q1410::Solution02>(), true);}

} // namespace q141 


