#pragma once

#include "distribution.h"
#include <vector>
#include "math.h"

const double EPS = 1e-3;

class NegativeBinomialTable : public Distribution {
private:
    vector<double> table_;
    
public:
    NegativeBinomialTable(double p, int k);
    ~NegativeBinomialTable();
    int Generate();
};