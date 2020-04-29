/*
#面试刷题# Q0105期
#Leetcode# Q1419 蛙的最小数量
难度：中
给定字符串 croakOfFrogs，表示不同青蛙的字符串 "呱呱 "的组合，即多个青蛙可以同时呱呱叫，
所以多个 "呱呱 "混合在一起。返回不同青蛙的最小数量，以完成给定字符串中所有的 "呱呱"。

一个有效的 "croak "表示青蛙依次打印出5个字母'c'、'r'、'o'、'a'、'k'。
青蛙必须将所有5个字母都打印出来才能完成一个 "croak"。
如果给出的字符串不是有效的 "croak "组合，则返回-1。

约束条件：
1 <= croakOfFrogs.length <= 10^5
字符串中的所有字符都是：'c'、'r'、'o'、'a'或'k'。'c'、'r'、'o'、'a'或'k'。

示例1:
Input: croakOfFrogs = "croakcroak"
Output: 1 
Explanation: One frog yelling "croak" twice.

示例2:
Input: croakOfFrogs = "crcoakroak"
Output: 2 
Explanation: The minimum number of frogs is two. 
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".

示例3:
Input: croakOfFrogs = "croakcrook"
Output: -1
Explanation: The given string is an invalid combination of "croak" from different frogs.

示例4:
Input: croakOfFrogs = "croakcroa"
Output: -1
*/
#include "leetcode.h"

namespace q1419 {

template<typename T>
bool run_testcases() {
    T slt;

    CHECK_RET(1 == slt.minNumberOfFrogs("croakcroak"));
    CHECK_RET(2 == slt.minNumberOfFrogs("crcoakroak"));
    CHECK_RET(-1 == slt.minNumberOfFrogs("croakcrook"));
    CHECK_RET(-1 == slt.minNumberOfFrogs("croakcroa"));

    return true;
}

// Runtime: 48 ms, faster than 94.98%
// Memory Usage: 9.3 MB, less than 100.00% 
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        const int NUM = 5;
        int croak[NUM] = {0}, used = 0, ret = 0;
        for (auto & c : croakOfFrogs) {
            // 统计字符出现的次数和单词不完整出现的次数
            switch(c) {
                case 'c': ++croak[0]; ++used;break;
                case 'r': ++croak[1];break;
                case 'o': ++croak[2];break;
                case 'a': ++croak[3];break;
                case 'k': ++croak[4]; --used;break;
                default: return -1;
            }
            // 记录最大的使用次数
            if (used > ret) { ret = used;}
            // 出现错序
            for (int i = 1; i < NUM; ++i) {
                if (croak[i-1] < croak[i]) {return -1;}
            }
        }
        // 使用的次数没有归零
        if (used) {return -1;}
        // 检查每个字母出现的次数
        for (int i = 1; i < NUM; ++i) {
            if (croak[i-1] != croak[i]) {return -1;}
        }
        return ret;
    }
};
TEST(Q1419, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

class Solution2 {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();
        if (n % 5 != 0) return -1;
        // count[i] => the number of frogs waiting to print (i + 1)-th letter
        // waiting : the numebr of frogs waiting to complete croaking
        // once count[i] < 0 we can have an early exit, meaning the rule must has been broken
        int count[4] = {0};
        int waiting = 0;
        int ans = 0;
        for (auto ch : croakOfFrogs)
        {
            if (ch != 'c' && ch != 'r' && ch != 'o' && ch != 'a' && ch != 'k') return -1;
            if (ch == 'c') { count[0] ++; waiting ++; ans = max(ans, waiting);}
            if (ch == 'r') { count[0] --; count[1] ++; if (count[0] < 0) return -1; }
            if (ch == 'o') { count[1] --; count[2] ++; if (count[1] < 0) return -1; }
            if (ch == 'a') { count[2] --; count[3] ++; if (count[2] < 0) return -1; }
            
            if (ch == 'k') 
            { 
                count[3] --; 
                if (count[3] < 0) return -1;
                waiting --;
            }
        }
        return ans;
    }
};
TEST(Q1419, Solution2) {EXPECT_TRUE(run_testcases<Solution2>());}
} // namespace q1419
