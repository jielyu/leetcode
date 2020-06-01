/*
#经典算法问题# 排序
本文件用于收集经典的排序算法
*/
#include "leetcode.h"

namespace quick_sort
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> arr {6,3,5,4,2,1}, ret{1,2,3,4,5,6};
        slt.quick_sort(arr, 0, arr.size()-1);
        CHECK_RET(comp_vector(ret, arr));
    }

    return true;
}

class Solution {
public:
    int partition(vector<int> & arr, int low, int high) {
        int pivot = arr[low];
        while (low < high) {
            while (low < high && arr[high] > pivot) {--high;}
            arr[low] = arr[high];
            while (low < high && arr[low] < pivot) {++low;}
            arr[high] = arr[low];
        }
        arr[low] = pivot;
        return low;
    }

    void quick_sort(vector<int> & arr, int low, int high) {
        if (low < high) {
            int idx = partition(arr, low, arr.size() - 1);
            quick_sort(arr, low, idx-1);
            quick_sort(arr, idx+1, arr.size() - 1);
        }
    }
};
TEST(QuickSort, Solution) {EXPECT_TRUE(run_testcases<Solution>());}
} // namespace quick_sort

