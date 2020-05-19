
# VSCode 调试配置说明

很多朋友需要在VSCode中调试运行代码，这里就简要介绍以下vscode中`launch.json`和`tasks.json`这两个文件的设置。

## 构建

`tasks.json` 这个文件主要用于构建程序的，也就是生成可执行文件。由于本工程中已经使用了cmake来定制编译流程和依赖，因此，最好还是直接利用cmake来构建。下面想给出一个MacOS下的配置：

```JSON
{
    "tasks": [
        {
            "type": "shell",
            "label": "g++-8 build active file",
            "command": "cd ${workspaceFolder}/build && cmake .. && make -j8 && cd ..",
            "options": {
                "cwd": "/usr/local/bin"
            }
        }
    ],
    "version": "2.0.0"
}
```

其中最重要的就是“command”这一项的设置。“command”的设置也就是最终会运行在shell中的命令，运行完成之后，会生成build/leetcode可执行文件，

## 调试

如果想要在vscode中调试，还需要设置`launch.json`这个文件，下面先给出一个MacOS下的配置：

```JSON
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++-8 build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/leetcode",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb",
            "preLaunchTask": "g++-8 build active file"
        }
    ]
}
```

其中最重要的是“program”这一项，主要是为了找到可执行文件，然后调用调试器来调试。在MacOS下使用的调试器是`lldb`，在ubuntu下使用的调试器是 `gdb`。其他的都是自动生成，基本都不需要改动，主要是正确设置“program”。

这两个配置文件设置完成之后，就可以任意找一个题目的cpp文件，打上断点调试。
