
/*
#剑指Offer# Q14 调整数组的顺序使得奇数位于偶数前面
输入一个整数数组，编写一个函数来调整这个数组中元素的顺序，使得所有奇数都在前半段，所有偶数都在后半段

*/
#include "leetcode.h"

namespace sword_q14
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> arr{1,2,3,4,5}, ret{1,3,5,2,4};
        arr = slt.recordOddFirst(arr);
        int idx = 0;
        for (;idx < arr.size(); ++idx) {if (arr[idx]%2==0){break;}}
        for (;idx < arr.size();++idx) {if (arr[idx]%2==1){return false;}}
    }

    return true;
}

class Solution {
public:
    vector<int> recordOddFirst(vector<int> & arr){
        int len = arr.size();
        if (len == 0) return arr;
        int low = 0, high = len - 1;
        while (low < high) {
            while (low < high && arr[low] % 2 == 1) {++low;}
            while (low < high && arr[high] % 2 == 0) {--high;}
            if (low < high) {
                int tmp = arr[low];
                arr[low] = arr[high];
                arr[high] = tmp;
            }
        }
        return arr;
    }
};
TEST(SwordQ14, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace sword_q14
