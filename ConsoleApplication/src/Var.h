/**
  ==============================================================================

    Int.h
    Created: 05 August 2022 20:21:03pm
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#pragma once

#ifndef VAR_H_INCLUDED
#define VAR_H_INCLUDED

#include <assert.h>
#include <iostream>
#include <typeinfo>

class Var
{
public:
    Var(int initialValue);
    Var(Var& newValue);
    Var(Var&& otherValue);
    ~Var() noexcept;

    Var& operator=(Var& newValue);
    Var& operator=(const Var& newValue);
    Var& operator=(Var&& otherValue) noexcept;

    Var& operator+=(const Var& rhs);

    friend Var operator+(Var lhs, const Var& rhs)
    {
        std::cout << "Operator +" << std::endl;

        lhs += rhs; // reuse compound assignment
        return lhs; // return the result by value (uses move constructor)
    }
    
    friend std::ostream& operator<<(std::ostream& stream, Var& val)
    {
        stream << val.value;
        return stream;
    }

private:
    int value{0};
};

#endif // VAR_H_INCLUDED
