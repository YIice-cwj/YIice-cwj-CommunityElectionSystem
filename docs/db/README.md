# 数据库交互模块 (db)

## 模块概述

数据库交互模块提供对MySQL数据库的访问封装，包括连接池管理、ORM映射和事务处理等功能。该模块确保数据访问的高效性、安全性和可靠性。

## 目录结构

```
db/
├── include/db/                # 公共头文件
│   ├── i_database_connection.h # 数据库连接接口
│   ├── i_connection_pool.h    # 连接池接口
│   ├── i_ormapper.h           # ORM映射器接口
│   ├── i_query_result.h       # 查询结果接口
│   ├── query_result.h         # 查询结果实现类
│   ├── transaction.h          # 事务管理类
│   ├── database_exception.h   # 数据库异常类
│   └── database_error_code.h  # 数据库错误码定义
├── src/                       # 源代码
│   ├── mysql_connection.cpp   # MySQL连接实现
│   ├── connection_pool.cpp    # 连接池实现
│   ├── ormapper.cpp           # ORM映射器实现
│   ├── query_result.cpp       # 查询结果实现
│   └── transaction_manager.cpp # 事务管理器实现
└── tests/                     # 测试代码
    ├── connection_pool_test.cpp
    └── ormapper_test.cpp
```

## 核心功能

1. **连接管理**
   - MySQL连接池管理
   - 连接复用和生命周期管理
   - 连接健康检查

2. **数据访问**
   - SQL查询执行
   - 结果集映射
   - 参数化查询防止SQL注入

3. **事务处理**
   - ACID事务保障
   - 事务嵌套支持
   - 事务回滚机制

## 依赖关系

- MySQL客户端库
- [exception](../../exception/) - 异常处理模块（包含错误码定义）

## 设计原则

- 高性能连接池管理
- 防止SQL注入攻击
- 保证数据一致性和完整性
- 支持事务处理