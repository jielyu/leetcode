/*
#面试刷题# 第79期
#Leetcode# Q1395 计数团队数目
难度：中
有n名士兵排成一列。 每个士兵都有一个唯一的rating值。
您必须按照以下规则组成由3名士兵组成的小组：
选择3个士兵，每个士兵的rating为（rating[i]，rating[j]，rating[k]），分别为索引（i，j，k）。
在以下情况下，团队有效：（rating [i] <rating[j] <rating[k]）
或（rating [i]>rating[j]>rating[k]）其中（0 <= i <j <k < n）。
根据条件返回您可以组队的数量。 （士兵可以是多个团队的一部分）。
约束条件：
(a) n == rating.length
(b) 1 <= n <= 200
(c) 1 <= rating[i] <= 10^5

例1:
Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 

例2:
Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.

例3:
Input: rating = [1,2,3,4]
Output: 4
*/

/*
提示：直接暴力枚举的复杂度是O(n^3)，稍微使用一点技巧的复杂度是O(n^2)
*/

#include "leetcode.h"

namespace q1395{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        vector<int> rating {2,5,3,4,1};
        CHECK_RET(3 == slt.numTeams(rating));
    }

    {
        vector<int> rating {2,1,3};
        CHECK_RET(0 == slt.numTeams(rating));
    }

    {
        vector<int> rating {1,2,3,4};
        CHECK_RET(4 == slt.numTeams(rating));
    }

    // succ
    return true;
}

// Runtime: 108 ms, faster than 59.33%
// Memory Usage: 7.7 MB, less than 100.00%
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ret = 0, n = rating.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n;  ++j) {
                for (int k=j+1; k<n; ++k) {
                    if ((rating[i] < rating[j] && rating[j] < rating[k]) 
                            || (rating[i] > rating[j] && rating[j] > rating[k])) {
                        ++ret;
                    }
                }
            }
        }
        return ret;
    }
};
TEST(Q1395, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

// Runtime: 4 ms, faster than 99.63%
// Memory Usage: 7.7 MB, less than 100.00%
class Solution02 {
public:
    int numTeams(vector<int>& rating) {
        int ret = 0, n = rating.size(), lt[2], gt[2];
        for (int i=1; i<n-1; ++i) {
            lt[0] = 0, lt[1] = 0, gt[0] = 0, gt[1] = 0;
            for (int j=0; j<n;  ++j) {
                if (rating[i] < rating[j]) {
                    ++lt[(int)(j>i)];
                } 
                if (rating[i] > rating[j]) {
                    ++gt[(int)(j>i)];
                }
            }
            ret += lt[0]*gt[1] + lt[1]*gt[0];
        }
        return ret;
    }
};
TEST(Q1395, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}
};
