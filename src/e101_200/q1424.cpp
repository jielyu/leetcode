/*
#面试刷题# 第0108期
#Leetcode# Q1424 对角线横移II
难度：中
给定一个整数的列表nums，按照下图所示的对角线顺序(从左下到右上的对角线)返回nums的所有元素。
约束条件：
1 <= nums.length <= 10^5
1 <= nums[i].length <= 10^5
1 <= nums[i][j] <= 10^9
nums中最多有10^5个元素。

示例1:
Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]

示例2:
Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]

示例3:
Input: nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
Output: [1,4,2,5,3,8,6,9,7,10,11]

示例4:
Input: nums = [[1,2,3,4,5,6]]
Output: [1,2,3,4,5,6]
*/
#include "leetcode.h"

namespace q1424
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<vector<int>> nums {{1,2,3},{4,5,6},{7,8,9}};
        vector<int> ret {1,4,2,7,5,3,8,6,9};
        CHECK_RET(comp_vector(ret, slt.findDiagonalOrder(nums)));
    }

    {
        vector<vector<int>> nums {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
        vector<int> ret {1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16};
        CHECK_RET(comp_vector(ret, slt.findDiagonalOrder(nums)));
    }

    {
        vector<vector<int>> nums {{1,2,3},{4},{5,6,7},{8},{9,10,11}};
        vector<int> ret {1,4,2,5,3,8,6,9,7,10,11};
        CHECK_RET(comp_vector(ret, slt.findDiagonalOrder(nums)));
    }

    {
        vector<vector<int>> nums {{1,2,3,4,5,6}};
        vector<int> ret {1,2,3,4,5,6};
        CHECK_RET(comp_vector(ret, slt.findDiagonalOrder(nums)));
    }

    return true;
}

// Time Limit Exceeded
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        for (auto & row : nums) {
            if (row.size() > n) {
                n = row.size();
            }
        }
        vector<int> ret;
        ret.reserve(m*n);
        // process the up-left triangle
        int r = 0, c= 0;
        for (int i = 0; i < m-1; ++i) {
            r = i; c = 0;
            while(r>=0 && c < n) {
                if (nums[r].size() > c) {
                    ret.push_back(nums[r][c]);
                }
                --r; ++c;
            }
        }
        // process the down-right triangle
        for (int i = 0; i < n; ++i) {
            r = m-1; c = i;
            while (r>=0 && c < n) {
                if (nums[r].size() > c) {
                    ret.push_back(nums[r][c]);
                }
                --r; ++c;
            }
        }
        return ret;
    }
};
TEST(Q1424, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

// Runtime: 644 ms, faster than 71.02% 
// Memory Usage: 96.7 MB, less than 100.00% 
class Solution02 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // create map from key (i+j) to vector
        int m = nums.size(), n = 0, sum = 0;
        map<int, vector<int>> key_vector;
        for (int i = 0; i < m; ++i) {
            n = nums[i].size();
            sum += n;
            for (int j = 0; j < n; ++j) {
                key_vector[i+j].push_back(nums[i][j]);
            }
        } 
        // format results
        vector<int> ret;
        ret.reserve(sum);
        for (auto & kv : key_vector) {
            auto & v = kv.second;
            for (auto iter = v.rbegin(); iter != v.rend(); ++iter) {
                ret.push_back(*iter);
            }
        }
        return ret;
    }
};
TEST(Q1424, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}
} // namespace q1424
