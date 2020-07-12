
/*
#面试刷题# 第130期
#LeetCode# Q0097 交织字符串
难度：高
给定s1，s2，s3，找出s3是否由s1和s2的交错形成。

范例1：

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/
#include "leetcode.h"

namespace q0097
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7 MB, less than 28.99%
class Solution {
private:
    bool _dfs(int i, int j, int k, string & s1, 
              string & s2, string & s3, vector<vector<int>> & dp) {
        if (s1.size() == i && s2.size() == j && s3.size() == k) {return true;}
        // 已经计算过的状态直接返回
        if (-1 != dp[i][j]) {return dp[i][j] > 0;}
        
        bool ret = false;
        // 对s1与s3进行比较
        if (i < s1.size()) {
            if (s1[i] == s3[k]) {
                ret = ret || _dfs(i+1,j, k+1, s1, s2,s3, dp);
            }
        }
        // 对s2和s3进行比较
        if (j < s2.size()) {
            if (s2[j] == s3[k]) {
                ret = ret || _dfs(i, j+1, k+1, s1, s2, s3, dp);
            }
        }
        // 设置状态
        dp[i][j] = (int)ret;
        return ret;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size();
        vector<vector<int>> dp (len1+1, vector<int>(len2+1, -1));
        return _dfs(0,0,0, s1, s2, s3, dp);
    }
};

} // namespace q0097
