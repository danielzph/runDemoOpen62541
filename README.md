# runDemoOpen62541

说明：本库为测试使用open62541构建客户端案例，还在开发阶段，若想查看open62541相关信息，请查看[官网](https://open62541.org/)、[官方文档](https://open62541.org/doc/current/index.html)。

## 简单介绍

open62541是一个开源的免费实现OPC UA（OPC统一架构），用C99和C ++ 98语言的通用子集编写。该库可与所有主要编译器一起使用，并提供实现专用OPC UA客户端和服务器的必要工具，或将基于OPC UA的通信集成到现有应用程序中。open62541库与平台无关。所有特定于平台的功能都是通过可交换的插件实现的。为主要操作系统提供了插件实现。   

本案例为使用open62541构建一个客户端，还在开发阶段，此后将不定时更新。

## 如何使用

编译。 (因为我在第一次同步时上传了编译好的中间文件，之后并没有持续更新，故需要在次编译本库，以下是源码的编译方法。)

> $ get clone https://github.com/danielzph/runDemoOpen62541.git //

> $ cd runDemoOpen62541 

> $ mkdir build

> $ cd build

> $ cmake ..

> $ make

编译完成后，在bin文件夹中，为生成的客户端可执行文件。










