# GMLIB
## Group Mountain Library
![Latest Tag](https://img.shields.io/github/v/tag/GroupMountain/GMLIB-Release?label=LATEST%20TAG&style=for-the-badge)    
[![Downloads](https://img.shields.io/github/downloads/GroupMountain/GMLIB-Release/total?style=for-the-badge&color=%2300ff00)](https://github.com/GroupMountain/GMLIB-Release/releases)     
QQ交流群: 931689535

`GMLIB` 是一个基于 `LeviLamina` 加载器的第三方插件前置库。为基岩版专用服务器 —— `Bedrock Dedicated Server`（以下简称**
BDS**）的插件开发者提供更多的API，一定程度上弥补了 `LeviLamina` 的API缺口。

`GMLIB` 封装了大量 `LeviLamina` 未直接提供的API，为插件开发者提供了更多便利。
插件开发者可以直接调用 `GMLIB` 中的现成API，而非重复造轮子。

`GMLIB` 的API支持使用头文件和静态链接库导入，我们提供了模板插件和GMLIB的SDK（xmake-repo）。
对于调用 `GMLIB API` 的代码来说，如果GMLIB没有API改动，仅需本项目在底层适配更新即可，给插件开发与维护带来了很大的便利。

`GMLIB` 的全部内容，在 `v0.13.6` 之前均为开源的。  

从 `v0.13.6` 开始，由于部分人不遵循本库开源协议的恶劣行为，以及mojang删除了pdb，GMLIB不再开源。

新版本正在重构，进度参见 [`这里`](https://github.com/GroupMountain/GMLIB-Release/issues/122) 

## 📕 编写插件和使用API
详细的API使用请参考我们的文档站（正在建设）或者参考头文件内注释。
如需使用正在测试的API，请加入我们的交流群获取和测试。
> 注意：  
> 正在开发的测试版API随时可能进行调整，在正式发布之前不保证API向后兼容性，请谨慎使用

#### 原生插件（`C++`）
1. 正常创建 `LeviLamina` 插件项目。
2. 添加头文件
3. 添加动态库
4. 编写你的代码...

## 🔨 构建项目
从 `v0.13.6` 开始，由于部分人的恶劣行为， `GMLIB` 不再开源，你无法自行构建  
早期版本可自行克隆仓库并构建

## 🎬 参与贡献

您可以使用以下方法为 `GMLIB` 项目做出贡献  

1. 帮助我们修改并优化开发文档、使用文档
2. 在 [`GitHub Issues`](https://github.com/GroupMountain/GMLIB-Release/issues) 中反馈使用过程中遇到的问题，或者提出好的建议
3. 帮助我们推广 `GMLIB`，支持我们的发展

⭐⭐⭐我们欢迎您的贡献！⭐⭐⭐

## 📍 许可证
- **开发者不对您负责，开发者没有义务为你编写代码、为你使用造成的任何后果负责**
1. 本前置插件在 `v0.13.6` 以前全部代码采用 `LGPL 3.0` 开源协议，在 `v0.13.6` 之后，由于部分人的恶劣行为，本库不再开源。
2. 您可以使用任何开源许可证编写基于 `GMLIB` 作为前置的插件，甚至不发布您的源代码。
3. 如果你修改了 `GMLIB` 的源代码，或者基于这个 `GMLIB` 编写了一个新的前置，你必须开源它。由于部分人的恶劣行为，你已经无法再获取到最新版GMLIB的源代码。
4. 如果你想要分发，转载本前置，你必须得到我们的授权！

## 🏆 致谢
- 感谢 `LeviLamina` 的开源代码和底层API，极大的简化了前置插件开发难度。
- 感谢 `GroupMountain` 开发成员对项目的巨大贡献。

## 💎 重要贡献者
- [@KobeBryant114514](https://github.com/KobeBryant114514)
- [@killcerr](https://github.com/killcerr)
- [@EpsilonZunsat](https://github.com/EpsilonZunsat)
- [@zimuya4153](https://github.com/zimuya4153)
- [@engsr6982](https://github.com/engsr6982)
- [@Dofes](https://github.com/Dofes)
- [@lostDeers](https://github.com/lostDeers)
- [@ShrBox](https://github.com/ShrBox)
- [@Zhongzi8972](https://github.com/Zhongzi8972)