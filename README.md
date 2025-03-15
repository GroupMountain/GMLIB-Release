<div align="center">

# GMLIB

## Group Mountain Library

![Latest Tag](https://img.shields.io/github/v/tag/GroupMountain/GMLIB-Release?label=LATEST) [![Downloads](https://img.shields.io/github/downloads/GroupMountain/GMLIB-Release/total?color=%2300ff00)](https://github.com/GroupMountain/GMLIB-Release/releases) [![QQ Group](https://img.shields.io/badge/QQ_Group-931689535-blue)](https://qm.qq.com/cgi-bin/qm/qr?group_code=931689535) [![Document](https://img.shields.io/badge/Document-Unavailable-red)](https://groupmountain.github.io/Documentation/)

</div>

## 🎇 简介

`GMLIB` 是一个基于[`LeviLamina`](https://github.com/LiteLDev/LeviLamina/)加载器的第三方模组前置库,为基于基岩版专用服务器—— `Bedrock Dedicated Server` (以下简称**BDS**)的模组开发者提供更多的 API,一定意义上弥补了`LeviLamina`的 API 缺口.

`GMLIB` 封装了大量 `LeviLamina` 未直接提供的 API,为模组开发者提供了更多便利.模组开发者可以调用 `GMLIB` 提供的 API 而非重复造轮子.

开发者可以通过使用头文件和静态链接导入本前置库,最终用户需要在服务器内安装 GMLIB 模组以支持其他模组.对于调用 `GMLIB API` 库的项目来说,如果 GMLIB 没有 API 改动,仅需本项目在底层适配更新即可，给基于该前置的模组的开发与维护带来了很大的便利.

本项目在 `0.13.6` 版本之前以 `LGPL 3.0` 协议开源,在其之后的版本源代码不再公开.

## 📦 安装

#### 🔬 使用[`lip`](https://github.com/futrime/lip)

首先请确认你以正确安装最新版的 `lip` 工具  
 在服务器根目录执行:

```
lip install github.com/GroupMountain/GMLIB-Release
```

或者安装特定的版本:

```
# 将0.13.10替换成你想要安装的版本
lip install github.com/GroupMountain/GMLIB-Release@0.13.10
```

#### 🧪 手动安装

> 1. 前往 [Release](https://github.com/GroupMountain/GMLIB-Release/releases) 下载适配你服务器版本的 `GMLIB-windows-x64.zip`
> 2. 解压压缩包，将 `GMLIB` 目录移动到你的插件目录.

## 🧵 FQA

**在安装插件到服务器时遇到了问题时请先看我,会更省时!**

> Q: 本模组安装后控制台没有模组信息.
>
> A: 你的服务器内没有模组依赖于本前置 `前置不会被加载`.
>
> > 如果你想始终加载请把模组 `manifest.json` 中的 `passive` 改为 false.

> Q: 服务器报错 GMLIB 无法找到 LeviLamina 中的函数.
>
> A: 请确保你的 GMLIB 版本与 LeviLamina bds 的版本匹配.

## 📗 使用 API 编写插件

详细的 API 使用请参考我们的文档站(正在建设 ⏳)或者参考头文件内注释.  
 如需使用正在测试的 API,请加入我们的交流群获取和测试.

> 注意：  
> 正在开发的测试版 API 随时可能进行调整,在正式发布之前不保证 API 向后兼容性,请谨慎使用!

#### 🎯 原生插件 (`C++`)

我们推荐使用 [`GMLIB-Mod-Template`](https://github.com/GroupMountain/GMLIB-Mod-Template) 模版创建项目，或者借助 GroupMountain 的 [`xmake-repo`](https://github.com/GroupMountain/xmake-repo) 引入 SDK。

> 手动添加 GMLIB 的 SDK:
>
> 1. 正常创建 `LeviLamina` 模组项目。
> 2. 在您项目中的 `xmake.lua` 中添加下方内容
> 3. 在 `manifest.json` 中声明 GMLIB 的版本依赖关系
> 4. 输入 `xmake project -k compile_commands` 重新生成补全文件
```lua
add_repositories("groupmountain-repo https://github.com/GroupMountain/xmake-repo.git")

add_requires("gmlib")

target("my-mod") -- 找到你Mod的这段内容
    add_packages("gmlib")
```

#### 🎨 LSE 插件 (`QuickJS` `Lua` `Node.JS` `Python`)

我们提供了 [`GMLIB_LegacyRemoteCallApi`](https://github.com/GroupMountain/GMLIB-LegacyRemoteCallApi) 模组使 LSE 插件调用 GMLIB 内部的 API,详情请查看该模组的主页.

## 🔨 构建项目

很遗憾本项目当前并不开放源代码,你无法在本地构建.  
 本项目在 0.13.6 之前的版本根据 `LGPL3.0` 协议开放源代码,代码位于[main 分支](https://github.com/GroupMountain/GMLIB-Release/tree/main),请克隆仓库自行构建.  
 **温馨提示:如果你修改了 `GMLIB` 开源版本的源代码,或者基于这个 `GMLIB` 编写了一个新的前置,你必须开源它.**

## 🎬 参与贡献

您可以使用以下方法为 `GMLIB` 项目做出贡献

1.  帮助我们修改并优化开发文档和使用文档
2.  在 [`GitHub Issues`](https://github.com/GroupMountain/GMLIB-Release/issues) 中反馈使用过程中遇到的问题,或者提出好的建议
3.  点亮 Star,帮助我们推广 `GMLIB`,支持我们的发展!

⭐⭐⭐ 我们欢迎您的贡献!⭐⭐⭐

## 📍 许可证

-   **开发者不对您负责，开发者没有义务为你编写代码、为你使用造成的任何后果负责**

1.  本前置插件在 `v0.13.6` 以前全部代码采用 `LGPL 3.0` 开源协议，在 `v0.13.6` 之后，由于部分人的恶劣行为，本库不再开源。
2.  您可以使用任何开源许可证编写基于 `GMLIB` 作为前置的插件，甚至不发布您的源代码。
3.  如果你修改了 `GMLIB` 开源版本的源代码，或者基于这个 `GMLIB` 编写了一个新的前置，你必须开源它。
4.  如果你想要分发，转载本前置，你必须得到我们的授权！

## 🏆 致谢

-   感谢 `LeviLamina` 的开源代码和底层 API,极大的简化了本项目的开发难度.
-   感谢 `GroupMountain` 开发成员对项目的巨大贡献.

## 💎 重要贡献者

-   [@KobeBryant114514](https://github.com/KobeBryant114514)
-   [@killcerr](https://github.com/killcerr)
-   [@EpsilonZunsat](https://github.com/EpsilonZunsat)
-   [@zimuya4153](https://github.com/zimuya4153)
-   [@engsr6982](https://github.com/engsr6982)
-   [@Dofes](https://github.com/Dofes)
-   [@lostDeers](https://github.com/lostDeers)
-   [@ShrBox](https://github.com/ShrBox)
-   [@Zhongzi8972](https://github.com/Zhongzi8972)
-   [@n15421](https://github.com/n15421)
