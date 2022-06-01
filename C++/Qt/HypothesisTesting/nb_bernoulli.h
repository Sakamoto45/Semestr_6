#ifndef NB_BERNOULLI_H
#define NB_BERNOULLI_H

#include "nb_generator.h"
#include "nb_distribution.h"

/**
 * @class NB_Bernoulli nb_bernoulli.h "src/nb_bernoulli.h"
 * @author Egor Tkachenko <tkachenko.egor.a@gmail.com>
 * @version 1.0
 * @brief Derived class for generating a negative binomial random value using the Bernoulli method.
 * @example main.cpp
 */
class NB_Bernoulli : public NB_Generator
{
public:
    /**
     * @param distribution pointer to the NB_Distribution object to get from it parameters for generation.
     * @param sample_size size of the sample to be generated.
     * @param rand_gen mt19937 random number generator.
     */
    NB_Bernoulli(NB_Distribution* distribution, int sample_size, std::mt19937& rand_gen);
    ~NB_Bernoulli();
    /**
     * Overridden method that implements generation using Bernoulli method.
     */
    int Generate() override;

private:
    int k_;
    double p_;
};

#endif // NB_BERNOULLI_H
