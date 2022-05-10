#ifndef SAMPLE_H
#define SAMPLE_H

//#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "math.h"

//template<typename T>

class Sample
{
protected:
    int k_;
    double p_;

public:

    Sample(double p, int k): p_{p}, k_{k} {}
    virtual ~Sample() {}

    virtual int Generate()=0;
    int* GenerateSample(int sample_size);
};

#endif // SAMPLE_H
