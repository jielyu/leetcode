#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <queue>
#include <regex>

#include <stddef.h>
#include <limits>
#include <cmath>

using namespace std;

#include <gflags/gflags.h>
#include <gtest/gtest.h>
#include <glog/logging.h>

#define CHECK_RET(cond) if (!(cond)) {return false;}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 先序遍历
void get_preorder(TreeNode * root, vector<int> & preorder);
// 中序遍历
void get_inorder(TreeNode * root, vector<int> & inorder);
// 释放内存
void delete_tree(TreeNode * root);

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode * create_list(vector<int> & arr);
vector<int> list2vector(ListNode* head);
void delete_list(ListNode * head);

/*Utils*/
void print(const string & info, bool enter=true);

template<typename T>
bool comp_vector(const vector<T> & v1, const vector<T> & v2) {
    if (v1.size() != v2.size()) {return false;}
    int n = v1.size();
    for (int i = 0; i < n; ++i) {
        if (v1[i] != v2[i]) {return false;}
    }
    return true;
}

template<typename T>
bool comp_matrix(const vector<vector<T>> & m1, const vector<vector<T>> & m2) {
    if (m1.size() != m2.size()) {return false;}
    int m = m1.size();
    for (int i = 0; i < m; ++i) {
        if (m1[i].size() != m2[i].size()) {return false;}
        int n = m1[i].size();
        for (int j = 0; j < n; ++j){
            if (m1[i][j] != m2[i][j]) {return false;}
        }
    }
    return true;
}

#endif
