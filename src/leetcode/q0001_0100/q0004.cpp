/*
#LeetCode# Q0004 两个排序数组的中位数
难度：高
有两个大小分别为m和n的排序数组nums1和nums2。

求出两个排序数组的中位数。总的运行时间复杂度应该是O(log(m+n))。

你可以假设nums1和nums2不能都是空的。

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/
#include "leetcode.h"
namespace q0004
{

template<typename T>
bool run_testcases() {
    T slt;

    {
        vector<int> nums1{1,2,7,8,9}, nums2{3,4,5,6};
        auto ret = slt.findMedianSortedArrays(nums1, nums2);
        CHECK_RET(abs(ret-5.0) < 0.00001);
    }

    return true;
}


// Runtime: 48 ms, faster than 46.10%
// Memory Usage: 89.9 MB, less than 7.42%
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 使用一个辅助存储空间用来存储合并后的序列
        vector<int> mid;
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 == 0 && len2 == 0) {return -1.0;}
        // 合并两个序列
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (nums1[i] < nums2[j]) {
                mid.push_back(nums1[i]);
                ++i;
            } else {
                mid.push_back(nums2[j]);
                ++j;
            }
        }
        // 填充剩余部分
        while(i < len1) {
            mid.push_back(nums1[i]);
            ++i;
        }
        while(j < len2) {
            mid.push_back(nums2[j]);
            ++j;
        }
        // 计算中位数
        int len = len1 + len2;
        if (len % 2 == 0) { // 元素个数为偶数则取中间两个的均值
            return (mid[len/2] + mid[len/2-1])/2.0;
        }
        return mid[len/2];
    }
};

// Runtime: 48 ms, faster than 46.10%
// Memory Usage: 89 MB, less than 54.43%
class Solution02 {
private:
    double _find(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int start = 0, end = len1;
        int i = 0, j = 0;
        double ret = 0.0;
        // 二分法搜索nums1
        while (start <= end) {
            i = start + (end - start) / 2;
            j = (len1 + len2 + 1) / 2 - i;
            if ((i<len1) && (j>0) && (nums1[i] < nums2[j-1])) {
                start = i + 1;
            } else if ((i>0) && (j<len2) && (nums1[i-1] > nums2[j])) {
                end = i - 1;
            } else {
                if (0 == i) { // nums1全都比nums2大
                    ret = nums2[j-1];
                } else if (0 == j) { // nums1全都比nums2小
                    ret = nums1[i - 1];
                } else {
                    ret = max(nums1[i-1], nums2[j-1]);
                }
                break;
            }
        }
        if ((len1 + len2) % 2 == 1) {return ret;}
        if (i == len1) {return (ret + nums2[j]) / 2.0;}
        if (j == len2) {return (ret + nums1[i]) / 2.0;}
        return (ret + min(nums1[i], nums2[j])) / 2.0;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            return _find(nums1, nums2);
        }
        return _find(nums2, nums1);
    }
};
TEST(Q0004, Solution) {EXPECT_TRUE(run_testcases<Solution02>());}

} // namespace q0004
