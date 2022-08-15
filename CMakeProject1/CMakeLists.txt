cmake_minimum_required(VERSION 3.0.0)
project(CMakeProject1 VERSION 0.1.0)

find_package(JUCE CONFIG REQUIRED)

add_subdirectory("Source")

include(CTest)
enable_testing()

add_executable(CMakeProject1 "Source/main.cpp")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
