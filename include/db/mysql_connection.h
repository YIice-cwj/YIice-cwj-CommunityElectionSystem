#pragma once
#include <mysql/mysql.h>
#include "db/interface_database_connection.h"
#include "db/query_result.h"

/**
 * @brief mysql 数据库连接
 */
class mysql_connection : public interface_database_connection {
   private:
    std::shared_ptr<MYSQL> connection_;  // 数据库连接
    std::string host_;                   // 数据库主机
    std::string user_;                   // 数据库用户
    std::string password_;               // 密码
    std::string database_;               // 数据库名称
    std::string port_;                   // 端口
   public:
    /**
     * 构造函数
     * @param host 数据库主机
     * @param user 数据库用户
     * @param password 密码
     * @param database 数据库名称
     * @param port 端口
     */
    mysql_connection(std::string host,
                     std::string user,
                     std::string password,
                     std::string database,
                     std::string port);

    /**
     * @brief 析构函数
     */
    ~mysql_connection() = default;

   public:
    /**
     * 建立数据库连接
     * @return 连接成功返回true，否则返回false
     */
    bool connect();

    /**
     * 断开数据库连接
     * @return 断开成功返回true，否则返回false
     */
    bool disconnect();

    /**
     * 执行查询语句
     * @param sql SQL查询语句
     * @return 查询结果
     */
    interface_database_connection::query_result_ptr execute_query(
        const std::string& sql);

    /**
     * 执行更新语句
     * @param sql SQL更新语句
     * @return 执行成功返回true，否则返回false
     */
    bool execute_update(const std::string& sql);

    /**
     * 检查连接是否有效
     * @return 连接有效返回true，否则返回false
     */
    bool is_valid() const;
};