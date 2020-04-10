#include "leetcode.h"

void print(const string & info, bool enter) {
    cout << info;
    if (enter) {cout << endl;}
}

template<> bool comp_vector<int>(const vector<int> & v1, const vector<int> & v2);
template<> bool comp_vector<string>(const vector<string> & v1, const vector<string> & v2);

template<> 
bool comp_matrix<int>(const vector<vector<int>> & m1, const vector<vector<int>> & m2);
template<> 
bool comp_matrix<string>(const vector<vector<string>> & m1, const vector<vector<string>> & m2);
