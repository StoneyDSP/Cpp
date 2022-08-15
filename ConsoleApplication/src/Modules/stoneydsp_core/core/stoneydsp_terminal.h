/*******************************************************************************
 * 
 * @file stoneydsp_terminal.h
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

#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED

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

private:

    Args& args;
};

void nextLine()
{
    std::cout << std::endl;
}

void lineBreak()
{
    std::cout << "//============================================================================//" << std::endl;
}

/** Prints a startup message to the console. */
void intro()
{
    lineBreak();
    std::cout << "// " << "StoneyDSP" << std::endl;
    std::cout << "// " << projectName << std::endl;
    std::cout << "// " << projectVersion << std::endl;
    lineBreak();
    nextLine();

    std::cout << "Hello World!" << std::endl;
    std::cout << std::endl;
    std::cin.get();
}

/** Prints a shutdown message to the console.
 * @return Int value of '0' to exit "main.cpp".
 */
int outro()
{
    std::cout << "Goodbye World!" << std::endl;
    std::cout << std::endl;
    std::cin.get();
    return 0;
}

void root(const int& argc, char* argv[], char* envp[])
{
    lineBreak();
    std::cout << "// " << &argc << std::endl;
    std::cout << "// " << *argv << std::endl;
    std::cout << "// " << *envp << std::endl;
    lineBreak();
    nextLine();
}

void wait()
{
    std::cout << "Press ''Enter'' to continue!" << std::endl;
    std::cin.get();
}

void print(const char string[])
{
    std::cout << string << std::endl;
    stoneydsp::nextLine();
    stoneydsp::wait();
}

void endFunction()
{
    lineBreak();
    nextLine();
    wait();
    nextLine();
}

template <class... Types>
inline void ignore(Types&&... ignored);

template <class... Types>
inline void ignore(Types&&... /*ignored*/)
{

}

} // namespace stoneydsp

#endif // TERMINAL_H_INCLUDED
