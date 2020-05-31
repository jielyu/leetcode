/*
#剑指Offer# Q01 赋值运算符函数
为所声明的类型添加赋值运算符函数
*/
#include "leetcode.h"

namespace sword_q01
{

/*
考虑以下四点：
只有返回一个引用，才能允许连续赋值
把参数上声明为引用可以避免不必要的构造函数调用
释放自己的内存，避免内存泄漏
判断是否为同一个示例，避免自身释放自己的内存造成严重问题
*/
class MyString {
public:
    MyString(char * p_data = nullptr);
    MyString(const MyString & str){/*未实现*/}
    ~MyString();

    MyString & operator=(const MyString & str) {
        if (&str == this) {return *this;}
        delete [] this->m_pdata;
        this->m_pdata = nullptr;
        this->m_pdata = new char[strlen(str.m_pdata)+1];
        strcpy(this->m_pdata, str.m_pdata);
        return *this;
    }
private:
    char* m_pdata;
};

/*
采用临时变量的好处是对于对象是异常安全的。
*/
class MyString02 {
public:
    MyString02(char * p_data = nullptr);
    MyString02(const MyString & str){/*未实现*/}
    ~MyString02();

    MyString02& operator=(const MyString02 & str) {
        if (&str != this) {
            MyString02 tmp(str);
            char * p_tmp = tmp.m_pdata;
            tmp.m_pdata = this->m_pdata;
            this->m_pdata = p_tmp;
        }
        return *this;
    }
private:
    char* m_pdata;
};
} // namespace sq01

