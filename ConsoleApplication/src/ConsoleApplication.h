// ConsoleApplication.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#ifndef CONSOLEAPPLICATION_H_INCLUDED
#define CONSOLEAPPLICATION_H_INCLUDED

#include <assert.h>
#include <atomic>
#include <iostream>
#include <typeinfo>

// TODO: Reference additional headers your program requires here.

// #include "AbstractClass.h"
// #include "BaseClass.h"
// #include "DerivedClass.h"
#include "Double.h"
//#include "Float.h"
//#include "Inheritance.h"
#include "Int.h"
//#include "Object.h"
//#include "Operators.h"
//#include "PluginProcessor.h"
//#include "UniquePointer.h"
//#include "T.h"
//#include "Value.h"

void intro();

void outro();

void wait();

void newLine();

void lineBreak();

void endFunction();

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

#endif // CONSOLEAPPLICATION_H_INCLUDED
