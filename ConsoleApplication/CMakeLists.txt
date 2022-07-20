# CMakeList.txt : CMake project for CMakeProject1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ConsoleApplication")

# Add source to this project's executable.
add_executable (ConsoleApplication "ConsoleApplication.cpp" "ConsoleApplication.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ConsoleApplication PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.