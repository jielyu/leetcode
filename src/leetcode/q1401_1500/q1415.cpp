/*
#面试刷题# 第0102期
#Leetcode# Q1415 长度为n的所有快乐字符串的第k个词典序的字符串
难度：中
一个快乐的字符串是一个字符串，它是由
仅由集合[''a', 'b', 'c']中的字母组成。
s[i] != s[i + 1] 对于所有的i的值从1到s.length - 1之间的值（字符串是1个索引）。
例如，字符串 "abc"，"ac"，"b "和 "abcbabcbcbcb "都是快乐的字符串，
而字符串 "aa"，"baa "和 "abababbc "不是快乐的字符串。
给定两个整数n和k，考虑一个按词法顺序排序的长度为n的所有快乐字符串的列表。
如果长度为n的快乐字符串少于k，则返回该列表中的第k个字符串，或者返回一个空字符串。
约束条件：
1 <= n <= 10
1 <= k <= 100

示例1:
Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

示例2:
Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.

示例3:
Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"

示例4:
Input: n = 2, k = 7
Output: ""

示例5:
Input: n = 10, k = 100
Output: "abacbabacb"
*/
#include "leetcode.h"

namespace q1415 {

template<typename T>
bool run_testcases() {
    T slt;

    {
        int n = 1, k = 3;
        string ret = "c";
        CHECK_RET(slt.getHappyString(n, k) == ret);
    }

    {
        int n = 1, k = 4;
        string ret = "";
        CHECK_RET(slt.getHappyString(n, k) == ret);
    }

    {
        int n = 3, k = 9;
        string ret = "cab";
        CHECK_RET(slt.getHappyString(n, k) == ret);
    }

    {
        int n = 2, k = 7;
        string ret = "";
        CHECK_RET(slt.getHappyString(n, k) == ret)
    }

    {
        int n = 10, k = 100;
        string ret = "abacbabacb";
        CHECK_RET(slt.getHappyString(n, k) == ret);
    }

    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 100.00%
class Solution {
public:
    string getHappyString(int n, int k) {
        // 第一个字母有3种选择，其他字母都只有两种选择。
        // 总的情况个数为3*2^(n-1)
        int t = 3;
        for (int i = 1; i < n; ++i) {
            t <<= 1;
        }
        if (k > t) {return "";}
        // create each char in the answer string
        string letters = "abc", ret;
        int count = 0, idx = 0;
        for (int i = 0; i < n; ++i) {
            if (0 == i) { // for the first char
                t /= 3;
            } else { // for the others
                t >>= 1;
            }
            // count bits
            for (count = 0; k > t; ++count) {k -= t;};
            // find index
            for (idx = 0; (ret != "" && ret.back() == letters[idx]) || (count--); ++idx);
            ret.push_back(letters[idx]);
        }
        return ret;
    }
};
TEST(Q1415, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

// @@Tiabeanie2
class Solution02 {
public:
    string sol;
    int count;
    int k;
    string kSol;
    string getHappyString(int n, int _k) {
        k = _k;
        count = 0;
        sol.resize(n);
        go(0);
        if (count == k) return kSol;
        return "";
    }
   
    void go(int pos)
    {
        if (count == k) return;
        if (pos == sol.size())
        {
            count ++;
            if (count == k) kSol = sol;
            return;
        }
       
        for (char ch = 'a'; ch <= 'c'; ch ++)
        {
            if (pos == 0 || sol[pos - 1] != ch)
            {
                sol[pos] = ch;
                go(pos + 1);
            }
        }        
    }
};
TEST(Q1415, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}

// @@Tiabeanie2
class Solution03 {
public:
    string getHappyString(int n, int k) {
        int total = 3;
        int p = 1;
        for (int i = 0; i < n - 1; i ++)
        {
            total <<= 1;
            p <<= 1;
        }
        if (k > total) return "";
        string sol(n, 'a');
        if (k > p && k <= 2 * p)
        {
            sol[0] = 'b'; k -= p;
        }
        else if (k > 2 * p)
        {
            sol[0] = 'c'; k -= 2 * p;
        }
       
        int i = 1;
        while (i < n)
        {
            p >>= 1;
            if (k <= p) sol[i] = getChar(sol[i - 1], true);
            else
            {
                sol[i] = getChar(sol[i - 1], false);
                k -= p;        
            }
            i ++;
        }
           
        return sol;
    }
   
    char getChar(char prev, bool first)
    {
        char ch;
        char last;
        for (ch = 'a'; ch <= 'c'; ch ++)
        {
            if (prev == ch) continue;
            if (first) return ch;
            last = ch;
        }
        return last;
    }
};
TEST(Q1415, Solution03) {EXPECT_TRUE(run_testcases<Solution03>());}

/* 回溯法 -- 递归模版
与Solution02的解法一致，只是避免了对象成员的使用，改为传递引用参数
*/
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 100.00%
class Solution04 {
private:
    void _dfs(string & slt, string & k_slt, int & k, int pos) {
        // 最优解终止条件
        if (0 == k) {return;}
        // 找到一个解的终止条件
        if (slt.size() == pos) {
            if (0 == (--k)) {k_slt = slt;}
            return;
        }
        // 遍历当前节点的所有可能解
        for (char ch = 'a'; ch <= 'c'; ++ch) {
            // 判断约束条件
            if (0 == pos || slt[pos-1] != ch) {
                // 设置当前位置
                slt[pos] = ch;
                // 搜索下一个位置
                _dfs(slt, k_slt, k, pos+1);
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        string slt(n, 0), k_slt;
        _dfs(slt, k_slt, k, 0);
        //cout << slt << "," << k_slt << "," << k << endl;
        if (0 == k) {return k_slt;}
        return "";
    }
};
TEST(Q1415, Solution04) {EXPECT_TRUE(run_testcases<Solution04>());}

/* 回溯法 -- while模版 */
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 100.00%
class Solution05 {
    public:
    string getHappyString(int n, int k) {
        // 初始化字符串
        string slt(n, 0); // 状态存储器
        string k_slt;     // 最优解记录器
        int pos = 0;      // 搜索索引位置
        // 设置索引位置的条件限制
        while (pos >= 0 && pos <= n) {
            //cout << pos << "," << slt << "," << k << endl;
            if (pos == n) { // 搜索到一个解
                // 搜索到符合条件的最优解，结束搜索
                if (0 == (--k)) {
                    k_slt = slt;
                    break;
                } else { // 不是最优解，则开始回溯
                    // 回退索引
                    --pos;
                }
            } else {
                // 设置slt[pos]的第一个可能字符
                if (slt[pos] == 0) {
                    slt[pos] = 'a';
                } else {
                    ++slt[pos];
                }
                // 搜索slt[pos] 
                while (pos > 0 && slt[pos-1] == slt[pos]) {
                    ++slt[pos];
                }
                // 判断当前解符合要求则尝试下一个
                if (slt[pos] >= 'a' && slt[pos] <= 'c') {
                    // 标示当前位置，上面已经完成
                    // 开始下一个
                    ++pos;
                }
                // 判断当前解不符合要求，则回溯
                else {
                    // 清理当前状态
                    slt[pos] = 0;
                    // 返回上一个
                    --pos;
                }
            }
        }
        if (0 == k) {return k_slt;}
        return "";
    }
};
TEST(Q1415, Solution05) {EXPECT_TRUE(run_testcases<Solution05>());}
} // namespace q1415