/*
  ==============================================================================

    ConsoleApplication.h
    Created: 10 Aug 2022 1:57:14am
    Author:  Nathan J. Hood - @StoneyDSP

  ==============================================================================
*/

#pragma once

#ifndef CONSOLEAPPLICATION_H_INCLUDED
#define CONSOLEAPPLICATION_H_INCLUDED

#include <iostream>
#include <JuceHeader.h>

namespace stoneydsp
{

struct Args
{
    int argc{ 0 };
    char** argv{ nullptr };
    char** envp{ nullptr };
};

class ConsoleApp
{
public:

    ConsoleApp() : args(getArgs())
    {
    }
    ConsoleApp(Args& arguments) : args(arguments)
    {
    }
    ~ConsoleApp()
    {
    }

    void prepare(Args& arguments)
    {
        args.argc = arguments.argc;
        args.argv = arguments.argv;
        args.envp = arguments.envp;
    }

    Args& getArgs()
    {
        return args;
    }

    friend inline void intro();
    friend inline int outro();
    friend inline void root(const int& argc, char* argv[], char* envp[]);
    friend inline void wait();
    friend inline void nextLine();
    friend inline void lineBreak();
    friend inline void print(const char string[]);
    friend inline void endFunction();

private:

    Args& args;
};

inline void intro()
{
    lineBreak();
    std::cout << "// " << (ProjectInfo::projectName) << std::endl;
    std::cout << "// " << (ProjectInfo::companyName) << std::endl;
    std::cout << "// " << (ProjectInfo::versionString) << std::endl;
    lineBreak();
    nextLine();

    std::cout << "Hello World!" << std::endl;
    std::cout << std::endl;
    std::cin.get();
}

inline int outro()
{
    std::cout << "Goodbye World!" << std::endl;
    std::cout << std::endl;
    std::cin.get();
    return 0;
}

inline void root(const int& argc, char* argv[], char* envp[])
{
    lineBreak();
    std::cout << "// " << &argc << std::endl;
    std::cout << "// " << *argv << std::endl;
    std::cout << "// " << *envp << std::endl;
    lineBreak();
    nextLine();
}

inline void wait()
{
    std::cout << "Press ''Enter'' to continue!" << std::endl;
    std::cin.get();
}

inline void nextLine()
{
    std::cout << std::endl;
}

inline void lineBreak()
{
    std::cout << "//============================================================================//" << std::endl;
}

inline void print(const char string[])
{
    std::cout << string << std::endl;
    nextLine();
    wait();
}

inline void endFunction()
{
    lineBreak();
    nextLine();
    wait();
    nextLine();
}

} // namespace stoneydsp

#endif // CONSOLEAPPLICATION_H_INCLUDED
