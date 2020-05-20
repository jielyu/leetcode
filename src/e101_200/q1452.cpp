/*
#面试刷题# 第128期
#LeetCode# Q1452 最喜欢的公司名单不是另一个名单的子集的人
难度：中
给出一个数组favoriteCompanies，其中favoriteCompanies[i]是最喜欢的公司的列表（索引从0开始）。
返回最喜欢的公司列表不是其他最喜欢的公司列表的子集的人的索引。你必须按递增的顺序返回这些指数。
约束条件：
1 <= favoriteCompanies.length <= 100
1 <= favoriteCompanies[i].length <= 500
1 <= favoriteCompanies[i][j].length <= 20
最喜欢的公司[i]中的所有字符串都是独立的。
所有喜欢的公司的列表都是独立的，也就是说，如果我们按字母顺序排序，
    那么favoriteCompanies[i] != favoriteCompanies[j]。
所有的字符串都只由小写的英文字母组成。

示例1:
Input: favoriteCompanies = [["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]
Output: [0,1,4] 
Explanation: 
Person with index=2 has favoriteCompanies[2]=["google","facebook"] which is a subset of favoriteCompanies[0]=["leetcode","google","facebook"] corresponding to the person with index 0. 
Person with index=3 has favoriteCompanies[3]=["google"] which is a subset of favoriteCompanies[0]=["leetcode","google","facebook"] and favoriteCompanies[1]=["google","microsoft"]. 
Other lists of favorite companies are not a subset of another list, therefore, the answer is [0,1,4].

示例2:
Input: favoriteCompanies = [["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]
Output: [0,1] 
Explanation: In this case favoriteCompanies[2]=["facebook","google"] is a subset of favoriteCompanies[0]=["leetcode","google","facebook"], therefore, the answer is [0,1].

示例3:
Input: favoriteCompanies = [["leetcode"],["google"],["facebook"],["amazon"]]
Output: [0,1,2,3]
*/
#include "leetcode.h"

namespace q1452
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<vector<string>> favoriteCompanies {{"leetcode","google","facebook"},
            {"google","microsoft"},{"google","facebook"},{"google"},{"amazon"}};
        vector<int> ret {0,1,4};
        CHECK_RET(comp_vector(ret, slt.peopleIndexes(favoriteCompanies)));
    }

    {
        vector<vector<string>> favoriteCompanies {{"leetcode","google","facebook"},
            {"leetcode","amazon"},{"facebook","google"}};
        vector<int> ret {0,1};
        CHECK_RET(comp_vector(ret, slt.peopleIndexes(favoriteCompanies)));
    }

    {
        vector<vector<string>> favoriteCompanies {{"leetcode"},{"google"},{"facebook"},{"amazon"}};
        vector<int> ret {0,1,2,3};
        CHECK_RET(comp_vector(ret, slt.peopleIndexes(favoriteCompanies)));
    }

    return true;
}

// https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/discuss/636363/C%2B%2B-includes
// Runtime: 672 ms, faster than 66.51%
// Memory Usage: 41.6 MB, less than 100.00%
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        // 将字符串形式转换为整型表示
        unordered_map<string, int> comp_id;
        int max_id = 0;
        vector<vector<int>> fav;
        for (int i = 0; i < favoriteCompanies.size(); ++i) {
            fav.push_back(vector<int>());
            for (int j = 0; j < favoriteCompanies[i].size(); ++j) {
                if (comp_id.find(favoriteCompanies[i][j]) == comp_id.end()) {
                    comp_id[favoriteCompanies[i][j]] = max_id;
                    ++max_id;
                }
                fav[i].push_back(comp_id[favoriteCompanies[i][j]]);
                //cout << fav[i][j] << ", ";
            }
            //cout << endl;
        }
        for (auto & comps : fav) {sort(comps.begin(), comps.end());}
        // 暴力枚举
        int len = fav.size();
        vector<int> ret;
        bool valid = true;
        for (int i = 0; i < len; ++i) {
            valid = true;
            for (int j = 0; j < len; ++j) {
                if (i == j) {continue;}
                if (includes(fav[j].begin(), fav[j].end(), 
                                 fav[i].begin(), fav[i].end())) {
                    valid = false;
                    break;
                }
            }
            if (valid) {ret.push_back(i);}
        }
        // 结果排序
        sort(ret.begin(), ret.end());
        return ret;
    }
};  
TEST(Q1452, Solution) {EXPECT_TRUE(run_testcases<Solution>());}  
} // namespace q1452
