
#pragma once

#include <assert.h>
#include <iostream>

#include "Float.h"

class AudioProcessor
{
public:

    AudioProcessor()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
        std::cout << std::endl;
    }

    ~AudioProcessor()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
        std::cout << std::endl;
    }

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    virtual void assertion() 
    { 
        assert(this);
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
    }

    const char* name() const noexcept
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* name() const noexcept = " << typeid(*this).name() << std::endl;

        return typeid(*this).name();
    }

    Float funcOne()
    {
        return 1.0F;
    }

    void prepare()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Function: void prepare()" << std::endl;
    }

    void reset()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Function: void reset()" << std::endl;
    }

    virtual Float process(Float& x)
    {
        return x;
    }

    virtual Float processBypass(Float& x)
    {
        return x;
    }
};