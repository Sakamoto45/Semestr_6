#ifndef NB_TABLE_H
#define NB_TABLE_H

#include "nb_generator.h"
#include "nb_distribution.h"

class NB_Table : public NB_Generator
{
public:
    NB_Table(NB_Distribution *distribution, int sample_size, std::mt19937& rand_gen);
    ~NB_Table();
    int Generate() override;

private:
    std::vector<double> table_;
};

#endif // NB_TABLE_H
