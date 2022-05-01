
/*
#剑指Offer# Q34 丑数
我们把只包含因子2，3，5的数称为丑数。求按照从小达到的顺序的第1500个丑数。
习惯上把1当作第一个丑数。

*/
#include "leetcode.h"

namespace sword_q34
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}

class Solution {
public:
    int getUglyNumber(int index) {
        vector<int> tab(index, 0);
        tab[0] = 1;
        int next_idx = 1;
        int T2 = 0, T3 = 0, T5 = 0;
        while (next_idx < index) {
            int min_ugly = min(min(tab[T2]*2, tab[T3]*3), tab[T5]*5);
            tab[next_idx] = min_ugly;
            while (tab[T2]*2 <= tab[next_idx]) {++T2;}
            while (tab[T3]*3 <= tab[next_idx]) {++T3;}
            while (tab[T5]*5 <= tab[next_idx]) {++T5;}
            ++next_idx; 
        }
        return tab[next_idx-1];
    }
};

} // namespace sword_q34
