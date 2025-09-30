#pragma once
#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <vector>

/**
 * @brief 数据库查询结果接口
 * @details 定义数据库查询结果的操作接口
 */
class interface_query_result {
   public:
    using row_t = std::map<std::string, std::string>;  // 单行数据
    using rows_t = std::vector<row_t>;                 // 多行数据

   protected:
    rows_t rows;              // 存储查询结果
    std::size_t current_row;  // 当前行索引

   public:
    /**
     * @brief 构造函数
     */
    interface_query_result() : current_row(0) {}

    /**
     * @brief 析构函数
     */
    virtual ~interface_query_result() = default;

   public:
    /**
     * @brief 获取指定行数据
     * @param index 行索引
     * @return 行数据
     */
    virtual std::optional<row_t> operator[](int index) = 0;

   public:
    /**
     * @brief 添加行数据
     * @param row 行数据
     */
    virtual void add_row(const row_t& row) = 0;

    /**
     * @brief 获取行数
     * @return 行数
     */
    virtual std::size_t get_row_count() const = 0;

    /**
     * @brief 获取列数
     * @return 列数
     */
    virtual std::size_t get_column_count() const = 0;

    /**
     * @brief 获取所有列名
     * @return 列名列表
     */
    virtual std::optional<std::vector<std::string>> get_column_names()
        const = 0;

    /**
     * @brief 获取指定行的数据
     * @param index 行索引
     * @return 行数据
     */
    virtual std::optional<row_t> get_row(std::size_t index) const = 0;

    /**
     * @brief 获取当前行指定列的数据
     * @param column_name 列名
     * @return 列数据
     */
    virtual std::optional<std::string> get_value(
        const std::string& column_name) const = 0;

    /**
     * @brief 移动到下一行
     * @return 是否成功
     */
    virtual bool next() = 0;

    /**
     * @brief 重置查询结果到第一行
     */
    virtual bool reset() = 0;

    /**
     * @brief 检查是否还有下一行
     * @return 是否有下一行
     */
    virtual bool has_next() const = 0;
};