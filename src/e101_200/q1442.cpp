/*
#面试刷题# 第119期
#Leetcode# Q1442 能组成两个相等的XOR数组的三胞胎数组
难度：中
我们要选择三个索引i、j和k，其中（0 <= i <j <= k < arr.length）。
让我们定义a和b如下:
(1) a = arr[i] ^ arr[i + 1] ^ ..... ^ arr[j - 1] ^ arr[j - 1]
(2) b = arr[j] ^ arr[j + 1] ^ ..... ^ arr[k]
注意，^表示位互换xor操作。返回三连数(i、j和k)，其中a===b。
约束条件：
1 <= arr.length <= 300
1 <= arr[i] <= 10^8

示例1:
Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)

示例2:
Input: arr = [1,1,1,1,1]
Output: 10

示例3:
Input: arr = [2,3]
Output: 0

示例4:
Input: arr = [1,3,5,7,9]
Output: 3

示例5:
Input: arr = [7,11,12,9,5,2,7,17,22]
Output: 8
*/
#include "leetcode.h"

namespace q1442
{
template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> arr {2,3,1,6,7};
        CHECK_RET(4 == slt.countTriplets(arr));
    }
    {
        vector<int> arr {1,1,1,1,1};
        CHECK_RET(10 == slt.countTriplets(arr));
    }
    {
        vector<int> arr {2,3};
        CHECK_RET(0 == slt.countTriplets(arr));
    }
    {
        vector<int> arr {1,3,5,7,9};
        CHECK_RET(3 == slt.countTriplets(arr));
    }
    {
        vector<int> arr {7,11,12,9,5,2,7,17,22};
        CHECK_RET(8 == slt.countTriplets(arr));
    }

    return true;
}

// refer to: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/discuss/623747/JavaC%2B%2BPython-One-Pass-O(N4)-to-O(N)
// Runtime: 4 ms, faster than 95.81% 
// Memory Usage: 7.5 MB, less than 100.00%
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        arr.insert(arr.begin(), 0);
        int ret = 0, len = arr.size();
        for (int i = 1; i < len; ++i) {arr[i] ^= arr[i-1];}
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (arr[i] == arr[j]) {ret += j - i - 1;}
            }
        }
        return ret;
    }
};
TEST(Q1442, Solution) {run_testcases<Solution>();}
} // namespace q1442
