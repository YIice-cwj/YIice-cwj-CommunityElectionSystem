# 网络通信模块接口文档

## i_web_server 接口

Web服务器接口定义了Web服务器的核心功能。

### 头文件
```cpp
#include <network/i_web_server.h>
```

### 接口定义
```cpp
class i_web_server {
public:
    virtual ~i_web_server() = default;
    
    /**
     * 启动Web服务器
     * @return 启动成功返回true，否则返回false
     */
    virtual bool start() = 0;
    
    /**
     * 停止Web服务器
     * @return 停止成功返回true，否则返回false
     */
    virtual bool stop() = 0;
    
    /**
     * 注册路由处理器
     * @param path 路径
     * @param handler 请求处理器
     */
    virtual void register_route(const std::string& path, request_handler handler) = 0;
    
    /**
     * 获取服务器端口
     * @return 服务器端口
     */
    virtual int get_port() const = 0;
};
```

## http_request 类

HTTP请求类，封装HTTP请求信息。

### 头文件
```cpp
#include <network/http_request.h>
```

### 类定义
```cpp
class http_request {
private:
    std::string method_;
    std::string path_;
    std::map<std::string, std::string> headers_;
    std::map<std::string, std::string> query_params_;
    std::string body_;
    std::string session_id_;
    
public:
    // 构造函数
    http_request(const std::string& method, const std::string& path);
    
    // Getter方法
    std::string get_method() const;
    std::string get_path() const;
    std::map<std::string, std::string> get_headers() const;
    std::map<std::string, std::string> get_query_params() const;
    std::string get_body() const;
    std::string get_session_id() const;
    
    // Setter方法
    void set_header(const std::string& key, const std::string& value);
    void set_query_param(const std::string& key, const std::string& value);
    void set_body(const std::string& body);
    void set_session_id(const std::string& session_id);
    
    // 功能方法
    std::string get_header(const std::string& key) const;
    std::string get_query_param(const std::string& key) const;
    bool has_header(const std::string& key) const;
    bool has_query_param(const std::string& key) const;
};
```

## http_response 类

HTTP响应类，封装HTTP响应信息。

### 头文件
```cpp
#include <network/http_response.h>
```

### 类定义
```cpp
class http_response {
private:
    int status_code_;
    std::map<std::string, std::string> headers_;
    std::string body_;
    
public:
    // 构造函数
    http_response(int status_code = 200);
    
    // Getter方法
    int get_status_code() const;
    std::map<std::string, std::string> get_headers() const;
    std::string get_body() const;
    
    // Setter方法
    void set_status_code(int code);
    void set_header(const std::string& key, const std::string& value);
    void set_body(const std::string& body);
    
    // 功能方法
    void set_json_body(const std::string& json);
    void set_content_type(const std::string& content_type);
};
```

## web_socket_handler 类

WebSocket处理器，处理WebSocket连接和消息。

### 头文件
```cpp
#include <network/web_socket_handler.h>
```

### 类定义
```cpp
class web_socket_handler {
public:
    virtual ~web_socket_handler() = default;
    
    /**
     * 处理新连接
     * @param connection_id 连接ID
     */
    virtual void on_connect(const std::string& connection_id) = 0;
    
    /**
     * 处理断开连接
     * @param connection_id 连接ID
     */
    virtual void on_disconnect(const std::string& connection_id) = 0;
    
    /**
     * 处理收到的消息
     * @param connection_id 连接ID
     * @param message 消息内容
     */
    virtual void on_message(const std::string& connection_id, const std::string& message) = 0;
    
    /**
     * 发送消息到客户端
     * @param connection_id 连接ID
     * @param message 消息内容
     * @return 发送成功返回true，否则返回false
     */
    virtual bool send_message(const std::string& connection_id, const std::string& message) = 0;
    
    /**
     * 广播消息到所有连接
     * @param message 消息内容
     */
    virtual void broadcast_message(const std::string& message) = 0;
};
```

## network_exception 类

网络通信相关异常类。

### 头文件
```cpp
#include <network/network_exception.h>
```

### 类定义
```cpp
class network_exception : public base_exception {
public:
    explicit network_exception(const std::string& message);
    network_exception(const std::string& message, const std::string& error_code);
};

class http_exception : public network_exception {
public:
    explicit http_exception(const std::string& message);
};

class web_socket_exception : public network_exception {
public:
    explicit web_socket_exception(const std::string& message);
};
```