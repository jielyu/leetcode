# 贡献说明

***可以直接将代码文件发送给本人，也可以按照一些规范提交PR***

***以“src/e001_100/q0048.cpp”的格式为例即可***

## 1. 添加新问题

### (A). 文件

如果需要添加新问题，请按照“q”+“问题编号”+“.cpp”的方式命名文件，并存放在`src/leetcode/cpp/`目录中，如果是python代码请放在`src/leetcode/python/`中。

### (B). 文件头的说明

每个文件的开头都需要指明对应Leetcode中的问题编号和题目标题，例如“Q1234 xxxx xxx xxxxx”。

### (C). 命名空间

每个文件中，除了`#include "leetcode.h"`，其他代码都需要在唯一的命名空间之下，命名空间以如下格式设置“q+问题编号”。

### (D). 测试用例函数

每个问题的命名空间下都需要实现一个模版函数如下：

```Cpp
template<typename T>
bool run_testcases() {
    T slt;
    // place testcases below

    // succ
    return true;
}
```

在注释之间添加该问题的所有测试用例

### (E). 为每个Solution添加`TEST`宏调用`run_testcases`函数

例如：

```Cpp
TEST(Q0048, Solution) {EXPECT_EQ(q0048::run_testcases<q0048::Solution>(), true);}
```

## 2. 贡献Solution

### (A). 如果需要在已有的问题下贡献Solution，请添加到对应编号的文件中，并添加`TEST`测试宏

### (B). 要求必须测试通过才能提PR

### (C). 最好提供leetcode官网评测数据

### (D). 如果原理比较复杂，最好提供合适的注释或者原理说明

## 3. 命名规范

### (A). 类名的每个单词首字母大写，其余字母小写

### (B). 属性和函数成员名的单词之间以一个下划线分隔，字母全小写

### (C). 私有成员以一个下划线开始，其他部分单词之间以下划线分割，字母全小写

### (D). 注释中的作者id前须加上@符号

## 贡献者名单

[jielyu](https://github.com/jielyu)
[extremedeckguru](https://github.com/extremedeckguru)
[yanlifang](https://github.com/yanlifang)
[zhaoyuniair](https://github.com/zhaoyuniair)
