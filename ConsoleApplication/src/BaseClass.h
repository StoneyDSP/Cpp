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

#include <iostream>

class BaseClass
{
public:
    BaseClass()
    {
        std::cout << "BaseClass constructed" << std::endl;
    }

    virtual ~BaseClass()
    {
        std::cout << "BaseClass destroyed" << std::endl;
    }

    float getPi()
    {
        return pi;
    }

protected:
    float pi {3.14159F};
};
