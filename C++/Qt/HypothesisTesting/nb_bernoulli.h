#ifndef NB_BERNOULLI_H
#define NB_BERNOULLI_H

#include "nb_generator.h"

class NB_Bernoulli : public NB_Generator
{
public:
    NB_Bernoulli(NB_Distribution* distribution);
    ~NB_Bernoulli() override;
    int Generate() override;
};

#endif // NB_BERNOULLI_H
