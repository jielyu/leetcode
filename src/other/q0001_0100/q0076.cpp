
/*
#LeetCode# Q0076 最小窗口子串
难度：高

给定一个字符串S和一个字符串T，求出S中包含T中所有字符的最小窗口，其复杂度为O(n)。

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

注意：

如果S中没有覆盖T中所有字符的窗口，返回空字符串""。
如果有这样的窗口，保证S中永远只有一个唯一的最小窗口。

*/
#include "leetcode.h"

namespace q0076
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 296 ms, faster than 5.90%
// Memory Usage: 16.6 MB, less than 10.15%
class Solution {
private:
    // 用于判断hs是否覆盖ht
    bool _is_covered(unordered_map<char, int> & ht, unordered_map<char, int> & hs) {
        for (auto & p : ht) {
            if (p.second > hs[p.first]) {
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int min_len = INT_MAX; // 用于记录最短长度
        string ret;            // 用于记录返回结果
        // 检查s比t短的情况
        int s_len = s.size(), t_len = t.size();
        if (s_len < t_len) {return ret;}
        // 统计
        unordered_map<char, int> s_hist, t_hist;
        int left = 0, right = 0;
        for (; right < t.size(); ++right) {
            t_hist[t[right]]++;
            s_hist[s[right]]++;
        }
        // 滑动窗口搜索
        while (left < right && right <= s_len) {
            if (_is_covered(t_hist, s_hist)) {
                // 检查并记录最小值
                if (min_len > right - left) {
                    min_len = right - left;
                    ret = s.substr(left, min_len);
                }
                // 统计减1
                s_hist[s[left]]--;
                // left右移
                ++left;
            } else {
                // 统计加1
                if (right < s_len) {s_hist[s[right]]++;}
                // right右移
                ++right;
            }
        }
        return ret;
    }
};

} // namespace q0076
