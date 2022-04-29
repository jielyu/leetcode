/*
面试刷题 第0002期
Leetcode Q1282.将人们按给定组的大小归为同一组
难度：中
有n个ID从0到n-1的人，每个人恰好属于一个组。给定长度为n的数组groupSizes告诉每个人所属的组大小，返回存在的组以及每个组包括的人的ID。
您可以按任何顺序返回任何解决方案，ID也一样。另外，可以保证至少存在一种解决方案。
约束条件：
(a) groupSizes.length == n
(b) 1 <= n <= 500
(c) 1 <= groupSizes[i] <= n

例1:
Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation: 
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
例2:
Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]
*/
#include "leetcode.h"
namespace q1282{

bool check_ret(const vector<int>& groupSizes, const vector<vector<int>> & ret) {
    for (auto & g : ret) {
        for (auto & p : g) {
            if (groupSizes[p] != g.size()) {
                return false;
            }
        }
    }
    return true;
} 

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        vector<int> groupSizes{3,3,3,3,3,1,3};
        vector<vector<int>> ret{{5},{0,1,2},{3,4,6}};
        if(!check_ret(groupSizes, slt.groupThePeople(groupSizes))) {return false;}
    }

    {
        vector<int> groupSizes{2,1,3,3,3,2};
        vector<vector<int>> ret{{1},{0,5},{2,3,4}};
        if(!check_ret(groupSizes, slt.groupThePeople(groupSizes))) {return false;}
    }

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 28 ms, faster than 55.03% 
    // Memory Usage: 11.2 MB, less than 100.00%
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> ret;  // to record all groups
        vector<int> ret_limit;    // to record limitation of groups
        bool succ = false;        // to mark if successful in inserting
        for (int i=0; i<n; ++i) {
            int s = groupSizes[i];
            int len = ret.size();
            succ = false;
            // insert current person into existing group
            for (int j=0; j<len; ++j) {
                int limit = ret_limit[j];
                // valid group
                if (s == limit && limit > ret[j].size()) {
                    ret[j].push_back(i);
                    succ = true;
                    break;
                }
            }
            // create a new group
            if (!succ) {
                vector<int> new_group;
                new_group.push_back(i);
                ret_limit.push_back(s);
                ret.push_back(new_group);
            }
        }
        return ret;
    }
};
TEST(Q1282, Solution) {EXPECT_EQ(q1282::run_testcases<q1282::Solution>(), true);}

class Solution02 {
public:
    // Runtime: 24 ms, faster than 85.14%
    // Memory Usage: 11 MB, less than 100.00%
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // build a dict mapping size to idx
        unordered_map<int, vector<int>> d;
        int len = groupSizes.size();
        for (int i = 0; i < len; ++i) {
            d[groupSizes[i]].push_back(i);
        }
        // get results
        vector<vector<int>> ret;
        vector<int> m;
        for (auto & p : d) {
            int step = p.second.size() / p.first;
            for (int j = 0; j < step; ++j) {
                m.clear();
                for (int k = j*p.first; k < (j+1)*p.first; ++k) {
                    m.push_back(p.second[k]);
                }
                ret.push_back(m);
            }
        }
        return ret;
    }
};
TEST(Q1282, Solution02) {EXPECT_EQ(q1282::run_testcases<q1282::Solution02>(), true);}

void print_vector(vector<vector<int>> & results) {
    cout << "[";
    for (auto & r : results) {
        cout << "[";
        for (auto & s : r) {
            cout << s << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

};