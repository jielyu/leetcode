#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <queue>

#include <stddef.h>
#include <cmath>

using namespace std;

#include <gflags/gflags.h>
#include <gtest/gtest.h>
#include <glog/logging.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*Utils*/
bool comp_matrix(const vector<vector<int>> & m1, const vector<vector<int>> & m2);
bool comp_string2d(const vector<vector<string>> &m1, const vector<vector<string>> &m2);
bool comp_vector(const vector<int> & v1, const vector<int> & v2);

#endif
