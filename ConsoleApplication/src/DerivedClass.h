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
		std::cout << "DerivedClass constructed" << std::endl;
    }

    ~DerivedClass()
    {
		std::cout << "DerivedClass destroyed" << std::endl;
    }

	float getPiTwo()
	{
		return pi + pi;
	}
};
