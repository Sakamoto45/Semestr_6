#ifndef CHISQUARE_H
#define CHISQUARE_H

#include <vector>

class ChiSquare
{
private:
    std::vector<double> theoretical_frequency_;
    std::vector<double> emperical_frequency_;

public:
    ChiSquare();

    void set_theoretical_frequency();
    void set_emperical_frequency();

};

#endif // CHISQUARE_H
