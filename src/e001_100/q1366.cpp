/*
#面试刷题# 第0082期
#Leetcode# Q1366 通过投票对球队排名
难度：中
在特殊的排名系统中，每个选民对参加比赛的所有团队都按从最高到最低的顺序进行排名。
团队的顺序由谁获得最高排名第一的选票决定。 如果两个或两个以上的团队并列第一，
我们将考虑第二个位置来解决冲突；如果两个团队再度并列，我们将继续此过程，直到双方平分。 
如果在考虑所有职位后仍将两个或更多团队并列，我们将根据其团队字母的字母顺序对其进行排名。
给定一系列字符串投票，这是排名系统中所有选民的投票。 根据上述排名系统对所有团队进行排序。
返回按排名系统排序的所有团队的字符串。
约束条件：
(a) 1 <=票数。长度<= 1000
(b) 1 <=票[i]。长度<= 26
(c) 投票[i] .length ==投票[j] .length等于0 <= i，j <投票.length。
(d) 投票[i] [j]是英文大写字母。
(e) 投票[i]的所有字符都是唯一的。
(f) 出现在voices [0]中的所有字符也出现在voices [j]中，其中1 <= j <tickets.length。

示例1:
Input: votes = ["ABC","ACB","ABC","ACB","ACB"]
Output: "ACB"
Explanation: Team A was ranked first place by 5 voters. No other team was voted as first place so team A is the first team.
Team B was ranked second by 2 voters and was ranked third by 3 voters.
Team C was ranked second by 3 voters and was ranked third by 2 voters.
As most of the voters ranked C second, team C is the second team and team B is the third.

示例2:
Input: votes = ["WXYZ","XYZW"]
Output: "XWYZ"
Explanation: X is the winner due to tie-breaking rule. X has same votes as W for the first position but X has one vote as second position while W doesn't have any votes as second position. 

示例3:
Input: votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
Output: "ZMNAGUEDSJYLBOPHRQICWFXTVK"
Explanation: Only one voter so his votes are used for the ranking.

示例4:
Input: votes = ["BCA","CAB","CBA","ABC","ACB","BAC"]
Output: "ABC"
Explanation: 
Team A was ranked first by 2 voters, second by 2 voters and third by 2 voters.
Team B was ranked first by 2 voters, second by 2 voters and third by 2 voters.
Team C was ranked first by 2 voters, second by 2 voters and third by 2 voters.
There is a tie and we rank teams ascending by their IDs.

示例5:
Input: votes = ["M","M","M","M"]
Output: "M"
Explanation: Only team M in the competition so it has the first rank.
*/




// Runtime: 20 ms, faster than 76.42%
// Memory Usage: 9.1 MB, less than 100.00%
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size(), N = 26;
        vector<vector<int>> stat_vote(N, vector<int>(n, 0));
        // stat votes by scores
        for (auto & v : votes) {
            for (int i = 0; i < n; ++i) {
                ++stat_vote[v[i]-'A'][i];
            }
        }
        // sort
        string ret = votes[0];
        sort(ret.begin(), ret.end(), [&](char & i, char & j) {
            for (int k = 0;  k < n; ++k) {
                if (stat_vote[i-'A'][k] > stat_vote[j-'A'][k]) {
                    return true;
                } else if (stat_vote[i-'A'][k] < stat_vote[j-'A'][k]) {
                    return false;
                }
            }
            return i < j;
        });
        return ret;
    }
};


class Comp {
private:
    vector<char> * _candidates;
    vector<vector<int>> * _stat_votes;
    int _n;
public:
    Comp(vector<char> * candidates, vector<vector<int>> * stat_votes, int n) {
        _candidates = candidates;
        _stat_votes = stat_votes;
        _n = n;
    }
    
    bool operator()(int i, int j) {
        for (int k = 0; k < _n; ++k) {
            if ((*_stat_votes)[i][k] > (*_stat_votes)[j][k]) {
                return true;
            } else if ((*_stat_votes)[i][k] < (*_stat_votes)[j][k]) {
                return false;
            }
        }
        return (*_candidates)[i] < (*_candidates)[j];
    }
};

// Runtime: 36 ms, faster than 12.15%
// Memory Usage: 9 MB, less than 100.00%
class Solution01 {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, vector<int>> vote_dict;
        int n = votes[0].size();
        // stat votes
        for (auto & v : votes) {
            for (int i = 0; i < n; ++i) {
                auto iter = vote_dict.find(v[i]);
                if (iter == vote_dict.end()) {
                    vote_dict[v[i]] = vector(n, 0);
                    vote_dict[v[i]][i] = 1;
                } else {
                    ++vote_dict[v[i]][i];
                }
            }
        }
        // sort
        vector<char> candidates;
        vector<vector<int>> stat_votes;
        for (auto & p : vote_dict) {
            candidates.push_back(p.first);
            stat_votes.push_back(p.second);
        }
        Comp comp(&candidates, &stat_votes, n);
        vector<int> idx(n, 0);
        std::iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), comp);
        // output result
        string ret;
        for (auto i : idx) {
            ret.push_back(candidates[i]);
        }
        return ret;
    }
};