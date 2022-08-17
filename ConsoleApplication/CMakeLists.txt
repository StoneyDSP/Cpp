cmake_minimum_required(VERSION 3.0.0)
project(ConsoleApplication VERSION 1.0.0.1 HOMEPAGE_URL www.github.com/StoneyDSP LANGUAGES CXX)

add_executable(ConsoleApplication "src/main.cpp")

configure_file (
  "${PROJECT_SOURCE_DIR}/src/Config.h.in"
  "${PROJECT_SOURCE_DIR}/src/Config.h"
)

target_include_directories(ConsoleApplication PUBLIC "${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
