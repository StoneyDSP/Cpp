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

#include "BaseClass.h"

class DerivedClass : public BaseClass
{
public:
    DerivedClass() : BaseClass()
    {

    }

    ~DerivedClass()
    {

    }

    float getPiTwo()
    {
        return pi *= 2.0F;
    }
};
