# 🗳️ 社区业主委员会选举投票系统

<p align="center">
  <img src="https://img.shields.io/badge/语言-C++17-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/构建-CMake-orange.svg" alt="Build">
  <img src="https://img.shields.io/badge/许可证-MIT-green.svg" alt="License">
</p>

## 🎯 项目概述

本项目是一个基于 **C++17** 标准开发的社区业主委员会电子投票系统，旨在提供一个**安全**、**可靠**、**易用**的在线投票平台。

```
      ┌─────────────────────────────────────┐
      │          用户界面层                  │
      └─────────────┬───────────────────────┘
                    │
      ┌─────────────▼───────────────────────┐
      │         网络通信模块 (network)        │
      └─────────────┬───────────────────────┘
                    │
      ┌─────────────▼───────────────────────┐
      │    业务逻辑层                         │
      │  ├── 用户认证 (auth)                 │
      │  ├── 选举管理 (election)             │
      │  ├── 投票处理 (vote)                 │
      │  ├── 报表生成 (report)               │
      │  └── 系统管理 (admin)                │
      └─────────────┬───────────────────────┘
                    │
      ┌─────────────▼───────────────────────┐
      │    系统服务层                         │
      │  ├── 数据库交互 (db)                 │
      │  ├── 配置管理 (config)     e          │
      │  ├── 安全加密 (security)             │
      │  ├── 缓存管理 (cache)                │
      │  ├── 异常处理 (exception)            │
      │  ├── 定时任务 (scheduler)            │
      │  ├── 国际化 (i18n)                  │
      │  └── 监控告警 (monitor)              │
      └─────────────────────────────────────┘
```

## 🚀 技术栈

- **编程语言**: C++17 ⚡
- **构建工具**: CMake 3.10+ 🛠️
- **数据库**: MySQL 8.0+ 🗄️
- **测试框架**: Google Test (gtest) ✅
- **辅助库**: Boost 🚀

## 📁 项目目录结构

```
CommunityElectionSystem/
├── .vscode/                 # VSCode配置文件
├── build/                   # 构建输出目录
├── include/                 # 公共头文件目录
├── src/                     # 源代码目录
├── tests/                   # 测试代码目录
├── docs/                    # 📚 详细文档目录
├── cmake/                   # CMake模块目录
├── third_party/             # 第三方依赖库
├── scripts/                 # 脚本目录
├── CMakeLists.txt           # CMake配置文件
└── README.md                # 项目说明文件
```

> 📝 **详细模块文档请查看 [docs](./docs) 目录**

## 🧩 系统架构总览

### 核心功能模块

| 模块                           | 功能                         | 文档                                      |
| ------------------------------ | ---------------------------- | ----------------------------------------- |
| 🛡️ [用户认证](./docs/auth)     | 身份验证、权限管理、会话控制 | [接口文档](./docs/auth/interfaces.md)     |
| 🗳️ [选举管理](./docs/election) | 选举创建、配置、候选人管理   | [接口文档](./docs/election/interfaces.md) |
| 📝 [投票处理](./docs/vote)     | 投票提交、验证、计票         | [接口文档](./docs/vote/interfaces.md)     |
| 🗄️ [数据库交互](./docs/db)     | 连接池管理、ORM 映射         | [接口文档](./docs/db/interfaces.md)       |
| 📊 [报表生成](./docs/report)   | 数据分析、可视化、PDF 导出   | [接口文档](./docs/report/interfaces.md)   |
| ⚙️ [系统管理](./docs/admin)    | 配置管理、日志、备份         | [接口文档](./docs/admin/interfaces.md)    |

### 基础服务模块

| 模块                            | 功能                   | 文档                                       |
| ------------------------------- | ---------------------- | ------------------------------------------ |
| 🌐 [网络通信](./docs/network)   | RESTful API、WebSocket | [接口文档](./docs/network/interfaces.md)   |
| ⚙️ [配置管理](./docs/config)    | 外部化配置、多环境支持 | [接口文档](./docs/config/interfaces.md)    |
| 🚀 [缓存管理](./docs/cache)     | 内存缓存、分布式缓存   | [接口文档](./docs/cache/interfaces.md)     |
| 🔐 [加密安全](./docs/security)  | 数据加解密、数字签名   | [接口文档](./docs/security/interfaces.md)  |
| ⏰ [定时任务](./docs/scheduler) | Cron 调度、异步处理    | [接口文档](./docs/scheduler/interfaces.md) |
| 🌍 [国际化](./docs/i18n)        | 多语言支持、本地化处理 | [接口文档](./docs/i18n/interfaces.md)      |
| 📡 [监控告警](./docs/monitor)   | 性能监控、健康检查     | [接口文档](./docs/monitor/interfaces.md)   |
| 🚨 [异常处理](./docs/exception) | 统一异常处理框架       | [接口文档](./docs/exception/interfaces.md) |

## 📋 开发规范

### 编码规范

- ✅ 所有代码必须遵循 C++17 标准
- ✅ 使用现代 C++特性（智能指针、lambda 表达式等）
- ✅ 类名使用 PascalCase 命名法
- ✅ 函数和变量使用 camelCase 命名法
- ✅ 常量使用 UPPER_CASE 命名法

### 接口设计原则

- ✅ 遵循 SOLID 原则
- ✅ 接口隔离原则：每个接口只负责一项功能
- ✅ 依赖倒置原则：高层模块不依赖低层模块
- ✅ 使用纯虚类定义接口

### 测试要求

- ✅ 每个模块都需要编写单元测试
- ✅ 单元测试覆盖率不低于 80%
- ✅ 集成测试覆盖所有核心业务流程

## 🛠️ 构建与部署

### 构建步骤

```bash
mkdir build && cd build
cmake ..
make
```

### 运行测试

```bash
cd build
ctest
```

### 部署要求

- MySQL 8.0+数据库
- 支持 C++17 的编译器
- 至少 4GB 内存
- 至少 10GB 磁盘空间

## 📅 开发计划

详细的模块实现优先级计划请查看 [IMPLEMENTATION_PLAN.md](./docs/IMPLEMENTATION_PLAN.md)

## 🤝 贡献

欢迎提交 Issue 和 Pull Request 来帮助我们改进项目！

## 📄 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](./LICENSE) 文件了解详情
