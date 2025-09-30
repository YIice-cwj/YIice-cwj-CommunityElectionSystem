#include "db/query_result.h"

/**
 * @brief 构造函数
 * @param reserve_count 预留的行数空间
 */
query_result::query_result(std::size_t reserve_count) {
    this->current_row = 0;
    this->rows.reserve(reserve_count);
}

/**
 * @brief 获取指定行数据
 * @param index 行索引
 * @return 行数据
 */
std::optional<interface_query_result::row_t> query_result::operator[](
    std::size_t index) {
    if (index >= this->rows.size()) {
        return std::nullopt;
    }
    return this->rows[index];
}

/**
 * @brief 添加一行数据
 * @param row 行数据
 */
void query_result::add_row(const row_t& row) {
    this->rows.push_back(row);
}

/**
 * @brief 获取行数
 * @return 行数
 */
std::size_t query_result::get_row_count() const {
    return this->rows.size();
}

/**
 * @brief 获取列数
 * @return 列数
 */
std::size_t query_result::get_column_count() const {
    if (this->rows.empty()) {
        return 0;
    }
    return this->rows.front().size();
}

/**
 * @brief 获取所有列名
 * @return 列名列表
 */
std::optional<std::vector<std::string>> query_result::get_column_names() const {
    if (this->rows.empty())
        return std::nullopt;

    std::vector<std::string> column_names;
    if (!this->rows.empty()) {
        for (const auto& pair : this->rows.front()) {
            column_names.push_back(pair.first);
        }
    }
    return std::make_optional(column_names);
}

/**
 * @brief 获取指定行的数据
 * @param index 行索引
 * @return 行数据
 */
std::optional<interface_query_result::row_t> query_result::get_row(
    std::size_t index) const {
    if (index >= this->rows.size()) {
        return std::nullopt;
    }
    return std::make_optional(this->rows[index]);
}

/**
 * @brief 获取当前行指定列的数据
 * @param column_name 列名
 * * @return 列数据
 */
std::optional<std::string> query_result::get_value(
    const std::string& column_name) const {
    if (this->current_row >= this->rows.size()) {
        return std::nullopt;
    }

    const auto& row = this->rows[this->current_row];
    auto it = row.find(column_name);
    if (it != row.end()) {
        return std::make_optional(it->second);
    }
    return std::nullopt;
}

/**
 * @brief 移动到下一行
 * @return 是否成功
 */
bool query_result::next() {
    if (!has_next())
        return false;
    current_row++;
    return true;
}

/**
 * @brief 重置查询结果到第一行
 */
bool query_result::reset() {
    this->current_row = 0;
    return true;
}

/**
 * @brief 检查是否还有下一行
 * @return 是否有下一行
 */
bool query_result::has_next() const {
    return (this->current_row + 1) < this->rows.size();
}