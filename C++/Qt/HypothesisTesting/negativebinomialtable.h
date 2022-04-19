#ifndef NEGATIVEBINOMIALTABLE_H
#define NEGATIVEBINOMIALTABLE_H

#include "distribution.h"

class NegativeBinomialTable : public Distribution<int>
{
private:
    double p_;
    int k_;
    std::vector<double> table_;
    void ExtendTable(int len);

public:
    NegativeBinomialTable(double p, int k);
    ~NegativeBinomialTable() override;
    int Generate() override;
};

#endif // NEGATIVEBINOMIALTABLE_H
