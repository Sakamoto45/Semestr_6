#ifndef NB_DISTRIBUTION_H
#define NB_DISTRIBUTION_H

#include <vector>

class NB_Distribution
{
private:
    double p_;
    int k_;
    std::vector<double> density_;
//    const double EPS = ; //

public:
    NB_Distribution(double p, int k);
    double GetP();
    int GetK();
    std::vector<double> GetDensity();

};

#endif // NB_DISTRIBUTION_H
