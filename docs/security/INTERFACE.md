# 加密安全模块接口文档

## i_security_manager 接口

安全管理器接口定义了安全相关的核心功能。

### 头文件
```cpp
#include <security/i_security_manager.h>
```

### 接口定义
```cpp
class i_security_manager {
public:
    virtual ~i_security_manager() = default;
    
    /**
     * 加密数据
     * @param plaintext 明文数据
     * @return 加密后的密文
     */
    virtual std::string encrypt(const std::string& plaintext) = 0;
    
    /**
     * 解密数据
     * @param ciphertext 密文数据
     * @return 解密后的明文
     */
    virtual std::string decrypt(const std::string& ciphertext) = 0;
    
    /**
     * 对数据进行签名
     * @param data 待签名数据
     * @return 数据签名
     */
    virtual std::string sign(const std::string& data) = 0;
    
    /**
     * 验证数据签名
     * @param data 原始数据
     * @param signature 数据签名
     * @return 签名有效返回true，否则返回false
     */
    virtual bool verify(const std::string& data, const std::string& signature) = 0;
    
    /**
     * 生成密钥对
     * @return 密钥对对象
     */
    virtual key_pair generate_key_pair() = 0;
};
```

## key_pair 类

密钥对类，包含公钥和私钥。

### 头文件
```cpp
#include <security/key_pair.h>
```

### 类定义
```cpp
class key_pair {
private:
    std::string public_key_;
    std::string private_key_;
    
public:
    // 构造函数
    key_pair();
    key_pair(const std::string& public_key, const std::string& private_key);
    
    // Getter方法
    std::string get_public_key() const;
    std::string get_private_key() const;
    
    // Setter方法
    void set_public_key(const std::string& public_key);
    void set_private_key(const std::string& private_key);
    
    // 功能方法
    bool is_valid() const;
};
```

## security_exception 类

安全相关异常类。

### 头文件
```cpp
#include <security/security_exception.h>
```

### 类定义
```cpp
class security_exception : public base_exception {
public:
    explicit security_exception(const std::string& message);
    security_exception(const std::string& message, const std::string& error_code);
};

class encryption_exception : public security_exception {
public:
    explicit encryption_exception(const std::string& message);
};

class decryption_exception : public security_exception {
public:
    explicit decryption_exception(const std::string& message);
};

class signature_exception : public security_exception {
public:
    explicit signature_exception(const std::string& message);
};
```