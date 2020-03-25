/*
#Leetcode# Q1387 按Power值对整数排序
难度：中
整数x的Power定义为使用以下步骤将x转换为1所需的步骤数：

如果x是偶数，则x = x / 2
如果x为奇数，则x = 3 * x + 1
例如，x = 3的Power是7，因为3需要7步才能变成1（3-> 10-> 5-> 16-> 8-> 4-> 2-> 1） 。

给定三个整数lo，hi和k。 如果两个或多个整数具有相同的Power值，则任务是按照Power值对区间[lo，hi]中的所有整数进行升序排序。

返回范围为[lo，hi]的第k个整数，该整数按Power值排序。

请注意，对于任何整数x（lo <= x <= hi），可以确保使用这些步骤将x转换为1，并且x的Power将适合32位有符号整数。
约束条件：
(a) 1 <= lo <= hi <= 1000
(b) 1 <= k <= hi - lo + 1

例1:
Input: lo = 12, hi = 15, k = 2
Output: 13
Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
The power of 13 is 9
The power of 14 is 17
The power of 15 is 17
The interval sorted by the power value [12,13,14,15]. For k = 2 answer is the second element which is 13.
Notice that 12 and 13 have the same power value and we sorted them in ascending order. Same for 14 and 15.

例2:
Input: lo = 1, hi = 1, k = 1
Output: 1

例3:
Input: lo = 7, hi = 11, k = 4
Output: 7
Explanation: The power array corresponding to the interval [7, 8, 9, 10, 11] is [16, 3, 19, 6, 14].
The interval sorted by power is [8, 10, 11, 7, 9].
The fourth number in the sorted array is 7.

例4:
Input: lo = 10, hi = 20, k = 5
Output: 13

例5:
Input: lo = 1, hi = 1000, k = 777
Output: 570
*/

/*
提示：关键在于构建一个仿函数，然后使用STL中的sort函数排序
*/

// Runtime: 40 ms, faster than 86.19%
// Memory Usage: 7.3 MB, less than 100.00%
class Comp {
private:
    vector<int> * _p_power;
public:
    Comp(vector<int> * p_power) {
        _p_power = p_power;
    }
    
    bool operator()(int i, int j) {
        if ((*_p_power)[i] == (*_p_power)[j]) {
            return i < j;
        }
        return (*_p_power)[i] < (*_p_power)[j];
    }
};

class Solution {
private:
    int _get_power(int x) {
        int ret = 0;
        while(x != 1) {
            ++ret;
            if (x%2 == 0) x /= 2;
            else x = 3*x + 1;
        }
        return ret;
    }
    
public:
    int getKth(int lo, int hi, int k) {
        int len = hi - lo + 1;
        // get power of all numbers
        vector<int> power(len, 0);
        for (int i = lo; i <= hi; ++i) {
            power[i-lo] = _get_power(i);
            //cout << power[i-lo] << endl;
        }
        // sort idx
        vector<int> idx(len, 0);
        std::iota(idx.begin(), idx.end(), 0);
        Comp comp(&power);
        sort(idx.begin(), idx.end(), comp);
        //for (auto & i : idx) {cout << i + lo << endl;}
        // get result
        return lo + idx[k-1];
    }
};