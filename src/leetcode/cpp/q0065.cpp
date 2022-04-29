
/*
#LeetCode# Q0065 有效数字
难度：高
验证一个给定的字符串是否可以被解释为十进制数。

一些例子。
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3 " => true
"1e" => false
"e3" => false
"6e-1" => true
"99e2.5" => false
"53.5e93" => true
" -6 " => false
"-+3" => false
"95a54e53" => false

注意：希望问题陈述是模糊不清的。你应该在实施前收集所有的需求，然后再实施一个。但是，以下是一个有效的十进制数字中可以出现的字符列表。

数字0-9
指数 - "e"
正/负号--"+"/"-"-"
小数点 - "."
当然，在输入中，这些字符的上下文也很重要。

更新（2015-02-10）。
C++函数的签名已经更新了。如果你仍然看到你的函数签名接受了一个 const char *参数，请点击重新加载按钮重置你的代码定义。


*/
#include "leetcode.h"

namespace q0065
{

template<typename T>
bool run_testcases() {
    T slt;

    return true;
}


// Runtime: 8 ms, faster than 17.49%
// Runtime: 8 ms, faster than 17.49%
class Solution {
private:
    bool _is_digit(char c) { return c >= '0' && c <= '9';}
    
public:
    bool isNumber(string s) {
        bool e_flag = false, dot_flag = false, sign_e_flag = false, d_flag = false;
        int len = s.size(), i = 0;
        // 找到第一个有效字符
        while (i < len && s[i] == ' ') {++i;}
        // 判断第一个字符是否合法
        if ('.' == s[i]) {
            // 小数点不能是最后一个字符
            if (i >= len - 1) {return false;}
            // 设置小数点标志
            dot_flag = true;
        } else if (s[i] != '+' && s[i] != '-' && (!_is_digit(s[i])) ) {
            return false;
        } else if (_is_digit(s[i])) {
            d_flag = true;
        }
        ++i;
        // 检查接下来的数字部分
        while (i < len) {
            if (s[i] == 'e') {
                if (false == d_flag) {return false;}
                // 设置e出现的标志位
                if (e_flag == false) {
                    e_flag=true;
                } else {
                    return false;
                }
                // e之前必须为数字
                if ((!_is_digit(s[i-1])) && ('.' != s[i-1]) ) {return false;}
                // e后必须为数字
                d_flag = false;
            } else if (s[i]=='.') {
                // 设置小数点标志
                if (dot_flag == false) {
                    dot_flag = true;
                } else {
                    return false;
                }
                // e后不能出现小数点
                if (e_flag) {return false;}
            } else if (!_is_digit(s[i])) {
                if (s[i] != '+' && s[i] != '-' && s[i] != ' ') {return false;}
                
                // 不允许出现e后面出现非“+-”的非数字字符
                if (('-' == s[i] || '+'== s[i])) {
                    if ( ('e' != s[i-1]) || (sign_e_flag) ) {
                        return false;
                    }
                    sign_e_flag = true;
                }
                // 不允许中间出现空格
                if (' ' == s[i]) {
                    while (i < len && s[i] == ' ') {++i;}
                    if (i < len) {return false;}
                }
            } else {
                // 数字存在标志
                d_flag = true;
            }
            //cout << i << endl;
            ++i;
        }
        return d_flag == true;
    }
};

} // namespace q0065
