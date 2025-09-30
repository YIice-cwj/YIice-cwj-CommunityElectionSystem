# 投票处理模块接口文档

## i_vote_processor 接口

投票处理器接口定义了投票处理相关的核心功能。

### 头文件
```cpp
#include <vote/i_vote_processor.h>
```

### 接口定义
```cpp
class i_vote_processor {
public:
    virtual ~i_vote_processor() = default;
    
    /**
     * 提交投票
     * @param vote 投票数据
     * @return 投票结果
     */
    virtual vote_result submit_vote(vote_data vote) = 0;
    
    /**
     * 验证投票有效性
     * @param vote 投票数据
     * @return 投票有效返回true，否则返回false
     */
    virtual bool is_valid_vote(vote_data vote) = 0;
    
    /**
     * 获取实时统计数据
     * @param election_id 选举ID
     * @return 投票统计信息
     */
    virtual vote_statistics get_real_time_stats(int election_id) = 0;
    
    /**
     * 检查用户是否已投票
     * @param user_id 用户ID
     * @param election_id 选举ID
     * @return 已投票返回true，否则返回false
     */
    virtual bool has_voted(const std::string& user_id, int election_id) = 0;
};
```

## vote 类

投票实体类，表示一次具体的投票行为。

### 头文件
```cpp
#include <vote/vote.h>
```

### 类定义
```cpp
class vote {
private:
    int vote_id_;
    int election_id_;
    std::string user_id_;
    std::vector<int> candidate_ids_;
    std::chrono::time_point<std::chrono::system_clock> timestamp_;
    std::string signature_;
    
public:
    // 构造函数
    vote(int vote_id, int election_id, const std::string& user_id);
    
    // Getter方法
    int get_vote_id() const;
    int get_election_id() const;
    std::string get_user_id() const;
    std::vector<int> get_candidate_ids() const;
    std::chrono::time_point<std::chrono::system_clock> get_timestamp() const;
    std::string get_signature() const;
    
    // Setter方法
    void set_candidate_ids(const std::vector<int>& candidate_ids);
    void set_timestamp(const std::chrono::time_point<std::chrono::system_clock>& timestamp);
    void set_signature(const std::string& signature);
};
```

## vote_data 类

投票数据类，包含用户提交的原始投票数据。

### 头文件
```cpp
#include <vote/vote_data.h>
```

### 类定义
```cpp
class vote_data {
private:
    int election_id_;
    std::string user_id_;
    std::vector<int> candidate_ids_;
    std::string session_token_;
    std::string digital_signature_;
    
public:
    // 构造函数
    vote_data(int election_id, const std::string& user_id);
    
    // Getter方法
    int get_election_id() const;
    std::string get_user_id() const;
    std::vector<int> get_candidate_ids() const;
    std::string get_session_token() const;
    std::string get_digital_signature() const;
    
    // Setter方法
    void set_candidate_ids(const std::vector<int>& candidate_ids);
    void set_session_token(const std::string& token);
    void set_digital_signature(const std::string& signature);
};
```

## vote_result 类

投票结果类，表示投票操作的结果。

### 头文件
```cpp
#include <vote/vote_result.h>
```

### 类定义
```cpp
class vote_result {
private:
    bool success_;
    std::string message_;
    std::string transaction_id_;
    std::chrono::time_point<std::chrono::system_clock> processed_time_;
    
public:
    // 构造函数
    vote_result(bool success, const std::string& message);
    
    // Getter方法
    bool is_success() const;
    std::string get_message() const;
    std::string get_transaction_id() const;
    std::chrono::time_point<std::chrono::system_clock> get_processed_time() const;
    
    // Setter方法
    void set_transaction_id(const std::string& transaction_id);
    void set_processed_time(const std::chrono::time_point<std::chrono::system_clock>& time);
};
```

## vote_statistics 类

投票统计类，包含选举的统计信息。

### 头文件
```cpp
#include <vote/vote_statistics.h>
```

### 类定义
```cpp
class vote_statistics {
private:
    int election_id_;
    int total_votes_;
    std::map<int, int> candidate_votes_;
    std::chrono::time_point<std::chrono::system_clock> last_updated_;
    
public:
    // 构造函数
    explicit vote_statistics(int election_id);
    
    // Getter方法
    int get_election_id() const;
    int get_total_votes() const;
    std::map<int, int> get_candidate_votes() const;
    std::chrono::time_point<std::chrono::system_clock> get_last_updated() const;
    
    // Setter方法
    void set_total_votes(int votes);
    void set_candidate_votes(const std::map<int, int>& votes);
    void set_last_updated(const std::chrono::time_point<std::chrono::system_clock>& time);
    
    // 功能方法
    double get_percentage(int candidate_id) const;
};
```

## vote_exception 类

投票相关异常类。

### 头文件
```cpp
#include <vote/vote_exception.h>
```

### 类定义
```cpp
class vote_exception : public base_exception {
public:
    explicit vote_exception(const std::string& message);
    vote_exception(const std::string& message, const std::string& error_code);
};

class duplicate_vote_exception : public vote_exception {
public:
    explicit duplicate_vote_exception(const std::string& message);
};

class invalid_vote_exception : public vote_exception {
public:
    explicit invalid_vote_exception(const std::string& message);
};

class voting_closed_exception : public vote_exception {
public:
    explicit voting_closed_exception(const std::string& message);
};
```