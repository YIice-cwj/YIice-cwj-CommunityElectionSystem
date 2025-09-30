#pragma once
#include "exception/base_exception.h"
#include "exception/database_error_code.h"

/**
 * @brief 数据库异常
 */
class database_exception : public base_exception {
   public:
    /**
     * @brief 构造函数
     * @param error_code 错误码
     */
    database_exception(database_error_code_t error_code);

    /**
     * @brief 构造函数
     * @param message 错误信息
     * @param cause 错误原因
     * @param error_code 错误码
     */
    database_exception(const std::string& message,
                       const base_exception::cause_t,
                       database_error_code_t error_code);

    /**
     * @brief 析构函数
     */
    virtual ~database_exception() = default;
};