/*******************************************************************************
 *
 * @file Config.h.in
 *
 * @author Nathan J. Hood (nathanjhood@googlemail.com)
 * @version 1.0.0.1
 * @date 2022-08-13
 *
 * @copyright Copyright (c) 2022 @StoneyDSP
 *
 *******************************************************************************
*/

#pragma once

#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#define companyName "StoneyDSP"
#define projectName "ConsoleApplication"
#define projectVersion "v1.0.0.2"
#define website "www.github.com/StoneyDSP"
#define V_Major 1
#define V_Minor 0
#define V_Patch 0
#define V_Tweak 2
#define sourceDir "C:/Cpp/ConsoleApplication"
#define currentSourceDir "C:/Cpp/ConsoleApplication"
#define binaryDir "C:/Cpp/ConsoleApplication/bin/x64"
#define currentBinaryDir "C:/Cpp/ConsoleApplication/bin/x64"
#define homeDir "C:/Cpp/ConsoleApplication"
#define makeCommand ""C:\Program Files\CMake\bin\cmake.exe" --build . --config "${CTEST_CONFIGURATION_TYPE}""
#define toolchain "C:/Cpp/vcpkg/scripts/buildsystems/vcpkg.cmake"

#endif // CONFIG_H_INCLUDED
