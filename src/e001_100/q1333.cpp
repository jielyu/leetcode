/*
#面试刷题# 第0019期
#Leetcode# Q1333 按价格和距离筛选素食餐厅
给定数组中的餐厅，其中restaurant [i] = [idi，ratingi，veganFriendlyi，pricei，distancei]。您必须使用三个过滤器过滤餐馆。
veganFriendly过滤器将为true（意味着您应该只包括veganFriendlyi设置为true的餐馆）或false（意味着您可以包括任何餐馆）。此外，您还有过滤器maxPrice和maxDistance，它们是分别应考虑的餐厅价格和距离的最大值。
过滤后返回饭店ID的数组，并按从高到低的等级排序。对于具有相同评分的餐厅，请按ID从高到低的顺序排序。为简单起见，当veganFriendlyi和veganFriendly为true时，取值为1；为false时，取值为0。
约束条件：
(a) 1 <= restaurants.length <= 10^4
(b) restaurants[i].length == 5
(c) 1 <= idi, ratingi, pricei, distancei <= 10^5
(d) 1 <= maxPrice, maxDistance <= 10^5
(e) veganFriendlyi 和 veganFriendly 是 0 or 1.
(f) 所有的 idi都是不相同的

例1:
Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 1, maxPrice = 50, maxDistance = 10
Output: [3,1,5] 
Explanation: 
The restaurants are:
Restaurant 1 [id=1, rating=4, veganFriendly=1, price=40, distance=10]
Restaurant 2 [id=2, rating=8, veganFriendly=0, price=50, distance=5]
Restaurant 3 [id=3, rating=8, veganFriendly=1, price=30, distance=4]
Restaurant 4 [id=4, rating=10, veganFriendly=0, price=10, distance=3]
Restaurant 5 [id=5, rating=1, veganFriendly=1, price=15, distance=1] 
After filter restaurants with veganFriendly = 1, maxPrice = 50 and maxDistance = 10 we have restaurant 3, restaurant 1 and restaurant 5 (ordered by rating from highest to lowest). 

例2:
Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 50, maxDistance = 10
Output: [4,3,2,1,5]
Explanation: The restaurants are the same as in example 1, but in this case the filter veganFriendly = 0, therefore all restaurants are considered.

例3:
Input: restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 30, maxDistance = 3
Output: [4,5]
*/
#include "leetcode.h"

namespace q1333{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        vector<vector<int>> restaurants {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
        int veganFriendly = 1, maxPrice = 50, maxDistance = 10;
        vector<int> ret{3,1,5};
        if (!comp_vector(ret, slt.filterRestaurants(
                restaurants, veganFriendly, maxPrice, maxDistance))) {return false;}
    }

    {
        vector<vector<int>> restaurants {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
        int veganFriendly = 0, maxPrice = 50, maxDistance = 10;
        vector<int> ret{4,3,2,1,5};
        if (!comp_vector(ret, slt.filterRestaurants(
                restaurants, veganFriendly, maxPrice, maxDistance))) {return false;}
    }

    {
        vector<vector<int>> restaurants {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
        int veganFriendly = 0, maxPrice = 30, maxDistance = 3;
        vector<int> ret{4,5};
        if (!comp_vector(ret, slt.filterRestaurants(
                restaurants, veganFriendly, maxPrice, maxDistance))) {return false;}
    }

    // succ
    return true;
}

class Comp {
private:
    vector<vector<int>> * _restaurants;
public:
    Comp(vector<vector<int>> * restaurants) {
        this->_restaurants = restaurants;
    }
    
    bool operator()(int i, int j) {
        if ((*_restaurants)[i][1] == (*_restaurants)[j][1]) {
            return (*_restaurants)[i][0] >= (*_restaurants)[j][0];
        }
        return (*_restaurants)[i][1] >= (*_restaurants)[j][1];
    }
};

class Solution {
public:
    // Runtime: 92 ms, faster than 65.25% 
    // Memory Usage: 20.5 MB, less than 100.00%
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        // accept idx
        vector<int> idx_vec;
        int len = restaurants.size();
        for (int i=0; i<len; ++i) {
            if (veganFriendly > 0 && restaurants[i][2] <= 0) {
                continue;
            }
            if (restaurants[i][3] > maxPrice) {
                continue;
            }
            if (restaurants[i][4] > maxDistance) {
                continue;
            }
            idx_vec.push_back(i);
        }
        // sort idx
        Comp comp(&restaurants);
        sort(idx_vec.begin(), idx_vec.end(), comp);
        // get results
        vector<int> ret;
        for (auto & idx : idx_vec) {
            ret.push_back(restaurants[idx][0]);
        }
        return ret;
    }
};
TEST(Q1333, Solution) {EXPECT_EQ(q1333::run_testcases<q1333::Solution>(), true);}
};