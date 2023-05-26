
# VSCode 调试配置说明

再使用调试功能之前，必须先生成 `debug` 版本，可以使用插件的操作，也可以使用指令操作。

`xmake` 默认是release模式，需要先切换到 debug 模式

```
xmake f -m debug
```

然后执行 `xmake` 指令就可以生成debug版本程序

```
build/macosx/x86_64/debug/test
```

将需要调试的目标路径设置到`launch.json`这个文件，下面先给出一个MacOS下的配置：

```JSON
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "test",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/macosx/x86_64/debug/test",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb"
        }
    ]
}
```

其中最重要的是“program”这一项，主要是为了找到可执行文件，然后调用调试器来调试。在MacOS下使用的调试器是`lldb`，在ubuntu下使用的调试器是 `gdb`。其他的都是自动生成，基本都不需要改动，主要是正确设置“program”。

配置完成之后，就可以在选中的cpp文件打上断点调试。
