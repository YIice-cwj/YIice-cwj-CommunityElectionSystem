#include "exception/base_exception.h"

/**
 * 构造函数
 * @param message 异常消息
 */
base_exception::base_exception(const std::string& message)
    : message_(message) {}

/**
 * 构造函数
 * @param message 异常消息
 * @param error_code 错误码
 */
base_exception::base_exception(const std::string& message, int error_code)
    : message_(message), error_code_(error_code) {}

/**
 * @brief 构造函数
 * @param message 错误信息
 * @param cause 原始异常
 * @param error_code 错误码
 */
base_exception::base_exception(const std::string& message,
                               const cause_t cause,
                               const int error_code)
    : message_(message), cause_(cause), error_code_(error_code) {}

/**
 * @brief 获取错误信息
 * @return 错误信息
 */
const char* base_exception::what() const noexcept {
    return message_.c_str();
}

/**
 * @brief 获取错误码
 * @return 错误码
 */
int base_exception::error_code() const noexcept {
    return error_code_;
}

/**
 * 获取原始异常
 * @return 原始异常
 */
base_exception::cause_t base_exception::get_cause() const {
    return cause_;
}

/**
 * 设置原始异常
 * @param cause 原始异常
 */
void base_exception::set_cause(cause_t cause) {
    // 防止循环引用
    cause_t current = cause;
    while (current != nullptr) {
        if (current.get() == this) {
            // 如果发现循环引用，不设置cause
            return;
        }
        current = current->get_cause();
    }
    cause_ = cause;
}