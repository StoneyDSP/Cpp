# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (CMakeProject1)

set(CMAKE_BINARY_DIR "${sourceDir}/bin/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${sourceDir}/bin/${generator}/${presetName}/Intermediates/")
set(CMAKE_CFG_INTDIR "${sourceDir}/bin/${generator}/${presetName}/Intermediates/")

# Add source to this project's executable.
add_executable (CMakeProject1 "src/main.cpp" "cfg/Config.h")


if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_target_properties(CMakeProject1 PROPERTIES CXX_STANDARD 20)
else()
	set_target_properties(CMakeProject1 PROPERTIES CXX_STANDARD 17)
endif()
set_target_properties(CMakeProject1 PROPERTIES CXX_STANDARD_REQUIRED true)

# TODO: Add tests and install targets if needed.

include(CPACK)
include(CTest)
enable_testing()
