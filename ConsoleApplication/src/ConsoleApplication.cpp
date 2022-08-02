// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ConsoleApplication.h"

Int a {1};

Int b {2};

Int c {3};

Int d {a};

Int e {10};

/** Readme.md example. */
int main()
{
    intro();

    c = a + b;
    endFunction();

    e = e + d + c + b + a;
    endFunction();

    e = e % d % c % b % a;
    endFunction();

    outro();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file



// /** Ptr tests. */
// int main()
// {
//     intro();

//     std::cout << "Test 1" << std::endl;
//     newLine();

//     Value<double> var{3.14159};
//     endFunction();

//     // Best to use std::make_unique
//     std::cout << "Test 2" << std::endl;
//     newLine();

//     auto test = make_unique<Value<double>>();
//     endFunction();

//     // You can also pass any pointer to std::unique_ptr's constructor
//     std::cout << "Test 3" << std::endl;
//     newLine();

//     Value<double>* p = new Value<double>();
//     endFunction();

//     std::cout << "Test 4" << std::endl;
//     newLine();

//     unique_ptr<Value<double>> uPtr(p);
//     endFunction();

//     // unique_ptr can be used just like regular pointers
//     // because of operator overloading
//     std::cout << "Test 5" << std::endl;
//     newLine();

//     describe_Value(*uPtr);
//     endFunction();

//     std::cout << "Test 6" << std::endl;
//     newLine();
    
//     p->name();
//     endFunction();

//     std::cout << "Test 7" << std::endl;
//     uPtr->value += 2.14159F;

//     outro();

//     return 0;
// }

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
