/*
#面试刷题# 第112期
#Leetcode# Q1436 目的地城市
难度：低
你得到了数组路径，其中paths[i]=[cityAi, cityBi]表示存在一条从cityAi到cityBi的直接路径。
返回目的地城市，即没有任何路径输出到另一个城市的城市。
可以保证路径图形成一条没有任何循环的直线，因此正好有一个目的地城市。
约束条件：
1 <= paths.length <= 100
paths[i].length ==2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
所有字符串都由小写和大写英文字母和空格字符组成。

示例1:
Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".

示例2:
Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".

示例3:
Input: paths = [["A","Z"]]
Output: "Z"
*/
#include "leetcode.h"

namespace q1436
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<vector<string>> paths {{"London","New York"},
                                     {"New York","Lima"},
                                     {"Lima","Sao Paulo"}};
        CHECK_RET("Sao Paulo"  == slt.destCity(paths));
    }

    {
        vector<vector<string>> paths {{"B","C"},{"D","B"},{"C","A"}};
        CHECK_RET("A"  == slt.destCity(paths));
    }

    {
        vector<vector<string>> paths {{"A","Z"}};
        CHECK_RET("Z"  == slt.destCity(paths));
    }
    
    return true;
}

// Runtime: 40 ms, faster than 25.00% 
// Memory Usage: 11.4 MB, less than 100.00%
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> out_nodes, in_nodes;
        for (auto & v : paths) {
            out_nodes.insert(v[0]);
            in_nodes.insert(v[1]);
        }
        for (auto & s : in_nodes) {if (out_nodes.count(s) <= 0) {return s;}}
        return "";
    }
};
TEST(Q1436, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

// Runtime: 44 ms, faster than 25.00%
// Memory Usage: 10.7 MB, less than 100.00% 
class Solution02 {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> out_nodes;
        for (auto & v : paths) {out_nodes.insert(v[0]);}
        for (auto & v : paths) {if (out_nodes.count(v[1]) <= 0) {return v[1];}}
        return "";
    }
}; 
TEST(Q1436, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}
} // namespace q1436
