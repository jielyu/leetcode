/*
#Leetcode# Q1390 四个除数
难度：中
给定一个整数数组nums，返回该数组中正好具有四个除数的整数的除数之和。
如果数组中没有这样的整数，则返回0。
约束条件：
(a) 1 <= nums.length <= 10^4
(b) 1 <= nums[i] <= 10^5

例1:
Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
*/

/*
提示：找到除1和本身之外的另一个除数，并且这个除数不是该数的平方根
*/

// Runtime: 28 ms, faster than 97.70%
// Memory Usage: 7.2 MB, less than 100.00%
class Solution {    
public:
    int sumFourDivisors(vector<int>& nums) {
        int ret = 0, mid_div = 0, mid_div_2 = 0;
        for (auto & n : nums) {
            // find divisors
            int d = (int)sqrt(n);
            mid_div = 0;
            for (int i = 2; i <= d; ++i) {
                if (n % i == 0) {
                    if (mid_div == 0) {
                        mid_div = i;
                    } else {  // more than 4 divisors
                        mid_div = 0;
                        break;
                    }
                }
            }
            //cout << mid_div << endl;
            // check divisor and accumulate result
            if (mid_div > 0) {
                mid_div_2 = n / mid_div;
                if (mid_div_2 != mid_div) {
                    ret += 1 + n + mid_div + mid_div_2;
                }
            }
        }
        return ret;
    }
};

// Runtime: 128 ms, faster than 45.11%
// Runtime: 128 ms, faster than 45.11%
class Solution01 {    
public:
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int, vector<int>> dict; 
        int ret = 0;
        for (auto & n : nums) {
            // compute divisors for n
            if (dict.find(n) == dict.end()) {
                int d = (int)sqrt(n);
                for (int i = 1; i <= d; ++i) {
                    if (n % i == 0) {
                        if (i == n/i) {
                            dict[n].push_back(i);
                        } else {
                            dict[n].push_back(i);
                            dict[n].push_back(n/i);
                        }
                        if (dict[n].size() > 4) {
                            break;
                        }
                    }
                }  
            } 
            // accumulate result
            if (dict[n].size() == 4) {
                for (auto & v : dict[n]) {
                    // cout << v << endl;
                    ret += v;
                }
            }
        }
        return ret;
    }
};