# 数据库交互模块接口文档

## i_database_connection 接口

数据库连接接口定义了数据库连接的基本操作。

### 头文件

```cpp
#include <db/i_database_connection.h>
```

### 接口定义

```cpp
class i_database_connection {
public:
    virtual ~i_database_connection() = default;

    /**
     * 建立数据库连接
     * @return 连接成功返回true，否则返回false
     */
    virtual bool connect() = 0;

    /**
     * 断开数据库连接
     * @return 断开成功返回true，否则返回false
     */
    virtual bool disconnect() = 0;

    /**
     * 执行查询语句
     * @param sql SQL查询语句
     * @return 查询结果
     */
    virtual i_query_result execute_query(const std::string& sql) = 0;

    /**
     * 执行更新语句
     * @param sql SQL更新语句
     * @return 执行成功返回true，否则返回false
     */
    virtual bool execute_update(const std::string& sql) = 0;

    /**
     * 检查连接是否有效
     * @return 连接有效返回true，否则返回false
     */
    virtual bool is_valid() const = 0;
};
```

## i_connection_pool 接口

连接池接口定义了数据库连接池的管理功能。

### 头文件

```cpp
#include <db/i_connection_pool.h>
```

### 接口定义

```cpp
class i_connection_pool {
public:
    virtual ~i_connection_pool() = default;

    /**
     * 获取数据库连接
     * @return 数据库连接对象
     */
    virtual std::shared_ptr<i_database_connection> acquire_connection() = 0;

    /**
     * 释放数据库连接
     * @param conn 数据库连接对象
     */
    virtual void release_connection(std::shared_ptr<i_database_connection> conn) = 0;

    /**
     * 获取连接池大小
     * @return 连接池中连接的数量
     */
    virtual size_t get_pool_size() const = 0;

    /**
     * 获取可用连接数
     * @return 可用连接的数量
     */
    virtual size_t get_available_connections() const = 0;
};
```

## i_query_result 接口

查询结果接口，用于存储和操作数据库查询结果。

### 头文件

```cpp
#include <db/i_query_result.h>
```

### 接口定义

```cpp
class i_query_result {
public:
    virtual ~i_query_result() = default;

    /**
     * 获取行数
     * @return 行数
     */
    virtual size_t get_row_count() const = 0;

    /**
     * 获取列数
     * @return 列数
     */
    virtual size_t get_column_count() const = 0;

    /**
     * 检查是否还有下一行
     * @return 有下一行返回true，否则返回false
     */
    virtual bool has_next() const = 0;

    /**
     * 移动到下一行
     * @return 移动成功返回true，否则返回false
     */
    virtual bool next() = 0;

    /**
     * 获取当前行指定列的值
     * @param column_name 列名
     * @return 列值，如果列不存在返回空
     */
    virtual std::optional<std::string> get_value(const std::string& column_name) const = 0;

    /**
     * 重置游标到第一行
     */
    virtual void reset() = 0;
};
```

## query_result 类

查询结果实现类，实现了 i_query_result 接口。

### 头文件

```cpp
#include <db/query_result.h>
```

### 类定义

```cpp
class query_result : public i_query_result {
private:
    std::vector<std::map<std::string, std::string>> rows_;
    size_t current_row_;

public:
    /**
     * 构造函数
     */
    query_result();

    /**
     * 添加一行数据
     * @param row 行数据
     */
    void add_row(const std::map<std::string, std::string>& row);

    /**
     * 获取行数
     * @return 行数
     */
    size_t get_row_count() const override;

    /**
     * 获取列数
     * @return 列数
     */
    size_t get_column_count() const override;

    /**
     * 检查是否还有下一行
     * @return 有下一行返回true，否则返回false
     */
    bool has_next() const override;

    /**
     * 移动到下一行
     * @return 移动成功返回true，否则返回false
     */
    bool next() override;

    /**
     * 获取当前行指定列的值
     * @param column_name 列名
     * @return 列值，如果列不存在返回空
     */
    std::optional<std::string> get_value(const std::string& column_name) const override;

    /**
     * 重置游标到第一行
     */
    void reset() override;
};
```

## i_ormapper 接口

ORM 映射器接口定义了对象关系映射功能。

### 头文件

```cpp
#include <db/i_ormapper.h>
```

### 接口定义

```cpp
class i_ormapper {
public:
    virtual ~i_ormapper() = default;

    /**
     * 插入对象到数据库
     * @param obj 要插入的对象
     * @return 插入成功返回true，否则返回false
     */
    virtual bool insert(const persistent_object& obj) = 0;

    /**
     * 根据ID查询对象
     * @param id 对象ID
     * @return 查询到的对象
     */
    virtual persistent_object find_by_id(int id) = 0;

    /**
     * 更新数据库中的对象
     * @param obj 要更新的对象
     * @return 更新成功返回true，否则返回false
     */
    virtual bool update(const persistent_object& obj) = 0;

    /**
     * 从数据库中删除对象
     * @param id 对象ID
     * @return 删除成功返回true，否则返回false
     */
    virtual bool remove(int id) = 0;
};
```

## transaction 类

事务管理类，提供事务操作功能。

### 头文件

```cpp
#include <db/transaction.h>
```

### 类定义

```cpp
class transaction {
private:
    std::shared_ptr<i_database_connection> connection_;
    bool is_active_;

public:
    /**
     * 构造函数
     * @param conn 数据库连接
     */
    explicit transaction(std::shared_ptr<i_database_connection> conn);

    /**
     * 开始事务
     * @return 启动成功返回true，否则返回false
     */
    bool begin();

    /**
     * 提交事务
     * @return 提交成功返回true，否则返回false
     */
    bool commit();

    /**
     * 回滚事务
     * @return 回滚成功返回true，否则返回false
     */
    bool rollback();

    /**
     * 检查事务是否活跃
     * @return 事务活跃返回true，否则返回false
     */
    bool is_active() const;
};
```

## database_exception 类

数据库相关异常类。

### 头文件

```cpp
#include <db/database_exception.h>
```

### 类定义

```cpp
class database_exception : public base_exception {
public:
    explicit database_exception(const std::string& message);
    database_exception(const std::string& message, const std::string& error_code);
};

class connection_exception : public database_exception {
public:
    explicit connection_exception(const std::string& message);
};

class query_exception : public database_exception {
public:
    explicit query_exception(const std::string& message);
};

class transaction_exception : public database_exception {
public:
    explicit transaction_exception(const std::string& message);
};
```
