# leetcode

Collect leetcode-like problems and solutions dedicated to improving algorithm design.

【译】收集leetcode类型的问题和解决方案，致力于提高算法设计的能力。

***对本项目感兴趣的朋友，麻烦加个star以示鼓励。***

仓库收录的所有问题，请查看：[收录列表](src/README.md)

## Articles 文章

[博客>>>](https://blog.bluegeek.me/archive/?tag=%E9%9D%A2%E8%AF%95%E5%88%B7%E9%A2%98)

## 1. Records 记录

[Leetcode](src/leetcode/)

[剑指Offer](src/sword_to_offer/)

[经典问题和算法](src/classical/)

## 2. Dependencies 依赖

本项目使用 `xmake` 管理依赖，因此在运行之前，先安装 `xmake`

```shell
curl -fsSL https://xmake.io/shget.text | bash
```

在Windows上可以使用如下指令

```shell
winget install xmake
```

## 3. Compile 编译

### (1). 操作系统

目前只在 `macOS` 和 `Ubuntu` 上测试

### (2). 安装依赖

```shell
xmake require
```

### (3). 指令

安装完成编译依赖之后，直接运行 `xmake`

```bash
xmake
```

运行所有测试用例：

```bash
xmake run leetcode
```

### (4). 调试

[VSCode 调试配置说明](doc/vscode-config.md)

## 4. Join 参与

欢迎正在使用leetcode的朋友提交Pull Request贡献代码，相关规范，请查看：[贡献说明](CONTRIBUTING.md)

### F&Q

#### 1. [为什么要学会Git？](https://mp.weixin.qq.com/s/GH6ka8zI2sqYQGmZyA-oKQ)

#### 2. [如何在Github上提交 Pull Request ？](https://mp.weixin.qq.com/s/4MH6edEc1TXieEUwwXj1Iw)

#### 3. 怎样只调试和运行一个解决方案？

`xmake.lua`  中配置的 `test` 目标就是用于调试和运行一个问题的解决方案。

将其中的 `src/leetcode/cpp/q0001.cpp` 字符串修改为想要调试的文件路径即可。
