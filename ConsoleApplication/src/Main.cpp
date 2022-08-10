// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#include "Main.h"

using namespace stoneydsp;

int main(int argc, char** argv, char** envp)
{
    ConsoleApp app;
    
    intro();

    {
        int init {2};

        Value<int> x {&init};
        Value<int> y {x};

        x += y;

        endFunction();
    }

    // Digital Biquad Equalizer Direct Form I 
    // Testing for copies of variables

    //{
    //    Float inputSample{ 5 };
    //    Float outputSample{ };

    //    auto& Xn = inputSample;
    //    auto& Yn = outputSample;

    //    Float b0{ Xn }, b1{ Xn }, b2{ Xn }, a0{ Xn }, a1{ Xn }, a2{ Xn };
    //    Float Wn1{ 3 }, Wn2{ 9 }, Xn1{ 2 }, Xn2 { 7 }, Yn1{ -5 }, Yn2 { -1 };

    //    endFunction();
    //    
    //    Yn = (Xn *= b0) + (Xn1 *= b1) + (Xn2 *= b2) + (Yn1 *= a1) + (Yn2 *= a2);
    //    endFunction();

    //    Xn2 = Xn1;
    //    Yn2 = Yn1;
    //    Xn1 = Xn;
    //    Yn1 = Yn;
    //    endFunction();

    //}

    

    return outro();
}

///** Readme.md example. */
//int main()
//{
//    Int a {1};
//    
//    Int b {2};
//
//    Int c {3};
//
//    Int d {a};
//
//    Int e {10};
//
//    intro();

    //print("Addition Tests");
    //e = e + d + c + b + a;
    //endFunction();

    // print("Subtraction Tests");
    // e = e - d - c - b - a;
    // endFunction();

    // print("Multiplication Tests");
    // e = e * d * c * b * a;
    // endFunction();

    // print("Division Tests");
    // e = e / d / c / b / a;
    // endFunction();

    // print("Modulo Tests");
    // e = e % d % c % b % a;
    // endFunction();

//    outro();
//
//    return 0;
//}



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

