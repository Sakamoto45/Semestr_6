#ifndef NB_GENERATOR_H
#define NB_GENERATOR_H

#include <vector>
#include <cstdlib>
#include <random>

/**
 * @class NB_Generator nb_generator.h "src/nb_generator.h"
 * @author Egor Tkachenko <tkachenko.egor.a@gmail.com>
 * @version 1.0
 * @brief Base class for generating a sample of negative binomial distribution.
 * @example main.cpp
 */
class NB_Generator
{
public:
    /**
     * @param sample_size size of the sample to be generated.
     * @param rand_gen mt19937 random number generator.
     */
    NB_Generator(int sample_size, std::mt19937& rand_gen);
    virtual ~NB_Generator();
    /**
     * Virtual method for different implementations of random value generation.
     */
    virtual int Generate()=0;
    /**
     * Method generating sample with Generate().
     */
    int* GenerateSample();
    int* get_sample() const;
    int get_sample_size() const;

protected:
    std::mt19937& rand_gen_;
    int* sample_;
    int sample_size_;
};

#endif // NB_GENERATOR_H
