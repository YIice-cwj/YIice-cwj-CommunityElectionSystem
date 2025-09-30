# 定时任务模块接口文档

## i_task_scheduler 接口

任务调度器接口定义了任务调度相关的核心功能。

### 头文件
```cpp
#include <scheduler/i_task_scheduler.h>
```

### 接口定义
```cpp
class i_task_scheduler {
public:
    virtual ~i_task_scheduler() = default;
    
    /**
     * 调度任务
     * @param cron_expression Cron表达式
     * @param task 任务函数
     * @return 任务ID
     */
    virtual int schedule_task(const std::string& cron_expression, task_function task) = 0;
    
    /**
     * 取消任务
     * @param task_id 任务ID
     * @return 取消成功返回true，否则返回false
     */
    virtual bool cancel_task(int task_id) = 0;
    
    /**
     * 列出所有任务
     * @return 任务信息列表
     */
    virtual std::vector<task_info> list_tasks() = 0;
    
    /**
     * 启动调度器
     * @return 启动成功返回true，否则返回false
     */
    virtual bool start() = 0;
    
    /**
     * 停止调度器
     * @return 停止成功返回true，否则返回false
     */
    virtual bool stop() = 0;
};
```

## task 类

任务类，表示一个可执行的任务。

### 头文件
```cpp
#include <scheduler/task.h>
```

### 类定义
```cpp
class task {
private:
    int task_id_;
    std::string name_;
    task_function function_;
    int max_retries_;
    int retry_count_;
    
public:
    // 构造函数
    task(int task_id, const std::string& name, task_function function);
    
    // Getter方法
    int get_task_id() const;
    std::string get_name() const;
    int get_max_retries() const;
    int get_retry_count() const;
    
    // Setter方法
    void set_max_retries(int retries);
    
    // 功能方法
    void execute();
    bool should_retry() const;
    void increment_retry_count();
};
```

## cron_expression 类

Cron表达式类，用于解析和匹配Cron表达式。

### 头文件
```cpp
#include <scheduler/cron_expression.h>
```

### 类定义
```cpp
class cron_expression {
private:
    std::string expression_;
    std::vector<int> seconds_;
    std::vector<int> minutes_;
    std::vector<int> hours_;
    std::vector<int> days_of_month_;
    std::vector<int> months_;
    std::vector<int> days_of_week_;
    
public:
    /**
     * 构造函数
     * @param expression Cron表达式字符串
     */
    explicit cron_expression(const std::string& expression);
    
    /**
     * 检查给定时间是否匹配Cron表达式
     * @param time 检查的时间点
     * @return 匹配返回true，否则返回false
     */
    bool is_satisfied_by(const std::chrono::time_point<std::chrono::system_clock>& time) const;
    
    /**
     * 获取表达式字符串
     * @return Cron表达式字符串
     */
    std::string get_expression() const;
    
    /**
     * 获取下次执行时间
     * @param current_time 当前时间
     * @return 下次执行时间
     */
    std::chrono::time_point<std::chrono::system_clock> get_next_valid_time(
        const std::chrono::time_point<std::chrono::system_clock>& current_time) const;
};
```

## scheduler_exception 类

调度相关异常类。

### 头文件
```cpp
#include <scheduler/scheduler_exception.h>
```

### 类定义
```cpp
class scheduler_exception : public base_exception {
public:
    explicit scheduler_exception(const std::string& message);
    scheduler_exception(const std::string& message, const std::string& error_code);
};

class task_execution_exception : public scheduler_exception {
public:
    explicit task_execution_exception(const std::string& message);
};

class cron_expression_exception : public scheduler_exception {
public:
    explicit cron_expression_exception(const std::string& message);
};
```