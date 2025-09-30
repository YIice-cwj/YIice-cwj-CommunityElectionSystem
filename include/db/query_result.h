#pragma once
#include "interface_query_result.h"

/**
 * @brief 查询结果类
 * @details 封装查询结果的具体实现
 */
class query_result : public interface_query_result {
   public:
    /**
     * @brief 构造函数
     * @param reserve_count 预留的行数空间
     */
    query_result(std::size_t reserve_count = 1024);

    /**
     * @brief 析构函数
     */
    ~query_result() = default;

   public:
    /**
     * @brief 获取指定行数据
     * @param index 行索引
     * @return 行数据
     */
    std::optional<interface_query_result::row_t> operator[](std::size_t index);

   public:
    /**
     * @brief 添加一行数据
     * @param row 行数据
     */
    void add_row(const row_t& row);

    /**
     * @brief 获取行数
     * @return 行数
     */
    std::size_t get_row_count() const override;

    /**
     * @brief 获取列数
     * @return 列数
     */
    std::size_t get_column_count() const override;

    /**
     * @brief 获取所有列名
     * @return 列名列表
     */
    std::optional<std::vector<std::string>> get_column_names() const override;

    /**
     * @brief 获取指定行的数据
     * @param index 行索引
     * @return 行数据
     */
    std::optional<row_t> get_row(std::size_t index) const override;

    /**
     * @brief 获取当前行指定列的数据
     * @param column_name 列名
     * @return 列数据
     */
    std::optional<std::string> get_value(
        const std::string& column_name) const override;

    /**
     * @brief 移动到下一行
     * @return 是否成功
     */
    bool next() override;

    /**
     * @brief 重置查询结果到第一行
     */
    bool reset() override;

    /**
     * @brief 检查是否还有下一行
     * @return 是否有下一行
     */
    bool has_next() const override;
};