/*
#面试刷题# 第65期
#Leetcode# Q1380 矩阵中的幸运数字
难度：低
给定一个m * n个不同数字的matrix，以任意顺序返回矩阵中的所有幸运数字。
幸运数字是矩阵的一个元素，因此它是行中的最小元素，列中的最大元素。
约束条件：
(a) m == mat.length
(b) n == mat[i].length
(c) 1 <= n, m <= 50
(d) 1 <= matrix[i][j] <= 10^5.
(e) 矩阵中的所有元素都是不相同的

例1:
Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column

例2:
Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

例3:
Input: matrix = [[7,8],[1,2]]
Output: [7]
*/
#include "leetcode.h"

namespace q1380{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}

class Solution {
public:
    
    /* generally forward idea
       find the candidate in the row and verify it in the column
       
       complexity: O(m(m+n)) = O(mn+m^2)
       Runtime: 24 ms, faster than 89.59%
       Memory Usage: 9.3 MB, less than 100.00% 
    */
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ret;
        int lucky_num = 0, col_idx = 0, i = 0, j = 0;
        for (auto & r : matrix) {
            // find max number in the row
            // lucky_num > 10^5 is OK
            lucky_num = 2100000000;
            for (j = 0; j < n; ++j) {
                if (lucky_num > r[j]) {
                    lucky_num = r[j];
                    // record the corresponding column index
                    col_idx = j;
                }
            }
            // verify the lucky number in the column
            // condition: 1 <= lucky_num <= 10^5
            for (i = 0; i < m; ++i) {
                if (matrix[i][col_idx] > lucky_num) {
                    // mark false lucky number
                    lucky_num = 0;
                    break;
                }
            }
            // check lucky number
            if (lucky_num > 0) {
                ret.push_back(lucky_num);
            }
        }
        return ret;
    }
};

};
