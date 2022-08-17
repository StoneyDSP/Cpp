
#pragma once

#include <assert.h>
#include <iostream>

#include "Float.h"

class AudioPlugin;
class ProcessSpec;

class PluginWrapper
{
public:
    PluginWrapper(AudioPlugin& p) : audioProcessor(p)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Constructor!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
        std::cout << std::endl;
    }
    ~PluginWrapper()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
        std::cout << std::endl;
    }

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    void assertion() 
    { 
        assert(this);
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
    }

    void prepare(ProcessSpec& spec)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Function: void prepare()" << std::endl;
        std::cout << std::endl;
    }

    void reset()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Function: void reset()" << std::endl;
        std::cout << std::endl;
    }

    Float process(Float& x)
    {
        return x;
    }

    AudioPlugin& audioProcessor;

    Float var {1.0F};
};