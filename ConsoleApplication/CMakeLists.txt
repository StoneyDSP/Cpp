# CMakeList.txt : CMake project for ConsoleApplication, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ConsoleApplication")

#Can manually add the sources using the "set()" command as follows:
#set(SOURCES src/ConsoleApplication.cpp src/Int.cpp... etc)
 
#However, the file(GLOB...) command allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

# Add source to this project's executable.
add_executable (ConsoleApplication "${SOURCES}" "${HEADERS}")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ConsoleApplication PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.


