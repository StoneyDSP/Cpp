# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
cmake_minimum_required(VERSION 3.8)
project(ConsoleApplication VERSION 1.0.0.2 HOMEPAGE_URL www.github.com/StoneyDSP LANGUAGES C CXX)

set(CMAKE_BINARY_DIR "${sourceDir}/bin/${presetName}")
set(CMAKE_CFG_INTDIR "${sourceDir}/bin/${presetName}/Intermediates/")

add_executable(ConsoleApplication "src/main.cpp")

configure_file (
  "${PROJECT_SOURCE_DIR}/cfg/Config.h.in"
  "${PROJECT_SOURCE_DIR}/cfg/Config.h"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ConsoleApplication PROPERTY CXX_STANDARD 20)
  set_property(TARGET ConsoleApplication PROPERTY C_STANDARD 17)
else()
  set_property(TARGET ConsoleApplication PROPERTY CXX_STANDARD 17)
  set_property(TARGET ConsoleApplication PROPERTY C_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD_REQUIRED True)

# Ensure that we do an out of source build
MACRO(MACRO_ENSURE_OUT_OF_SOURCE_BUILD MSG)
     STRING(COMPARE EQUAL "${CMAKE_SOURCE_DIR}"
     "${CMAKE_BINARY_DIR}" insource)
     GET_FILENAME_COMPONENT(PARENTDIR ${CMAKE_SOURCE_DIR} PATH)
     STRING(COMPARE EQUAL "${CMAKE_SOURCE_DIR}"
     "${PARENTDIR}" insourcesubdir)
    IF(insource OR insourcesubdir)
        MESSAGE(FATAL_ERROR "${MSG}")
    ENDIF(insource OR insourcesubdir)
ENDMACRO(MACRO_ENSURE_OUT_OF_SOURCE_BUILD)

MACRO_ENSURE_OUT_OF_SOURCE_BUILD(" ${CMAKE_PROJECT_NAME} requires an out of source build.")

include(CPACK)
include(CTest)
enable_testing()
