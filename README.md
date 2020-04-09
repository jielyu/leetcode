# leetcode

to manage code solving leetcode-like problems

## Records 记录

[第001～100期](src/e001_100/README.md)

## Articles 文章

### [Q1339 分裂二叉树的最大乘积](https://mp.weixin.qq.com/s/svDYMz8ch1-L5XaFhoc54g)

### [Q1262 能被3整除的最大和](https://mp.weixin.qq.com/s/FiSLqpGMY3b134QFsYDLLw)

### [Q1288 移除被覆盖的区间](https://mp.weixin.qq.com/s/GQlvS5rk4DDQJ7JtKmKGtA)

### [Q1282 将人们按给定组的大小归为同一组](https://mp.weixin.qq.com/s/nJCNa3InsT85ER2JQD6f9Q)

### [Q1276 不浪费原料的汉堡数量](https://mp.weixin.qq.com/s/NL2Fg_le_8uQiYM6NMDNKg)

[更多文章>>>](https://cnbluegeek.github.io/archive/?tag=%E9%9D%A2%E8%AF%95%E5%88%B7%E9%A2%98)

## Dependencies 依赖

* gflags
* glog
* gtest

## Compile 编译

安装完成编译依赖之后，直接运行 `release.sh`脚本即可在 `build`目录下生成`leetcode`可执行文件。

```
bash release.sh
```

运行所有测试用例：

```
./build/leetcode
```

## Join 参与

***以“src/e001_100/q0048.cpp”的格式为例即可***

### 1. 添加新问题

#### (1). 文件

如果需要添加新问题，请按照“q”+“问题编号”+“.cpp”的方式命名文件，并存放在`src/other/`目录中，最后我会统一整理。

#### (2). 文件头的说明

每个文件的开头都需要指明对应Leetcode中的问题编号和题目标题，例如“Q1234 xxxx xxx xxxxx”。

#### (3). 命名空间

每个文件中，除了`#include "leetcode.h"`，其他代码都需要在唯一的命名空间之下，命名空间以如下格式设置“q+问题编号”。

#### (4). 测试用例函数

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

#### (5). 为每个Solution添加`TEST`宏调用`run_testcases`函数

例如：

```Cpp
TEST(Q0048, Solution) {EXPECT_EQ(q0048::run_testcases<q0048::Solution>(), true);}
```

### 2. 贡献Solution

#### (1). 如果需要在已有的问题下贡献Solution，请添加到对应编号的文件中，并添加`TEST`测试宏

#### (2). 要求必须测试通过才能提PR

#### (3). 最好提供leetcode官网评测数据

#### (4). 如果原理比较复杂，最好提供合适的注释或者原理说明

### 3. 命名规范

#### (1). 类名的每个单词首字母大写，其余字母小写

#### (2). 属性和函数成员名的单词之间以一个下划线分隔

#### (3). 私有成员以一个下划线开始，其他部分单词之间以下划线分割

#### (4). 注释中的作者id前须加上@符号

## Communicate 交流

关于“Leetcode面试刷题”或者“计算机编程”相关的讨论可以加入 ***电报群*** ：

[面试刷题Leetcode频道](https://t.me/interview_leetcode_channel)

[面试刷题Leetcode群组](https://t.me/interview_leetcode)

国内私聊可以添加本人微信：cnbluegeek

<div style="text-align:center;width:100%;"><img width="150" height="150" src="images/cnbluegeek-qr.jpeg" /></div>
