#ifndef CHISQUARE_H
#define CHISQUARE_H

#include <vector>
#include "nb_distribution.h"
#include "nb_generator.h"
#include "probdist.h"

/**
 * @class ChiSquare chisquare.h "src/chisquare.h"
 * @author  Egor Tkachenko <tkachenko.egor.a@gmail.com>
 * @version 1.0
 * @brief Provides methods for calculating P-value for a given distribution and sample.
 * @example main.cpp
 */
class ChiSquare
{
public:
    /**
     * @param distribution The NB_Distribution object stores distribution function
     * @param generator The NB_Generator object stores sample
     */
    ChiSquare(NB_Distribution& distribution, const NB_Generator& generator);
    /**
     * Set new distribution and sample
     * @param distribution The NB_Distribution object stores distribution function
     * @param generator The NB_Generator object stores sample
     */
    void set_data(NB_Distribution& distribution, const NB_Generator& generator);

    std::vector<double> get_theoretical_frequency() const;
    std::vector<int> get_empirical_frequency() const;
    double get_test_stat();
    int get_degree_of_freedom();
    double get_p_value();

private:
    std::vector<double> theoretical_frequency_; 
    std::vector<int> empirical_frequency_;
    std::vector<double> theoretical_frequency_grouped_;
    std::vector<int> empirical_frequency_grouped_;
    double test_stat_;
    int degree_of_freedom_;
    double p_value_;
    bool stats_are_relevant_;

    void group();
    void calc_p_value();
};

#endif // CHISQUARE_H
