/*
#面试刷题# 第0107期
#Leetcode# Q1423 你可以从卡中获得的最大积分
有几张卡片排列在一排，每张卡片都有一个相关的点数。
在一个步骤中，你可以从该行的开头或结尾取一张牌。你必须拿正好k张牌。
你的分数是你所拿的牌的分数之和。
给出整数组卡片点数和整数k，返回你能得到的最大分数。
约束条件：
1 <= cardPoints.length <= 10^5
1 <= cardPoints[i] <= 10^4
1 <= k <= cardPoints.length

示例1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

示例2:
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

示例3:
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.

示例4:
Input: cardPoints = [1,1000,1], k = 1
Output: 1
Explanation: You cannot take the card in the middle. Your best score is 1. 

示例5:
Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
Output: 202
*/
#include "leetcode.h"

namespace q1423
{

template<typename T>
bool run_testcases() {
    T slt;
    {
        vector<int> cardPoints {1,2,3,4,5,6,1};
        int k = 3, ret = 12;
        CHECK_RET(ret == slt.maxScore(cardPoints, k));
    }
    
    {
        vector<int> cardPoints {2,2,2};
        int k = 2, ret = 4;
        CHECK_RET(ret == slt.maxScore(cardPoints, k));
    }

    {
        vector<int> cardPoints {9,7,7,9,7,7,9};
        int k = 7, ret = 55;
        CHECK_RET(ret == slt.maxScore(cardPoints, k));
    }

    {
        vector<int> cardPoints {1,1000,1};
        int k = 1, ret = 1;
        CHECK_RET(ret == slt.maxScore(cardPoints, k));
    }

    {
        vector<int> cardPoints {1,79,80,1,1,1,200,1};
        int k = 3, ret = 202;
        CHECK_RET(ret == slt.maxScore(cardPoints, k));
    }

    return true;
}

// Time Limit Exceeded
class Solution {
private:
    int _take_card(vector<int> & cardPoints, int low, int high, int k) {
        if ((0 == k) || (low > high)) return 0;
        if (low == high) {return cardPoints[low];}
        int left = cardPoints[low] + _take_card(cardPoints, low+1, high, k-1);
        int right = cardPoints[high] + _take_card(cardPoints, low, high-1, k-1);
        return max(left, right);
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        return _take_card(cardPoints, 0, cardPoints.size()-1, k);
    }
};
TEST(Q1423, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

// Runtime: 136 ms, faster than 95.10% 
// Memory Usage: 42.6 MB, less than 100.00%
class Solution02 {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // accumulate k points in the right
        int sum = 0, len = cardPoints.size();
        for (int i = 0; i < k; ++i) {
            sum += cardPoints[len - i - 1];
        }
        // slide window from right to left in loop
        int ret = sum;
        for (int i = 0; i < k; ++i) {
            sum += cardPoints[i] - cardPoints[len-k+i];
            if (sum > ret) {
                ret = sum;
            }
        }
        return ret;
    }
};
TEST(Q1423, Solution02) {EXPECT_TRUE(run_testcases<Solution02>());}
} // namespace q1423

