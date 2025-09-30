#include "db/mysql_connection.h"

/**
 * 构造函数
 * @param host 数据库主机
 * @param user 数据库用户
 * @param password 密码
 * @param database 数据库名称
 * @param port 端口
 */
mysql_connection::mysql_connection(std::string host,
                                   std::string user,
                                   std::string password,
                                   std::string database,
                                   std::string port)
    : host_(std::move(host)),
      user_(std::move(user)),
      password_(std::move(password)),
      database_(std::move(database)),
      port_(std::move(port)) {}

/**
 * 建立数据库连接
 * @return 连接成功返回true，否则返回false
 */
/**
 * 建立数据库连接
 * @return 连接成功返回true，否则返回false
 */
bool mysql_connection::connect() {
    // 如果已经连接，则返回true
    if (connection_) {
        return true;
    }

    // 初始化MYSQL对象
    connection_ = std::shared_ptr<MYSQL>(mysql_init(nullptr), mysql_close);
    if (!connection_) {
        return false;
    }

    // 设置连接超时时间
    mysql_options(connection_.get(), MYSQL_OPT_CONNECT_TIMEOUT, "30");

    // 连接数据库
    if (!mysql_real_connect(connection_.get(), host_.c_str(), user_.c_str(),
                            password_.c_str(), database_.c_str(),
                            std::stoi(port_), nullptr, 0)) {
        // 失败，重置连接对象
        connection_.reset();
        return false;
    }

    // 设置字符集
    mysql_set_character_set(connection_.get(), "utf8mb4");

    return true;
}

/**
 * 断开数据库连接
 * @return 断开成功返回true，否则返回false
 */
bool mysql_connection::disconnect() {
    connection_.reset();
    return connection_ == nullptr;
}

/**
 * 执行查询语句
 * @param sql SQL查询语句
 * @return 查询结果
 */
interface_database_connection::query_result_ptr mysql_connection::execute_query(
    const std::string& sql) {
    if (!is_valid()) {
    }
}

/**
 * 执行更新语句
 * @param sql SQL更新语句
 * @return 执行成功返回true，否则返回false
 */
bool mysql_connection::execute_update(const std::string& sql) {}

/**
 * 检查连接是否有效
 * @return 连接有效返回true，否则返回false
 */
bool mysql_connection::is_valid() const {
    return connection_ && mysql_ping(connection_.get()) == 0;
}