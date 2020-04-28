/*
#面试刷题# 第0006期
#Leetcode# Q1286 组合迭代器
设计一个Iterator类，它具有：
1. 一个构造函数，该函数使用已排序的不同小写英文字母的字符串字符和一个数字compositionLength作为参数。
2. 函数next（），按字典顺序返回length CombineLength的下一个组合。
3. 函数hasNext（）仅当存在下一个组合时才返回True。
约束条件：
(a) 1 <= combinationLength <= characters.length <= 15
(b) 每个测试最多10^4 次函数调用
(c)保证每次调用next都是有效的

例1:
CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
*/
#include "leetcode.h"
namespace q1286{

template<typename T>
bool run_testcases() {
    T slt("abc", 2);
    // place testcases below
    if ("ab" != slt.next()) {return false;}
    if (true != slt.hasNext()) {return false;}
    if ("ac" != slt.next()) {return false;}
    if (true != slt.hasNext()) {return false;}
    if ("bc" != slt.next()) {return false;}
    if (false != slt.hasNext()) {return false;}
    // succ
    return true;
}

// 16ms
class CombinationIterator {
private:
    string _chars;
    vector<int> _idx_vec;
    int _len;
    bool _has_next;
public:
    CombinationIterator(string characters, int combinationLength) {
        this->_chars = characters;
        this->_len = combinationLength;
        for (int i=0; i< combinationLength; ++i) {
            _idx_vec.push_back(i);
        }
        this->_has_next = true;
    }
    
    string next() {
        char * buff = new char[this->_idx_vec.size() + 1]();
        const char * data = this->_chars.data();
        for (int i=0; i<this->_len; ++i) {
            buff[i] = data[this->_idx_vec[i]];
        }
        string ret = string(buff);
        delete [] buff;
        // move idx_vec to next
        this->_has_next = false;
        for (int j=this->_len-1; j>=0; --j) {
            int thresh = this->_chars.size() - (this->_len - j);
            if (this->_idx_vec[j] < thresh) {
                this->_idx_vec[j] += 1;
                this->_has_next = true;
                // reset behind idx
                for (int i=j+1; i<this->_len; ++i) {
                    this->_idx_vec[i] = this->_idx_vec[i-1] + 1;
                }
                break;
            }
        }
        return ret;
    }
    
    bool hasNext() {
        return this->_has_next;
    }
};
TEST(Q1286, Solution) {EXPECT_EQ(q1286::run_testcases<q1286::CombinationIterator>(), true);}
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

};