# 监控告警模块接口文档

## i_monitoring_service 接口

监控服务接口定义了系统监控相关的核心功能。

### 头文件
```cpp
#include <monitor/i_monitoring_service.h>
```

### 接口定义
```cpp
class i_monitoring_service {
public:
    virtual ~i_monitoring_service() = default;
    
    /**
     * 获取系统指标
     * @return 系统指标数据
     */
    virtual system_metrics get_system_metrics() = 0;
    
    /**
     * 检查系统健康状态
     * @return 健康返回true，否则返回false
     */
    virtual bool is_healthy() = 0;
    
    /**
     * 注册健康检查函数
     * @param check 健康检查函数
     */
    virtual void register_health_check(health_check_function check) = 0;
    
    /**
     * 发送告警消息
     * @param alert 告警消息
     */
    virtual void send_alert(const alert_message& alert) = 0;
    
    /**
     * 启动监控服务
     * @return 启动成功返回true，否则返回false
     */
    virtual bool start() = 0;
    
    /**
     * 停止监控服务
     * @return 停止成功返回true，否则返回false
     */
    virtual bool stop() = 0;
};
```

## system_metrics 类

系统指标类，包含系统的各项性能指标。

### 头文件
```cpp
#include <monitor/system_metrics.h>
```

### 类定义
```cpp
class system_metrics {
private:
    double cpu_usage_;
    size_t memory_usage_;
    size_t disk_usage_;
    size_t network_in_;
    size_t network_out_;
    std::chrono::time_point<std::chrono::system_clock> timestamp_;
    
public:
    // 构造函数
    system_metrics();
    
    // Getter方法
    double get_cpu_usage() const;
    size_t get_memory_usage() const;
    size_t get_disk_usage() const;
    size_t get_network_in() const;
    size_t get_network_out() const;
    std::chrono::time_point<std::chrono::system_clock> get_timestamp() const;
    
    // Setter方法
    void set_cpu_usage(double usage);
    void set_memory_usage(size_t usage);
    void set_disk_usage(size_t usage);
    void set_network_in(size_t bytes);
    void set_network_out(size_t bytes);
    void set_timestamp(const std::chrono::time_point<std::chrono::system_clock>& time);
};
```

## health_check 类

健康检查类，表示一个健康检查项。

### 头文件
```cpp
#include <monitor/health_check.h>
```

### 类定义
```cpp
class health_check {
private:
    std::string name_;
    health_check_function check_function_;
    bool critical_;
    
public:
    /**
     * 构造函数
     * @param name 检查项名称
     * @param check_function 检查函数
     * @param critical 是否为关键检查项
     */
    health_check(const std::string& name, health_check_function check_function, bool critical = false);
    
    // Getter方法
    std::string get_name() const;
    bool is_critical() const;
    
    /**
     * 执行健康检查
     * @return 检查结果
     */
    health_status execute() const;
};
```

## monitor_exception 类

监控相关异常类。

### 头文件
```cpp
#include <monitor/monitor_exception.h>
```

### 类定义
```cpp
class monitor_exception : public base_exception {
public:
    explicit monitor_exception(const std::string& message);
    monitor_exception(const std::string& message, const std::string& error_code);
};

class metrics_collection_exception : public monitor_exception {
public:
    explicit metrics_collection_exception(const std::string& message);
};

class health_check_exception : public monitor_exception {
public:
    explicit health_check_exception(const std::string& message);
};
```