// Quick test class for constructors

#pragma once

#include <assert.h>
#include <iostream>

#include "AudioProcessor.h"
#include "Float.h"
#include "PluginWrapper.h"
#include "ProcessSpec.h"

class AudioPlugin : public AudioProcessor
{
public:

    AudioPlugin() : processor(*this)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
        std::cout << std::endl;
    }

    ~AudioPlugin()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
        std::cout << std::endl;
    }

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    void assertion() override
    { 
        assert(this);
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
    }

    const char* name() const noexcept
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* name() const noexcept = " << typeid(*this).name() << std::endl;

        return typeid(*this).name();
    }

    void prepare()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Function: void prepare()" << std::endl;

        spec.sampleRate = 48000.0;
        spec.maximumBlockSize = 512;
        spec.numChannels = 2;
    }

    void reset()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Function: void reset()" << std::endl;
    }

    Float process(Float& x) override
    {
        processor.process(x);

        return x;
    }

    Float processBypass(Float& x) override
    {
        return x;
    }

    ProcessSpec& getSpec() { return spec; };

    ProcessSpec spec;
    PluginWrapper processor;
};
