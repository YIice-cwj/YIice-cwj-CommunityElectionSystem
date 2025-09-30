# 报表生成模块接口文档

## i_report_generator 接口

报表生成器接口定义了报表生成相关的核心功能。

### 头文件
```cpp
#include <report/i_report_generator.h>
```

### 接口定义
```cpp
class i_report_generator {
public:
    virtual ~i_report_generator() = default;
    
    /**
     * 生成选举报告
     * @param election_id 选举ID
     * @return 报表数据
     */
    virtual report_data generate_election_report(int election_id) = 0;
    
    /**
     * 生成统计图表
     * @param election_id 选举ID
     * @return 图表数据列表
     */
    virtual std::vector<chart_data> generate_statistical_charts(int election_id) = 0;
    
    /**
     * 导出为PDF格式
     * @param data 报表数据
     * @param filepath 导出文件路径
     * @return 导出成功返回true，否则返回false
     */
    virtual bool export_to_pdf(const report_data& data, const std::string& filepath) = 0;
};
```

## report_data 类

报表数据类，包含报表的所有数据信息。

### 头文件
```cpp
#include <report/report_data.h>
```

### 类定义
```cpp
class report_data {
private:
    int election_id_;
    std::string title_;
    std::string generated_date_;
    std::vector<report_section> sections_;
    std::vector<chart_data> charts_;
    
public:
    // 构造函数
    report_data(int election_id, const std::string& title);
    
    // Getter方法
    int get_election_id() const;
    std::string get_title() const;
    std::string get_generated_date() const;
    std::vector<report_section> get_sections() const;
    std::vector<chart_data> get_charts() const;
    
    // Setter方法
    void set_generated_date(const std::string& date);
    void set_sections(const std::vector<report_section>& sections);
    void set_charts(const std::vector<chart_data>& charts);
    
    // 功能方法
    void add_section(const report_section& section);
    void add_chart(const chart_data& chart);
};
```

## chart_data 类

图表数据类，包含图表的配置和数据。

### 头文件
```cpp
#include <report/chart_data.h>
```

### 类定义
```cpp
class chart_data {
private:
    std::string chart_type_;
    std::string title_;
    std::vector<std::string> labels_;
    std::vector<double> values_;
    std::map<std::string, std::string> options_;
    
public:
    // 构造函数
    chart_data(const std::string& chart_type, const std::string& title);
    
    // Getter方法
    std::string get_chart_type() const;
    std::string get_title() const;
    std::vector<std::string> get_labels() const;
    std::vector<double> get_values() const;
    std::map<std::string, std::string> get_options() const;
    
    // Setter方法
    void set_labels(const std::vector<std::string>& labels);
    void set_values(const std::vector<double>& values);
    void set_options(const std::map<std::string, std::string>& options);
};
```

## report_exception 类

报表相关异常类。

### 头文件
```cpp
#include <report/report_exception.h>
```

### 类定义
```cpp
class report_exception : public base_exception {
public:
    explicit report_exception(const std::string& message);
    report_exception(const std::string& message, const std::string& error_code);
};

class report_generation_exception : public report_exception {
public:
    explicit report_generation_exception(const std::string& message);
};

class export_exception : public report_exception {
public:
    explicit export_exception(const std::string& message);
};
```