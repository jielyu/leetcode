/*
#剑指Offer# Q12 打印1到最大的n位数

*/
#include "leetcode.h"

namespace sword_q12
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<string> ret {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
        CHECK_RET(comp_vector(ret, slt.printNumber(1)))
    }

    return true;
}

class Solution {
    bool _increase(string & num) {
        int len = num.size(), inc = 0;
        for (int i = len - 1; i >= 0; --i) {
            int num_bit = num[i] - '0' + inc;
            if (len - 1 == i) {++num_bit;}
            if (num_bit >= 10) {
                if (0 == i) {return false;}
                num_bit -= 10;
                inc = 1;
                num[i] = num_bit + '0';
            } else {
                num[i] = num_bit + '0';
            }
        }
        return true;
    }

    void _print(string & num, vector<string> & ret) {
        int len = num.size(), idx = 0;
        while (idx < len ) {
            if (num[idx] != '0') break;
        }
        ret.push_back(num.substr(idx, len - idx));
    }

public:
    vector<string> printNumber(int n) {
        vector<string> ret;
        if (n <= 0) {return ret;}

        string num(n, '0');
        while (_increase(num)) {_print(num, ret);}
        return ret;
    }

};

TEST(SwordQ12, Solution) {EXPECT_TRUE(run_testcases<Solution>());}

} // namespace sword_q12
