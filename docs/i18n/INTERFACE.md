# 国际化支持模块接口文档

## i_localization_manager 接口

本地化管理器接口定义了国际化相关的核心功能。

### 头文件
```cpp
#include <i18n/i_localization_manager.h>
```

### 接口定义
```cpp
class i_localization_manager {
public:
    virtual ~i_localization_manager() = default;
    
    /**
     * 获取本地化文本
     * @param key 文本键
     * @param locale 本地化设置
     * @return 本地化文本
     */
    virtual std::string get_text(const std::string& key, const std::string& locale) = 0;
    
    /**
     * 设置当前本地化设置
     * @param locale 本地化设置
     * @return 设置成功返回true，否则返回false
     */
    virtual bool set_current_locale(const std::string& locale) = 0;
    
    /**
     * 获取当前本地化设置
     * @return 当前本地化设置
     */
    virtual std::string get_current_locale() = 0;
    
    /**
     * 格式化本地化消息
     * @param key 消息键
     * @param locale 本地化设置
     * @param params 参数列表
     * @return 格式化后的消息
     */
    virtual std::string format_message(const std::string& key, const std::string& locale,
                                    const std::vector<std::string>& params) = 0;
};
```

## locale 类

本地化类，表示一种语言和区域设置。

### 头文件
```cpp
#include <i18n/locale.h>
```

### 类定义
```cpp
class locale {
private:
    std::string language_;
    std::string country_;
    std::string variant_;
    
public:
    /**
     * 构造函数
     * @param language 语言代码（如"zh"）
     * @param country 国家代码（如"CN"）
     * @param variant 变体代码（可选）
     */
    locale(const std::string& language, const std::string& country = "", 
           const std::string& variant = "");
    
    /**
     * 从字符串解析本地化设置
     * @param locale_str 本地化字符串（如"zh-CN"）
     * @return locale对象
     */
    static locale parse(const std::string& locale_str);
    
    // Getter方法
    std::string get_language() const;
    std::string get_country() const;
    std::string get_variant() const;
    
    /**
     * 转换为字符串表示
     * @return 本地化字符串表示
     */
    std::string to_string() const;
    
    /**
     * 检查是否相等
     * @param other 另一个locale对象
     * @return 相等返回true，否则返回false
     */
    bool operator==(const locale& other) const;
};
```

## i18n_exception 类

国际化相关异常类。

### 头文件
```cpp
#include <i18n/i18n_exception.h>
```

### 类定义
```cpp
class i18n_exception : public base_exception {
public:
    explicit i18n_exception(const std::string& message);
    i18n_exception(const std::string& message, const std::string& error_code);
};

class resource_bundle_exception : public i18n_exception {
public:
    explicit resource_bundle_exception(const std::string& message);
};

class locale_not_supported_exception : public i18n_exception {
public:
    explicit locale_not_supported_exception(const std::string& message);
};
```