
/*
#LeetCode# Q0009 回文数字
难度：低

判断一个整数是否为回文。如果一个整数的反向读法与正向读法相同，那么这个整数就是一个回文。

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

*/
#include "leetcode.h"

namespace q0009
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

/*
思路：构建逆序数字，然后判断是否相等
*/

// Runtime: 8 ms, faster than 89.22% 
// Memory Usage: 6.2 MB, less than 100.00%
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {return false;}
        long xx = x;
        long val = 0; 
        while(xx){
            int t = xx % 10;
            xx /= 10;
            if ((0x7fffffff - t) > val * 10){val = 10 * val + t;}
            else {return false;}
        } 
        if(val == x){return true;}
        return false;
    }
};

} // namespace q0009
