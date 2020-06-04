/*
#LeetCode# Q0006 ZigZag转换
难度：中
字符串 "PAYPALISHIRING "是在给定的行数上以人字形写成的，就像这样。(你可能想用固定的字体显示这个图案，以提高可读性)

P   A   H   N
A P L S I I G
Y   I   R
然后逐行阅读。"pahnaplsiigyir"

编写一个字符串的代码，并给定一个行数进行转换。

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/
#include "leetcode.h"

namespace q0006{

// Runtime: 72 ms, faster than 12.51%
// Memory Usage: 8.2 MB, less than 100.00%
class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if ((!size) || (numRows == 1)) {return s;}
        string str = "";
        int maxColumn = (size / (2*numRows - 2) + 1) * (numRows - 1);
        for(int r=0; r<numRows; r++){
            for(int c=0; c<maxColumn; c++){
                int cnt = c / (numRows - 1);
                int res = c % (numRows - 1);
                int index = -1;
                if(res==0) {index = 2*cnt*(numRows-1) + r;}
                else{if(r == numRows- 1 - res){index = (2*cnt+1)*(numRows-1) + res;}}
                if(index >= 0 && index < size){str.append(s.substr(index, 1));}
            }
        }
        return str;
    }
};
}