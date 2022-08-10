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
project (CONSOLE_APPLICATION VERSION 1.0.0)

find_package(JUCE CONFIG REQUIRED)

add_subdirectory(".vscode")
add_subdirectory("src")

set(SOURCES 
"src/Main.cpp")

set(HEADERS 
"src/Main.h" 
"src/Float.h" 
"src/Dbl.h" 
"src/Int.h" 
#"src/Object.h"
"src/UniquePointer.h"
"src/Value.h")



juce_add_console_app(ConsoleApplication
    PRODUCT_NAME "Console Application") 

juce_generate_juce_header(ConsoleApplication)

target_sources(ConsoleApplication PRIVATE "${SOURCES}")

target_link_libraries(ConsoleApplication
PRIVATE
    # ConsoleAppData            # If you'd created a binary data target, you'd link to it here
    juce::juce_core
PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_warning_flags)
