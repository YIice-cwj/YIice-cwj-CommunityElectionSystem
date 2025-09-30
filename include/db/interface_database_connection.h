#pragma once
#include <memory>
#include "interface_query_result.h"

/**
 * @brief 数据库连接接口
 * @details 所有数据库连接接口， 都继承自此接口
 */
class interface_database_connection {
   public:
    using query_result_ptr = std::shared_ptr<interface_query_result>;

   public:
    virtual ~interface_database_connection() = default;

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
    virtual query_result_ptr execute_query(const std::string& sql) = 0;

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