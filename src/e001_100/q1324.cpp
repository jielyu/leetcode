/*
#面试刷题# 第0031期
#Leetcode# Q1324 垂直打印单词
难度：中
给定一个字符串s。垂直返回所有单词，顺序与它们在s中出现的顺序相同。
单词以字符串列表形式返回，必要时以空格结尾。 （不允许使用尾随空间）。
每个单词将仅放在一列上，而在一列中将只有一个单词。
约束条件：
(a) 1 <= s.length <= 200
(b) 仅包含大写英文字母
(c) 保证两个单词之间只有一个空格。

例1:
Input: s = "HOW ARE YOU"
Output: ["HAY","ORO","WEU"]
Explanation: Each word is printed vertically. 
 "HAY"
 "ORO"
 "WEU"

例2:
Input: s = "TO BE OR NOT TO BE"
Output: ["TBONTB","OEROOE","   T"]
Explanation: Trailing spaces is not allowed. 
"TBONTB"
"OEROOE"
"   T"

例3:
Input: s = "CONTEST IS COMING"
Output: ["CIC","OSO","N M","T I","E N","S G","T"]
*/
#include "leetcode.h"

namespace q1324{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
private:
    int _split(const string & s, const string & sep, vector<string> & ret) {
        int word_max = 0, mid_size = 0;
        string::size_type start = 0;
        string::size_type end = s.find(sep);
        int len = s.size(), sep_len = sep.size();
        // get words and record max_size
        while (string::npos != end) {
            auto w = s.substr(start, end - start);
            mid_size = w.size();
            if (word_max < mid_size) {
                word_max = mid_size;
            }
            ret.push_back(w);
            start = end + sep_len;
            end = s.find(sep, start);
        }
        // get the last word
        if (start != len) {
            auto w = s.substr(start);
            mid_size = w.size();
            if (word_max < mid_size) {
                word_max = mid_size;
            }
            ret.push_back(w);
        }
        return word_max;
    }
    
public:
    // Runtime: 0 ms, faster than 100.00%
    // Memory Usage: 8.5 MB, less than 100.00% 
    vector<string> printVertically(string s) {
        // split string into vector
        string sep = " ";
        vector<string> words;
        auto max_size = _split(s, sep, words);
        // concat results
        vector<string> ret;
        string buff;
        for (int i = 0; i < max_size; ++i) {
            buff.clear();
            for (auto & w : words) {
                if (i >= w.size()) {
                    buff.push_back(' ');
                } else {
                    buff.push_back(w[i]);
                }
            }
            ret.push_back(buff);
        }
        // remove trailing spaces
        for (auto & r : ret) {
            auto end = r.find_last_not_of(' ');
            r = r.substr(0, end+1);
        }
        return ret;
    }
};

};