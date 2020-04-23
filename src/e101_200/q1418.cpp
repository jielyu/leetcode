/*
#面试刷题# 第0104期
#Leetcode# Q1418 餐厅内的食品订单展示表格
难度：中
给出数组订单，表示顾客在餐馆中完成的订单。更具体地说，订单[i]=[customerNamei,tableNumberi,foodItemi]，
其中customerNamei是顾客的名字，tableNumberi是顾客所坐的餐桌，foodItemi是顾客所点的菜品。

返回餐厅的 "展示桌"。"显示表 "是一个表，其行项表示每桌客人点了多少个菜品。第一列是表号，
其余各列按字母顺序对应每个食物项目。第一行应该是表头，其第一列是 "表"，后面是食品项目的名称。
注意，顾客的名字不属于表格的一部分。此外，各行应按数字递增的顺序排列。
约束条件：
1 <= orders.length <= 5 * 10^4
订单[i].length ==3
1 <= customerNamei.length, foodItemi.length <= 20
customerNamei和foodItemi由小写和大写英文字母和空格字符组成。
tableNumberi是1到500之间的有效整数。

示例1:
Input: orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
Output: [["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] 
Explanation:
The displaying table looks like:
Table,Beef Burrito,Ceviche,Fried Chicken,Water
3    ,0           ,2      ,1            ,0
5    ,0           ,1      ,0            ,1
10   ,1           ,0      ,0            ,0
For the table 3: David orders "Ceviche" and "Fried Chicken", and Rous orders "Ceviche".
For the table 5: Carla orders "Water" and "Ceviche".
For the table 10: Corina orders "Beef Burrito". 

示例2:
Input: orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
Output: [["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]] 
Explanation: 
For the table 1: Adam and Brianna order "Canadian Waffles".
For the table 12: James, Ratesh and Amadeus order "Fried Chicken".

示例3:
Input: orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
Output: [["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]
*/
#include "leetcode.h"

namespace q1418 {

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

// Runtime: 240 ms, faster than 95.57%
// Memory Usage: 38.9 MB, less than 100.00%
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        // 创建词典, 使用map来保证顺序
        map<int, unordered_map<string, int>> dict;
        map<string, int> items;
        for (auto & order : orders) {
            ++dict[stoi(order[1])][order[2]];
            items[order[2]] = 1;
        }
        // 记录项目的条数
        int n_items = items.size() + 1;
        // 获取表格的标题
        vector<vector<string>> ret;
        vector<string> vec{"Table"};
        for (auto & p : items) {
            vec.push_back(p.first);
        }
        ret.push_back(vec);
        vec.clear();
        // 获取表哥的内容
        for (auto & p : dict) {
            // 获取桌号
            vec.push_back(to_string(p.first));
            // 获取各个商品的数量
            for (int i = 1; i < n_items; ++i) {
                auto iter = p.second.find(ret[0][i]);
                if (p.second.end() != iter) {
                    vec.push_back(to_string(iter->second));
                } else {
                    vec.push_back("0");
                }
            }
            ret.push_back(vec);
            vec.clear();
        }
        return ret;
    }
};
} // namespace q1418
