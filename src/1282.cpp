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
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
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

int main() {
    vector<int> groupSizes{3,3,3,3,3,1,3};
    Solution slt;
    auto ret = slt.groupThePeople(groupSizes);
    print_vector(ret);
    return 0;
}