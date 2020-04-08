#include "leetcode.h"

bool comp_matrix(const vector<vector<int>> & m1, const vector<vector<int>> & m2) {
    if (m1.size() != m2.size() || m1[0].size() != m2[0].size()) {return false;}
    int m = m1.size(), n = m1[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (m1[i][j] != m2[i][j]) {return false;}
        }
    }
    return true;
}

bool comp_vector(const vector<int> & v1, const vector<int> & v2) {
    if (v1.size() != v2.size()) {return false;}
    int n = v1.size();
    for (int i = 0; i < n; ++i) {
        if (v1[i] != v2[i]) {return false;}
    }
    return true;
}

bool comp_string2d(const vector<vector<string>> &m1, const vector<vector<string>> &m2) {
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