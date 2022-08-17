/**
  ==============================================================================

    BaseClass.h
    Created: 25 Jul 2022 8:42:29am
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#pragma once

#ifndef BASECLASS_H_INCLUDED
#define BASECLASS_H_INCLUDED

#include <iostream>

class BaseClass
{
public:
    BaseClass()
    {
        std::cout << "BaseClass constructed" << std::endl;
    }

    ~BaseClass()
    {
        std::cout << "BaseClass destroyed" << std::endl;
    }

    virtual float getPi()
    {
        return pi;
    }

protected:
    float pi {3.14159F};
};

#endif // BASECLASS_H_INCLUDED
