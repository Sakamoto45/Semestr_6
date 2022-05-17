#ifndef NB_GENERATOR_H
#define NB_GENERATOR_H

//#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "math.h"
#include "nb_distribution.h"

//template<typename T>

class NB_Generator
{
protected:
//    int k_;
//    double p_;
    NB_Distribution* distribution_;
    int* sample_;

public:

    NB_Generator(NB_Distribution* distribution);
    virtual ~NB_Generator() {}

    virtual int Generate()=0;
    int* GenerateSample(int sample_size);
    int* GetSample();
};

#endif // NB_GENERATOR_H
