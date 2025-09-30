#pragma once
#include <string>

/**
 * @brief 数据库错误码
 */
enum class database_error_code_t {
    // 数据库连接相关错误 (5000-5099)
    db_connection_failed = 5000,   // 数据库连接失败
    db_connection_lost,            // 数据库连接丢失
    db_connection_timeout,         // 数据库连接超时
    db_authentication_failed,      // 数据库认证失败
    db_invalid_connection_string,  // 无效的连接字符串

    // 数据库查询相关错误 (5100-5199)
    db_query_failed = 5100,     // 数据库查询失败
    db_query_timeout,           // 数据库查询超时
    db_invalid_query,           // 无效的查询语句
    db_query_result_truncated,  // 查询结果被截断
    db_no_result_found,         // 未找到查询结果

    // 数据库事务相关错误 (5200-5299)
    db_transaction_failed = 5200,  // 数据库事务失败
    db_transaction_rollback,       // 数据库事务回滚
    db_transaction_timeout,        // 数据库事务超时
    db_deadlock_detected,          // 检测到死锁
    db_lock_timeout,               // 锁超时

    // 数据库对象相关错误 (5300-5399)
    db_table_not_found = 5300,  // 表未找到
    db_column_not_found,        // 列未找到
    db_constraint_violation,    // 约束违反
    db_duplicate_key,           // 重复键值
    db_foreign_key_violation,   // 外键约束违反

    // 数据库配置相关错误 (5400-5499)
    db_config_error = 5400,  // 数据库配置错误
    db_unsupported_feature,  // 不支持的功能
    db_driver_not_found,     // 数据库驱动未找到
    db_version_mismatch,     // 数据库版本不匹配

    // 数据库资源相关错误 (5500-5599)
    db_out_of_memory = 5500,      // 数据库内存不足
    db_disk_full,                 // 磁盘空间不足
    db_max_connections_exceeded,  // 超过最大连接数
    db_resource_limit_exceeded    // 资源限制超出
};

/**
 * @brief 数据库错误码转字符串
 * @param error_code 数据库错误码
 * @return 错误码字符串
 */
inline std::string error_code_to_string(database_error_code_t error_code) {
    switch (error_code) {
        case database_error_code_t::db_connection_failed:
            return "DB_CONNECTION_FAILED";
        case database_error_code_t::db_connection_lost:
            return "DB_CONNECTION_LOST";
        case database_error_code_t::db_connection_timeout:
            return "DB_CONNECTION_TIMEOUT";
        case database_error_code_t::db_authentication_failed:
            return "DB_AUTHENTICATION_FAILED";
        case database_error_code_t::db_invalid_connection_string:
            return "DB_INVALID_CONNECTION_STRING";
        case database_error_code_t::db_query_failed:
            return "DB_QUERY_FAILED";
        case database_error_code_t::db_query_timeout:
            return "DB_QUERY_TIMEOUT";
        case database_error_code_t::db_invalid_query:
            return "DB_INVALID_QUERY";
        case database_error_code_t::db_query_result_truncated:
            return "DB_QUERY_RESULT_TRUNCATED";
        case database_error_code_t::db_no_result_found:
            return "DB_NO_RESULT_FOUND";
        case database_error_code_t::db_transaction_failed:
            return "DB_TRANSACTION_FAILED";
        case database_error_code_t::db_transaction_rollback:
            return "DB_TRANSACTION_ROLLBACK";
        case database_error_code_t::db_transaction_timeout:
            return "DB_TRANSACTION_TIMEOUT";
        case database_error_code_t::db_deadlock_detected:
            return "DB_DEADLOCK_DETECTED";
        case database_error_code_t::db_lock_timeout:
            return "DB_LOCK_TIMEOUT";
        case database_error_code_t::db_table_not_found:
            return "DB_TABLE_NOT_FOUND";
        case database_error_code_t::db_column_not_found:
            return "DB_COLUMN_NOT_FOUND";
        case database_error_code_t::db_constraint_violation:
            return "DB_CONSTRAINT_VIOLATION";
        case database_error_code_t::db_duplicate_key:
            return "DB_DUPLICATE_KEY";
        case database_error_code_t::db_foreign_key_violation:
            return "DB_FOREIGN_KEY_VIOLATION";
        case database_error_code_t::db_config_error:
            return "DB_CONFIG_ERROR";
        case database_error_code_t::db_unsupported_feature:
            return "DB_UNSUPPORTED_FEATURE";
        case database_error_code_t::db_driver_not_found:
            return "DB_DRIVER_NOT_FOUND";
        case database_error_code_t::db_version_mismatch:
            return "DB_VERSION_MISMATCH";
        case database_error_code_t::db_out_of_memory:
            return "DB_OUT_OF_MEMORY";
        case database_error_code_t::db_disk_full:
            return "DB_DISK_FULL";
        case database_error_code_t::db_max_connections_exceeded:
            return "DB_MAX_CONNECTIONS_EXCEEDED";
        case database_error_code_t::db_resource_limit_exceeded:
            return "DB_RESOURCE_LIMIT_EXCEEDED";
        default:
            return "UNKNOWN_DATABASE_ERROR";
    }
}

/**
 * @brief 数据库错误码转整型
 * @param error_code 数据库错误码
 * @return 错误码整型值
 */
inline int error_code_to_int(database_error_code_t error_code) {
    return static_cast<int>(error_code);
}