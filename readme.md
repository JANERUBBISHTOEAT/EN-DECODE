#

~~看不懂自己几年前写的东西 真抽象啊
朝花夕拾了属于是~~  
几年前写的内容如今难以理解，颇具抽象意味，宛如重拾旧日时光。

## 使用

```cmd
g++ encode.cpp -o encode
g++ decode.cpp -o decode
```

> 编译

```cmd
chcp 65001
```

> 代码页 65001 代表 UTF-8，可正常显示中文，避免乱码。
> 此外，需确保所用控制台字体支持中文字符。

```cmd
>encode.exe
wcbav

..嗯..嗯..嗯..哼...啊...嗯...哼....啊....哼....哼...嗯....哼....嗯....啊...啊..嗯...哼...嗯..啊....嗯....嗯..嗯..嗯....哼..嗯

Woc牛b啊V

...嗯...哼....哼...啊...哼..嗯....嗯....哼..嗯...哼...嗯...哼...啊....哼..哼嗯哼啊嗯嗯哼哼嗯哼哼哼嗯哼哼哼..嗯...哼...嗯...啊...啊嗯哼啊哼啊哼哼啊嗯哼哼哼嗯哼嗯...嗯..哼...哼....嗯...啊
```

> 输入明文，回车后输出密文。

```cmd
> .\decode.exe
..嗯..嗯..嗯..哼...啊...嗯...哼....啊....哼....哼...嗯....哼....嗯....啊...啊..嗯...哼...嗯..啊....嗯....嗯..嗯..嗯....哼..嗯
wcbav

...嗯...哼....哼...啊...哼..嗯....嗯....哼..嗯...哼...嗯...哼...啊....哼..哼嗯哼啊嗯嗯哼哼嗯哼哼哼嗯哼哼哼..嗯...哼...嗯...啊...啊嗯哼啊哼啊哼哼啊嗯哼哼哼嗯哼嗯...嗯..哼...哼....嗯...啊
Woc牛b啊V
```

> 输入密文，回车后输出明文。
