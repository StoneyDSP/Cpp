// ConsoleApplication.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <typeinfo>

// TODO: Reference additional headers your program requires here.

//#include "Atomic.h"
#include "Double.h"
//#include "Float.h"
//#include "PluginProcessor.h"
//#include "UniquePointer.h"
#include "Value.h"
//#include "X.h"

void intro()
{
    std::cout << "Hello CMake World!" << std::endl;
    std::cout << std::endl;
    std::cin.get();
}

void outro()
{
    std::cout << "Goodbye CMake World!" << std::endl;
    std::cout << std::endl;
    std::cin.get();
}

void wait()
{
    std::cout << "Press ''Enter'' to continue!" << std::endl;
    std::cin.get();
}

void newLine()
{
    std::cout << std::endl;
}

void lineBreak()
{
    std::cout << "//============================================================================//" << std::endl;
}

void endFunction()
{
    lineBreak();
    newLine();
    wait();
    newLine();
}

// void describe_plugin(const AudioPlugin& p) 
// {
//     std::cout << "describe_plugin:" << std::endl;
//     std::cout << std::endl;
//     std::cout << p.name() << std::endl;
//     std::cout << &p << std::endl;
//     std::cout << std::endl;
// }

// void describe_Float(const Float& value) 
// {
//     std::cout << "describe_plugin:" << std::endl;
//     std::cout << std::endl;
//     std::cout << value.name() << std::endl;
//     std::cout << &value << std::endl;
//     std::cout << std::endl;
// }

// template <typename Type>
// void describe_Value(const Value<Type>& value) 
// {
//     std::cout << "describe_Value:" << std::endl;
//     std::cout << std::endl;
//     std::cout << value.name() << std::endl;
//     std::cout << &value << std::endl;
//     std::cout << std::endl;
// }