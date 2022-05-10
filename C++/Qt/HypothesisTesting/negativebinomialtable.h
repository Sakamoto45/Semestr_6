#ifndef NEGATIVEBINOMIALTABLE_H
#define NEGATIVEBINOMIALTABLE_H

#include "sample.h"

class NegativeBinomialTable : public Sample
{
private:
    std::vector<double> table_;
    void ExtendTable(int len);

public:
    NegativeBinomialTable(double p, int k);
    ~NegativeBinomialTable() override;
    int Generate() override;
};

#endif // NEGATIVEBINOMIALTABLE_H
