/*
面试刷题 第0001期
Leetcode Q1276 不浪费原料的汉堡数量
难度：中
给定两个整数TomatoSlices和CheeseSlices。不同汉堡的成分如下：
巨型汉堡：4个番茄片和1个奶酪片。
小汉堡：2个西红柿片和1个奶酪片。
返回[total_jumbo，total_small]，以使剩余的TomatoSlices数量等于0，并且剩余的CheeseSlices数量等于0。如果不可能使剩余的TomatoSlices和cheeseSlices等于0，则返回[]。
约束条件：
(a) 0 <= tomatoSlices <= 10^7
(b) 0 <= cheeseSlices <= 10^7

例1:
Input: tomatoSlices = 16, cheeseSlices = 7
Output: [1,6]
Explantion: To make one jumbo burger and 6 small burgers we need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 cheese. There will be no remaining ingredients.
例2:
Input: tomatoSlices = 17, cheeseSlices = 4
Output: []
Explantion: There will be no way to use all ingredients to make small and jumbo burgers.
例3:
Input: tomatoSlices = 4, cheeseSlices = 17
Output: []
Explantion: Making 1 jumbo burger there will be 16 cheese remaining and making 2 small burgers there will be 15 cheese remaining.
例4:
Input: tomatoSlices = 0, cheeseSlices = 0
Output: [0,0]
例5:
Input: tomatoSlices = 2, cheeseSlices = 1
Output: [0,1]

提示：1. 二元一次方程组；2. 非负整数解
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 8ms
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // equations
        // 4x+2y=c1 & x+y=c2
        // formatted to 4x+2y=c1 & 2x+2y=2c2
        vector<int> ret;
        int mid_val = tomatoSlices - 2*cheeseSlices;
        // check integer solver for x
        if (mid_val < 0 || mid_val % 2 == 1) {
            return ret;
        }
        int x = mid_val / 2;
        int y = cheeseSlices - x;
        // check postive for y
        if (y < 0) {
            return ret;
        }
        // return [x, y]
        ret.push_back(x);
        ret.push_back(y);
        return ret;
    }
};

int main() {
    int tomatoSlices = 2;
    int cheeseSlices = 1;
    Solution slt;
    auto ret = slt.numOfBurgers(tomatoSlices, cheeseSlices);
    for (auto & v : ret) {
        cout << v << ",";
    }
    cout << endl;
    return 0;
}
