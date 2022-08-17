cmake_minimum_required(VERSION 3.2.0)
project(CMakeProject1 VERSION 0.1.0)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#include(CTest)
#enable_testing()

add_executable(CMakeProject1 "source/main.cpp")

target_include_directories(CMakeProject1 PUBLIC "${PROJECT_BINARY_DIR}")

configure_file (
  "${PROJECT_SOURCE_DIR}/cfg/Config.h.in"
  "${PROJECT_SOURCE_DIR}/cfg/Config.h"
)

set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}")

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
