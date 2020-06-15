/*
#面试刷题# 第93期
#Leetcode# Q1078 Bigram之后发生
给定单词“ first”和“ second”，请考虑出现某些形式为“第一第二三”的文本，
其中第二紧跟在第一之后，第三紧随第二。
对于每次发生的此类情况，在答案中添加“第三”，然后返回答案。
约束条件：
1 <= text.length <= 1000
文本由空格分隔的单词组成，其中每个单词均由小写英文字母组成。
1 <=第一长度，第二长度<= 10
第一和第二个由小写英文字母组成。

示例1:
Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]

示例2:
Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]
*/
#include "leetcode.h"

namespace q1078{

template<typename T>
bool run_testcases() {
    T slt;
    // example 01
    {
        string text = "alice is a good girl she is a good student";
        string first = "a", second = "good";
        vector<string> ret {"girl","student"};
        CHECK_RET(comp_vector(slt.findOcurrences(text, first, second), ret));
    }
    // example 02
    {
        string text = "we will we will rock you";
        string first = "we", second = "will";
        vector<string> ret {"we","rock"};
        CHECK_RET(comp_vector(slt.findOcurrences(text, first, second), ret));
    }
    return true;
}
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        // construct pattern string
        string key = first + " " + second + " ";
        int len = (int)(text.size());

        vector<string> res;
        int start = 0;
        const char * p_text = text.data();
        while(start < len - 1) {
            // get sub string
            string sub = text.substr(start, len-start);
            // find key pattern in substring
            int pos = sub.find(key);
            //cout << "sub=" << sub << ", pos=" << pos << endl;
            if ( pos == string::npos) {
                break;
            }
            // get the third word
            int start_res_pos = start + pos + key.size();
            for (int i=start_res_pos; i<=len; ++i) {
                if (i == len || p_text[i] == ' ') {
                    string sub_res = text.substr(start_res_pos, i - start_res_pos);
                    res.push_back(sub_res);
                    if (sub_res == first) {
                        start += key.size() + pos;
                    } else {
                        start = i + 1;
                    }
                    break;
                }
            }
        }
        return res;
    }
};
TEST(Q1078, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

};
