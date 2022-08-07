// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ConsoleApplication.h"

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

class Object
{
public:
    Object() : x(), y(), z() {}
    explicit Object(float a, float b, float c) : x(a), y(b), z(c) {}
    explicit Object(Float a, Float b, Float c) : x(a), y(b), z(c) {}
    explicit Object(float* a, float* b, float* c) : x(*a), y(*b), z(*c) {}
    explicit Object(Float* a, Float* b, Float* c) : x(*a), y(*b), z(*c) {}
    explicit Object(float& a, float& b, float& c) : x(a), y(b), z(c) {}
    explicit Object(Float& a, Float& b, Float& c) : x(a), y(b), z(c) {}
    explicit Object(float&& a, float&& b, float&& c) : x(a), y(b), z(c) {}
    explicit Object(Float&& a, Float&& b, Float&& c) : x(a), y(b), z(c) {}
    ~Object(){}
private:
    Float x, y, z;
};

class Array
{

};

int main()
{
    intro();

    //Object object{ Float{ 0.0F }, Float{ 1.0F }, Float{ 3.14159F } };

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

    outro();

    return 0;
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

void intro()
{
    lineBreak();
    std::cout << "// " << std::endl;
    // std::cout << "// " << (ProjectInfo::projectName) << std::endl;
    // std::cout << "// " << (ProjectInfo::companyName) << std::endl;
    // std::cout << "// " << (ProjectInfo::versionString) << std::endl;
    std::cout << "// " << std::endl;
    lineBreak();
    newLine();

    std::cout << "Hello World!" << std::endl;
    std::cout << std::endl;
    std::cin.get();

}

void outro()
{
    std::cout << "Goodbye World!" << std::endl;
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

void print(const char string[])
{
    std::cout << string << std::endl;
    newLine();
    wait();
}

void endFunction()
{
    lineBreak();
    newLine();
    wait();
    newLine();
}
