// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ConsoleApplication.h"

const float pi = 3.14159F;

int main()
{
    intro();
    
    wait();
    lineBreak();
    newLine();
    
    Float varA{};
    endFunction();

    Float varB{varA};

    varB.booleanChecks(3.14159F);

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


// int main()
// {
//     intro();

//     Value<float> varF(0.789f); // Init constructed...

//     varF.info();
//     varF.dataChecks();
//     varF.BooleanChecks();

//     lineBreak();
//     newLine();
//     wait();

//     varF(0.0f);

//     varB += 3.14159f; // Called swap()...
//     lineBreak();
//     newLine();
//     wait();

//     varF += varB.value;

//     newLine();
    
//     varF.info();
//     varF.dataChecks();
//     varF.BooleanChecks();

//     lineBreak();
//     newLine();
//     wait();

//     outro();

//     return 0;

//     assert(&varF != nullptr);
// }
