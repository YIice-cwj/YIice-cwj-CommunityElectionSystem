# 选举管理模块接口文档

## i_election_manager 接口

选举管理器接口定义了选举管理相关的核心功能。

### 头文件
```cpp
#include <election/i_election_manager.h>
```

### 接口定义
```cpp
class i_election_manager {
public:
    virtual ~i_election_manager() = default;
    
    /**
     * 创建选举
     * @param config 选举配置
     * @return 创建的选举对象
     */
    virtual election create_election(election_config config) = 0;
    
    /**
     * 更新选举
     * @param election_id 选举ID
     * @param config 新的选举配置
     * @return 更新成功返回true，否则返回false
     */
    virtual bool update_election(int election_id, election_config config) = 0;
    
    /**
     * 取消选举
     * @param election_id 选举ID
     * @return 取消成功返回true，否则返回false
     */
    virtual bool cancel_election(int election_id) = 0;
    
    /**
     * 获取选举信息
     * @param election_id 选举ID
     * @return 选举对象
     */
    virtual election get_election(int election_id) = 0;
    
    /**
     * 列出符合条件的选举
     * @param filter 选举过滤器
     * @return 选举列表
     */
    virtual std::vector<election> list_elections(election_filter filter) = 0;
};
```

## election 类

选举实体类，表示一个选举活动。

### 头文件
```cpp
#include <election/election.h>
```

### 类定义
```cpp
class election {
private:
    int election_id_;
    std::string title_;
    std::string description_;
    std::chrono::time_point<std::chrono::system_clock> start_time_;
    std::chrono::time_point<std::chrono::system_clock> end_time_;
    election_status status_;
    election_config config_;
    
public:
    // 构造函数
    election(int election_id, const std::string& title);
    
    // Getter方法
    int get_election_id() const;
    std::string get_title() const;
    std::string get_description() const;
    std::chrono::time_point<std::chrono::system_clock> get_start_time() const;
    std::chrono::time_point<std::chrono::system_clock> get_end_time() const;
    election_status get_status() const;
    election_config get_config() const;
    
    // Setter方法
    void set_description(const std::string& description);
    void set_start_time(const std::chrono::time_point<std::chrono::system_clock>& start_time);
    void set_end_time(const std::chrono::time_point<std::chrono::system_clock>& end_time);
    void set_status(election_status status);
    void set_config(const election_config& config);
};
```

## candidate 类

候选人实体类，表示选举中的候选人。

### 头文件
```cpp
#include <election/candidate.h>
```

### 类定义
```cpp
class candidate {
private:
    int candidate_id_;
    int election_id_;
    std::string name_;
    std::string biography_;
    std::string platform_;
    bool is_active_;
    
public:
    // 构造函数
    candidate(int candidate_id, int election_id, const std::string& name);
    
    // Getter方法
    int get_candidate_id() const;
    int get_election_id() const;
    std::string get_name() const;
    std::string get_biography() const;
    std::string get_platform() const;
    bool get_is_active() const;
    
    // Setter方法
    void set_biography(const std::string& biography);
    void set_platform(const std::string& platform);
    void set_is_active(bool is_active);
};
```

## election_config 类

选举配置类，包含选举的各种配置参数。

### 头文件
```cpp
#include <election/election_config.h>
```

### 类定义
```cpp
class election_config {
private:
    int max_votes_per_user_;
    bool allow_multiple_selections_;
    bool require_login_;
    std::vector<std::string> allowed_roles_;
    
public:
    // 构造函数
    election_config();
    
    // Getter方法
    int get_max_votes_per_user() const;
    bool get_allow_multiple_selections() const;
    bool get_require_login() const;
    std::vector<std::string> get_allowed_roles() const;
    
    // Setter方法
    void set_max_votes_per_user(int max_votes);
    void set_allow_multiple_selections(bool allow);
    void set_require_login(bool required);
    void set_allowed_roles(const std::vector<std::string>& roles);
};
```

## election_exception 类

选举相关异常类。

### 头文件
```cpp
#include <election/election_exception.h>
```

### 类定义
```cpp
class election_exception : public base_exception {
public:
    explicit election_exception(const std::string& message);
    election_exception(const std::string& message, const std::string& error_code);
};

class election_not_found_exception : public election_exception {
public:
    explicit election_not_found_exception(const std::string& message);
};

class election_not_active_exception : public election_exception {
public:
    explicit election_not_active_exception(const std::string& message);
};
```