/*******************************************************************************
 * 
 * @file Main.cpp
 * 
 * @author Nathan J. Hood (nathanjhood@googlemail.com)
 * @version 1.0.0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright (c) 2022 @StoneyDSP
 * 
 *******************************************************************************
*/

#include "Main.h"

/** "Main.cpp" - Entry point for program execution. */ 
int main(int argc, char* argv[], char* envp[])
{
    using namespace stoneydsp;

    ignore(argc, argv, envp);

    intro();

    Double a {1};
    
    Double b {2};

    Double c {3};

    Double d {a};

    Double e {10};

    print("Addition Tests");
    e = e + d + c + b + a;
    endFunction();

    print("Subtraction Tests");
    e = e - d - c - b - a;
    endFunction();

    print("Multiplication Tests");
    e = e * d * c * b * a;
    endFunction();

    print("Division Tests");
    e = e / d / c / b / a;
    endFunction();

    // print("Modulo Tests");
    // e = e % d % c % b % a;
    // endFunction();

    return outro();
}
