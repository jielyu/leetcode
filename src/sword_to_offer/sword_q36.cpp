
/*
#剑指Offer# Q36 数组中的逆序对
在一个数组中如果两个数字前一个大于后一个，则称这两个数字构成一个逆序对，求出这个数组中逆序对的总数。

*/
#include "leetcode.h"

namespace sword_q36
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> arr {7,5,6,4};
        cout << slt.countInversePairs(arr) << endl;
        // CHECK_RET(5 == slt.countInversePairs(arr));
    }

    return true;
}

class Solution {
private:
    int _inversePairs(vector<int> & arr, vector<int> & copy, int start, int end) {
        if (start == end) {
            copy[start] = arr[start];
            return 0;
        }
        int len = (end-start)/2;
        int left = _inversePairs(arr, copy, start, start+len);
        int right = _inversePairs(arr, copy, start+len+1, end);
        // 合并两个子数组，并保证顺序
        int left_idx = start + len, right_idx = end, count = 0, copy_idx = end;
        while (left_idx >= start && right_idx >= start+len + 1) {
            //cout << "while:" << start << "," << end << "," <<  right_idx << "," << start + len << endl;
            if (copy[left_idx] > copy[right_idx]) {
                // 遇到逆序对，则排序
                copy[copy_idx--] = arr[left_idx--];
                count += (right_idx - (start + len));
            } else {
                copy[copy_idx--] = arr[right_idx--];
            }
        }
        for (; left_idx >= start; --left_idx) {copy[copy_idx--] = arr[left_idx];}
        for (; right_idx >= start + len + 1; --right_idx) {copy[copy_idx--] = arr[right_idx];}
        return left + right + count;
    }
public:
    int countInversePairs(vector<int> & arr) {
        int len = arr.size();
        vector<int> copy(arr);
        return _inversePairs(arr, copy, 0, len - 1);
    }
};
TEST(SwordQ36, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q36
