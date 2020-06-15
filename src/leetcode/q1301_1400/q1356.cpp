/*
#面试刷题# 第0059期
#Leetcode# Q1356 按bit位为1的位数对整数排序
难度：低
给定一个整数数组arr。您必须按其二进制表示形式中的1的数目按升序对数组中的整数进行排序，
如果两个或多个整数具有相同的1数，则必须按升序对它们进行排序。
返回排序后的数组。
约束条件：
(a) 1 <= arr.length <= 500
(b) 0 <= arr[i] <= 10^4

例1:
Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]

例2:
Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.

例3:
Input: arr = [10000,10000]
Output: [10000,10000]

例4:
Input: arr = [2,3,5,7,11,13,17,19]
Output: [2,3,5,17,7,11,13,19]

例5:
Input: arr = [10,100,1000,10000]
Output: [10,100,10000,1000]
*/
#include "leetcode.h"

namespace q1356{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    {
        vector<int> arr{0,1,2,3,4,5,6,7,8}, ret{0,1,2,4,8,3,5,6,7};
        CHECK_RET(comp_vector(ret, slt.sortByBits(arr)));
    }

    {
        vector<int> arr{1024,512,256,128,64,32,16,8,4,2,1}, ret{1,2,4,8,16,32,64,128,256,512,1024};
        CHECK_RET(comp_vector(ret, slt.sortByBits(arr)));
    }

    {
        vector<int> arr{10000,10000}, ret{10000,10000};
        CHECK_RET(comp_vector(ret, slt.sortByBits(arr)));
    }

    {
        vector<int> arr{2,3,5,7,11,13,17,19}, ret{2,3,5,17,7,11,13,19};
        CHECK_RET(comp_vector(ret, slt.sortByBits(arr)));
    }

    {
        vector<int> arr{10,100,1000,10000}, ret{10,100,10000,1000};
        CHECK_RET(comp_vector(ret, slt.sortByBits(arr)));
    }

    // succ
    return true;
}

class Comp{
private:
    const vector<int> * _num_bits_p;
    const vector<int> * _num_p;
public:
    Comp(const vector<int> * num_bits_p, const vector<int> * num_p) {
        this->_num_bits_p = num_bits_p;
        this->_num_p = num_p;
    }
    
    bool operator()(const int & i, const int & j) {
        if ((*_num_bits_p)[i] == (*_num_bits_p)[j]) {
            return (*_num_p)[i] < (*_num_p)[j];
        }
        return (*_num_bits_p)[i] < (*_num_bits_p)[j];
    }
};

class Solution {
public:
    // Runtime: 20 ms, faster than 84.71%
    // Memory Usage: 8.9 MB, less than 100.00%
    vector<int> sortByBits(vector<int>& arr) {
        // get number of bits for all elements
        vector<int> num_bits(arr.size(), 0);
        int len = arr.size();
        for (int i = 0; i < len; ++i) {
            int n = arr[i];
            while(n) {
                if (n & 0x01) {
                    ++num_bits[i];
                }
                n >>= 1;
            }
        }
        // sort
        vector<int> idx(len, 0);
        std::iota(idx.begin(), idx.end(), 0);
        Comp comp(&num_bits, &arr);
        sort(idx.begin(), idx.end(), comp);
        // get results by ordered idx
        for (auto & v : idx) {
            v = arr[v];
        }
        return idx;
    }
};
TEST(Q1356, Solution) {EXPECT_TRUE(q1356::run_testcases<q1356::Solution>());}
};