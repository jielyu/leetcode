/*
#面试刷题# 第0003期
#Leetcode# Q1275 寻找井字游戏中的获胜者
井字游戏由两名玩家A和B在3 x 3的网格上进行。
这是井字游戏的规则：
1. 玩家轮流将字符放置在空的正方形(" ")中。
2. 第一个玩家A总是放置“X”字符，而第二个玩家总是放置“O”字符；
3. “X”和“O”字符始终放置在空的正方形中，绝不能放在已填充的正方形中。
4. 当有3个相同（非空）字符填充任何行、列或者对角线时，游戏结束。
5. 如果所有方块都不为空，则游戏也会结束。
6. 如果游戏结束，将无法再进行任何移动。
给定一个数组moves，其中每个元素是大小为2的另一数组， 对应于网络中的行和列，
他们在其中按A和B的操作顺序标记各自的字符。
如果游戏赢家（A或者B）存在，则返回该游戏的赢家；
如果游戏以平局结束，则返回“Draw”；
如果仍有空的正方形则返回“Pending”。
您可以假定移动是有效的，遵守井字游戏的规则，网格最初是空的，A将首先操作。
约束条件：
(a) 1 <= moves.length <= 9
(b) moves[i].length == 2
(c) 0 <= moves[i][j] <= 2
(d) There are no repeated elements on moves.
(e) moves follow the rules of tic tac toe.

例1:
Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: "A" wins, he always plays first.
"X  "    "X  "    "X  "    "X  "    "X  "
"   " -> "   " -> " X " -> " X " -> " X "
"   "    "O  "    "O  "    "OO "    "OOX"
例2:
Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: "B" wins.
"X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
"   " -> " O " -> " O " -> " O " -> "XO " -> "XO " 
"   "    "   "    "   "    "   "    "   "    "O  "
例3:
Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.
"XXO"
"OOX"
"XOX"
例4:
Input: moves = [[0,0],[1,1]]
Output: "Pending"
Explanation: The game has not finished yet.
"X  "
" O "
"   "
*/
#include "leetcode.h"

namespace q1275{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below
    // example 01
    {
        vector<vector<int>> moves{{0,0},{2,0},{1,1},{2,1},{2,2}};
        string ret = "A";
        if (slt.tictactoe(moves) != ret) {return false;}
    }
    // example 02
    {
        vector<vector<int>> moves{{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
        string ret = "B";
        if (slt.tictactoe(moves) != ret) {return false;}
    }
    // example 03
    {
        vector<vector<int>> moves{{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};
        string ret = "Draw";
        if (slt.tictactoe(moves) != ret) {return false;}
    }
    // example 04
    {
        vector<vector<int>> moves{{0,0},{1,1}};
        string ret = "Pending";
        if (slt.tictactoe(moves) != ret) {return false;}
    }

    // succ
    return true;
}

class Solution {
public:
    // 4ms
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> tab{0,0,0,0,0,0,0,0,0};
        int player = -1;
        for (auto & vec : moves) {
            tab[vec[0] * 3 + vec[1]] = player;
            player *= -1;
        }
        // check row
        int sum = 0;
        for (int i=0; i<3; ++i) {
            sum = 0;
            for (int j=0; j<3; ++j) {
                sum += tab[i*3+j];
            }
            if (-3 == sum) {
                return string("A");
            } else if (3 == sum) {
                return string("B");
            }
        }
        // check col
        for (int j=0; j<3; ++j) {
            sum = 0;
            for (int i=0; i<3; ++i) {
                sum += tab[i*3+j];
            }
            if (-3 == sum) {
                return string("A");
            } else if (3 == sum) {
                return string("B");
            }
        }
        // check diagonal
        sum = tab[0] + tab[4] + tab[8];
        if (-3 == sum) {
            return string("A");
        } else if (3 == sum) {
            return string("B");
        }
        sum = tab[2] + tab[4] + tab[6];
        if (-3 == sum) {
            return string("A");
        } else if (3 == sum) {
            return string("B");
        }
        // check empty
        for (int k=0; k<9; ++k) {
            if (tab[k]==0) {
                return string("Pending");
            }
        }
        
        // a draw
        return string("Draw");
    }
};
TEST(Q1275, Solution) {EXPECT_EQ(q1275::run_testcases<q1275::Solution>(), true);}

};