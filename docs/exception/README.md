# 异常处理模块 (exception)

## 模块概述

异常处理模块提供统一的异常处理框架，定义系统中各种异常类型，并集成错误码管理机制，确保异常信息的一致性和可追踪性。

## 目录结构

```
exception/
├── include/exception/         # 公共头文件
│   ├── base_exception.h       # 异常基类
│   ├── auth_exception.h       # 认证异常类
│   ├── election_exception.h   # 选举异常类
│   ├── vote_exception.h       # 投票异常类
│   ├── database_exception.h   # 数据库异常类
│   ├── report_exception.h     # 报表异常类
│   ├── admin_exception.h      # 管理异常类
│   ├── exception_handler.h    # 异常处理器
│   └── error_code.h           # 错误码枚举定义
├── src/                       # 源代码
│   ├── base_exception.cpp     # 异常基类实现
│   └── exception_handler.cpp  # 异常处理器实现
└── tests/                     # 测试代码
    └── exception_test.cpp
```

## 核心功能

1. **统一异常体系**
   - 定义系统级异常基类
   - 各模块专用异常类型
   - 异常层次结构清晰

2. **异常处理**
   - 异常捕获和记录
   - 错误码管理
   - 异常信息格式化

3. **错误码管理**
   - 统一定义系统错误码
   - 错误码分类管理
   - 错误码描述信息维护

## 依赖关系

- 标准库异常处理机制
- 日志系统（用于记录异常）

## 设计原则

- 提供一致的异常处理接口
- 异常信息清晰明确
- 支持异常链追踪
- 便于扩展新的异常类型
- 错误码与异常信息结合使用