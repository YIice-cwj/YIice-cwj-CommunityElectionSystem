cmake_minimum_required(VERSION 3.10)                                        # 设置最低版本

set(CMAKE_CXX_STANDARD 17)                                          # 设置C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)                                 # 强制使用C++17
set(CMAKE_CXX_EXTENSIONS OFF)                                       # 关闭C++11特性
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)                               # 输出编译命令

set(PROJECT_NAME "CommunityElectionSystem")                         # 项目名

set(VERSION_MAJOR 1)                                                # 重大版本
set(VERSION_MINOR 0)                                                # 次要版本
set(VERSION_PATCH 0)                                                # 补丁版本
      
set(CommunityElectionSystemVERSION                                  # 项目版本    
${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})     

project(${PROJECT_NAME} VERSION ${CommunityElectionSystemVERSION})  # 设置项目名和版本

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY                                  # 设置运行时输出目录  
${CMAKE_BINARY_DIR}/$<CONFIGURATION>)    

find_package(PkgConfig)                                             # 添加PkgConfig
pkg_check_modules(MYSQL_CLIENT REQUIRED mysqlclient)                # 检查MySQL库

if(MSVC)
    add_definitions(/W4)                                            # 添加警告级别
    add_definitions(/Zc:__cplusplus)                                # 预处理器宏
    add_definitions(/permissive-)                                   # 添加严格模式
    add_definitions(/std:c++17)                                     # 添加C++17特性
    add_definitions(/bigobj)                                        # 添加大对象支持 
    add_definitions(/utf-8)                                         # 添加UTF-8支持
    add_definitions(/MP)                                            # 添加多线程编译
else()
    add_definitions(-Wall)                                          # 添加警告级别
    add_definitions(-Wextra)                                        # 添加额外警告
    add_definitions(-Wpedantic)                                     # 添加标准警告
    add_definitions(-Werror)                                        # 添加错误警告
endif()

include_directories(${MYSQL_CLIENT_INCLUDE_DIRS})                   # 添加头文件
include_directories(include)                                        # 添加头文件   

file(GLOB_RECURSE SOURCES "src/*.cc" "src/*.h"  "src/*.c"           # 获取源文件
 "src/*.hpp" "src/*.cpp")

file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS src/*.cc)          # 获取核心源文件

add_library(CORE STATIC ${CORE_SOURCES})                            # 添加静态库

target_include_directories(CORE PUBLIC include)                     # 添加头文件

add_executable(${PROJECT_NAME} ${SOURCES})                          # 添加可执行文件    

target_link_libraries(${PROJECT_NAME} ${MYSQL_CLIENT_LIBRARIES} ${CORE})    # 链接库

set_target_properties(${PROJECT_NAME} PROPERTIES                    # 设置属性
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug"      # 设置调试输出目录
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release"  # 设置发布输出目录  
    DEBUG_POSTFIX "_d"                                              # 设置调试后缀                
)

message("项目名：${PROJECT_NAME}")
message("版本：${CommunityElectionSystemVERSION}")
message("编译器标准：${CMAKE_CXX_STANDARD}")
message("编译器类型：${CMAKE_CXX_COMPILER_ID}")
message("编译器版本：${CMAKE_CXX_COMPILER_VERSION}")


enable_testing()                                                      # 启用测试
add_subdirectory(tests)                                               # 添加测试目录