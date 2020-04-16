/*
#面试刷题# 第0096期
#Leetcode# Q1409 带键置换的查询
难度：中
给定1到m之间的正整数的数组queries，您必须根据以下规则处理所有queries[i]
（从i = 0到i = queries.length-1）：
(1) 开始时，您的排列P = [1,2,3，...，m]。
(2) 对于当前的i，在置换P中找到query[i]的位置（从0开始索引），然后把它移动到置换P的开始位置。
请注意，P中query[i]的位置是查询的结果。
返回一个包含给定查询结果的数组。
约束条件：
1 <= m <= 10^3
1 <= queries.length <= m
1 <= queries[i] <= m

示例1:
Input: queries = [3,1,2,1], m = 5
Output: [2,1,2,1] 
Explanation: The queries are processed as follow: 
For i=0: queries[i]=3, P=[1,2,3,4,5], position of 3 in P is 2, then we move 3 to the beginning of P resulting in P=[3,1,2,4,5]. 
For i=1: queries[i]=1, P=[3,1,2,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,3,2,4,5]. 
For i=2: queries[i]=2, P=[1,3,2,4,5], position of 2 in P is 2, then we move 2 to the beginning of P resulting in P=[2,1,3,4,5]. 
For i=3: queries[i]=1, P=[2,1,3,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,2,3,4,5]. 
Therefore, the array containing the result is [2,1,2,1]. 

示例2:
Input: queries = [4,1,2,2], m = 4
Output: [3,1,2,0]

示例3:
Input: queries = [7,5,5,8,3], m = 8
Output: [6,5,0,7,5]
*/
#include "leetcode.h"

namespace q1409{

template<typename T>
bool run_testcases() {
    T slt;
    // example 01
    {
        vector<int> queries{3,1,2,1};
        int m = 5;
        vector<int> ret{2,1,2,1};
        if (!comp_vector(slt.processQueries(queries, m), ret)) {return false;}
    }

    // example 02
    {
        vector<int> queries{4,1,2,2};
        int m = 4;
        vector<int> ret{3,1,2,0};
        if (!comp_vector(slt.processQueries(queries, m), ret)) {return false;}
    }

    // example 03
    {
        vector<int> queries{7,5,5,8,3};
        int m = 8;
        vector<int> ret{6,5,0,7,5};
        if (!comp_vector(slt.processQueries(queries, m), ret)) {return false;}
    }

    return true;
}

// Runtime: 24 ms, faster than 71.30%
// Memory Usage: 8.5 MB, less than 100.00%
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int len = queries.size();
        // prepare 
        vector<int> ret, P(m, 0);
        ret.reserve(len);
        std::iota(P.begin(), P.end(), 1);
        // run the workflow
        int idx = 0, tmp = 0;
        for (int i = 0; i < len; ++i) {
            // find element
            auto iter = std::find(P.begin(), P.end(), queries[i]);
            idx = (int)(iter - P.begin());
            //cout << i << "," << queries[i] << "," << idx << endl;
            // store result
            ret.push_back(idx);
            // move idx element to the first
            tmp = P[idx];
            while(idx > 0) {
                P[idx] = P[idx-1];
                --idx;
            }
            P[0] = tmp;
        }
        return ret;
    }
};
TEST(Q1409, Solution) {EXPECT_EQ(q1409::run_testcases<q1409::Solution>(), true);}

} // namespace q1409

