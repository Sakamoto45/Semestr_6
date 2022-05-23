#ifndef CHISQUARE_H
#define CHISQUARE_H

#include <vector>
#include "nb_distribution.h"
#include "probdist.h"

class ChiSquare
{
public:
    ChiSquare(const NB_Distribution& distribution, const int* sample, int sample_size);
    void set_data(const NB_Distribution& distribution, const int* sample, int sample_size);

    std::vector<double> get_theoretical_frequency() const;
    std::vector<int> get_emperical_frequency() const;
    std::vector<double> get_theoretical_frequency_grouped();
    std::vector<int> get_emperical_frequency_grouped();
    double get_test_stat();
    int get_degree_of_freedom();
    double get_p_value();

private:
    std::vector<double> theoretical_frequency_;
    std::vector<int> emperical_frequency_;
    std::vector<double> theoretical_frequency_grouped_;
    std::vector<int> emperical_frequency_grouped_;
    double test_stat_;
    int degree_of_freedom_;
    double p_value_;
    bool grouped_is_relevant_;
    bool stats_are_relevant_;

    void group();
    void calc_p_value();
};

#endif // CHISQUARE_H
