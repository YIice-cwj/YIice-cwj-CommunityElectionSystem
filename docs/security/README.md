# 加密安全模块 (security)

## 模块概述

加密安全模块提供数据加解密、数字签名验证和密钥管理功能，确保系统数据的安全性和完整性。

## 目录结构

```
security/
├── include/security/           # 公共头文件
│   ├── i_security_manager.h    # 安全管理器接口
│   ├── key_pair.h              # 密钥对类
│   ├── security_exception.h    # 安全异常类
│   └── security_error_code.h   # 安全错误码定义
├── src/                       # 源代码
│   ├── security_manager.cpp    # 安全管理器实现
│   ├── encryptor.cpp           # 加密器实现
│   ├── decryptor.cpp           # 解密器实现
│   ├── signer.cpp              # 签名器实现
│   └── key_manager.cpp         # 密钥管理器实现
└── tests/                     # 测试代码
    └── security_manager_test.cpp
```

## 核心功能

1. **数据加密解密**
   - 对称加密算法支持
   - 非对称加密算法支持
   - 数据加密性能优化

2. **数字签名**
   - 数据签名生成
   - 签名验证功能
   - 防篡改机制

3. **密钥管理**
   - 密钥生成和存储
   - 密钥轮换机制
   - 密钥安全分发

## 依赖关系

- [exception](../../exception/) - 异常处理模块（包含错误码定义）

## 设计原则

- 确保数据的机密性和完整性
- 提供易用的安全接口
- 支持多种加密算法
- 符合安全最佳实践