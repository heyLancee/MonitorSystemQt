cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(TcpClientTest)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找Qt库
find_package(Qt5 REQUIRED COMPONENTS Core Network)

# 添加可执行文件
add_executable(test_tcpclient test_tcpclient.cpp)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/inc/core)

# 链接Qt库
target_link_libraries(test_tcpclient Qt5::Core Qt5::Network pthread) 