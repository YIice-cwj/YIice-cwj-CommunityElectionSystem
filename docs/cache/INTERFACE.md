# 缓存管理模块接口文档

## i_cache_manager 接口

缓存管理器接口定义了缓存管理相关的核心功能。

### 头文件
```cpp
#include <cache/i_cache_manager.h>
```

### 接口定义
```cpp
class i_cache_manager {
public:
    virtual ~i_cache_manager() = default;
    
    /**
     * 存储键值对到缓存
     * @param key 键
     * @param value 值
     * @param ttl_seconds 生存时间（秒），0表示永不过期
     * @return 存储成功返回true，否则返回false
     */
    virtual bool put(const std::string& key, const cache_value& value, int ttl_seconds = 0) = 0;
    
    /**
     * 从缓存中获取值
     * @param key 键
     * @return 缓存值，如果不存在则返回空的optional
     */
    virtual std::optional<cache_value> get(const std::string& key) = 0;
    
    /**
     * 从缓存中移除键值对
     * @param key 键
     * @return 移除成功返回true，否则返回false
     */
    virtual bool remove(const std::string& key) = 0;
    
    /**
     * 清空缓存
     */
    virtual void clear() = 0;
    
    /**
     * 获取缓存大小
     * @return 缓存中键值对的数量
     */
    virtual size_t size() const = 0;
};
```

## cache_value 类

缓存值类，表示缓存中存储的值。

### 头文件
```cpp
#include <cache/cache_value.h>
```

### 类定义
```cpp
class cache_value {
private:
    enum class type {
        string,
        integer,
        double,
        boolean,
        object
    };
    
    type type_;
    std::string string_value_;
    int int_value_;
    double double_value_;
    bool bool_value_;
    std::shared_ptr<void> object_value_;
    
public:
    // 构造函数
    cache_value();
    cache_value(const std::string& value);
    cache_value(int value);
    cache_value(double value);
    cache_value(bool value);
    
    // 类型检查方法
    bool is_string() const;
    bool is_integer() const;
    bool is_double() const;
    bool is_boolean() const;
    bool is_object() const;
    
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
    
    // 对象相关方法
    template<typename T>
    void set_object(std::shared_ptr<T> obj);
    
    template<typename T>
    std::shared_ptr<T> get_object() const;
};
```

## cache_exception 类

缓存相关异常类。

### 头文件
```cpp
#include <cache/cache_exception.h>
```

### 类定义
```cpp
class cache_exception : public base_exception {
public:
    explicit cache_exception(const std::string& message);
    cache_exception(const std::string& message, const std::string& error_code);
};

class cache_full_exception : public cache_exception {
public:
    explicit cache_full_exception(const std::string& message);
};

class cache_key_not_found_exception : public cache_exception {
public:
    explicit cache_key_not_found_exception(const std::string& message);
};
```