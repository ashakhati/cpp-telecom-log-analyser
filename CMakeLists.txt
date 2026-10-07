cmake_minimum_required(VERSION 3.16)

project(cpp_5g_log_analyzer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_5g_log_analyzer
    src/main.cpp
    src/LogEvent.cpp
    src/logAnalyzer.cpp
)
