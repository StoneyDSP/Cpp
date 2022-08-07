# CMakeList.txt : CMake project for ConsoleApplication, include source and define
# project specific logic here.
#
# The first line of any CMake project should be a call to `cmake_minimum_required`, which checks
# that the installed CMake will be able to understand the following CMakeLists, and ensures that
# CMake's behaviour is compatible with the named version. This is a standard CMake command, so more
# information can be found in the CMake docs.
cmake_minimum_required (VERSION 3.8)

# The top-level CMakeLists.txt file for a project must contain a literal, direct call to the
# `project()` command. `project()` sets up some helpful variables that describe source/binary
# directories, and the current project version. This is a standard CMake command.
project ("ConsoleApplication" VERSION 1.0.0)

#Can manually add the sources using the "set()" command as follows:
#set(SOURCES src/ConsoleApplication.cpp src/Int.cpp... etc)

#However, the file(GLOB...) command allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

find_package(JUCE CONFIG REQUIRED)

juce_generate_juce_header(ConsoleAppExample)

# Add source to this project's executable.
add_executable (ConsoleApplication "${SOURCES}" "${HEADERS}")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ConsoleApplication PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.


