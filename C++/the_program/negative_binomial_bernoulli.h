#pragma once

#include "distribution.h"
#include <vector>
#include "math.h"

class NegativeBinomialBernoulli : public Distribution {
private:
    double p_;
    int k_;
    
public:
    NegativeBinomialBernoulli(double p, int k);
    ~NegativeBinomialBernoulli();
    int Generate();
};