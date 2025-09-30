# 配置管理模块接口文档

## i_config_manager 接口

配置管理器接口定义了配置管理相关的核心功能。

### 头文件
```cpp
#include <config/i_config_manager.h>
```

### 接口定义
```cpp
class i_config_manager {
public:
    virtual ~i_config_manager() = default;
    
    /**
     * 获取配置值
     * @param key 配置键
     * @return 配置值
     */
    virtual config_value get_value(const std::string& key) = 0;
    
    /**
     * 设置配置值
     * @param key 配置键
     * @param value 配置值
     * @return 设置成功返回true，否则返回false
     */
    virtual bool set_value(const std::string& key, const config_value& value) = 0;
    
    /**
     * 从文件加载配置
     * @param filepath 配置文件路径
     * @return 加载成功返回true，否则返回false
     */
    virtual bool load_from_file(const std::string& filepath) = 0;
    
    /**
     * 重新加载配置
     * @return 重新加载成功返回true，否则返回false
     */
    virtual bool reload() = 0;
    
    /**
     * 获取当前环境
     * @return 环境名称
     */
    virtual std::string get_current_environment() const = 0;
};
```

## config_value 类

配置值类，表示一个配置项的值。

### 头文件
```cpp
#include <config/config_value.h>
```

### 类定义
```cpp
class config_value {
private:
    enum class type {
        string,
        integer,
        double,
        boolean
    };
    
    type type_;
    std::string string_value_;
    int int_value_;
    double double_value_;
    bool bool_value_;
    
public:
    // 构造函数
    config_value();
    config_value(const std::string& value);
    config_value(int value);
    config_value(double value);
    config_value(bool value);
    
    // 类型检查方法
    bool is_string() const;
    bool is_integer() const;
    bool is_double() const;
    bool is_boolean() const;
    
    // 值获取方法
    std::string as_string() const;
    int as_integer() const;
    double as_double() const;
    bool as_boolean() const;
    
    // 值设置方法
    void set_string(const std::string& value);
    void set_integer(int value);
    void set_double(double value);
    void set_boolean(bool value);
};
```

## config_exception 类

配置相关异常类。

### 头文件
```cpp
#include <config/config_exception.h>
```

### 类定义
```cpp
class config_exception : public base_exception {
public:
    explicit config_exception(const std::string& message);
    config_exception(const std::string& message, const std::string& error_code);
};

class config_not_found_exception : public config_exception {
public:
    explicit config_not_found_exception(const std::string& message);
};

class config_load_exception : public config_exception {
public:
    explicit config_load_exception(const std::string& message);
};
```