# 用户认证模块 (auth)

## 模块概述

用户认证模块负责系统的用户身份验证、权限管理和会话控制。它确保只有经过授权的用户才能访问系统功能，并提供安全的会话管理机制。

## 目录结构

```
auth/
├── include/auth/              # 公共头文件
│   ├── i_auth_manager.h       # 认证管理器接口
│   ├── user.h                 # 用户实体类
│   ├── session.h              # 会话实体类
│   ├── auth_exception.h       # 认证异常类
│   └── auth_error_code.h      # 认证错误码定义
├── src/                       # 源代码
│   ├── auth_manager.cpp       # 认证管理器实现
│   ├── session_manager.cpp    # 会话管理器实现
│   └── auth_validator.cpp     # 认证验证器实现
└── tests/                     # 测试代码
    ├── auth_manager_test.cpp
    └── session_manager_test.cpp
```

## 核心功能

1. **用户身份验证**
   - 用户名密码验证
   - 多因素认证支持
   - 登录尝试限制

2. **权限管理**
   - 基于角色的访问控制(RBAC)
   - 权限验证
   - 角色分配与管理

3. **会话管理**
   - 会话令牌生成与验证
   - 会话过期处理
   - 并发登录控制

## 依赖关系

- [exception](../../exception/) - 异常处理模块（包含错误码定义）
- [db](../../db/) - 数据库交互模块
- [security](../../security/) - 加密安全模块

## 设计原则

- 遵循SOLID原则
- 接口隔离，易于扩展
- 安全优先，防止常见攻击（如SQL注入、XSS等）