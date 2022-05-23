#ifndef NB_BERNOULLI_H
#define NB_BERNOULLI_H

#include "nb_generator.h"
#include "nb_distribution.h"

class NB_Bernoulli : public NB_Generator
{
private:
    int k_;
    double p_;

public:
    NB_Bernoulli(NB_Distribution* distribution, int sample_size, std::mt19937& rand_gen);
    ~NB_Bernoulli() override;

    int Generate() override;
};

#endif // NB_BERNOULLI_H
