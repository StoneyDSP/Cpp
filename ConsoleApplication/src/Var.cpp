/**
  ==============================================================================

    Int.cpp
    Created: 05 August 2022 20:21:03pm
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#include "Var.h"

Var::Var(int initialValue = {0}) : value(initialValue)
{
    std::cout << "Default constructed!" << std::endl;
}

Var::Var(Var& newValue) : value(newValue.value)
{
    std::cout << "Copy constructed!" << std::endl;
}

Var::Var(Var&& otherValue) : value(otherValue.value)
{
    std::cout << "Move constructed!" << std::endl;
}

Var::~Var() noexcept
{
    std::cout << "Destroyed" << std::endl;
}

Var& Var::operator=(Var& newValue)
{
    std::cout << "Copy assigned" << std::endl;

    value = 0;

    value = newValue.value;

    return *this;
}

Var& Var::operator=(Var&& otherValue) noexcept
{
    std::cout << "Move assigned" << std::endl;  

    value = 0;

    value = otherValue.value;

    otherValue.value = 0;

    return *this;
}

Var& Var::operator+=(const Var& rhs)
{
    std::cout << "Operator +=" << std::endl;

    value += rhs.value;

    return *this;
}
