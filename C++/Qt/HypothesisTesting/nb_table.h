#ifndef NB_TABLE_H
#define NB_TABLE_H

#include "nb_generator.h"
#include "nb_distribution.h"

/**
 * @class NB_Table nb_table.h "src/nb_table.h"
 * @author Egor Tkachenko <tkachenko.egor.a@gmail.com>
 * @version 1.0
 * @brief Derived class for generating a negative binomial random value using the table method.
 * @example main.cpp
 */
class NB_Table : public NB_Generator
{
public:
    /**
     * @param distribution pointer to the NB_Distribution object to get from it parameters for generation.
     * @param sample_size size of the sample to be generated.
     * @param rand_gen mt19937 random number generator.
     */
    NB_Table(NB_Distribution *distribution, int sample_size, std::mt19937& rand_gen);
    ~NB_Table();
    /**
     * Overridden method that implements generation using table method.
     */
    int Generate() override;

private:
    std::vector<double> table_;
};

#endif // NB_TABLE_H
