#ifndef NB_INVERSE_H
#define NB_INVERSE_H

#include "nb_generator.h"
#include "nb_distribution.h"

class NB_Inverse : public NB_Generator
{
public:
    NB_Inverse(NB_Distribution *distribution, int sample_size, std::mt19937& rand_gen);
    ~NB_Inverse();
    int Generate() override;

private:
    int k_;
    double p_;
};

#endif // NB_INVERSE_H
