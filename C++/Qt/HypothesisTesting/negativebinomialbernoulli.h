#ifndef NEGATIVEBINOMIALBERNOULLI_H
#define NEGATIVEBINOMIALBERNOULLI_H

#include "distribution.h"

class NegativeBinomialBernoulli : public Distribution<int>
{
private:
    double p_;
    int k_;

public:
    NegativeBinomialBernoulli(double p, int k);
    ~NegativeBinomialBernoulli() override;
    int Generate() override;
};

#endif // NEGATIVEBINOMIALBERNOULLI_H
