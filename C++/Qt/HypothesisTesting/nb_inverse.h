#ifndef NB_INVERSE_H
#define NB_INVERSE_H

#include "nb_generator.h"
#include "nb_distribution.h"

/**
 * @class NB_Inverse nb_inverse.h "src/nb_inverse.h"
 * @author Egor Tkachenko <tkachenko.egor.a@gmail.com>
 * @version 1.0
 * @brief Derived class for generating a negative binomial random value using the inverse CDF method.
 * @example main.cpp
 */
class NB_Inverse : public NB_Generator
{
public:
    /**
     * @param distribution pointer to the NB_Distribution object to get from it parameters for generation.
     * @param sample_size size of the sample to be generated.
     * @param rand_gen mt19937 random number generator.
     */
    NB_Inverse(NB_Distribution *distribution, int sample_size, std::mt19937& rand_gen);
    ~NB_Inverse();
    /**
     * Overridden method that implements generation using inverse CDF method.
     */
    int Generate() override;

private:
    NB_Distribution *distribution_;
};

#endif // NB_INVERSE_H
