# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
cmake_minimum_required(VERSION 3.8)

project(ConsoleApplication VERSION 1.0.0.2 HOMEPAGE_URL www.github.com/StoneyDSP LANGUAGES C CXX)

# this way others can override this value form command line
set(CMAKE_TOOLCHAIN_FILE ~/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE FILEPATH "Path to toolchain")

find_package(Doxygen)

add_executable(ConsoleApplication "src/main.cpp")

configure_file (
  "${PROJECT_SOURCE_DIR}/cfg/Config.h.in"
  "${PROJECT_SOURCE_DIR}/cfg/Config.h"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ConsoleApplication PROPERTY CXX_STANDARD 20)
else()
  set_property(TARGET ConsoleApplication PROPERTY CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CPACK)
include(CTest)
enable_testing()
