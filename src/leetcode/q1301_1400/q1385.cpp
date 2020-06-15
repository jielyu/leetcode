/*
#面试刷题# 第0072期
#Leetcode# Q1385 查找两个数组之间的距离值
难度：低
给定两个整数数组arr1和arr2，以及整数d，返回两个数组之间的距离值。
距离值被定义为元素arr1 [i]的数量，使得不存在任何元素arr2 [j]，
其中| arr1 [i] -arr2 [j] | <= d。
约束条件：
(a) 1 <= arr1.length, arr2.length <= 500
(b) -10^3 <= arr1[i], arr2[j] <= 10^3
(c) 0 <= d <= 100

例1:
Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
Output: 2
Explanation: 
For arr1[0]=4 we have: 
|4-10|=6 > d=2 
|4-9|=5 > d=2 
|4-1|=3 > d=2 
|4-8|=4 > d=2 
For arr1[1]=5 we have: 
|5-10|=5 > d=2 
|5-9|=4 > d=2 
|5-1|=4 > d=2 
|5-8|=3 > d=2
For arr1[2]=8 we have:
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2

例2:
Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
Output: 2

例3:
Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
Output: 1
*/

/*
原理说明：先计算出所有的区间上下界，然后在比较
时间复杂度：假设arr1的长度为m，arr2的长度为n，则时间复杂度为：O(mn)
*/
#include "leetcode.h"

namespace q1385{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        vector<int> arr1 {4,5,8}, arr2{10,9,1,8};
        int d = 2, ret = 2;
        CHECK_RET(ret == slt.findTheDistanceValue(arr1, arr2, d));
    }

    {
        vector<int> arr1 {1,4,2,3}, arr2{-4,-3,6,10,20,30};
        int d = 3, ret = 2;
        CHECK_RET(ret == slt.findTheDistanceValue(arr1, arr2, d));
    }

    {
        vector<int> arr1 {2,1,100,3}, arr2{-5,-2,10,-3,7};
        int d = 6, ret = 1;
        CHECK_RET(ret == slt.findTheDistanceValue(arr1, arr2, d));
    }

    // succ
    return true;
}

class Solution {
public:
    // Runtime: 16 ms, faster than 20.00%
    // Memory Usage: 8 MB, less than 100.00%
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int len_arr2 = arr2.size();
        vector<vector<int>> limits_bnd(len_arr2, {0, 0});
        // arr2 - d <= arr1 <= arr2 + d
        for (int i = 0; i < len_arr2; ++i) {
            limits_bnd[i][0] = arr2[i] - d;
            limits_bnd[i][1] = arr2[i] + d;
            //cout << limits_bnd[i][0] << "," << limits_bnd[i][1] << endl;
        }
        // check all elements in arr1
        int ret = 0, valid = true;
        for (auto & i : arr1) {
            valid = true;
            for (auto & limit : limits_bnd) {
                if (limit[0] <= i && limit[1] >= i) {
                    valid = false;
                    break;
                }
            }
            // count if valid is true
            if (valid) {
                ++ret;
                //cout << i << endl;
            }
        }
        return ret;
    }
};
TEST(Q1385, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

/*
原理说明：利用有序数组的特点，可以避免一些比较
时间复杂度：
    假设arr1的长度为m，arr2的长度为n，则时间复杂度为：O(mlog(m)+nlog(n))
*/
class Solution02 {
public:
    // Runtime: 12 ms, faster than 70.00%
    // Memory Usage: 6.9 MB, less than 100.00%
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // sort array by increasing order
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        // check all elements in arr1
        int ret = 0, idx2 = 0, len1 = arr1.size(), len2 = arr2.size();
        for (int i = 0; i < len1; ++i) {
            if ((idx2 >= len2) || (arr1[i] < arr2[idx2] - d)) {
                ++ret;
            } else if (arr1[i] > arr2[idx2] + d) {
                ++idx2;
                --i; // combinate with ++i to keep i invariable
            }
        }
        return ret;
    }
};
TEST(Q1385, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}
};