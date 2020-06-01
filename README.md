# leetcode

Collect leetcode-like problems and solutions dedicated to improving algorithm design.

【译】收集leetcode类型的问题和解决方案，致力于提高算法设计的能力。

***对本项目感兴趣的朋友，麻烦加个star以示鼓励。***

仓库收录的所有问题，请查看：[收录列表](src/README.md)

## Articles 文章

### (1) 经典算法思想

[经典算法思想之回溯法 Q1415](https://mp.weixin.qq.com/s/4nbyiJ8foXIkgj3n0ccorQ)

### (2) 基础算法

[深度优先搜索DFS Q1376](https://mp.weixin.qq.com/s/7VwPNVWNPJmPQgzSl0xQYA)

[广度优先搜索 BFS Q102 Q1311](https://mp.weixin.qq.com/s/MwACh4_Ahjamwpf6stxSmw)

### (3) 动态规划

[积分图加速矩阵块求和 Q1314](https://mp.weixin.qq.com/s/tehqEiBslkFUdarZ5vVO1w)

[能被3整除的最大和 Q1262](https://mp.weixin.qq.com/s/FiSLqpGMY3b134QFsYDLLw)

### (4) 数学方法

[钟针之间的角度 Q1344](https://mp.weixin.qq.com/s/vJ2RFrewvWYcWr4jeDzKoQ)

### (5) 捋一捋逻辑

[旋转矩阵 Q0048](https://mp.weixin.qq.com/s/n_0FJkuX2N0_EPMHG3MBDw)

### (6) 实用STL

[矩阵对角线排序 Q1329](https://mp.weixin.qq.com/s/ddnzIpv7K07urg0F0SsrRA)

[更多文章>>>](https://cnbluegeek.github.io/archive/?tag=%E9%9D%A2%E8%AF%95%E5%88%B7%E9%A2%98)

## 1. Records 记录

[第001～100期](src/e001_100/README.md)

[第101～200期](src/e101_200/README.md)

[剑指Offer](src/sword_to_offer/README.md)

[经典问题和算法](src/classical/README.md)

## 2. Dependencies 依赖

* cmake
* gflags
* glog
* gtest

## 3. Compile 编译

### (1). 操作系统

目前的编译配置支持的操作系统为：***MacOS和Ubuntu***，其他操作系统下可能需要自行稍作修改。

### (2). 安装依赖

MacOS：

参考 `.github/workflows/main.yml`文件中的`build`任务中的`Installation depends`步骤即可

Ubuntu：

参考 `.github/workflows/main.yml`文件中的`build_on_ubuntu`任务中的`Installation depends`步骤即可

### (3). 指令

安装完成编译依赖之后，直接运行 `release.sh`脚本即可在 `build`目录下生成`leetcode`可执行文件。

```bash
bash release.sh
```

运行所有测试用例：

```bash
./build/leetcode
```

### (4). 调试

[VSCode 调试配置说明](doc/vscode-config.md)

## 4. Join 参与

欢迎正在使用leetcode的朋友提交Pull Request贡献代码，相关规范，请查看：[贡献说明](CONTRIBUTING.md)

F&Q

[为什么要学会Git？](https://mp.weixin.qq.com/s/GH6ka8zI2sqYQGmZyA-oKQ)

[如何在Github上提交 Pull Request ？](https://mp.weixin.qq.com/s/4MH6edEc1TXieEUwwXj1Iw)

## 5. Communicate 交流

关于“Leetcode面试刷题”或者“计算机编程”相关的讨论可以加入 ***电报群*** ：

[面试刷题Leetcode频道](https://t.me/interview_leetcode_channel)

[面试刷题Leetcode群组](https://t.me/interview_leetcode)

国内私聊可以添加本人微信：cnbluegeek

<div style="text-align:center;width:100%;"><img width="150" height="150" src="images/cnbluegeek-qr.jpeg" /></div>

更多文章，请关注【青衣极客】公众号

![青衣极客](images/wechat_public.png)
