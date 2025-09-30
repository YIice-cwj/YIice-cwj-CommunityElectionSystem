#include "exception/database_exception.h"

/**
 * @brief 构造函数
 * @param error_code 错误码
 */
database_exception::database_exception(database_error_code_t error_code)
    : base_exception(error_code_to_string(error_code),
                     error_code_to_int(error_code)) {}

/**
 * @brief 构造函数
 * @param message 错误信息
 * @param cause 错误原因
 * @param error_code 错误码
 */
database_exception::database_exception(const std::string& message,
                                       const base_exception::cause_t cause,
                                       database_error_code_t error_code)
    : base_exception(message, cause, error_code_to_int(error_code)) {}