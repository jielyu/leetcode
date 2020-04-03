/*#面试刷题# 第0007期
#Leetcode# Q1268 搜索建议系统
难度：中
给定一个字符串数组products和一个字符串searchWord。我们希望设计一个系统，
在键入searchWord的每个字符之后，最多建议三个产品名称。
建议的产品应使用searchWord共同的前缀。
如果有三个以上具有共同前缀的乘积，则返回三个词典序最前的产品。
输入searchWord的每个字符后，返回建议产品列表的列表。
约束条件：
(a)1 <= products.length <= 1000
(b) There are no repeated elements in products.
(c) 1 <= Σ products[i].length <= 2 * 10^4
(d) All characters of products[i] are lower-case English letters.
(e) 1 <= searchWord.length <= 1000
(f) All characters of searchWord are lower-case English letters.

例1:
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
例2:
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
例3:
Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
例4:
Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// build a functor
class Comp {
    private:
    vector<string> * _p;
    public:
    // record pointer
    Comp(vector<string> * p) {
        this->_p = p;
    }
    // compare two string by indexes in buffer
    bool operator()(int a, int b) {
        return (*_p)[a] < (*_p)[b];
    }
};

class Solution {
public:
    // 56ms, faster than 70.91%
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<int> prod_idx;       // record indexes for valid products
        int search_len = searchWord.size();
        vector<vector<string>> ret; // record return results
        vector<string> first_3ret;  // record first 3 results, just for speeding up
        for (int i=0; i<search_len; ++i) {
            char search_letter = searchWord[i];
            // create idx and order lexicographically
            if (0 == i) {
                int prod_len = products.size();
                // build index 
                for (int j=0; j<prod_len; ++j) {
                    if (products[j].size() > 0 && search_letter == products[j][0]) {
                        prod_idx.push_back(j);
                    }
                }
                // sort lexicographically
                Comp comp(&products);
                sort(prod_idx.begin(), prod_idx.end(), comp);
                // get first 3 results
                first_3ret.clear();
                for (auto & k : prod_idx) {
                    first_3ret.push_back(products[k]);
                    if (first_3ret.size() == 3) {
                        break;
                    }
                }
                ret.push_back(first_3ret);
            } else { // just ignore someone not satisfied conditions
                // erase invalid indexes
                for (auto & k : prod_idx) {
                    if (k< 0 || products[k].size() < i+1 
                                 || search_letter != products[k][i]) {
                        k = -1;
                    }
                }
                // get first 3 results
                first_3ret.clear();
                for (auto & k : prod_idx) {
                    if (k>=0) {
                        first_3ret.push_back(products[k]);
                    }
                    if (first_3ret.size() == 3) {
                        break;
                    }
                }
                ret.push_back(first_3ret);
            }
        }
        return ret;
    }
};

void print_vector(vector<vector<string>> & results) {
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
    vector<string> products{"bags","baggage","banner","box","cloths"};
    string searchWord = "bags";
    Solution slt;
    print_vector(slt.suggestedProducts(products, searchWord));
    return 0;
}