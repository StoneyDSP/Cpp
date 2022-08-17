cmake_minimum_required(VERSION 3.2.0)
project(ConsoleApplication VERSION 1.0.0.2 HOMEPAGE_URL www.github.com/StoneyDSP LANGUAGES C CXX)

#include(CTest)
#enable_testing()

add_executable(ConsoleApplication "src/main.cpp")

configure_file (
  "${PROJECT_SOURCE_DIR}/cfg/Config.h.in"
  "${PROJECT_SOURCE_DIR}/cfg/Config.h"
)

target_include_directories(ConsoleApplication PUBLIC "${PROJECT_BINARY_DIR}")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
