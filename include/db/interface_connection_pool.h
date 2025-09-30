#pragma once
#include <memory>
#include "interface_database_connection.h"

/**
 * @brief 连接池接口
 * @details 创建连接池，管理连接，提供连接
 */
class interface_connection_pool {
   public:
    /**
     * @brief 析构函数
     */
    virtual ~interface_connection_pool() = default;

    /**
     * @brief 获取数据库连接
     * @return 数据库连接对象
     */
    virtual std::shared_ptr<interface_database_connection>
    acquire_connection() = 0;

    /**
     * @brief 释放数据库连接
     * @param connection 数据库连接对象
     */
    virtual void release_connection(
        std::shared_ptr<interface_database_connection> connection) = 0;

    /**
     * @brief 获取数据库连接数量
     * @return 数据库连接数量
     */
    virtual std::size_t get_connection_count() = 0;

    /**
     * @brief 获取可以用连接数
     * @return 可以用连接数
     */
    virtual std::size_t get_available_connection_count() = 0;
};