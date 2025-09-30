# 用户认证模块接口文档

## i_auth_manager 接口

认证管理器接口定义了用户认证相关的核心功能。

### 头文件
```cpp
#include <auth/i_auth_manager.h>
```

### 接口定义
```cpp
class i_auth_manager {
public:
    virtual ~i_auth_manager() = default;
    
    /**
     * 用户身份验证
     * @param username 用户名
     * @param password 密码
     * @return 验证成功返回true，否则返回false
     */
    virtual bool authenticate(const std::string& username, const std::string& password) = 0;
    
    /**
     * 用户授权检查
     * @param user_id 用户ID
     * @param permission 权限标识
     * @return 具有权限返回true，否则返回false
     */
    virtual bool authorize(const std::string& user_id, const std::string& permission) = 0;
    
    /**
     * 生成会话令牌
     * @param user_id 用户ID
     * @return 会话令牌字符串
     */
    virtual std::string generate_session_token(const std::string& user_id) = 0;
    
    /**
     * 验证会话有效性
     * @param token 会话令牌
     * @return 会话有效返回true，否则返回false
     */
    virtual bool validate_session(const std::string& token) = 0;
    
    /**
     * 使会话失效
     * @param token 会话令牌
     */
    virtual void invalidate_session(const std::string& token) = 0;
};
```

## user 类

用户实体类，表示系统中的用户信息。

### 头文件
```cpp
#include <auth/user.h>
```

### 类定义
```cpp
class user {
private:
    std::string user_id_;
    std::string username_;
    std::string email_;
    std::vector<std::string> roles_;
    bool is_active_;
    
public:
    // 构造函数
    user(const std::string& user_id, const std::string& username);
    
    // Getter方法
    std::string get_user_id() const;
    std::string get_username() const;
    std::string get_email() const;
    std::vector<std::string> get_roles() const;
    bool get_is_active() const;
    
    // Setter方法
    void set_email(const std::string& email);
    void set_roles(const std::vector<std::string>& roles);
    void set_is_active(bool is_active);
};
```

## session 类

会话实体类，表示用户的登录会话信息。

### 头文件
```cpp
#include <auth/session.h>
```

### 类定义
```cpp
class session {
private:
    std::string token_id_;
    std::string user_id_;
    std::chrono::time_point<std::chrono::system_clock> create_time_;
    std::chrono::time_point<std::chrono::system_clock> expire_time_;
    std::string ip_address_;
    
public:
    // 构造函数
    session(const std::string& token_id, const std::string& user_id);
    
    // Getter方法
    std::string get_token_id() const;
    std::string get_user_id() const;
    std::chrono::time_point<std::chrono::system_clock> get_create_time() const;
    std::chrono::time_point<std::chrono::system_clock> get_expire_time() const;
    std::string get_ip_address() const;
    
    // Setter方法
    void set_expire_time(const std::chrono::time_point<std::chrono::system_clock>& expire_time);
    void set_ip_address(const std::string& ip_address);
    
    // 功能方法
    bool is_expired() const;
};
```

## auth_exception 类

认证相关异常类。

### 头文件
```cpp
#include <auth/auth_exception.h>
```

### 类定义
```cpp
class auth_exception : public base_exception {
public:
    explicit auth_exception(const std::string& message);
    auth_exception(const std::string& message, const std::string& error_code);
};

class authentication_exception : public auth_exception {
public:
    explicit authentication_exception(const std::string& message);
};

class authorization_exception : public auth_exception {
public:
    explicit authorization_exception(const std::string& message);
};
```