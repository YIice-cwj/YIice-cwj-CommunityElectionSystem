#pragma once
#include <exception>
#include <memory>
#include <string>
#include "exception/error_code.h"

/**
 * @brief 异常基类
 */
class base_exception : public std::exception {
   public:
    using cause_t = std::shared_ptr<base_exception>;

   protected:
    std::string message_;  // 错误信息
    cause_t cause_;        // 错误原因
    int error_code_;       // 错误码

   public:
    /**
     * 构造函数
     * @param message 异常消息
     */
    base_exception(const std::string& message);

    /**
     * 构造函数
     * @param message 异常消息
     * @param error_code 错误码
     */
    base_exception(const std::string& message, int error_code);

    /**
     * @brief 构造函数
     * @param message 错误信息
     * @param cause 原始异常
     * @param error_code 错误码
     */
    base_exception(const std::string& message,
                   const cause_t cause,
                   const int error_code);
    /**
     * @brief 析构函数
     */
    virtual ~base_exception() = default;

   public:
    /**
     * @brief 获取错误信息
     * @return 错误信息
     */
    virtual const char* what() const noexcept override;

    /**
     * @brief 获取错误码
     * @return 错误码
     */
    virtual int error_code() const noexcept;

    /**
     * 获取原始异常
     * @return 原始异常
     */
    virtual cause_t get_cause() const;

    /**
     * 设置原始异常
     * @param cause 原始异常
     */
    virtual void set_cause(cause_t cause);
};
