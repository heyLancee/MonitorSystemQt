cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MonitorSystemQt)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin) 

# 添加子目录
add_subdirectory(tests)