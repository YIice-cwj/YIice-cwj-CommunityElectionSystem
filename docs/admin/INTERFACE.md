# 系统管理模块接口文档

## i_system_manager 接口

系统管理器接口定义了系统管理相关的核心功能。

### 头文件
```cpp
#include <admin/i_system_manager.h>
```

### 接口定义
```cpp
class i_system_manager {
public:
    virtual ~i_system_manager() = default;
    
    /**
     * 获取系统配置
     * @return 系统配置对象
     */
    virtual system_config get_configuration() = 0;
    
    /**
     * 更新系统配置
     * @param config 新的系统配置
     * @return 更新成功返回true，否则返回false
     */
    virtual bool update_configuration(system_config config) = 0;
    
    /**
     * 备份数据库
     * @param backup_path 备份文件路径
     * @return 备份成功返回true，否则返回false
     */
    virtual bool backup_database(const std::string& backup_path) = 0;
    
    /**
     * 获取系统日志
     * @param filter 日志过滤器
     * @return 日志条目列表
     */
    virtual std::vector<log_entry> get_system_logs(log_filter filter) = 0;
};
```

## system_config 类

系统配置类，包含系统的各项配置参数。

### 头文件
```cpp
#include <admin/system_config.h>
```

### 类定义
```cpp
class system_config {
private:
    std::string environment_;
    int max_connections_;
    std::string log_level_;
    std::string backup_path_;
    std::map<std::string, std::string> custom_settings_;
    
public:
    // 构造函数
    system_config();
    
    // Getter方法
    std::string get_environment() const;
    int get_max_connections() const;
    std::string get_log_level() const;
    std::string get_backup_path() const;
    std::map<std::string, std::string> get_custom_settings() const;
    
    // Setter方法
    void set_environment(const std::string& env);
    void set_max_connections(int max_conn);
    void set_log_level(const std::string& level);
    void set_backup_path(const std::string& path);
    void set_custom_settings(const std::map<std::string, std::string>& settings);
    
    // 功能方法
    void set_custom_setting(const std::string& key, const std::string& value);
    std::string get_custom_setting(const std::string& key) const;
};
```

## log_entry 类

日志条目类，表示一条系统日志记录。

### 头文件
```cpp
#include <admin/log_entry.h>
```

### 类定义
```cpp
class log_entry {
private:
    std::string log_id_;
    std::chrono::time_point<std::chrono::system_clock> timestamp_;
    std::string level_;
    std::string module_;
    std::string message_;
    std::string user_id_;
    
public:
    // 构造函数
    log_entry(const std::string& log_id, const std::string& level, const std::string& message);
    
    // Getter方法
    std::string get_log_id() const;
    std::chrono::time_point<std::chrono::system_clock> get_timestamp() const;
    std::string get_level() const;
    std::string get_module() const;
    std::string get_message() const;
    std::string get_user_id() const;
    
    // Setter方法
    void set_timestamp(const std::chrono::time_point<std::chrono::system_clock>& time);
    void set_module(const std::string& module);
    void set_user_id(const std::string& user_id);
};
```

## admin_exception 类

系统管理相关异常类。

### 头文件
```cpp
#include <admin/admin_exception.h>
```

### 类定义
```cpp
class admin_exception : public base_exception {
public:
    explicit admin_exception(const std::string& message);
    admin_exception(const std::string& message, const std::string& error_code);
};

class config_exception : public admin_exception {
public:
    explicit config_exception(const std::string& message);
};

class backup_exception : public admin_exception {
public:
    explicit backup_exception(const std::string& message);
};
```