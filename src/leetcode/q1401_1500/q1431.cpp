/*
#面试刷题# 第109期
#Leetcode# Q1431 糖果数量最多的孩子
难度：低
给出数组candies和整数extraCandies，其中candies[i]表示第i个孩子拥有的糖果数量。
对于每个孩子，检查是否有办法在孩子们之间分配extraCandies，
使他或她能得到最大数量的糖果。
请注意，多个孩子可以拥有最大的糖果数量。
约束条件：
2 <= candies.length <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50

示例1:
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: 
Kid 1 has 2 candies and if he or she receives all extra candies (3) will have 5 candies --- the greatest number of candies among the kids. 
Kid 2 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids. 
Kid 3 has 5 candies and this is already the greatest number of candies among the kids. 
Kid 4 has 1 candy and even if he or she receives all extra candies will only have 4 candies. 
Kid 5 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids. 

示例2:
Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy, therefore only kid 1 will have the greatest number of candies among the kids regardless of who takes the extra candy.

示例3:
Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
*/
#include "leetcode.h"

namespace q1431
{
template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> candies {2,3,5,1,3};
        int extraCandies = 3;
        vector<bool> ret {true,true,true,false,true};
        CHECK_RET(comp_vector(ret, slt.kidsWithCandies(candies, extraCandies)));
    }

    {
        vector<int> candies {4,2,1,1,2};
        int extraCandies = 1;
        vector<bool> ret {true,false,false,false,false};
        CHECK_RET(comp_vector(ret, slt.kidsWithCandies(candies, extraCandies)));
    }

    {
        vector<int> candies {12,1,12};
        int extraCandies = 10;
        vector<bool> ret {true,false,true};
        CHECK_RET(comp_vector(ret, slt.kidsWithCandies(candies, extraCandies)));
    }

    return true;
}

// Runtime: 8 ms, faster than 25.00%
// Memory Usage: 9.2 MB, less than 100.00% 
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_val = 0, len = candies.size();
        for (auto & c : candies) {
            if (c > max_val) {
                max_val = c;
            }
        }
        vector<bool> ret(len, false);
        for (int i = 0; i < len; ++i) {
            if (candies[i] + extraCandies >= max_val) {
                ret[i] = true;
            }
        }
        return ret;
    }
};
TEST(Q1431, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

// Runtime: 8 ms, faster than 25.00%
// Memory Usage: 9 MB, less than 100.00%
class Solution02 {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_val = *max_element(candies.begin(), candies.end());
        int len = candies.size();
        vector<bool> ret(len, false);
        for (int i = 0; i < len; ++i) {
            if (candies[i] + extraCandies >= max_val) {
                ret[i] = true;
            }
        }
        return ret;
    }
};
TEST(Q1431, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}
    
 
//Runtime: 4 ms 
//Memory Usage: 9 MB
class Solution03 {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int sizeOfArray = candies.size();
        
        vector<bool> results(sizeOfArray);
        int max = 0; 
        for(int i = 0; i < sizeOfArray; i++)
        {
            results.at(i) = true;
            max = candies.at(i) + extraCandies;
            for(int j = 0; j < sizeOfArray; j++)
            {
                if(candies.at(j) > max)
                {
                    results[i] = false;
                    break;
                }
            }
        }
        
        return results;
    }
};
TEST(Q1431, Solution03) {EXPECT_TRUE(run_testcases<Solution03>());}
} // namespace q1431

