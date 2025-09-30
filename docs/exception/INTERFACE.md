# 异常处理模块接口文档

## base_exception 类

异常基类，所有自定义异常类的父类。

### 头文件

```cpp
#include <exception/base_exception.h>
```

### 类定义

```cpp
class base_exception : public std::exception {
private:
    std::string message_;
    error_code_t error_code_;
    std::shared_ptr<base_exception> cause_;

public:
    /**
     * 构造函数
     * @param message 异常消息
     */
    explicit base_exception(const std::string& message);

    /**
     * 构造函数
     * @param message 异常消息
     * @param error_code 错误码
     */
    base_exception(const std::string& message, error_code_t error_code);

    /**
     * 构造函数
     * @param message 异常消息
     * @param error_code 错误码
     * @param cause 原始异常
     */
    base_exception(const std::string& message, error_code_t error_code,
                  std::shared_ptr<base_exception> cause);

    /**
     * 获取异常消息
     * @return 异常消息
     */
    const char* what() const noexcept override;

    /**
     * 获取错误码
     * @return 错误码
     */
    error_code_t error_code() const;

    /**
     * 获取原始异常
     * @return 原始异常
     */
    std::shared_ptr<base_exception> get_cause() const;

    /**
     * 设置原始异常
     * @param cause 原始异常
     */
    void set_cause(std::shared_ptr<base_exception> cause);
};
```

## error_code_t 枚举类

错误码枚举类定义了系统中使用的所有错误码。

### 头文件

```cpp
#include <exception/error_code.h>
```

### 枚举定义

```cpp
enum class error_code_t {
    // 通用错误码 (1000-1999)
    success = 1000,              // 操作成功
    unknown_error,               // 未知错误
    invalid_parameter,           // 参数无效
    operation_not_supported,     // 操作不支持
    resource_not_found,          // 资源未找到
    resource_already_exists,     // 资源已存在
    internal_error,              // 内部错误

    // 认证相关错误码 (2000-2999)
    auth_invalid_credentials = 2000,  // 无效凭证
    auth_session_expired,             // 会话过期
    auth_access_denied,               // 访问被拒绝
    auth_account_locked,              // 账户被锁定
    auth_account_disabled,            // 账户被禁用

    // 选举相关错误码 (3000-3999)
    election_not_found = 3000,        // 选举未找到
    election_not_active,              // 选举未激活
    election_already_ended,           // 选举已结束
    election_candidate_full,          // 候选人已满
    election_voting_not_started,      // 投票尚未开始

    // 投票相关错误码 (4000-4999)
    vote_duplicate = 4000,            // 重复投票
    vote_invalid,                     // 无效投票
    vote_out_of_time_window,          // 超出投票时间窗口
    vote_user_not_qualified,          // 用户无投票资格

    // 数据库相关错误码 (5000-5999)
    db_connection_failed = 5000,      // 数据库连接失败
    db_query_failed,                  // 数据库查询失败
    db_transaction_failed,            // 数据库事务失败

    // 配置相关错误码 (6000-6999)
    config_load_failed = 6000,        // 配置加载失败
    config_invalid,                   // 配置无效

    // 安全相关错误码 (7000-7999)
    security_encryption_failed = 7000, // 加密失败
    security_decryption_failed,        // 解密失败
    security_signature_invalid,        // 签名无效

    // 网络相关错误码 (8000-8999)
    network_request_failed = 8000,    // 网络请求失败
    network_timeout,                  // 网络超时
    network_invalid_response          // 无效网络响应
};
```

## exception_handler 类

异常处理器，提供统一的异常处理机制。

### 头文件

```cpp
#include <exception/exception_handler.h>
```

### 类定义

```cpp
class exception_handler {
public:
    /**
     * 处理异常
     * @param ex 异常对象
     * @param context 上下文信息
     */
    static void handle_exception(const base_exception& ex, const std::string& context = "");

    /**
     * 记录异常日志
     * @param ex 异常对象
     * @param context 上下文信息
     */
    static void log_exception(const base_exception& ex, const std::string& context = "");

    /**
     * 将异常转换为错误码
     * @param ex 异常对象
     * @return 错误码
     */
    static error_code_t to_error_code(const base_exception& ex);

    /**
     * 将异常转换为用户友好的消息
     * @param ex 异常对象
     * @return 用户友好的消息
     */
    static std::string to_user_message(const base_exception& ex);
};
```

## 各模块异常类

### 认证异常类

```cpp
class auth_exception : public base_exception {
    // 认证相关异常
public:
    auth_exception(const std::string& message, error_code_t error_code = error_code_t::auth_invalid_credentials);
};

class authentication_exception : public auth_exception {
    // 身份验证异常
public:
    authentication_exception(const std::string& message);
};

class authorization_exception : public auth_exception {
    // 授权异常
public:
    authorization_exception(const std::string& message);
};
```

### 选举异常类

```cpp
class election_exception : public base_exception {
    // 选举相关异常
public:
    election_exception(const std::string& message, error_code_t error_code = error_code_t::election_not_found);
};

class election_not_found_exception : public election_exception {
    // 选举未找到异常
public:
    election_not_found_exception(const std::string& message);
};

class election_not_active_exception : public election_exception {
    // 选举未激活异常
public:
    election_not_active_exception(const std::string& message);
};
```

### 投票异常类

```cpp
class vote_exception : public base_exception {
    // 投票相关异常
public:
    vote_exception(const std::string& message, error_code_t error_code = error_code_t::vote_invalid);
};

class duplicate_vote_exception : public vote_exception {
    // 重复投票异常
public:
    duplicate_vote_exception(const std::string& message);
};

class invalid_vote_exception : public vote_exception {
    // 无效投票异常
public:
    invalid_vote_exception(const std::string& message);
};
```

### 数据库异常类

```cpp
class database_exception : public base_exception {
    // 数据库相关异常
public:
    database_exception(const std::string& message, error_code_t error_code = error_code_t::db_connection_failed);
};

class connection_exception : public database_exception {
    // 数据库连接异常
public:
    connection_exception(const std::string& message);
};

class query_exception : public database_exception {
    // 查询异常
public:
    query_exception(const std::string& message);
};
```

## 错误码分类说明

| 错误码范围 | 类别       | 说明                   |
| ---------- | ---------- | ---------------------- |
| 1000-1999  | 通用错误   | 系统通用错误           |
| 2000-2999  | 认证错误   | 用户认证和授权相关错误 |
| 3000-3999  | 选举错误   | 选举管理相关错误       |
| 4000-4999  | 投票错误   | 投票处理相关错误       |
| 5000-5999  | 数据库错误 | 数据库操作相关错误     |
| 6000-6999  | 配置错误   | 系统配置相关错误       |
| 7000-7999  | 安全错误   | 安全加密相关错误       |
| 8000-8999  | 网络错误   | 网络通信相关错误       |

## 错误严重性等级

```cpp
enum class error_severity_t {
    info,     // 信息级别
    warning,  // 警告级别
    error,    // 错误级别
    critical  // 严重级别
};
```