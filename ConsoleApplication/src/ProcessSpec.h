
#pragma once

struct ProcessSpec
{
    /** The sample rate that will be used for the data that is sent to the processor. */
    double sampleRate {0.0};

    /** The maximum number of samples that will be in the blocks sent to process() method. */
    uint32_t maximumBlockSize {0};

    /** The number of channels that the process() method will be expected to handle. */
    uint32_t numChannels {0};
};
