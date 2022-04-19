#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

//#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "math.h"

template<typename T>
class Distribution
{
public:
    Distribution() {}
    virtual ~Distribution() {}

    virtual T Generate()=0;
    std::vector<T> GenerateSample(int sample_size)
    {
        std::vector<T> sample;
        for (int i = 0; i < sample_size; ++i) {
            sample.push_back(Generate());
        }
        return sample;
    }
};

#endif // DISTRIBUTION_H
