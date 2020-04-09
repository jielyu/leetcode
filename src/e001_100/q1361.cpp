/*
#面试刷题# 第0091期
#Leetcode# Q1361 验证二叉树节点
难度：中
您有n个二叉树节点，编号从0到n-1，其中节点i有两个子节点leftChild [i]和rightChild [i]，当且仅当所有给定节点完全形成一个有效的二叉树时，才返回true。
如果节点i没有左子节点，则leftChild [i]等于-1（对于右子节点）。
请注意，节点没有值，并且在此问题中我们仅使用节点号。
约束条件：
1 <= n <= 10^4
leftChild.length == rightChild.length == n
-1 <= leftChild[i], rightChild[i] <= n - 1

示例1:
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true

示例2:
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false

示例3:
Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false

示例4:
Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
Output: false
*/
#include "leetcode.h"

namespace q1361 {

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below
    // example 01
    {
        int n = 4;
        vector<int> leftChild{1,-1,3,-1};
        vector<int> rightChild{2,-1,-1,-1};
        bool ret = true;
        if (slt.validateBinaryTreeNodes(n, leftChild, rightChild)!=ret) {return false;}
    }
    // example 02
    {
        int n = 4;
        vector<int> leftChild{1,-1,3,-1};
        vector<int> rightChild{2,3,-1,-1};
        bool ret = false;
        if (slt.validateBinaryTreeNodes(n, leftChild, rightChild)!=ret) {return false;}
    }
    // example 03
    {
        int n = 2;
        vector<int> leftChild{1,0};
        vector<int> rightChild{-1,-1};
        bool ret = false;
        if (slt.validateBinaryTreeNodes(n, leftChild, rightChild)!=ret) {return false;}
    }
    // example 04
    {
        int n = 6;
        vector<int> leftChild{1,-1,-1,4,-1,-1};
        vector<int> rightChild{2,-1,-1,5,-1,-1};
        bool ret = false;
        if (slt.validateBinaryTreeNodes(n, leftChild, rightChild)!=ret) {return false;}
    }

    // succ
    return true;
}

// Runtime: 48 ms, faster than 93.89% 
// Memory Usage: 9.5 MB, less than 100.00%
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // record in degrees for all nodes
        vector<int> in_degree(n, 0);
        for (int i = 0; i < n; ++i) {
            auto & left = leftChild[i];
            auto & right = rightChild[i];
            if (-1 != left && in_degree[left]++) {return false;}
            if (-1 != right && in_degree[right]++) {return false;}
        }
        // find root node with in degree equal to zero
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] > 0) {continue;}
            if (-1 != root) {return false;} // meet two root
            root = i; // record the first root
        }
        // check root
        if (-1 == root) return false;
        if (1 == n) return true;
        return leftChild[root] >= 0 || rightChild[root] >= 0;
    }
};    
TEST(Q1361, Solution) {EXPECT_EQ(q1361::run_testcases<q1361::Solution>(), true);}

};