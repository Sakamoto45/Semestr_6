#ifndef NB_DISTRIBUTION_H
#define NB_DISTRIBUTION_H

#include <vector>
#include <string>
#include "math.h"

/**
 * @class NB_Distribution nb_distribution.h "src/nb_distribution.h"
 * @author Egor Tkachenko <tkachenko.egor.a@gmail.com>
 * @version 1.0
 * @brief Calculates the probability function of negative binomial distribution for given parameters.
 * @example main.cpp
 */
class NB_Distribution
{
public:
    /** 
     * @param p probability of success in Bernoulli trails.
     * @param k predefined number of successes.
     */
    NB_Distribution(double p, int k);
    ~NB_Distribution();
    double get_p() const;
    int get_k() const;
    /**
     * Return calculated probabilities.
     * If no probabilities have been calculated, calls ExtendProbabilities().
     */
    std::vector<double> get_probabilities();
    std::string get_name() const;
    int get_probabilities_size() const;
    /**
     * Calculates the probabilities for the following len values
     * or until the probability of the remaining ones is less than 10^-6.
     * @param len indicates how many next probabilities to calculate.
     * If 0, calculate until the probability of the remaining ones is less than 10^-6.
     */
    void ExtendProbabilities(int len = 0);

private:
    double p_;
    int k_;
    std::vector<double> probabilities_;
    double residual_;
    // 10^6 = max sample_size, EPS * sample_size < 5
    const double EPS = 1e-6;
};

#endif // NB_DISTRIBUTION_H
