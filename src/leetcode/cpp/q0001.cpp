/*
#面试刷题# 第0116期
#Leetcode# Q0001 两数之和
难度：低
给定一个整数组，返回两个数字的索引，使它们相加到一个特定的目标。
你可以假设每个输入都会有一个完全相同的解，而且你可能不会使用相同的元素两次。

示例1:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include "leetcode.h"

namespace q0001
{

template<typename T>
bool run_testcases() {
    T slt;

    vector<int> nums {2, 7, 11, 15};
    vector<int> ret {0,1};
    CHECK_RET(comp_vector(ret, slt.twoSum(nums, 9)));

    return true;
}

// Runtime: 588 ms, faster than 15.96%
// Memory Usage: 9.4 MB, less than 65.67%
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ret;
		for(int i = 0; i < nums.size()-1; ++i){
			for(int j = i+1; j != nums.size(); ++j){
				int sum = nums[i] + nums[j];
				if(sum == target){
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}
		// Rrturn an empty vector
		return ret;
    }
};
TEST(Q0001, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

// Runtime: 16 ms, faster than 56.07%
// Memory Usage: 10.4 MB, less than 16.62%
class Solution02 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_idx_dict;
        for (int i = 0; i < nums.size(); ++i) {
            val_idx_dict[nums[i]] = i;
        } 
        vector<int> ret;
        for (int i = 0;  i < nums.size(); ++i) {
            auto iter = val_idx_dict.find(target - nums[i]);
            if (val_idx_dict.end() != iter) {
                if (i == iter->second) {continue;}
                ret.push_back(i);
                ret.push_back(iter->second);
                break;
            }
        }
        return ret;
    }
};
TEST(Q0001, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}

// Runtime: 12 ms, faster than 76.39%
// Memory Usage: 10.1 MB, less than 55.86%
class Solution03 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_idx_dict;
        vector<int> ret;
        for (int i = 0;  i < nums.size(); ++i) {
            auto iter = val_idx_dict.find(target - nums[i]);
            if (val_idx_dict.end() != iter) {
                ret.push_back(iter->second);
                ret.push_back(i);
                break;
            }
            val_idx_dict[nums[i]] = i;
        }
        return ret;
    }
};
TEST(Q0001, Solution03) {EXPECT_TRUE(run_testcases<Solution03>());}
} // namespace q0001

