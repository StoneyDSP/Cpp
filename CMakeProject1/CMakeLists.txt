# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cfg/Config.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/cfg/Config.h")

project (CMakeProject1 CXX)

set(CMAKE_BINARY_DIR "${sourceDir}/bin/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${sourceDir}/bin/${generator}/${presetName}/Intermediates/")
set(CMAKE_CFG_INTDIR "${sourceDir}/bin/${generator}/${presetName}/Intermediates/")
set(CMAKE_PDB_OUTPUT_DIRECTORY "${sourceDir}/bin/${generator}/${presetName}/Intermediates/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${sourceDir}/bin/${generator}/${presetName}/Intermediates/")

# Add source to this project's executable.
add_executable (CMakeProject1 "src/main.cpp")

find_package(fmt REQUIRED)
target_link_libraries(CMakeProject1 PRIVATE fmt::fmt)

find_package(CppUnit CONFIG REQUIRED)
target_link_libraries(CMakeProject1 PRIVATE CppUnit)


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
