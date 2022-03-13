#pragma once

#include "distribution.h"
#include "negative_binomial_table.h"
#include "negative_binomial_bernoulli.h"
#include <vector>
#include <algorithm>
#include <string>

class ChiSquareTest {
private:
    double ligf(double s, double x, int n = 100);
    double gamma_half(int n);

public:
    enum class Method{None, Table, Bernoulli};
    ChiSquareTest();
    ~ChiSquareTest();

    vector<double> GetTheoreticalDistribution(double p, int k);
    Distribution* GetGenerator(double p, int k, Method method);
    pair<double, int> CalculateChiSquared(vector<double> theoretical_distribution, vector<int> sample);
    double p_value(pair<double, int> chi_squared);
    vector<double> GeneratePvalueSample(double p0, int k0, double p1, int k1, Method method, int sample_size, int p_sample_size);
    void PrintDistributionAsTable(vector<double> distribution);
};