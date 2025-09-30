# 缓存管理模块 (cache)

## 模块概述

缓存管理模块提供内存级和分布式缓存支持，用于提高系统性能和响应速度。

## 目录结构

```
cache/
├── include/cache/              # 公共头文件
│   ├── i_cache_manager.h       # 缓存管理器接口
│   ├── cache_value.h           # 缓存值类
│   ├── cache_exception.h       # 缓存异常类
│   └── cache_error_code.h      # 缓存错误码定义
├── src/                       # 源代码
│   ├── cache_manager.cpp       # 缓存管理器实现
│   ├── memory_cache.cpp        # 内存缓存实现
│   ├── cache_entry.cpp         # 缓存条目实现
│   └── cache_eviction_policy.cpp # 缓存淘汰策略实现
└── tests/                     # 测试代码
    └── cache_manager_test.cpp
```

## 核心功能

1. **内存级缓存**
   - 高速数据访问
   - 缓存大小限制
   - LRU淘汰策略

2. **分布式缓存**
   - 支持Redis等分布式缓存
   - 缓存集群管理
   - 数据一致性保障

3. **缓存管理**
   - 缓存失效策略
   - 缓存预热机制
   - 缓存监控和统计

## 依赖关系

- [exception](../../exception/) - 异常处理模块（包含错误码定义）

## 设计原则

- 提供统一的缓存访问接口
- 支持多种缓存实现
- 实现高效的缓存淘汰机制
- 确保缓存数据的一致性