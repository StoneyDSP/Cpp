
#pragma once

#include <assert.h>
#include <iostream>

class AudioPlugin;

class PluginWrapper
{
public:
    PluginWrapper(AudioPlugin& p) : audioProcessor(p)
    {
        std::cout << "PluginWrapper - Called Copy Constructor!" << std::endl;
        assertion();
        std::cout << "PluginWrapper - Default Constructed!" << std::endl;
        std::cout << std::endl;
    }
    ~PluginWrapper()
    {
        std::cout << "PluginWrapper - Called Destructor!" << std::endl;
        std::cout << "PluginWrapper - Destroyed!" << std::endl;
        std::cout << std::endl;
    }

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    void assertion() 
    { 
        assert(this);
        std::cout << "PluginWrapper - Passed assertion check!" << std::endl;
    }

    float process(float x)
    {
        return x;
    }

    AudioPlugin& audioProcessor;
};