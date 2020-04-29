/*
#面试刷题# 第0057期
#Leetcode# Q1352 最后K个数的乘积
难度：中
实现支持两种方法的ProductOfNumbers类：
1. add(int num)
将数字num添加到当前数字列表的后面。
2. getProduct(int k)
返回当前列表中最后k个数字的乘积。您可以假设当前列表始终至少包含k个数字。
任何时候，任何连续数字序列的乘积都将适合单个32位整数而不会溢出
约束条件：
(a) 最多进行4000次 add 和 getProduct 调用.
(b) 0 <= num <= 100
(c) 1 <= k <= 40000

例1:
Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
*/
#include "leetcode.h"

namespace q1352{

template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below
    slt.add(3);
    slt.add(0);
    slt.add(2);
    slt.add(5);
    slt.add(4);
    CHECK_RET(20 == slt.getProduct(2));
    CHECK_RET(40 == slt.getProduct(3));
    CHECK_RET(0 == slt.getProduct(4));
    slt.add(8);
    CHECK_RET(32 == slt.getProduct(2));

    // succ
    return true;
}

// Runtime: 192 ms, faster than 85.28% 
// Memory Usage: 61.3 MB, less than 100.00%
class ProductOfNumbers {
private:
    vector<int> _buff;
public:
    ProductOfNumbers() {
        _buff.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            _buff.clear();
            _buff.push_back(1);
        } else {
            _buff.push_back(_buff.back() * num);
        }
    }
    
    int getProduct(int k) {
        int len = _buff.size();
        if (k >= len) {
            return 0;
        }
        return _buff.back() / _buff[len - (k + 1)];
    }
};
TEST(Q1352, Solution) {EXPECT_TRUE(q1352::run_testcases<q1352::ProductOfNumbers>());}
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
};
