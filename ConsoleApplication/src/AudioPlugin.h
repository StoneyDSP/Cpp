// Quick test class for constructors

#pragma once

#include <assert.h>
#include <iostream>

#include "PluginWrapper.h"

class AudioPlugin
{
public:

    AudioPlugin() : processor(*this)
    {
        std::cout << "AudioPlugin - Called Default Constructor!" << std::endl;
        assertion();
        std::cout << "AudioPlugin - Default Constructed!" << std::endl;
        std::cout << std::endl;
    }

    ~AudioPlugin()
    {
        std::cout << "AudioPlugin - Called Destructor!" << std::endl;
        std::cout << "AudioPlugin - Destroyed!" << std::endl;
        std::cout << std::endl;
    }

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    void assertion() 
    { 
        assert(this);
        std::cout << "AudioPlugin - Passed assertion check!" << std::endl;
    }

    float funcOne()
    {
        return 1.0F;
    }

    float process(float x)
    {
        processor.process(x);

        return x;
    }

    PluginWrapper processor;
};