#ifndef NB_DISTRIBUTION_H
#define NB_DISTRIBUTION_H

#include <vector>
#include <string>
#include "math.h"


class NB_Distribution
{
public:
    NB_Distribution(double p, int k);
    ~NB_Distribution();
    double get_p() const;
    int get_k() const;
    std::vector<double> get_density() const;
    std::string get_name() const;
    int get_size() const;

private:
    double p_;
    int k_;
    std::vector<double> density_;
    // 10^6 = max sample_size, EPS * sample_size < 5
    const double EPS = 1e-6;
};

#endif // NB_DISTRIBUTION_H
