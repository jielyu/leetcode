/*

#Leetcode# Q1386 电影院座位分配
难度：中
电影院有n排座位，编号从1到n，每排有10个座位，标记为1到10，
1-2-3||4-5-6-7||8-9-10。

例如，给定包含已预留座位数的reservedSeats数组，
reservedSeats [i] = [3,8]表示位于第3行并标记为8的座位已被预留。

返回您可以在电影院座位上分配的四人家庭的最大人数。 一个四人家庭一排排四个座位，彼此相邻。 
过道上的座位（例如[3,3]和[3,4]）不被认为是相邻的，但是，
允许四口之家通过走道分开，但是 情况下，恰好两个人必须坐在过道的每一侧。
约束条件：
(a) 1 <= n <= 10^9
(b) 1 <= reservedSeats.length <= min(10*n, 10^4)
(c) reservedSeats[i].length == 2
(d) 1 <= reservedSeats[i][0] <= n
(e) 1 <= reservedSeats[i][1] <= 10
(f) 所有reservedSeats[i]都是不同的.

例1:
Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows the optimal allocation for four families, where seats mark with blue are already reserved and contiguous seats mark with orange are for one family. 

例2:
Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2

例3:
Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4
*/

/*
提示：本题最大的关键点是不能从正面考虑，否则容易超时；只能从已经被预定的位置着手。
*/

// Runtime: 256 ms, faster than 81.73%
// Memory Usage: 48.9 MB, less than 100.00%
class Solution {
    
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> seats;
        // fill reserved seats
        for (auto & s : reservedSeats) {
            seats[s[0]-1].push_back(s[1]);
        }
        // find all possible results
        int ret = n * 2;
        bool left = false, right = false, mid = false;
        for (auto & row : seats) {
            left = false, right = false, mid = false;
            // check all reserved labels
            for (auto & label : row.second) {
                if (label >= 2 && label <= 5) {left = true;}
                if (label >= 4 && label <= 7) {mid = true;}
                if (label >= 6 && label <= 9) {right = true;}
            }
            // update result
            if (left) --ret;
            if (right) --ret;
            // left and right are occupied but mid is empty
            if (left && right && !mid) ++ret;
        }
        return ret;
    }
};

// Time Limit Exceeded
class Solution03 {
    
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> seats;
        // fill reserved seats
        for (auto & s : reservedSeats) {
            seats[s[0]-1].push_back(s[1]);
        }
        // find all possible results
        int ret = 0;
        bool left = false, right = false, mid = false;
        for (int i = 0; i < n; ++i) {
            left = false, right = false, mid = false;
            // as to empty row
            if (seats.find(i) == seats.end()) {
                ret += 2;
                continue;
            }
            // check all reserved labels
            for (auto & label : seats[i]) {
                if (label >= 2 && label <= 5) {left = true;}
                if (label >= 4 && label <= 7) {mid = true;}
                if (label >= 6 && label <= 9) {right = true;}
            }
            // update result
            if (!left) ++ret;
            if (!right) ++ret;
            if (left && right && (!mid)) ++ret;
        }
        return ret;
    }
};

// Time Limit Exceeded
class Solution02 {
private:
    bool _check_four(unordered_set<int> & row, int start) {
        for (int i=0; i<4; ++i) {
            if (row.count(start+i) > 0) {
                return false;
            }
        }
        return true;
    }
    
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> seats;
        for (int i = 0; i < n; ++i) {
            seats[i+1] = unordered_set<int>();
        }
        // fill reserved seats
        for (auto & s : reservedSeats) {
            seats[s[0]].insert(s[1]);
        }
        // find all possible results
        int ret = 0;
        bool mark = true;
        for (auto & r : seats) {
            mark = true;
            // check left
            if (_check_four(r.second, 2)) {++ret; mark=false;}
            // check right
            if (_check_four(r.second, 6)) {++ret; mark=false;}
            // check middle
            if (mark&&_check_four(r.second, 4)) {++ret;}
        }
        return ret;
    }
};

// out of memory
class Solution01 {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<vector<bool>> seats(n, vector<bool>(10, true));
        // fill reserved seats
        for (auto & s : reservedSeats) {
            seats[s[0]-1][s[1]-1] = false;
        }
        // find all possible results
        int ret = 0;
        bool mark = true;
        for (auto & r : seats) {
            mark = true;
            if (r[1]&&r[2]&&r[3]&&r[4]) {++ret; mark=false;}
            if (r[5]&&r[6]&&r[7]&&r[8]) {++ret; mark=false;}
            if (mark&&r[3]&&r[4]&&r[5]&&r[6]) {++ret;}
        }
        return ret;
    }
};