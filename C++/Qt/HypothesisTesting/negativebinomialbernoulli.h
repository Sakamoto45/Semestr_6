#ifndef NEGATIVEBINOMIALBERNOULLI_H
#define NEGATIVEBINOMIALBERNOULLI_H

#include "sample.h"

class NegativeBinomialBernoulli : public Sample
{
public:
    NegativeBinomialBernoulli(double p, int k);
    ~NegativeBinomialBernoulli() override;
    int Generate() override;
};

#endif // NEGATIVEBINOMIALBERNOULLI_H
