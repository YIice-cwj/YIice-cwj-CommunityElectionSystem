# 网络通信模块 (network)

## 模块概述

网络通信模块提供RESTful API接口和WebSocket实时通信支持，实现系统与外部客户端的安全数据交换。

## 目录结构

```
network/
├── include/network/            # 公共头文件
│   ├── i_web_server.h          # Web服务器接口
│   ├── http_request.h          # HTTP请求类
│   ├── http_response.h         # HTTP响应类
│   ├── web_socket_handler.h    # WebSocket处理器
│   ├── network_exception.h     # 网络异常类
│   └── network_error_code.h    # 网络错误码定义
├── src/                       # 源代码
│   ├── web_server.cpp          # Web服务器实现
│   ├── http_request.cpp        # HTTP请求实现
│   ├── http_response.cpp       # HTTP响应实现
│   ├── rest_controllers/       # REST控制器
│   │   ├── auth_controller.cpp
│   │   ├── election_controller.cpp
│   │   ├── vote_controller.cpp
│   │   └── report_controller.cpp
│   └── web_socket_handler.cpp  # WebSocket处理器实现
└── tests/                     # 测试代码
    ├── web_server_test.cpp
    └── rest_controller_test.cpp
```

## 核心功能

1. **RESTful API**
   - 提供标准HTTP接口
   - 支持JSON数据格式
   - 身份验证和授权

2. **WebSocket通信**
   - 实时数据推送
   - 双向通信支持
   - 连接管理

3. **安全传输**
   - HTTPS安全传输协议
   - 请求验证和过滤
   - 防止常见Web攻击

## 依赖关系

- [auth](../../auth/) - 用户认证模块
- [election](../../election/) - 选举管理模块
- [vote](../../vote/) - 投票处理模块
- [report](../../report/) - 报表生成模块
- [exception](../../exception/) - 异常处理模块（包含错误码定义）

## 设计原则

- 遵循RESTful设计原则
- 提供安全的API访问机制
- 支持高并发访问
- 实现实时通信功能