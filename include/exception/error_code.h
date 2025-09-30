#pragma once
#include <string>

/**
 * @brief 错误码
 */
enum error_code_t {
    success = 1000,           // 操作成功
    unknown_error,            // 未知错误
    invalid_parameter,        // 参数无效
    operation_not_supported,  // 操作不支持
    resource_not_found,       // 资源未找到
    resource_already_exists,  // 资源已存在
    internal_error,           // 内部错误
};

/**
 * @brief 错误码转字符串
 * @param error_code 错误码
 * @return 错误码字符串
 */
inline std::string error_code_to_string(error_code_t error_code) {
    switch (error_code) {
        case error_code_t::success:
            return "SUCCESS";
        case error_code_t::unknown_error:
            return "UNKNOWN_ERROR";
        case error_code_t::invalid_parameter:
            return "INVALID_PARAMETER";
        case error_code_t::operation_not_supported:
            return "OPERATION_NOT_SUPPORTED";
        case error_code_t::resource_not_found:
            return "RESOURCE_NOT_FOUND";
        case error_code_t::resource_already_exists:
            return "RESOURCE_ALREADY_EXISTS";
        case error_code_t::internal_error:
            return "INTERNAL_ERROR";
    }
}

/**
 * @brief 错误码转整型
 * @param error_code 错误码
 * @return 错误码整型
 */
inline int error_code_to_int(error_code_t error_code) {
    return static_cast<int>(error_code);
}
